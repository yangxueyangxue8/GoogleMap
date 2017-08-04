#include "RectLatLng.h"
namespace cowisinternals {
RectLatLng RectLatLng::Empty = RectLatLng();
uint qHash(const RectLatLng &rect)
{
    return (int) (((((uint) rect.Lng()) ^ ((((uint) rect.Lat()) << 13) | (((uint) rect.Lat()) >> 0x13))) ^ ((((uint) rect.WidthLng()) << 0x1a) | (((uint) rect.WidthLng()) >> 6))) ^ ((((uint) rect.HeightLat()) << 7) | (((uint) rect.HeightLat()) >> 0x19)));
}

bool operator==(const RectLatLng &left, const RectLatLng &right)
{
    return ((((left.Lng() == right.Lng()) && (left.Lat() == right.Lat())) && (left.WidthLng() == right.WidthLng())) && (left.HeightLat() == right.HeightLat()));
}

bool operator !=(const RectLatLng &left, const RectLatLng &right)
{
    return !(left == right);
}

}


