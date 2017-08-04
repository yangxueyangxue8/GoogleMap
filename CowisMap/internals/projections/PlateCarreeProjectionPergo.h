#ifndef PLATECARREEPROJECTIONPERGO_H
#define PLATECARREEPROJECTIONPERGO_H
#include "../PureProjection.h"
namespace cowisprojections {
class PlateCarreeProjectionPergo:public cowisinternals::PureProjection
{
public:
    PlateCarreeProjectionPergo();
    QString Type(){return "PlateCarreeProjectionPergo";}
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

    double Clip(double const&n, double const& minValue, double const& maxValue);
    Size tileSize;
};
}


#endif // PLATECARREEPROJECTIONPERGO_H
