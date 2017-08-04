#include "OPMaps.h"
#include "Cache.h"
#include <QDir>
namespace cowiscore {

OPMaps* OPMaps::m_pInstance = 0;

/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
OPMaps::~OPMaps()
{
    TileDBcacheQueue.wait();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
OPMaps *OPMaps::Instance()
{
    if(!m_pInstance)
    {
        m_pInstance = new OPMaps();
    }
    return m_pInstance;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool OPMaps::ImportFromGMDB(const QString &file)
{
    return Cache::Instance()->imageCache.exportMapDataToDB(file, Cache::Instance()->imageCache.GtileCache() + QDir::separator() + "Data.qmdb");
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool OPMaps::ExportToGMDB(const QString &file)
{
    return Cache::Instance()->imageCache.exportMapDataToDB(Cache::Instance()->imageCache.GtileCache() + QDir::separator() + "Data.qmdb", file);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QByteArray OPMaps::GetImageFrom(const Maptype::Types &type, const Point &pos, const int &zoom)
{
    QByteArray ret;
    if (useMemoryCache)
    {
        ret = getTileFromMemoryCache(RawTitle(type, pos, zoom));
        if (!ret.isEmpty())
        {
            errorvars.lock();
            ++diag.titlesFromMem;
            errorvars.unlock();
        }

    }
    if (ret.isEmpty())
    {
        if (accessmode != (AccessMode::ServerOnly))
        {
            ret = Cache::Instance()->imageCache.getImageFroCache(type, pos, zoom);
            if (!ret.isEmpty())
            {
                errorvars.lock();
                ++diag.titlesFromDB;
                errorvars.unlock();
                if (useMemoryCache)
                {
                    AddTileToMemoryCache(RawTitle(type, pos, zoom), ret);
                }
                return ret;
            }
        }
        if (accessmode != (AccessMode::CacheOnly))
        {
            QEventLoop q;
            QNetworkReply* reply;
            QNetworkRequest qheader;
            QNetworkAccessManager network;
            QTimer tT;
            tT.setSingleShot(true);
            connect(&network, SIGNAL(finished(QNetworkReply*)), &q, SLOT(quit()));
            connect(&tT, SIGNAL(timeout()), &q, SLOT(quit()));
            network.setProxy(Proxy);
            QString url = makeImageUrl(type, pos, zoom, LanguageStr);
            qheader.setUrl(url);
            qheader.setRawHeader("User-Agent", UserAgent);
            qheader.setRawHeader("Accept", "*/*");
            switch(type)
            {
            case Maptype::GoogleMap:
            case Maptype::GoogleSatellite:
            case Maptype::GoogleLabels:
            case Maptype::GoogleTerrain:
            case Maptype::GoogleHybrid:
            {
                qheader.setRawHeader("Referrer", "http://maps.google.com/");
            }
                break;

            case Maptype::GoogleMapChina:
            case Maptype::GoogleSatelliteChina:
            case Maptype::GoogleLabelsChina:
            case Maptype::GoogleTerrainChina:
            case Maptype::GoogleHybridChina:
                {
                    qheader.setRawHeader("Referrer", "http://ditu.google.cn/");
                }
                break;

            case Maptype::BingHybrid:
            case Maptype::BingMap:
            case Maptype::BingSatellite:
                {
                    qheader.setRawHeader("Referrer", "http://www.bing.com/maps/");
                }
                break;

            case Maptype::YahooHybrid:
            case Maptype::YahooLabels:
            case Maptype::YahooMap:
            case Maptype::YahooSatellite:
                {
                    qheader.setRawHeader("Referrer", "http://maps.yahoo.com/");
                }
                break;

            case Maptype::ArcGIS_MapsLT_Map_Labels:
            case Maptype::ArcGIS_MapsLT_Map:
            case Maptype::ArcGIS_MapsLT_OrtoFoto:
            case Maptype::ArcGIS_MapsLT_Map_Hybrid:
                {
                    qheader.setRawHeader("Referrer", "http://www.maps.lt/map_beta/");
                }
                break;

            case Maptype::OpenStreetMapSurfer:
            case Maptype::OpenStreetMapSurferTerrain:
                {
                    qheader.setRawHeader("Referrer", "http://www.mapsurfer.net/");
                }
                break;

            case Maptype::OpenStreetMap:
            case Maptype::OpenStreetOsm:
                {
                    qheader.setRawHeader("Referrer", "http://www.openstreetmap.org/");
                }
                break;

            case Maptype::YandexMapRu:
                {
                    qheader.setRawHeader("Referrer", "http://maps.yandex.ru/");
                }
                break;
            default:
                break;
            }
            reply = network.get(qheader);
            tT.start(Timeout);
            q.exec();
            if(!tT.isActive())
            {
                errorvars.lock();
                ++diag.timeouts;
                errorvars.unlock();
                return ret;
            }
            tT.stop();
            if ((reply->error() != QNetworkReply::NoError))
            {
                errorvars.lock();
                ++diag.networkerrors;
                errorvars.unlock();
                reply->deleteLater();
                return ret;
            }
            ret = reply->readAll();
            reply->deleteLater();
            if (ret.isEmpty())
            {
                errorvars.lock();
                ++diag.emptytitles;
                errorvars.unlock();
                return ret;
            }
            errorvars.lock();
            ++diag.titlesFromNet;
            errorvars.unlock();
            if (UseMemoryCache())
            {
                AddTileToMemoryCache(RawTitle(type, pos, zoom), ret);
            }
            if (accessmode != AccessMode::ServerOnly)
            {
                CacheItemQueue* item = new CacheItemQueue(type, pos, ret, zoom);
                TileDBcacheQueue.EnqueueCacheTask(item);
            }
        }
    }
    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
NetDiagnostics OPMaps::GetDiagnostics()
{
    NetDiagnostics i;
    errorvars.lock();
    i = diag;
    errorvars.unlock();
    return i;
}

OPMaps::OPMaps()
{
    accessmode  = AccessMode::ServerAndCache;
    Language    = LanguageType::PortuguesePortugal;
    LanguageStr = LanguageType().toShortString(Language);
    Cache::Instance();
}
}


