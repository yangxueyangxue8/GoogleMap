#ifndef SIZE_H
#define SIZE_H
#include "Point.h"
namespace cowiscore {
struct Size{
    Size();
    Size(Point pt){width = pt.X(); height = pt.Y();}
    Size(int width, int height){this->width = width; this->height = height;}

    friend uint qHash(Size const& size);

    Size operator-(const Size& sz1){ return Size(width - sz1.width, height - sz1.height);}
    Size operator +(const Size& sz1){return Size(width + sz1.width, height + sz1.height);}

    int getHasCode(){return width^height;}
    uint qHash(Size const&){return width^height;}

    void setWidth(int value){this->width = value;}
    void setHeight(int value) {this->height = value;}

    int Width() const{return width;}
    int Height()const { return height;}

private:
    int width;
    int height;
};
}

#endif // SIZE_H
