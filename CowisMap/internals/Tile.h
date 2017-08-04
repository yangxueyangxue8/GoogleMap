#ifndef TILE_H
#define TILE_H
#include "../mapcore/Point.h"
#include <QList>
#include <QMutex>
using namespace cowiscore;
namespace cowisinternals {
class Tile
{
public:
    Tile(int zoom, cowiscore::Point pos);
    Tile();
    void Clear();
    int GetZoom(){return zoom;}
    cowiscore::Point GetPos(){return pos;}
    void SetZoom(const int& value)
    {
        zoom = value;
    }
    void SetPos(const cowiscore::Point& value)
    {
        pos = value;
    }

    Tile& operator= (const Tile& cSource);

    Tile(const Tile& cSource)
    {
        this->zoom = cSource.zoom;
        this->pos  = cSource.pos;
    }

    bool HasValue()
    {
        return !(zoom == 0);
    }

    QList<QByteArray> Overlays;
protected:
    QMutex mutex;

private:
    int zoom;
    cowiscore::Point pos;
};
}



#endif // TILE_H
