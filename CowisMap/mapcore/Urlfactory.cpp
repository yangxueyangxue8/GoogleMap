#include "Urlfactory.h"
#include <QRegExp>
#include <cmath>
#include "Cache.h"
#include <QTextCodec>
namespace cowiscore {
const double Urlfactory::EarthRadiusKm = 6378.137;
Urlfactory::Urlfactory()
{
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    UserAgent = QString("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:%1.0) Gecko/%2%3%4 Firefox/%5.0.%6").arg(QString::number(Random(3,14)), QString::number(Random(QDate().currentDate().year() - 4, QDate().currentDate().year())), QString::number(Random(11,12)), QString::number(Random(10,30)), QString::number(Random(3,14)), QString::number(Random(1,10))).toLatin1();
    Timeout = 5000;
    CorrectGoogleVersion      = true;
    isCorrectedGoogleversions = false;
    UseGeocoderCache          = true;
    UsePlacemarkCache         = true;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
cowiscore::Urlfactory::~Urlfactory()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Urlfactory::makeImageUrl(const Maptype::Types &type, const Point &pos, const int &zoom, const QString &language)
{
    switch (type)
    {
    case Maptype::GoogleMap:
    {
        QString server  = "mts";
        QString request = "vt";
        QString sec1    = "";
        QString sec2    = "";
        GetSecGoogleWords(pos, sec1, sec2);
        TryCorrectGoogleVersions();
        return QString("http://%1%2.google.com/%3/lyrs=%4&hl=%5&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleMap).arg(language).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
    }
        break;
    case Maptype::GoogleSatellite:
         {
            // QString server = "khms";
            // QString request = "kh";
             QString sec1 = ""; // after &x=...
             QString sec2 = ""; // after &zoom=...
             GetSecGoogleWords(pos,  sec1,  sec2);
             TryCorrectGoogleVersions();
             return QString("http://mt1.google.com/vt/lyrs=y&x=%1%2&y=%3&z=%4").arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom);
         }
         break;
     case Maptype::GoogleLabels:
         {
             QString server = "mts";
             QString request = "vt";
             QString sec1 = ""; // after &x=...
             QString sec2 = ""; // after &zoom=...
             GetSecGoogleWords(pos,  sec1,  sec2);
             TryCorrectGoogleVersions();

             return QString("http://%1%2.google.com/%3/lyrs=%4&hl=%5&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleLabels).arg(language).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
         }
         break;
     case Maptype::GoogleTerrain:
         {
             QString server = "mts";
             QString request = "vt";
             QString sec1 = ""; // after &x=...
             QString sec2 = ""; // after &zoom=...
             GetSecGoogleWords(pos,  sec1,  sec2);
             TryCorrectGoogleVersions();
             return QString("http://%1%2.google.com/%3/v=%4&hl=%5&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleTerrain).arg(language).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
         }
         break;
    case Maptype::GoogleMapChina:
        {
            QString server = "mt";
            QString request = "vt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.google.cn/%3/lyrs=%4&hl=%5&gl=cn&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleMapChina).arg("zh-CN").arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
        }
        break;
    case Maptype::GoogleSatelliteChina:
        {
            QString server = "mt";
            QString request = "vt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.google.cn/%3/lyrs=%4&gl=zh-CN&x=%5%6&y=%7&z=%8&s=%9").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleSatelliteChina).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
        }
        break;
    case Maptype::GoogleLabelsChina:
        {
            QString server = "mt";
            QString request = "vt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.google.cn/%3/imgtp=png32&lyrs=%4&hl=%5&gl=cn&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleLabelsChina).arg("zh-CN").arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);

        }
        break;
    case Maptype::GoogleTerrainChina://GoogleTerrainChina:
        {
            QString server = "mt";
            QString request = "vt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.google.cn/%3/lyrs=%4&hl=%5&gl=cn&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleTerrainChina).arg("zh-CN").arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
        }
        break;
    case Maptype::GoogleMapKorea:
        {
            QString server = "mt";
            QString request = "mt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            QString ret = QString("http://%1%2.gmaptiles.co.kr/%3/v=%4&hl=%5&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleMapKorea).arg(language).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
            return ret;
        }
        break;
    case Maptype::GoogleSatelliteKorea:
        {
            QString server = "khm";
            QString request = "kh";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.google.co.kr/%3/v=%4&x=%5%6&y=%7&z=%8&s=%9").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleSatelliteKorea).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
        }
        break;

    case Maptype::GoogleLabelsKorea:
        {
            QString server = "mt";
            QString request = "mt";
            QString sec1 = ""; // after &x=...
            QString sec2 = ""; // after &zoom=...
            GetSecGoogleWords(pos,  sec1,  sec2);
            return QString("http://%1%2.gmaptiles.co.kr/%3/v=%4&hl=%5&x=%6%7&y=%8&z=%9&s=%10").arg(server).arg(GetServerNum(pos, 4)).arg(request).arg(VersionGoogleLabelsKorea).arg(language).arg(pos.X()).arg(sec1).arg(pos.Y()).arg(zoom).arg(sec2);
        }
        break;
    case Maptype::YahooMap:
        {
            return QString("http://maps%1.yimg.com/hx/tl?v=%2&.intl=%3&x=%4&y=%5&z=%6&r=1").arg(((GetServerNum(pos, 2)) + 1)).arg(VersionYahooMap).arg(language).arg(pos.X()).arg((((1 << zoom) >> 1) - 1 - pos.Y())).arg((zoom + 1));
        }

    case Maptype::YahooSatellite:
        {
            return QString("http://maps%1.yimg.com/ae/ximg?v=%2&t=a&s=256&.intl=%3&x=%4&y=%5&z=%6&r=1").arg("3").arg(VersionYahooSatellite).arg(language).arg(pos.X()).arg(((1 << zoom) >> 1) - 1 - pos.Y()).arg(zoom + 1);
        }
        break;
    case Maptype::YahooLabels:
        {
            return QString("http://maps%1.yimg.com/hx/tl?v=%2&t=h&.intl=%3&x=%4&y=%5&z=%6&r=1").arg("1").arg(VersionYahooLabels).arg(language).arg(pos.X()).arg(((1 << zoom) >> 1) - 1 - pos.Y()).arg(zoom + 1);
        }
        break;
    case Maptype::OpenStreetMap:
        {
            char letter= "abc"[GetServerNum(pos, 3)];
            return QString("http://%1.tile.openstreetmap.org/%2/%3/%4.png").arg(letter).arg(zoom).arg(pos.X()).arg(pos.Y());
        }
        break;
    case Maptype::OpenStreetOsm:
        {
            char letter = "abc"[GetServerNum(pos, 3)];
            return QString("http://%1.tah.openstreetmap.org/Tiles/tile/%2/%3/%4.png").arg(letter).arg(zoom).arg(pos.X()).arg(pos.Y());
        }
        break;
    case Maptype::OpenStreetMapSurfer:
        {
            // http://tiles1.mapsurfer.net/tms_r.ashx?x=37378&y=20826&z=16

            return QString("http://tiles1.mapsurfer.net/tms_r.ashx?x=%1&y=%2&z=%3").arg(pos.X()).arg(pos.Y()).arg(zoom);
        }
        break;
    case Maptype::OpenStreetMapSurferTerrain:
        {
            // http://tiles2.mapsurfer.net/tms_t.ashx?x=9346&y=5209&z=14

            return QString("http://tiles2.mapsurfer.net/tms_t.ashx?x=%1&y=%2&z=%3").arg(pos.X()).arg(pos.Y()).arg(zoom);
        }
        break;
    case Maptype::BingMap:
        {
            QString key = TileXYToQuadKey(pos.X(), pos.Y(), zoom);
            return QString("http://ecn.t%1.tiles.virtualearth.net/tiles/r%2.png?g=%3&mkt=%4%5").arg(GetServerNum(pos, 4)).arg(key).arg(VersionBingMaps).arg(language).arg(!(BingMapsClientToken.isNull()|BingMapsClientToken.isEmpty()) ? "&token=" + BingMapsClientToken : QString(""));
        }
        break;
    case Maptype::BingSatellite:
        {
            QString key = TileXYToQuadKey(pos.X(), pos.Y(), zoom);
            return QString("http://ecn.t%1.tiles.virtualearth.net/tiles/a%2.jpeg?g=%3&mkt=%4%5").arg(GetServerNum(pos, 4)).arg(key).arg(VersionBingMaps).arg(language).arg(!(BingMapsClientToken.isNull()|BingMapsClientToken.isEmpty()) ? "&token=" + BingMapsClientToken : QString(""));
        }
        break;
    case Maptype::BingHybrid:
        {
            QString key = TileXYToQuadKey(pos.X(), pos.Y(), zoom);
            return QString("http://ecn.t%1.tiles.virtualearth.net/tiles/h%2.jpeg?g=%3&mkt=%4%5").arg(GetServerNum(pos, 4)).arg(key).arg(VersionBingMaps).arg(language).arg(!(BingMapsClientToken.isNull()|BingMapsClientToken.isEmpty()) ? "&token=" + BingMapsClientToken : QString(""));
        }

    case Maptype::ArcGIS_Map:
        {
            // http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_StreetMap_World_2D/MapServer/tile/0/0/0.jpg

            return QString("http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_StreetMap_World_2D/MapServer/tile/%1/%2/%3").arg(zoom).arg(pos.Y()).arg(pos.X());
        }
        break;
    case Maptype::ArcGIS_Satellite:
        {
            // http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_Imagery_World_2D/MapServer/tile/1/0/1.jpg

            return QString("http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_Imagery_World_2D/MapServer/tile/%1/%2/%3").arg(zoom).arg(pos.Y()).arg(pos.X());
        }
        break;
    case Maptype::ArcGIS_ShadedRelief:
        {
            // http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_ShadedRelief_World_2D/MapServer/tile/1/0/1.jpg

            return QString("http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_ShadedRelief_World_2D/MapServer/tile/%1/%2/%3").arg(zoom).arg(pos.Y()).arg(pos.X());
        }
        break;
    case Maptype::ArcGIS_Terrain:
        {
            // http://server.arcgisonline.com/ArcGIS/rest/services/NGS_Topo_US_2D/MapServer/tile/4/3/15

            return QString("http://server.arcgisonline.com/ArcGIS/rest/services/NGS_Topo_US_2D/MapServer/tile/%1/%2/%3").arg(zoom).arg(pos.Y()).arg(pos.X());
        }
        break;
    case Maptype::ArcGIS_MapsLT_OrtoFoto:
        {
            // http://www.maps.lt/ortofoto/mapslt_ortofoto_vector_512/map/_alllayers/L02/R0000001b/C00000028.jpg
            // http://arcgis.maps.lt/ArcGIS/rest/services/mapslt_ortofoto/MapServer/tile/0/9/13
            // return string.Format("http://www.maps.lt/ortofoto/mapslt_ortofoto_vector_512/map/_alllayers/L{0:00}/R{1:x8}/C{2:x8}.jpg", zoom, pos.Y(), pos.X());
            // http://dc1.maps.lt/cache/mapslt_ortofoto_512/map/_alllayers/L03/R0000001c/C00000029.jpg
            // return string.Format("http://arcgis.maps.lt/ArcGIS/rest/services/mapslt_ortofoto/MapServer/tile/{0}/{1}/{2}", zoom, pos.Y(), pos.X());
            // http://dc1.maps.lt/cache/mapslt_ortofoto_512/map/_alllayers/L03/R0000001d/C0000002a.jpg
            //TODO verificar
            return QString("http://dc1.maps.lt/cache/mapslt_ortofoto/map/_alllayers/L%1/R%2/C%3.jpg").arg(zoom,2,10,(QChar)'0').arg(pos.Y(),8,16,(QChar)'0').arg(pos.X(),8,16,(QChar)'0');
        }
        break;
    case Maptype::ArcGIS_MapsLT_Map:
        {
            // http://www.maps.lt/ortofoto/mapslt_ortofoto_vector_512/map/_alllayers/L02/R0000001b/C00000028.jpg
            // http://arcgis.maps.lt/ArcGIS/rest/services/mapslt_ortofoto/MapServer/tile/0/9/13
            // return string.Format("http://www.maps.lt/ortofoto/mapslt_ortofoto_vector_512/map/_alllayers/L{0:00}/R{1:x8}/C{2:x8}.jpg", zoom, pos.Y(), pos.X());
            // http://arcgis.maps.lt/ArcGIS/rest/services/mapslt/MapServer/tile/7/1162/1684.png
            // http://dc1.maps.lt/cache/mapslt_512/map/_alllayers/L03/R0000001b/C00000029.png
            //TODO verificar
            // http://dc1.maps.lt/cache/mapslt/map/_alllayers/L02/R0000001c/C00000029.png
            return QString("http://dc1.maps.lt/cache/mapslt/map/_alllayers/L%1/R%2/C%3.png").arg(zoom,2,10,(QChar)'0').arg(pos.Y(),8,16,(QChar)'0').arg(pos.X(),8,16,(QChar)'0');
        }
        break;
    case Maptype::ArcGIS_MapsLT_Map_Labels:
        {
            //http://arcgis.maps.lt/ArcGIS/rest/services/mapslt_ortofoto_overlay/MapServer/tile/0/9/13
            //return string.Format("http://arcgis.maps.lt/ArcGIS/rest/services/mapslt_ortofoto_overlay/MapServer/tile/{0}/{1}/{2}", zoom, pos.Y(), pos.X());
            //http://dc1.maps.lt/cache/mapslt_ortofoto_overlay_512/map/_alllayers/L03/R0000001d/C00000029.png
            //TODO verificar
            return QString("http://dc1.maps.lt/cache/mapslt_ortofoto_overlay/map/_alllayers/L%1/R%2/C%3.png").arg(zoom,2,10,(QChar)'0').arg(pos.Y(),8,16,(QChar)'0').arg(pos.X(),8,16,(QChar)'0');
        }
        break;
    case Maptype::PergoTurkeyMap:
        {
            // http://{domain}/{layerName}/{zoomLevel}/{first3LetterOfTileX}/{second3LetterOfTileX}/{third3LetterOfTileX}/{first3LetterOfTileY}/{second3LetterOfTileY}/{third3LetterOfTileXY}.png

            // http://map3.pergo.com.tr/tile/00/000/000/001/000/000/000.png
            // That means: Zoom Level: 0 TileX: 1 TileY: 0

            // http://domain/tile/14/000/019/371/000/011/825.png
            // That means: Zoom Level: 14 TileX: 19371 TileY:11825

            //               string x = pos.X().ToString("000000000").Insert(3, "/").Insert(7, "/"); // - 000/000/001
            //               string y = pos.Y().ToString("000000000").Insert(3, "/").Insert(7, "/"); // - 000/000/000
            QString x=QString("%1").arg(QString::number(pos.X()),9,(QChar)'0');
            x.insert(3,"/").insert(7,"/");
            QString y=QString("%1").arg(QString::number(pos.Y()),9,(QChar)'0');
            y.insert(3,"/").insert(7,"/");
            //"http://map03.pergo.com.tr/tile/2/000/000/003/000/000/002.png"
            return QString("http://map%1.pergo.com.tr/tile/%2/%3/%4.png").arg(GetServerNum(pos, 4)).arg(zoom,2,10,(QChar)'0').arg(x).arg(y);
        }
        break;
    case Maptype::SigPacSpainMap:
        {
            return QString("http://sigpac.mapa.es/kmlserver/raster/%1@3785/%2.%3.%4.img").arg(levelsForSigPacSpainMap[zoom]).arg(zoom).arg(pos.X()).arg((2 << (zoom - 1)) - pos.Y() - 1);
        }
        break;

    case Maptype::YandexMapRu:
        {
            QString server = "vec";

            //http://vec01.maps.yandex.ru/tiles?l=map&v=2.10.2&x=1494&y=650&z=11

            return QString("http://%1").arg(server)+QString("0%2.maps.yandex.ru/tiles?l=map&v=%3&x=%4&y=%5&z=%6").arg(GetServerNum(pos, 4)+1).arg(VersionYandexMap).arg(pos.X()).arg(pos.Y()).arg(zoom);
        }
        break;
    default:
        break;
    }
    return QString::null;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
cowisinternals::PointLatLng Urlfactory::getLatLngFromGeodecoder(const QString &keywords, GeoCoderStatusCode::Types &status)
{
    return GetLatLngFromGeocoderUrl(MakeGeocoderUrl(keywords), UseGeocoderCache, status);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Placemark Urlfactory::getPalcemarkFromGeocoder(cowisinternals::PointLatLng location)
{
    return GetPalcemarkFromReverseGeocoderUrl(MakeReverseGeocoderUrl(location, LanguageStr), UsePlacemarkCache);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
int Urlfactory::Random(int low, int high)
{
    return low + qrand() % (high - low);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Urlfactory::GetSecGoogleWords(const Point &pos, QString &sec1, QString &sec2)
{
    sec1 = "";
    sec2 = "";
    int seclen = ((pos.X() * 3) + pos.Y()) % 8;
    sec2 = SecGoogleWord.left(seclen);
    if (pos.Y() >= 10000 && pos.Y() < 100000)
    {
        sec1 = "&s=";
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
int Urlfactory::GetServerNum(const Point &pos, const int &max) const
{
    return (pos.X() + 2 * pos.Y()) % max;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Urlfactory::TryCorrectGoogleVersions()
{
    static bool versionRetrieved = false;
    if (versionRetrieved)
    {
        return;
    }
   // QMutexLocker locker(&mutex);
    if (CorrectGoogleVersion && !IscorrectGoogleVersions())
    {
        QNetworkReply* reply;
        QNetworkRequest qheader;
        QNetworkAccessManager network;
        QEventLoop q;
        QTimer tT;
        tT.setSingleShot(true);
        connect(&network, SIGNAL(finished(QNetworkReply*)),&q, SLOT(quit()));
        connect(&tT, SIGNAL(timeout()), &q, SLOT(quit()));
        network.setProxy(Proxy);
        setIscorrectGoogleVersions(true);

        QString url = "http://maps.google.com";
        qheader.setUrl(QUrl(url));
        qheader.setRawHeader("User-Agent", UserAgent);
        reply = network.get(qheader);
        tT.start(Timeout);
        q.exec();
        if(!tT.isActive())
        {
            return;
        }
        tT.stop();
        if((reply->error() != QNetworkReply::NoError))
        {
            return;
        }
        QString html = QString(reply->readAll());
        QRegExp reg("\"*http://mt0.google.com/vt/lyrs=m@(\\d*)",Qt::CaseInsensitive);
        if (reg.indexIn(html) != -1)
        {
            QStringList gc = reg.capturedTexts();
            VersionGoogleMap = QString("m@%1").arg(gc[1]);
            VersionGoogleMapChina = VersionGoogleMap;
        }

        reg=QRegExp("\"*http://mt0.google.com/vt/lyrs=h@(\\d*)",Qt::CaseInsensitive);
        if(reg.indexIn(html)!=-1)
        {
            QStringList gc=reg.capturedTexts();
            VersionGoogleLabels = QString("h@%1").arg(gc[1]);
            VersionGoogleLabelsChina = VersionGoogleLabels;
        }
        reg=QRegExp("\"*http://khm\\D?\\d.google.com/kh/v=(\\d*)",Qt::CaseInsensitive);
        if(reg.indexIn(html)!=-1)
        {
            QStringList gc=reg.capturedTexts();
            VersionGoogleSatellite = gc[1];
            VersionGoogleSatelliteKorea = VersionGoogleSatellite;
            VersionGoogleSatelliteChina = "s@" + VersionGoogleSatellite;
            qDebug()<<"TryCorrectGoogleVersions, VersionGoogleSatellite: "<<VersionGoogleSatellite;

        }
        reg=QRegExp("\"*http://mt0.google.com/vt/lyrs=t@(\\d*),r@(\\d*)",Qt::CaseInsensitive);
        if(reg.indexIn(html)!=-1)
        {
            QStringList gc=reg.capturedTexts();
            VersionGoogleTerrain = QString("t@%1,r@%2").arg(gc[1]).arg(gc[2]);
            VersionGoogleTerrainChina = VersionGoogleTerrain;
        }
        reply->deleteLater();
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Urlfactory::TileXYToQuadKey(const int &titleX, const int &titleY, const int &levelOfDetail) const
{
    QString quadKey;
    for (int i = levelOfDetail; i > 0; i--)
    {
        char digit = '0';
        int mask = 1 <<(i - 1);
        if ((titleX & mask) != 0)
        {
            digit++;
        }
        if ((titleY & mask) != 0)
        {
            digit++;
            digit++;
        }
        quadKey.append(digit);
    }
    return quadKey;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double Urlfactory::GetDistance(const cowisinternals::PointLatLng &p1, const cowisinternals::PointLatLng &p2)
{
    double dLat1InRad   = p1.Lat() * (M_PI / 180);
    double dLong1InRad  = p1.Lng() * (M_PI / 180);
    double dLat2InRad   = p2.Lat() * (M_PI / 180);
    double dLong2InRad  = p2.Lng() * (M_PI / 180);
    double dLongitude   = dLong2InRad - dLong1InRad;
    double dLatitude    = dLat2InRad - dLat1InRad;
    double a = pow(sin(dLatitude / 2), 2) + cos(dLat1InRad) * cos(dLat2InRad) * pow(sin(dLongitude / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double dDistance = EarthRadiusKm * c;
    return dDistance;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool Urlfactory::IscorrectGoogleVersions()
{
    return isCorrectedGoogleversions;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Urlfactory::setIscorrectGoogleVersions(bool value)
{
    isCorrectedGoogleversions = value;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Urlfactory::MakeGeocoderUrl(QString keywords)
{
    QString key = keywords.replace(' ', '+');
    return QString("http://maps.google.com/maps/geo?q=%1&output=csv&key=%2").arg(key).arg(GoogleMapsAPIKey);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString Urlfactory::MakeReverseGeocoderUrl(cowisinternals::PointLatLng &pt, const QString &language)
{
    return QString("http://maps.google.com/maps/geo?hl=%1&ll=%2,%3&output=csv&key=%4").arg(language).arg(QString::number(pt.Lat())).arg(QString::number(pt.Lng())).arg(GoogleMapsAPIKey);

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
cowisinternals::PointLatLng Urlfactory::GetLatLngFromGeocoderUrl(const QString &url, bool useCache, GeoCoderStatusCode::Types &status)
{
    status = GeoCoderStatusCode::Unknow;
    cowisinternals::PointLatLng ret(0, 0);
    QString urlEnd = url.mid(url.indexOf("geo?q=") + 6);
    urlEnd.replace(QRegExp(
                       "[^"
                       "A-Z,a-z,0-9,"
                       "\\^,\\&,\\',\\@,"
                       "\\{,\\},\\[,\\],"
                       "\\,,\\$,\\=,\\!,"
                       "\\-,\\#,\\(,\\),"
                       "\\%,\\.,\\+,\\~,\\_"
                       "]"), "_" );
    QString geo = useCache ? Cache::Instance()->getGeocoderFromCache(urlEnd) : "";
    if (geo.isNull() | geo.isEmpty())
    {
        QNetworkReply* reply;
        QNetworkRequest qheader;
        QNetworkAccessManager network;
        network.setProxy(Proxy);
        qheader.setUrl(QUrl(url));
        qheader.setRawHeader("User-Agent", UserAgent);
        reply = network.get(qheader);
        QTime time;
        time.start();
        while((!(reply->isFinished()) || (time.elapsed() > (6 * Timeout))))
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents);
        }
        if ((reply->error() != QNetworkReply::NoError) || (time.elapsed() > Timeout * 6))
        {
            return cowisinternals::PointLatLng(0, 0);
        }
        {
            geo = reply->readAll();

            if(useCache && geo.startsWith("200"))
            {
                Cache::Instance()->CacheGeocoder(urlEnd, geo);
            }
        }
        reply->deleteLater();
    }
    {
        QStringList values = geo.split(',');
        if (values.count() == 4)
        {
            status = (GeoCoderStatusCode::Types)QString(values[0]).toInt();
            if (status == GeoCoderStatusCode::G_GEO_SUCCESS)
            {
                double lat = QString(values[2]).toDouble();
                double lng = QString(values[3]).toDouble();
                ret = cowisinternals::PointLatLng(lat, lng);
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
Placemark Urlfactory::GetPalcemarkFromReverseGeocoderUrl(const QString &url, const bool &useCache)
{
    Placemark ret("");
    QString urlEnd = url.right(url.indexOf("geo?hl="));
    urlEnd.replace(QRegExp(
                       "[^"
                       "A-Z,a-z,0-9,"
                       "\\^,\\&,\\',\\@,"
                       "\\{,\\},\\[,\\],"
                       "\\,,\\$,\\=,\\!,"
                       "\\-,\\#,\\(,\\),"
                       "\\%,\\.,\\+,\\~,\\_"
                       "]"), "_" );
    QString reverse = useCache ? Cache::Instance()->getPlacemarkfromCache(urlEnd) : "";
    if (reverse.isNull() || reverse.isEmpty())
    {
        QNetworkReply* reply;
        QNetworkRequest qheader;
        QNetworkAccessManager network;
        network.setProxy(Proxy);
        qheader.setUrl(QUrl(url));
        qheader.setRawHeader("User-Agent",UserAgent);
        reply = network.get(qheader);
        QTime time;
        time.start();
        while((!(reply->isFinished()) || (time.elapsed() > (6 * Timeout))))
        {
            QCoreApplication::processEvents(QEventLoop::AllEvents);
        }
        if ((reply->error() != QNetworkReply::NoError) || (time.elapsed() > 6 * Timeout))
        {
            return ret;
        }
        {
            QByteArray a = (reply->readAll());
            QTextCodec *codec = QTextCodec::codecForName("UTF-8");
            reverse = codec->toUnicode(a);
            if (useCache && reverse.startsWith("200"))
            {
                Cache::Instance()->CachePlacemark(urlEnd, reverse);
            }
        }
        reply->deleteLater();

    }
    if (reverse.startsWith("200"))
    {
        QString acc = reverse.left(reverse.indexOf('\"'));
        ret = Placemark(reverse.remove(reverse.indexOf('\"')));
        ret.setAccuracy((int)(((QString)acc.split(',')[1]).toInt()));
    }
    return ret;
}

}


