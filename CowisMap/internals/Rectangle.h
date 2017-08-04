#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QString>
#include <cmath>
#include "../mapcore/Size.h"
using namespace cowiscore;
namespace cowisinternals {
struct Rectangle
{
    friend uint qHash(Rectangle const& rect);
    friend bool operator==(Rectangle const& lhs, Rectangle const& rhs);

public:
    static Rectangle Empty;
    static Rectangle FromLTRB(int left, int top, int right, int bottom);

    Rectangle()
    {
        x = 0;
        y = 0;
        width  = 0;
        height = 0;
    }
    Rectangle(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width  = width;
        this->height = height;
    }
    Rectangle(cowiscore::Point const& location, cowiscore::Size const& size)
    {
        this->x = location.X();
        this->y = location.Y();
        this->width  = size.Width();
        this->height = size.Height();
    }
    cowiscore::Point GetLocation()
    {
        return cowiscore::Point(x, y);
    }
    void setLocation(const cowiscore::Point& value)
    {
        x = value.X();
        y = value.Y();
    }

    int X()const {return x;}
    void setX(int x){this->x = x;}

    int Y()const {return y;}
    void setY(int y){this->y = y;}

    int Width()const {return width;}
    void setWidth(int width){this->width = width;}

    int Height()const {return height;}
    void setHeight(int height){this->height = height;}

    int Left()const {return x;}
    int Top()const  {return y;}
    int Right()const {return x + width;}
    int Bottom()const {return y + height;}

    bool IsEmpty(){return (height==0 && width==0 && x==0 && y==0);}

    bool operator ==(const Rectangle& cSource)
    {
        return (cSource.x == x && cSource.y == y && cSource.width == width && cSource.height == height);
    }

    bool operator !=(const Rectangle& cSource)
    {
        return !(*this == cSource);
    }

    bool Contains(const int &x,const int &y)
     {
         return this->x<=x && x<this->x+this->width && this->y<=y && y<this->y+this->height;
     }

    bool Contains(const cowiscore::Point &pt)
    {
        return Contains(pt.X(),pt.Y());
    }

    bool Contains(const Rectangle &rect)
    {
        return (this->x <= rect.x) &&
                    ((rect.x + rect.width) <= (this->x + this->width)) &&
                    (this->y <= rect.y) &&
                    ((rect.y + rect.height) <= (this->y + this->height));
    }

    void Inflate(const int &width,const int &height)
    {
        this->x -= width;
        this->y -= height;
        this->width += 2*width;
        this->height += 2*height;
    }

    void Inflate(Size &size)
    {

        Inflate(size.Width(), size.Height());
    }

    static Rectangle Inflate(Rectangle rect, int x, int y);

    void Intersect(const Rectangle &rect)
    {
        Rectangle result = Rectangle::Intersect(rect, *this);

        this->x = result.X();
        this->y = result.Y();
        this->width = result.Width();
        this->height = result.Height();
    }

    static Rectangle Intersect(Rectangle a, Rectangle b);

    bool IntersectsWith(const Rectangle &rect)
    {
        return (rect.x < this->x + this->width) &&
                (this->x < (rect.x + rect.width)) &&
                (rect.y < this->y + this->height) &&
                (this->y < rect.y + rect.height);
    }

    static Rectangle Union(const Rectangle &a,const Rectangle &b);

    void Offset(const cowiscore::Point &pos)
    {
        Offset(pos.X(), pos.Y());
    }

    void Offset(const int &x,const int &y)
    {
        this->x += x;
        this->y += y;
    }


    QString ToString()
    {
        return "{X=" + QString::number(x) + ",Y=" + QString::number(y) +
                ",Width=" + QString::number(width) +
                ",Height=" +QString::number(height) +"}";
    }

private:
    int x;
    int y;
    int width;
    int height;

};
}


#endif // RECTANGLE_H
