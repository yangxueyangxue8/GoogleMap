#ifndef KIBERTILECACHE_H
#define KIBERTILECACHE_H
#include <QReadWriteLock>
#include <QQueue>
#include "RawTitle.h"
namespace cowiscore {
class KiberTileCache
{
public:
    KiberTileCache();
    void setMemoryCacheCapacity(const int &value);
    int memoryCacheCapacity();
    double MemoryCacheSize(){return memoryCacheSize / 1048576.0;}
    void removeMemoryOverload();
    QReadWriteLock kiberCachelock;
    QHash <RawTitle, QByteArray> cachequeue;
    QQueue<RawTitle> list;
    long memoryCacheSize;


private:
    int _memoryCacheCapacity;
};
}


#endif // KIBERTILECACHE_H
