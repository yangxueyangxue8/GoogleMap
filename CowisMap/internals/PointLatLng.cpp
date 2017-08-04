#include "PointLatLng.h"
namespace cowisinternals {

PointLatLng PointLatLng::Empty = PointLatLng();
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator==(const PointLatLng &lhs, const PointLatLng &rhs)
{
    return ((lhs.Lat() == rhs.Lat()) && (lhs.Lng() == rhs.Lng()));
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator!=(const PointLatLng &left, const PointLatLng& right)
{
    return !(left == right);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
PointLatLng operator+(PointLatLng pt, Sizelatlng sz)
{
    return PointLatLng::Add(pt, sz);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
PointLatLng operator-(PointLatLng pt, Sizelatlng sz)
{
    return PointLatLng::Subtract(pt, sz);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
PointLatLng::PointLatLng():lat(0.0),lng(0.0),empty(true)
{

}
}


