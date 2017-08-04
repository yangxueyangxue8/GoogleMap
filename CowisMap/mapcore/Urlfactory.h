#ifndef URLFACTORY_H
#define URLFACTORY_H

#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTimer>
#include <QCoreApplication>
#include "ProviderStrings.h"
#include "PureImageCache.h"
#include <QTime>
#include "GeoCoderStatusCode.h"
#include "../internals/PointLatLng.h"
#include "Placemark.h"

namespace cowiscore {
class Urlfactory:public QObject, public ProviderStrings
{
    Q_OBJECT

public:
    Urlfactory();
    ~Urlfactory();
    QByteArray UserAgent;
    QNetworkProxy Proxy;
    QString makeImageUrl(const Maptype::Types& type, const cowiscore::Point& pos, const int& zoom, const QString& language);
    cowisinternals::PointLatLng getLatLngFromGeodecoder(const QString& keywords, GeoCoderStatusCode::Types& status);
    Placemark getPalcemarkFromGeocoder(cowisinternals::PointLatLng location);
    int Timeout;

private:
    int Random(int low, int high);
    void GetSecGoogleWords(const cowiscore::Point& pos, QString& sec1, QString& sec2);
    int GetServerNum(cowiscore::Point const& pos, const int& max) const;
    void TryCorrectGoogleVersions();
    bool isCorrectedGoogleversions;
    QString TileXYToQuadKey(const int& titleX, const int& titleY, const int& levelOfDetail) const;
    bool CorrectGoogleVersion;
    bool UseGeocoderCache;
    bool UsePlacemarkCache;
    static const double EarthRadiusKm;
    double GetDistance(const cowisinternals::PointLatLng& p1, const cowisinternals::PointLatLng& p2);
    QMutex mutex;

protected:
    static short timelapse;
    QString LanguageStr;
    bool IscorrectGoogleVersions();
    void setIscorrectGoogleVersions(bool value);
    QString MakeGeocoderUrl(QString keywords);

    QString MakeReverseGeocoderUrl(cowisinternals::PointLatLng& pt, const QString& language);
    cowisinternals::PointLatLng GetLatLngFromGeocoderUrl(const QString& url, bool useCache, GeoCoderStatusCode::Types& status);
    Placemark GetPalcemarkFromReverseGeocoderUrl(const QString& url, const bool& useCache);
};
}


#endif // URLFACTORY_H
