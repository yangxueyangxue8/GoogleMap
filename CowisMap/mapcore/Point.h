#ifndef POINT_H
#define POINT_H
#include <QString>
namespace cowiscore {
struct Size;
struct Point{
    friend uint qHash(Point const& point);

    friend bool operator ==(Point const& lhs, Point const& rhs);
    friend bool operator !=(Point const& lhs, Point const& rhs);

public:
    Point();
    Point(int x, int y);
    Point(Size sz);
    Point(int dw);

    bool isEmpty()const{return empty;}

    int X() const{return x;}
    int Y() const{return y;}

    void setX(const int& value){x = value; empty = false;}
    void setY(const int& value){y = value; empty = false;}

    QString toString() const{ return "{" + QString::number(x) + "," + QString::number(y) + "}";}

    static Point Empty;

    void offset(const int& dx, const int& dy)
    {
        this->x += dx;
        this->y += dy;
    }

    void offset(const Point& p)
    {
        offset(p.x, p.y);
    }

    static int hiWord(int n)
    {
        return (n >> 16) & 0xffff;
    }

    static loWord(int n)
    {
        return n & 0xffff;
    }

    private:
    int x;
    int y;
    bool empty;
};
}


#endif // POINT_H
