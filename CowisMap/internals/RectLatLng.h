#ifndef RECTLATLNG_H
#define RECTLATLNG_H

#include <QString>
#include "PointLatLng.h"
#include "Sizelatlng.h"
#include <cmath>

namespace cowisinternals {
struct RectLatLng
{
public:
    static RectLatLng Empty;
    friend uint qHash(RectLatLng const& rect);
    friend bool operator== (RectLatLng const& left, RectLatLng const& right);
    friend bool operator !=(RectLatLng const& left, RectLatLng const& right);
    RectLatLng(double const& lat, double const& lng, double const& widthLng, double const& heightLat)
    {
        this->lat       = lat;
        this->lng       = lng;
        this->widthLng  = widthLng;
        this->heightLat = heightLat;
        isempty         = false;
    }

    RectLatLng(PointLatLng const& pos, Sizelatlng const& size)
    {
        this->lat       = pos.Lat();
        this->lng       = pos.Lng();
        this->widthLng  = size.WidthLng();
        this->heightLat = size.HeightLat();
        this->isempty   = false;
    }

    RectLatLng()
    {
        this->lat       = 0;
        this->lng       = 0;
        this->widthLng  = 0;
        this->heightLat = 0;
        this->isempty   = true;
    }

    static RectLatLng FromLTRB(double const& lng, double const& lat, double const& rightLng, double const& bottomLat)
    {
        return RectLatLng(lat, lng, rightLng - lng, bottomLat - lat);
    }

    PointLatLng LocationToLeft()const
    {
        return PointLatLng(this->lat, this->lng);
    }

    void setLocationTopLeft(PointLatLng const& pos)
    {
        this->lng = pos.Lng();
        this->lat = pos.Lat();
        isempty = false;
    }

    PointLatLng LocationRightBottom()
    {
        PointLatLng ret = PointLatLng(this->lat, this->lng);
        ret.Offset(this->heightLat, this->widthLng);
        return ret;
    }

    Sizelatlng Size()
    {
        return Sizelatlng(this->heightLat, this->widthLng);
    }
    void setSize(Sizelatlng const& value)
    {
        this->widthLng  = value.WidthLng();
        this->heightLat = value.HeightLat();
        this->isempty   = false;
    }

    double Lng()const
    {
        return this->lng;
    }
    void setLng(double lng)
    {
        this->lng = lng;
        this->isempty = false;
    }

    double Lat()const
    {
        return this->lat;
    }
    void setLat(double lat)
    {
        this->lat = lat;
        this->isempty = false;
    }

    double WidthLng() const
    {
        return this->widthLng;
    }
    void setWidthLng(double value)
    {
        this->widthLng = value;
        isempty        = false;
    }

    double HeightLat() const
    {
        return this->heightLat;
    }
    void setHeightLat(double value)
    {
        this->heightLat = value;
        this->isempty   = false;
    }

    double Left()const
    {
        return this->lng;
    }
    double Top()const
    {
        return this->lat;
    }

    double Right()const
    {
        return (this->lng + this->widthLng);
    }
    double Bottom()const
    {
        return (this->lat - this->heightLat);
    }

    bool IsEmpty()const
    {
        return isempty;
    }

    bool Contains(double const& lat, const double& lng)
    {
        return ((((this->lng <= lng) && (lng < (this->lng + this->widthLng))) &&(this->lat >= lat) && (lat > (this->lat - this->heightLat))));
    }
    bool Contains(PointLatLng const& pos)
    {
        return Contains(pos.Lat(), pos.Lng());
    }

    void Inflate(double const& lat, const double& lng)
    {
        this->lng -= lng;
        this->lat += lat;
        this->widthLng  += (double)2 * lng;
        this->heightLat += (double) 2 * lat;
    }

    void Inflate(Sizelatlng const& size)
    {
        this->Inflate(size.HeightLat(), size.WidthLng());
    }

    static RectLatLng Inflate(RectLatLng const& rsct, double const& lat, double const& lng)
    {
        RectLatLng ef = rsct;
        ef.Inflate(lat, lng);
        return ef;
    }

    void Interect(RectLatLng const& rect)
    {
        RectLatLng ef = Intersect(rect, *this);
        this->lng = ef.Lng();
        this->lat = ef.Lat();
        this->widthLng  = ef.WidthLng();
        this->heightLat = ef.HeightLat();
    }

    static RectLatLng Intersect(RectLatLng const& a, RectLatLng const& b)
    {
        double lng  = qMax(a.Lng(), b.Lng());
        double num2 = qMin((double)(a.Lng() + a.WidthLng()), (double)(b.Lng() + b.WidthLng()));
        double lat  = qMax(a.Lat(), b.Lat());
        double num4 = qMin((double) (a.Lat() + a.HeightLat()), (double) (b.Lat() + b.HeightLat()));
        if((num2 >= lng) && (num4 >= lat))
         {
             return RectLatLng(lng, lat, num2 - lng, num4 - lat);
         }
         return Empty;
    }

    bool IntersectsWith(RectLatLng const& rect)
    {
        return ((((rect.Lng() < (this->Lng() + this->WidthLng())) && (this->Lng() < (rect.Lng() + rect.WidthLng()))) && (rect.Lat() < (this->Lat() + this->HeightLat()))) && (this->Lat() < (rect.Lat() + rect.HeightLat())));
    }

    static RectLatLng Union(RectLatLng const& a, RectLatLng const& b)
    {
        double lng = qMin(a.Lng(), b.Lng());
        double num2 = qMax((double) (a.Lng() + a.WidthLng()), (double) (b.Lng() + b.WidthLng()));
        double lat = qMin(a.Lat(), b.Lat());
        double num4 = qMax((double) (a.Lat() + a.HeightLat()), (double) (b.Lat() + b.HeightLat()));
        return RectLatLng(lng, lat, num2 - lng, num4 - lat);
    }
    void Offset(PointLatLng const& pos)
    {
        this->Offset(pos.Lat(), pos.Lng());
    }

    void Offset(double const& lat, double const& lng)
    {
        this->lng += lng;
        this->lat -= lat;
    }
    QString ToString() const
    {
        return ("{Lat=" + QString::number(this->Lat()) + ",Lng=" + QString::number(this->Lng()) + ",WidthLng=" + QString::number(this->WidthLng()) + ",HeightLat=" + QString::number(this->HeightLat()) + "}");
    }


private:
    double lng;
    double lat;
    double widthLng;
    double heightLat;
    bool isempty;
};
}


#endif // RECTLATLNG_H
