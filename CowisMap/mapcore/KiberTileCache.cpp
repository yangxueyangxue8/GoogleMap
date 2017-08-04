#include "KiberTileCache.h"
namespace cowiscore {
KiberTileCache::KiberTileCache()
{
    memoryCacheSize      = 0;
    _memoryCacheCapacity = 22;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void KiberTileCache::setMemoryCacheCapacity(const int &value)
{
    kiberCachelock.lockForWrite();
    _memoryCacheCapacity = value;
    kiberCachelock.unlock();
}
/********************************************************************************
* @version   1.0 ??????????
* @parameter
* @Function:
* @return
*******************************************************************************/
int KiberTileCache::memoryCacheCapacity()
{
    kiberCachelock.lockForRead();
    return _memoryCacheCapacity;
    kiberCachelock.unlock();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void KiberTileCache::removeMemoryOverload()
{
    while(MemoryCacheSize() > memoryCacheCapacity())
    {
        if ((cachequeue.count() > 0) && (list.count() > 0))
        {
            RawTitle first = list.dequeue();
            memoryCacheSize -= cachequeue.value(first).size();
            cachequeue.remove(first);
        }
    }
}
}


