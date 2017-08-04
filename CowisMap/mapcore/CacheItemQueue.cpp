#include "CacheItemQueue.h"
namespace cowiscore {
CacheItemQueue::CacheItemQueue()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
CacheItemQueue::CacheItemQueue(const Maptype::Types &type, const Point &pos, const QByteArray &img, const int zoom)
{
    this->type = type;
    this->pos  = pos;
    this->img  = img;
    this->zoom = zoom;
}

CacheItemQueue &CacheItemQueue::operator=(const CacheItemQueue &cSource)
{
    img  = cSource.img;
    type = cSource.type;
    pos  = cSource.pos;
    zoom = cSource.zoom;
    return *this;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool CacheItemQueue::operator ==(const CacheItemQueue &cSource)
{
    bool ret = false;
    if ((this->img == cSource.img) && (this->pos == cSource.pos) && (this->zoom == cSource.zoom) && (this->type == cSource.type))
    {
        ret = true;
    }
    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void CacheItemQueue::setMapType(const Maptype::Types &type)
{
    this->type = type;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void CacheItemQueue::setPosition(const Point &pos)
{
    this->pos = pos;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void CacheItemQueue::setImage(const QByteArray &value)
{
    this->img = value;
}

}


