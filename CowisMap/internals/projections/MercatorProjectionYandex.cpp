#include "MercatorProjectionYandex.h"

namespace cowisprojections {
MercatorProjectionYandex::MercatorProjectionYandex():MinLatitude(-85.05112878), MaxLatitude(85.05112878),MinLongitude(-177),
    MaxLongitude(177), RAD_DEG(180 / M_PI),DEG_RAD(M_PI / 180),MathPiDiv4(M_PI / 4),tileSize(256, 256)
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjectionYandex::TileSize() const
{
    return tileSize;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double MercatorProjectionYandex::Axis() const
{
    return 6356752.3142;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double MercatorProjectionYandex::Flattening() const
{
    return (1.0 / 298.257223563);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point MercatorProjectionYandex::FromLatLngToPixel(double lat, double lng, const int &zoom)
{
    lat = Clip(lat, MinLatitude, MaxLatitude);
    lng = Clip(lng, MinLongitude, MaxLongitude);
    double rLon = lng * DEG_RAD;
    double rLat = lat * DEG_RAD;

    double a = 6378137;
    double k = 0.0818191908426;

    double z = tan(MathPiDiv4 + rLat / 2) / pow((tan(MathPiDiv4 + asin(k * sin(rLat)) / 2)), k);
    double z1 = pow(2.0, 23 - zoom);
    double DX =  ((20037508.342789 + a * rLon) * 53.5865938 /  z1);
    double DY = ((20037508.342789 - a * log(z)) * 53.5865938 / z1);

    Point ret;// = Point.Empty;
    ret.setX((int) DX);
    ret.setY((int) DY);

    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
cowisinternals::PointLatLng MercatorProjectionYandex::FromPixelToLatLng(const int &x, const int &y, const int &zoom)
{
    Size s = GetTileMatrixSizePixel(zoom);
    //2017-6-9
    Q_UNUSED(s);


    double a = 6378137;
    double c1 = 0.00335655146887969;
    double c2 = 0.00000657187271079536;
    double c3 = 0.00000001764564338702;
    double c4 = 0.00000000005328478445;
    double z1 = (23 - zoom);
    double mercX = (x * pow(2, z1)) / 53.5865938 - 20037508.342789;
    double mercY = 20037508.342789 - (y *pow(2, z1)) / 53.5865938;

    double g = M_PI /2 - 2 *atan(1 / exp(mercY /a));
    double z = g + c1 * sin(2 * g) + c2 * sin(4 * g) + c3 * sin(6 * g) + c4 * sin(8 * g);

    cowisinternals::PointLatLng ret;// = internals::PointLatLng.Empty;
    ret.setLat(z * RAD_DEG);
    ret.setLng (mercX / a * RAD_DEG);

    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjectionYandex::GetTileMatrixMinXY(const int &zoom)
{
    Q_UNUSED(zoom);
    return Size(0, 0);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjectionYandex::GetTileMatrixMaxXY(const int &zoom)
{
    int xy = (1 << zoom);
    return Size(xy - 1, xy - 1);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double MercatorProjectionYandex::Clip(const double &n, const double &minValue, const double &maxValue) const
{
    return qMin(qMax(n, minValue), maxValue);
}
}


