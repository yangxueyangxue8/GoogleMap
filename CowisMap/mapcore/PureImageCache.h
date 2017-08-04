/******************************************************************************
* @brief 摘要
* @author Xue yang
* @date   2017/07/17
******************************************************************************/
#ifndef PUREIMAGECACHE_H
#define PUREIMAGECACHE_H
#include <QString>
#include <QVariant>
#include <QByteArray>
#include "Maptype.h"
#include "Point.h"
#include <QMutex>
#include <QReadWriteLock>
namespace cowiscore {
class PureImageCache
{
public:
    PureImageCache();

    static bool createEmptyDB(const QString& file);

    bool putImageToCache(const QByteArray& title, const Maptype::Types &type, const cowiscore::Point& pos, const int& zoom);
    QByteArray getImageFroCache(Maptype::Types type, cowiscore::Point pos, int zoom);

    QString GtileCache();
    void setGtileCache(const QString& value);

    static bool exportMapDataToDB(QString sourceFile, QString destFile);
    void deleteOlderTiles(int const& days);
private:
    QString gtileCache;
    QMutex Mcountter;
    QReadWriteLock lock;
    static qlonglong ConnCounter;
};
}


#endif // PUREIMAGECACHE_H
