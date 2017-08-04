#ifndef PLATECARREEPROJECTION_H
#define PLATECARREEPROJECTION_H
#include "../PureProjection.h"

namespace cowisprojections {
class PlateCarreeProjection: public cowisinternals::PureProjection
{
public:
    PlateCarreeProjection();
    virtual QString Type(){return "PlateCarreeProjection";}

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

    double Clip(double const& n, double const& minValue, double maxValue);
    Size tileSize;
};
}


#endif // PLATECARREEPROJECTION_H
