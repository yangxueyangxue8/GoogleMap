#ifndef POINTLATLNG_H
#define POINTLATLNG_H
#include "Sizelatlng.h"
#include <QString>
#include <QHash>
namespace cowisinternals {
class PointLatLng
{
    friend bool operator==(PointLatLng const& lhs, PointLatLng const& rhs);
    friend bool operator!=(PointLatLng const& left, PointLatLng const& right);
    friend PointLatLng operator+(PointLatLng pt, Sizelatlng sz);
    friend PointLatLng operator-(PointLatLng pt, Sizelatlng sz);

public:
    PointLatLng();
    static PointLatLng Empty;
    PointLatLng(const double& lat, const double& lng)
    {
        this->lat = lat;
        this->lng = lng;
        empty = false;

    }

    bool IsEmpty() const
    {
        return empty;
    }



    double Lat()const {return lat;}
    void setLat(double const& value)
    {
        this->lat = value;
    }

    double Lng()const {return lng;}
    void setLng(double const& value)
    {
        this->lng = value;
    }

    static PointLatLng Add(PointLatLng const& pt, Sizelatlng const& sz)
    {
        return PointLatLng(pt.Lat() - sz.HeightLat(), pt.Lng() + sz.WidthLng());
    }

    static PointLatLng Subtract(PointLatLng const& pt, Sizelatlng const& sz)
    {
        return PointLatLng(pt.Lat() + sz.HeightLat(), pt.Lng() - sz.WidthLng());
    }

    void Offset(PointLatLng const& pos)
    {
        this->Offset(pos.lat, pos.lng);
    }

    void Offset(double const& lat, double const& lng)
    {
        this->lng += lng;
        this->lat -= lat;
    }

    QString ToString() const
    {
        return QString("{Lat=%1, Lng=%2").arg(lat).arg(lng);
    }
 private:
    double lat;
    double lng;
    bool   empty;
};
}


#endif // POINTLATLNG_H
