#include "MemoryCache.h"
namespace cowiscore {
MemoryCache::MemoryCache()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QByteArray MemoryCache::getTileFromMemoryCache(const RawTitle &title)
{
    kiberCacheLock.lockForRead();
    QByteArray pic;
    pic = TilesInMemory.cachequeue.value(title);
    kiberCacheLock.unlock();
    return pic;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void MemoryCache::AddTileToMemoryCache(const RawTitle &title, const QByteArray &pic)
{
    kiberCacheLock.lockForWrite();
    TilesInMemory.memoryCacheSize += pic.size();
    TilesInMemory.cachequeue.insert(title, pic);
    TilesInMemory.list.enqueue(title);
    kiberCacheLock.unlock();
}
}


