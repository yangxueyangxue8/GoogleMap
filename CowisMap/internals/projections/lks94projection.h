#ifndef LKS94PROJECTION_H
#define LKS94PROJECTION_H
#include "../PureProjection.h"
#include <QVector>
using namespace cowisinternals;
namespace cowisprojections {
class LKS94Projection: public cowisinternals::PureProjection
{
public:
    LKS94Projection();
    double GetTileMatrixResolution(int const& zoom);
    virtual QString Type(){return "LKS94Projection";}
    virtual Size TileSize()const;
    virtual double Axis() const;
    virtual double Flattening()const;
    virtual cowiscore::Point FromLatLngToPixel(double lat, double lng, const int &zoom);
    virtual cowisinternals::PointLatLng FromPixelToLatLng(const int &x, const int &y, const int &zoom);
    virtual double GetGroundResolution(const int &zoom, const double &latitude);
    virtual Size GetTileMatrixMinXY(const int &zoom);
    virtual Size GetTileMatrixMaxXY(const int &zoom);
private:
    const double MinLatitude;
    const double MaxLatitude;
    const double MinLongitude;
    const double MaxLongitude;
    const double orignX;
    const double orignY;
    Size tileSize;
    QVector<double> DTM10(const QVector<double>& lonlat);
    QVector<double> MTD10(QVector<double>& pnt);
    QVector<double> DTM00(QVector<double>& lonlat);
    QVector<double> DTM01(QVector<double>& lonlat);
    QVector<double> MTD01(QVector<double>& pnt);
    QVector<double> MTD11(QVector<double>& p);
    double Clip(double const& n, double const& minValue, double const& maxValue);

};
}


#endif // LKS94PROJECTION_H
