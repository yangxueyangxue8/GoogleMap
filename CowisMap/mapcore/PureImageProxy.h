#ifndef PUREIMAGEPROXY_H
#define PUREIMAGEPROXY_H
#include <QPixmap>
#include <QString>
namespace cowiscore {
class PureImageProxy
{
public:
    PureImageProxy();
    static QPixmap FromStream(const QByteArray& array);
    static bool Save(const QByteArray& array, QPixmap &pic);
};
}


#endif // PUREIMAGEPROXY_H
