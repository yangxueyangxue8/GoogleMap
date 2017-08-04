#ifndef MEMORYCACHE_H
#define MEMORYCACHE_H
#include "KiberTileCache.h"
#include <QByteArray>
#include "RawTitle.h"
#include <QReadWriteLock>
namespace cowiscore {
class MemoryCache
{
public:
    MemoryCache();
    KiberTileCache TilesInMemory;
    QByteArray getTileFromMemoryCache(const RawTitle& title);
    void AddTileToMemoryCache(const RawTitle& title, const QByteArray &pic);
    QReadWriteLock kiberCacheLock;
};

}

#endif // MEMORYCACHE_H
