#ifndef SIZELATLNG_H
#define SIZELATLNG_H
#include <QString>

namespace cowisinternals {
class PointLatLng;

class Sizelatlng
{
public:
    Sizelatlng();
    static Sizelatlng Empty;

    Sizelatlng(Sizelatlng const& size)
    {
        this->widthLng  = size.widthLng;
        this->heightLat = size.heightLat;
    }

    Sizelatlng(PointLatLng const& pt);

    Sizelatlng(double const& heightLat, double const& widthLng)
    {
        this->widthLng  = widthLng;
        this->heightLat = heightLat;
    }

    friend Sizelatlng operator +(Sizelatlng const& sz1, Sizelatlng const& sz2);
    friend Sizelatlng operator-(Sizelatlng const& sz1, Sizelatlng const& sz2);
    friend bool operator==(Sizelatlng const sz1, Sizelatlng const& sz2);
    friend bool operator !=(Sizelatlng const sz1, Sizelatlng const& sz2);

    bool IsEmpty() const
    {
        return ((this->widthLng == 0) && (this->heightLat == 0));
    }

    double HeightLat()const
    {
        return heightLat;
    }
    void SetHeightLat(double const& value)
    {
        heightLat = value;
    }

    double WidthLng()const
    {
        return widthLng;
    }
    void SetWidthLng(double const& value)
    {
        widthLng = value;
    }

    static Sizelatlng Add(Sizelatlng const& sz1, Sizelatlng const& sz2)
    {
        return Sizelatlng(sz1.heightLat + sz2.heightLat, sz1.widthLng + sz2.widthLng);
    }

    static Sizelatlng Subtract(Sizelatlng const& sz1, Sizelatlng const& sz2)
    {
        return Sizelatlng(sz1.heightLat - sz2.heightLat, sz1.widthLng - sz2.widthLng);
    }

    QString ToString()
    {
        return QString("{widthLng=%1, HeightLat=%2}").arg(widthLng).arg(heightLat);
    }

 private:
    double widthLng;
    double heightLat;

};
}


#endif // SIZELATLNG_H
