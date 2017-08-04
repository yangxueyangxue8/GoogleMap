#include "RawTitle.h"
namespace cowiscore {

/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
uint qHash(const RawTitle &tile)
{
    quint64 tmp=(((quint64)(tile.zoom))<<54)+(((quint64)(tile.type))<<36)+(((quint64)(tile.pos.X()))<<18)+(((quint64)(tile.pos.Y())));
    return ::qHash(tmp);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator ==(const RawTitle &lhs, const RawTitle &rhs)
{
    return ((lhs.zoom == rhs.zoom) && (lhs.type == rhs.type) && (lhs.pos == rhs.pos));
}

RawTitle::RawTitle(const Maptype::Types &type, const Point &pos, const int &zoom)
{
   this->type = type;
   this->pos  = pos;
   this->zoom = zoom;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QString RawTitle::toString()
{
   return QString("%1 at zoom %2, pos:%3,%4").arg(type).arg(zoom).arg(pos.X()).arg(pos.Y());
}

}

