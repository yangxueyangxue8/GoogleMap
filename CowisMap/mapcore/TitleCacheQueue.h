#ifndef TITLECACHEQUEUE_H
#define TITLECACHEQUEUE_H
#include <QThread>
#include "CacheItemQueue.h"
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
namespace cowiscore {
class TitleCacheQueue:public QThread
{
    Q_OBJECT
public:
    TitleCacheQueue();
    ~TitleCacheQueue();
    void EnqueueCacheTask(CacheItemQueue* task);

protected:
    QQueue<CacheItemQueue*> titlecacheQueue;
    void run();

private:
    QMutex mutex;
    QMutex waitmutex;
    QWaitCondition waitc;
};
}


#endif // TITLECACHEQUEUE_H
