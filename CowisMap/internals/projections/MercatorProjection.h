#ifndef MERCATORPROJECTION_H
#define MERCATORPROJECTION_H
#include "../PureProjection.h"
namespace cowisprojections {
class MercatorProjection:public cowisinternals::PureProjection
{
public:
    MercatorProjection();
    virtual QString Type(){return "MercatorProjection";}
    virtual Size TileSize()const;
    virtual double Axis()const;
    virtual double Flattening()const;
    virtual cowiscore::Point FromLatLngToPixel(double lat, double lng, const int &zoom);
    virtual cowisinternals::PointLatLng FromPixelToLatLng(const int &x, const int &y, const int &zoom);
    virtual Size GetTileMatrixMinXY(const int &zoom);
    virtual Size GetTileMatrixMaxXY(const int &zoom);

private:
    const double MinLatitude;
    const double MaxLatitude;
    const double MinLongitude;
    const double MaxLongitude;
    double Clip(double const& n, const double& minValue, double const& maxValue)const;
    Size tileSize;
};
}


#endif // MERCATORPROJECTION_H
