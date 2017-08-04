/******************************************************************************
* @brief access mode
* @author Xue yang
* @date   2017/07/15
******************************************************************************/
#ifndef ACCESSMODE_H
#define ACCESSMODE_H
#include <QObject>
#include <QMetaEnum>
#include <QMetaEnum>
#include <QStringList>
namespace cowiscore {
class AccessMode:public QObject
{
    Q_OBJECT
    Q_ENUMS(Types)
public:
    enum Types
    {
        ServerOnly,
        ServerAndCache,
        CacheOnly
    };

    static QString StrByType(Types const& value)
    {
        QMetaObject metaObject = AccessMode().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        QString ret = metaEnum.valueToKey(value);
        return ret;
    }

    static Types TypeByStr(QString const& value)
    {
        QMetaObject metaObject = AccessMode().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        Types ret = (Types)metaEnum.keysToValue(value.toLatin1());
        return ret;
    }

    static QStringList TypesList()
    {
        QStringList ret;
        QMetaObject metaObject = AccessMode().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
            ret.append(metaEnum.key(i));
        }
        return ret;
    }
};

}


#endif // ACCESSMODE_H

