#include "Tile.h"
namespace cowisinternals {
Tile::Tile(int zoom, Point pos)
{
    this->zoom = zoom;
    this->pos  = pos;
}

Tile::Tile():zoom(0),pos(0, 0)
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Tile::Clear()
{
    mutex.lock();
    foreach (QByteArray img, Overlays)
    {
        img.~QByteArray();
    }
    Overlays.clear();
    mutex.unlock();
}

Tile &Tile::operator=(const Tile &cSource)
{
    this->zoom = cSource.zoom;
    this->pos  = cSource.pos;
    return *this;
}
}


