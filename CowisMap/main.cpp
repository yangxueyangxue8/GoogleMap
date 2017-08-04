#include "Mainwindow.h"
#include <QApplication>
#include "QStringList"
#include <QDir>
#include <QDebug>
#include <QTime>
QStringList findFiles(const QString &startDir, QStringList filters)
{
    QStringList names;
    QDir dir(startDir);

    foreach (QString file, dir.entryList(filters, QDir::Files))
        names += startDir + '/' + file;

    foreach (QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot))
        names += findFiles(startDir + '/' + subdir, filters);
    return names;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QStringList ret ;
    QTime time;
    time.start();
    ret = findFiles(QString("C:/Users/Administrator/Desktop/myTcpTools"), QStringList() <<"*.*");
    qDebug()<<ret.count()<<"time:"<<time.elapsed();
//    foreach (QString str, ret) {
//        qDebug()<<str;
//    }
    MainWindow w;
    w.show();

    return a.exec();
}


