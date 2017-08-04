#ifndef MOUSEWHEELZOOMTYPE_H
#define MOUSEWHEELZOOMTYPE_H

#include <QObject>
#include <QStringList>
#include <QMetaObject>
#include <QMetaEnum>
#include <QMetaType>
namespace cowisinternals {
class MouseWheelZoomType : public QObject
{
    Q_OBJECT
    Q_ENUMS(Types)
public:
   enum Types
   {
       MousePositionAndCenter,
       MousePositionWithoutCenter,
       ViewCenter
   };

   static QString StrByType(Types const& value)
   {
       QMetaObject metaObject = MouseWheelZoomType().staticMetaObject;
       QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
       QString s = metaEnum.valueToKey(value);
       return s;

   }

   static Types TypesByStr(QString const& value)
   {
       QMetaObject metaObject = MouseWheelZoomType().staticMetaObject;
       QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
       Types ret = (Types)metaEnum.keyToValue(value.toLatin1());
       return ret;
   }
   static QStringList TypesList()
   {
       QStringList ret;
       QMetaObject metaObject = MouseWheelZoomType().staticMetaObject;
       QMetaEnum   metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
       for (int i = 0; i < metaEnum.keyCount(); i++)
       {
           ret.append(metaEnum.key(i));
       }
       return ret;
   }
};
}


#endif // MOUSEWHEELZOOMTYPE_H
