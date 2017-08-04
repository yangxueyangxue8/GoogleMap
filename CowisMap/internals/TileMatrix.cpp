#include "TileMatrix.h"
namespace cowisinternals {
TileMatrix::TileMatrix()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void TileMatrix::Clear()
{
    mutex.lock();
    foreach (Tile* t, matrix.values()) {
        delete t;
         t = 0;
    }
    matrix.clear();
    mutex.unlock();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void TileMatrix::ClearPointsNotin(QList<Point> list)
{
    removals.clear();
    QMutexLocker lock(&mutex);
    foreach (Point p, matrix.keys())
    {
        if (!list.contains(p))
        {
            removals.append(p);
        }
    }
    foreach (Point p, removals)
    {
        Tile *t = matrix.value(p, 0);
        if (t != 0)
        {
            delete t;
            t = 0;
            matrix.remove(p);
        }
    }
    removals.clear();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Tile *TileMatrix::TileAt(const Point &p)
{
    Tile* ret;
    mutex.lock();
    ret = matrix.value(p, 0);
    mutex.unlock();
    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void TileMatrix::SetTileAt(const Point &p, Tile *tile)
{
    mutex.lock();
    Tile* t = matrix.value(p, 0);
    if (t != 0)
    {
        delete t;
    }
    matrix.insert(p, tile);
    mutex.unlock();
}
}


