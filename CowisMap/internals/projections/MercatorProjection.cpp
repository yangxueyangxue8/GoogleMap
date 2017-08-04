#include "MercatorProjection.h"
namespace cowisprojections {
MercatorProjection::MercatorProjection():MinLatitude(-85.05112878), MaxLatitude(85.05112878),MinLongitude(-177),
    MaxLongitude(177), tileSize(256, 256)
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjection::TileSize() const
{
    return tileSize;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double MercatorProjection::Axis() const
{
    return 6378137;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
double MercatorProjection::Flattening() const
{
    return (1.0 / 298.257223563);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point MercatorProjection::FromLatLngToPixel(double lat, double lng, const int &zoom)
{
    Point ret;
    lat = Clip(lat, MinLatitude, MaxLatitude);
    lng = Clip(lng, MinLongitude, MaxLongitude);

    double x = (lng + 180) / 360;
    double sinLatitude = sin(lat * M_PI / 180);
    double y = 0.5 - log((1 + sinLatitude) / (1 - sinLatitude)) / ( 4 * M_PI);

    Size s = GetTileMatrixSizePixel(zoom);
    int mapSizeX = s.Width();
    int mapSizeY = s.Height();

    ret.setX((int) Clip(x * mapSizeX + 0.5, 0, mapSizeX - 1));
    ret.setY((int) Clip(y * mapSizeY + 0.5, 0, mapSizeY - 1));
    return ret;

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
cowisinternals::PointLatLng MercatorProjection::FromPixelToLatLng(const int &x, const int &y, const int &zoom)
{
    cowisinternals::PointLatLng ret;
    Size s = GetTileMatrixSizePixel(zoom);
    double mapSizeX = s.Width();
    double mapSizeY = s.Height();

    double xx = (Clip(x, 0, mapSizeX - 1) / mapSizeX) - 0.5;
    double yy = 0.5 - (Clip(y, 0, mapSizeY - 1) / mapSizeY);

    ret.setLat(90 - 360 * atan(exp(-yy * 2 * M_PI)) / M_PI);
    ret.setLng(360 * xx);

    return ret;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjection::GetTileMatrixMinXY(const int &zoom)
{
    Q_UNUSED(zoom)
    return Size(0, 0);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Size MercatorProjection::GetTileMatrixMaxXY(const int &zoom)
{
    int xy = (1 << zoom);
    return  Size(xy - 1, xy - 1);
}

double MercatorProjection::Clip(const double &n, const double &minValue, const double &maxValue) const
{
    return qMin(qMax(n, minValue), maxValue);
}
}


