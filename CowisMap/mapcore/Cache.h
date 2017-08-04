#ifndef CACHE_H
#define CACHE_H
#include <QString>
#include "PureImageCache.h"
namespace cowiscore {
class Cache
{
public:
    static Cache* Instance();

    PureImageCache imageCache;

    QString CacheLocation();
    void setCacheLocation(const QString& value);

    void CacheGeocoder(const QString& urlEnd, const QString& content);
    QString getGeocoderFromCache(const QString& urlEnd);

    void CachePlacemark(const QString& urlEnd, const QString& content);
    QString getPlacemarkfromCache(const QString& urlEnd);

    void CacheRoute(const QString& urlEnd, const QString& content);
    QString  getRouteFromCache(const QString& urlEnd);
private:
    Cache();
    Cache(Cache const&){}
    Cache& operator=(Cache const&){ return *this;}
private:
    static Cache* m_pInstance;
    QString cache;
    QString routeCache;
    QString geoCache;
    QString placemarkCache;

};
}


#endif // CACHE_H
