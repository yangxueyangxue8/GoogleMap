#include "PureImageProxy.h"
namespace cowiscore {
PureImageProxy::PureImageProxy()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QPixmap PureImageProxy::FromStream(const QByteArray &array)
{
    return QPixmap::fromImage(QImage::fromData(array));
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
bool PureImageProxy::Save(const QByteArray &array, QPixmap &pic)
{
    pic = QPixmap::fromImage(QImage::fromData(array));
    return true;
}
}


