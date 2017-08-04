#ifndef PLACEMARK_H
#define PLACEMARK_H
#include <QString>
namespace cowiscore {
class Placemark
{
public:
    Placemark(const QString& address)
    {
        this->address = address;
    }
    QString Address()const {return address;}
    int Accuracy()const {return accuracy;}
    void setAccuracy(int accuracy)
    {
        this->accuracy = accuracy;
    }
    void setAddress(QString const& value)
    {
        this->address = value;
    }


private:
    QString address;
    int accuracy;
};
}


#endif // PLACEMARK_H
