#include "PureImageCache.h"
#include <QDir>
#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QDateTime>
#include <QList>
namespace cowiscore {
static QMutex addDatabaseMutex;
qlonglong PureImageCache::ConnCounter = 0;
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
PureImageCache::PureImageCache()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool PureImageCache::createEmptyDB(const QString &file)
{
    QFileInfo fileInfo(file);
    QDir dir = fileInfo.absoluteDir();
    QString path = dir.absolutePath();
    QString filename = fileInfo.fileName();

    if (fileInfo.exists())
    {
        QFile(filename).remove();
    }

    if (!dir.exists())
    {
        if (!dir.mkpath(path))
        {
            return false;
        }
    }
    addDatabaseMutex.lock();
    QSqlDatabase db(QSqlDatabase::addDatabase("QSQLITE", QLatin1String("CreateConn")));
    addDatabaseMutex.unlock();
    db.setDatabaseName(file);
    if (!db.open())
    {
        return false;
    }

    QSqlQuery query(db);
    query.exec("CREATE TABLE IF NOT EXISTS Tiles (id INTEGER NOT NULL PRIMARY KEY, X INTEGER NOT NULL, Y INTEGER NOT NULL, Zoom INTEGER NOT NULL, Type INTEGER NOT NULL,Date TEXT)");
    if (query.numRowsAffected() == -1)
    {
        db.close();
        return false;
    }
    query.exec("CREATE TABLE IF NOT EXISTS TilesData (id INTEGER NOT NULL PRIMARY KEY CONSTRAINT fk_Tiles_id REFERENCES Tiles(id) ON DELETE CASCADE, Tile BLOB NULL)");
    if(query.numRowsAffected() == -1)
    {
        db.close();
        return false;
    }
    query.exec(
                "CREATE TRIGGER fki_TilesData_id_Tiles_id "
                "BEFORE INSERT ON [TilesData] "
                "FOR EACH ROW BEGIN "
                "SELECT RAISE(ROLLBACK, 'insert on table TilesData violates foreign key constraint fki_TilesData_id_Tiles_id') "
                "WHERE (SELECT id FROM Tiles WHERE id = NEW.id) IS NULL; "
                "END");
    if (query.numRowsAffected() == -1)
    {
        db.close();
        return false;
    }
    query.exec(
             "CREATE TRIGGER fku_TilesData_id_Tiles_id "
             "BEFORE UPDATE ON [TilesData] "
             "FOR EACH ROW BEGIN "
             "SELECT RAISE(ROLLBACK, 'update on table TilesData violates foreign key constraint fku_TilesData_id_Tiles_id') "
             "WHERE (SELECT id FROM Tiles WHERE id = NEW.id) IS NULL; "
             "END");
     if(query.numRowsAffected()==-1)
     {
         db.close();
         return false;
     }
     query.exec(
             "CREATE TRIGGER fkdc_TilesData_id_Tiles_id "
             "BEFORE DELETE ON Tiles "
             "FOR EACH ROW BEGIN "
             "DELETE FROM TilesData WHERE TilesData.id = OLD.id; "
             "END");
     if(query.numRowsAffected()==-1)
     {
         db.close();
         return false;
     }
     db.close();
     QSqlDatabase::removeDatabase(QLatin1String("CreateConn"));
     return true;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool PureImageCache::putImageToCache(const QByteArray &title, const Maptype::Types &type, const Point &pos, const int &zoom)
{
    if (gtileCache.isEmpty() || gtileCache.isNull())
    {
        return false;
    }
    lock.lockForRead();
    Mcountter.lock();
    qlonglong id = ++ConnCounter;
    Mcountter.unlock();
    {
        addDatabaseMutex.lock();
        QSqlDatabase cn(QSqlDatabase::addDatabase("QSQLITE", QString::number(id)));
        addDatabaseMutex.unlock();
        QString db = gtileCache + "Data.qmdb";
        cn.setDatabaseName(db);
        cn.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE");
        if(cn.open())
        {
            {
                QSqlQuery query(cn);
                query.prepare("INSERT INTO Tiles(X, Y, Zoom, Type,Date) VALUES(?, ?, ?, ?,?)");
                query.addBindValue(pos.X());
                query.addBindValue(pos.Y());
                query.addBindValue(zoom);

                query.addBindValue((int)type);
                query.addBindValue(QDateTime::currentDateTime().toString());
                query.exec();
            }
            {
                QSqlQuery query(cn);
                query.prepare("INSERT INTO TilesData(id, Tile) VALUES((SELECT last_insert_rowid()), ?)");
                query.addBindValue(title);
                query.exec();
            }
            cn.close();
        }
    }
    QSqlDatabase::removeDatabase(QString::number(id));
    lock.unlock();
    return true;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QByteArray PureImageCache::getImageFroCache(Maptype::Types type, Point pos, int zoom)
{
    lock.lockForRead();
    QByteArray ar;
    if (gtileCache.isEmpty() || gtileCache.isNull())
    {
        return ar;
    }
    QString dir = gtileCache;
    Mcountter.lock();
    qlonglong id = ++ConnCounter;
    Mcountter.unlock();
    QString db = dir + "Data.qmdb";
    {
        addDatabaseMutex.lock();
        QSqlDatabase cn(QSqlDatabase::addDatabase("QSQLITE", QString::number(id)));
        addDatabaseMutex.unlock();

        cn.setDatabaseName(db);
        cn.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE");
        if(cn.open())
        {
            QSqlQuery query(cn);
            query.exec(QString("SELECT Tile FROM TilesData WHERE id = (SELECT id FROM Tiles WHERE X=%1 AND Y=%2 AND Zoom=%3 AND Type=%4)").arg(pos.X()).arg(pos.Y()).arg(zoom).arg((int)type));
            query.next();
            if(query.isValid())
            {
                ar = query.value(0).toByteArray();
            }
            cn.close();

        }
    }
    QSqlDatabase::removeDatabase(QString::number(id));
    lock.unlock();
    return ar;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString PureImageCache::GtileCache()
{
    return gtileCache;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void PureImageCache::setGtileCache(const QString &value)
{
    lock.lockForWrite();
    gtileCache = value;
    QDir dir(value);

    if (!dir.exists())
    {
        dir.mkdir(value);
    }
    QString db = gtileCache + "Data.qmdb";
    if (!QFileInfo(db).exists())
    {
        createEmptyDB(db);
    }
    lock.unlock();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool PureImageCache::exportMapDataToDB(QString sourceFile, QString destFile)
{
    bool ret = true;
    QList<long> add;
    if (!QFileInfo(destFile).exists())
    {
        ret = createEmptyDB(destFile);
    }
    if (!ret)
    {
        return false;
    }
    addDatabaseMutex.lock();
    QSqlDatabase ca(QSqlDatabase::addDatabase("QSQLITE", "ca"));
    addDatabaseMutex.unlock();
    ca.setDatabaseName(sourceFile);
    if (ca.open())
    {
        addDatabaseMutex.lock();
        QSqlDatabase cb(QSqlDatabase::addDatabase("QSQLITE", "cb"));
        addDatabaseMutex.unlock();
        cb.setDatabaseName(destFile);
        if (cb.open())
        {
            QSqlQuery queryb(cb);
            queryb.exec(QString("ATTACH DATABASE \"%1\" AS Source").arg(sourceFile));
            QSqlQuery querya(ca);
            querya.exec("SELECT id, X, Y, Zoom, Type, Date FROM Tiles");
            while (querya.next()) {
                long id=querya.value(0).toLongLong();
                queryb.exec(QString("SELECT id FROM Tiles WHERE X=%1 AND Y=%2 AND Zoom=%3 AND Type=%4;").arg(querya.value(1).toLongLong()).arg(querya.value(2).toLongLong()).arg(querya.value(3).toLongLong()).arg(querya.value(4).toLongLong()));
                if(!queryb.next())
                {
                    add.append(id);
                }
            }
            long f;
            foreach(f,add)
            {
                queryb.exec(QString("INSERT INTO Tiles(X, Y, Zoom, Type, Date) SELECT X, Y, Zoom, Type, Date FROM Source.Tiles WHERE id=%1").arg(f));
                queryb.exec(QString("INSERT INTO TilesData(id, Tile) Values((SELECT last_insert_rowid()), (SELECT Tile FROM Source.TilesData WHERE id=%1))").arg(f));
            }
            add.clear();
            ca.close();
            cb.close();


        }
         else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    QSqlDatabase::removeDatabase("ca");
    QSqlDatabase::removeDatabase("cb");
    return true;

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void PureImageCache::deleteOlderTiles(const int &days)
{
    if(gtileCache.isEmpty()|gtileCache.isNull())
    {
        return;
    }
    QList<long> add;
    bool ret = true;
    QString dir = gtileCache;
    {
        QString db=dir+"Data.qmdb";
        ret=QFileInfo(db).exists();
        if(ret)
        {

            Mcountter.lock();
            qlonglong id=++ConnCounter;
            Mcountter.unlock();
            addDatabaseMutex.lock();
            QSqlDatabase cn(QSqlDatabase::addDatabase("QSQLITE",QString::number(id)));
            addDatabaseMutex.unlock();
            cn.setDatabaseName(db);
            cn.setConnectOptions("QSQLITE_ENABLE_SHARED_CACHE");
            if(cn.open())
            {
                {
                    QSqlQuery query(cn);
                    query.exec(QString("SELECT id, X, Y, Zoom, Type, Date FROM Tiles"));
                    while(query.next())
                    {
                        if(QDateTime::fromString(query.value(5).toString()).daysTo(QDateTime::currentDateTime())>days)
                            add.append(query.value(0).toLongLong());
                    }
                    foreach(long i,add)
                    {
                        query.exec(QString("DELETE FROM Tiles WHERE id = %1;").arg(i));
                    }
                }

                cn.close();
            }
            QSqlDatabase::removeDatabase(QString::number(id));
        }
    }
}

}


