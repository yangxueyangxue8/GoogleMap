#ifndef RAWTITLE_H
#define RAWTITLE_H
#include "Point.h"
#include "Maptype.h"
#include <QString>
namespace cowiscore {
class RawTitle
{
    friend uint qHash(RawTitle const& title);
    friend bool operator ==(RawTitle const& lhs, RawTitle const& rhs);
public:
    RawTitle(const Maptype::Types& type, const cowiscore::Point& pos, const int& zoom);
    QString toString();

    void setType(const Maptype::Types& type){this->type = type;}
    Maptype::Types getType() const{return type;}

    void setPos(const cowiscore::Point& pos){this->pos = pos;}
    cowiscore::Point getPos() const{return pos;}

    void setZoom(const int zoom){this->zoom = zoom;}
    int getZoom() const {return zoom;}

   private:
    Maptype::Types type;
    cowiscore::Point pos;
    int zoom;
};
}


#endif // RAWTITLE_H
