#include "Sizelatlng.h"
#include "PointLatLng.h"
namespace cowisinternals {

Sizelatlng Sizelatlng::Empty = Sizelatlng();
Sizelatlng::Sizelatlng():widthLng(0),heightLat(0)
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Sizelatlng::Sizelatlng(const PointLatLng &pt)
{
    this->widthLng  = pt.Lng();
    this->heightLat = pt.Lat();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool operator !=(const Sizelatlng sz1, const Sizelatlng &sz2)
{
    return !(sz1 == sz2);
}

bool operator==(const Sizelatlng sz1, const Sizelatlng &sz2)
{
    return ((sz1.widthLng == sz2.widthLng) && (sz1.heightLat == sz2.heightLat));
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Sizelatlng operator-(const Sizelatlng &sz1, const Sizelatlng &sz2)
{
    return Sizelatlng::Subtract(sz1, sz2);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Sizelatlng operator +(const Sizelatlng &sz1, const Sizelatlng &sz2)
{
    return Sizelatlng::Add(sz1, sz2);
}
}


