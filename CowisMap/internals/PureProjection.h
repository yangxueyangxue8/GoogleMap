#ifndef PUREPROJECTION_H
#define PUREPROJECTION_H
#include "../mapcore/Size.h"
#include "../mapcore/Point.h"
#include "PointLatLng.h"
#include "../mapcore/Size.h"
#include "RectLatLng.h"
#include <cmath>
using namespace cowiscore;
namespace cowisinternals {
class PureProjection
{
public:
    virtual ~PureProjection(){}
    virtual Size TileSize()const = 0;

    virtual double Axis()const = 0;

    virtual double Flattening()const = 0;

    virtual cowiscore::Point FromLatLngToPixel(double lat, double lng, int const& zoom) = 0;

    virtual PointLatLng FromPixelToLatLng(const int&x, const int& y, const int& zoom) = 0;

    virtual QString Type(){return "PureProjection";}

    cowiscore::Point FromLatLngToPixel(const PointLatLng& p, const int& zoom);
    PointLatLng      FromPixelToLatLng(const Point& p, const int& zoom);

    virtual cowiscore::Point FromPixelToTileXY(cowiscore::Point const& p);
    virtual cowiscore::Point FromTileXYToPixel(cowiscore::Point const& p);

    virtual Size GetTileMatrixMinXY(const int &zoom) = 0;
    virtual Size GetTileMatrixMaxXY(const int &zoom) = 0;
    virtual Size GetTileMatrixSizeXY(const int &zoom);

    int GetTileMatrixItemCount(const int& zoom);

    virtual Size GetTileMatrixSizePixel(const int& zoom);
    QList<cowiscore::Point> GetAreaTileList(const RectLatLng& rect, const int& zoom, const int& padding);
    virtual double GetGroundResolution(const int& zoom, const double& latitude);

    double DegreesToRadians(const double &deg)const
    {
        return (D2R * deg);
    }

    double RadiansToDegrees(const double& rad)const
    {
        return (R2D * rad);
    }

    void FromGeodeticToCartesian(double Lat, double Lng, double Height, double& X, double& Y, double& Z);
    void FromCartesianTGeodetic(const double& X, const double &Y, const double& Z, double& Lat, double& Lng);
    static double DistanceBetweenLatLng(PointLatLng const& p1, PointLatLng const& p2);

protected:
    static const double PI;
    static const double HALF_PI;
    static const double TWO_PI;
    static const double EPSLoN;
    static const double MAX_VAL;
    static const double maxLong;
    static const double DBLLONG;
    static const double R2D;
    static const double D2R;

    static double Sign(const double& x);
    static double AdjustLongitude(double x);

    static void SinCos(const double& val, double& sin, double& cos);
    static double e0fn(const double& x);
    static double e1fn(const double& x);
    static double e2fn(const double& x);
    static double e3fn(const double& x);
    static double mlfn(const double& e0, const double& e1, const double& e2, const double& e3, const double &phi);
    static qlonglong GetUTMzone(const double& lon);


};
}


#endif // PUREPROJECTION_H
