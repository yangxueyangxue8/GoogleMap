#ifndef TILEMATRIX_H
#define TILEMATRIX_H
#include <QList>
#include "../mapcore/Point.h"
#include "Tile.h"
#include <QHash>
namespace cowisinternals {
class TileMatrix
{
public:
    TileMatrix();
    void Clear();
    void ClearPointsNotin(QList<cowiscore::Point> list);
    Tile* TileAt(const cowiscore::Point& p);
    void SetTileAt(const cowiscore::Point& p, Tile* tile);
protected:
    QHash<cowiscore::Point, Tile*> matrix;
    QList<cowiscore::Point> removals;
    QMutex mutex;
};
}


#endif // TILEMATRIX_H
