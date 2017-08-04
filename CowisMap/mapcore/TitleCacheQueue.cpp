#include "TitleCacheQueue.h"
#include "Cache.h"
namespace cowiscore {
TitleCacheQueue::TitleCacheQueue()
{

}

TitleCacheQueue::~TitleCacheQueue()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void TitleCacheQueue::EnqueueCacheTask(CacheItemQueue *task)
{
    if (!titlecacheQueue.contains(task))
    {
        mutex.lock();
        titlecacheQueue.enqueue(task);
        mutex.unlock();
        if (this->isRunning())
        {
            waitc.wakeAll();
        }
        else
        {
            this->start(QThread::NormalPriority);
        }
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void TitleCacheQueue::run()
{
    while (true)
    {
        CacheItemQueue* task;
        if (titlecacheQueue.count() > 0)
        {
            mutex.lock();
            task = titlecacheQueue.dequeue();
            mutex.lock();
            Cache::Instance()->imageCache.putImageToCache(task->getImage(), task->getMapType(), task->getPosition(), task->getZoom());
            usleep(44);
            delete task;
        }
        else
        {
            waitmutex.lock();
            int tout = 4000;
            if (!waitc.wait(&waitmutex, tout))
            {
                waitmutex.unlock();
                mutex.lock();
                if (titlecacheQueue.count() == 0)
                {
                    mutex.unlock();
                    break;
                }
                mutex.unlock();
            }
            waitmutex.unlock();
        }
    }
}
}


