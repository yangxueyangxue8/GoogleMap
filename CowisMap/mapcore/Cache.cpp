#include "Cache.h"
#include <QDir>
#include <QTextStream>
namespace cowiscore {
Cache* Cache::m_pInstance = 0;
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Cache *Cache::Instance()
{
    if (!m_pInstance)
    {
        m_pInstance = new Cache;
    }
    return m_pInstance;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Cache::CacheLocation()
{
    return cache;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Cache::setCacheLocation(const QString &value)
{
    cache = value;
    routeCache = cache + "RouteCache/";
    geoCache   = cache + "GeocoderCache/";
    placemarkCache = cache + "PlacemarkCache/";
    imageCache.setGtileCache(value);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Cache::CacheGeocoder(const QString &urlEnd, const QString &content)
{
    QString filename = geoCache + urlEnd + ".geo";
    QFileInfo fileInfo(filename);
    QDir dir = fileInfo.absoluteDir();
    QString path = dir.absolutePath();
    if (!dir.exists())
    {
        if (!dir.mkpath(path))
        {
            return;
        }
    }
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << content;

    }
    file.close();

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Cache::getGeocoderFromCache(const QString &urlEnd)
{
    QString ret = QString::null;
    QString filename = geoCache + urlEnd + ".geo";
    QFileInfo fileInfo(filename);
    if (fileInfo.exists())
    {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream >> ret;
        }
        file.close();
    }
    return ret;

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Cache::CachePlacemark(const QString &urlEnd, const QString &content)
{
    QString filename = placemarkCache + urlEnd + ".plc";
    QFileInfo fileInfo(filename);
    QDir dir = fileInfo.absoluteDir();
    QString path = dir.absolutePath();

    if (!dir.exists())
    {
        if (!dir.mkpath(path))
        {
            return;
        }
    }
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << content;
    }
    file.close();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Cache::getPlacemarkfromCache(const QString &urlEnd)
{
    QString ret = QString::null;
    QString filename = placemarkCache + urlEnd + ".plc";
    QFileInfo fileInfo(filename);
    if (fileInfo.exists())
    {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            stream.setCodec("UTF-8");
            stream >> ret;
        }
        file.close();
    }
    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Cache::Cache()
{
    if (cache.isNull() || cache.isEmpty())
    {
        cache = QDir::homePath() + "/mapscache/";
        setCacheLocation(cache);
    }
}


}

