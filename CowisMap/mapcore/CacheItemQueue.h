/******************************************************************************
* @brief 摘要
* @author Xue yang
* @date   2017/07/17
******************************************************************************/
#ifndef CACHEITEMQUEUE_H
#define CACHEITEMQUEUE_H
#include "Maptype.h"
#include "Point.h"
#include <QByteArray>
namespace cowiscore {

class CacheItemQueue
{
public:
    CacheItemQueue();
    CacheItemQueue(const Maptype::Types &type, const cowiscore::Point& pos, const QByteArray& img, const int zoom);

    CacheItemQueue(const CacheItemQueue& cSource)
    {
        this->type = cSource.type;
        this->img  = cSource.img;
        this->pos  = cSource.pos;
        this->zoom = cSource.zoom;
    }
    CacheItemQueue& operator= (const CacheItemQueue& cSource);

    bool operator ==(const CacheItemQueue& cSource);

    void setMapType(const Maptype::Types& type);
     Maptype::Types getMapType()const {return type;}

    void setPosition(const cowiscore::Point& pos);
    cowiscore::Point getPosition()const {return pos;}

    void setImage(const QByteArray& value);
    QByteArray     getImage()const {return img;}

    void setZoom(const int zoom){this->zoom = zoom;}
    int getZoom() const {return zoom;}

private:
    Maptype::Types type;
    cowiscore::Point pos;
    QByteArray img;
    int zoom;
};

}


#endif // CACHEITEMQUEUE_H
