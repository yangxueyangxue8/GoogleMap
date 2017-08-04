#include "Point.h"
#include "Size.h"
namespace cowiscore {
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
uint qHash(const Point &point)
{
    return point.x^point.y;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator ==(const Point &lhs, const Point &rhs)
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator !=(const Point &lhs, const Point &rhs)
{
    return !(lhs==rhs);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point::Point():x(0),y(0),empty(true)
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    empty = false;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point::Point(Size sz)
{
    this->x = sz.Width();
    this->y = sz.Height();
    empty = false;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point::Point(int dw)
{
    this->x = (short)Point::loWord(dw);
    this->y = (short)Point::hiWord(dw);
    empty = true;
}
Point Point::Empty = Point();
}
