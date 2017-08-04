#ifndef GEOCODERSTATUSCODE_H
#define GEOCODERSTATUSCODE_H

#include <QObject>
#include <QMetaObject>
#include <QMetaEnum>
#include <QStringList>
namespace cowiscore {
class GeoCoderStatusCode:public QObject
{
    Q_OBJECT
    Q_ENUMS(Types)
public:
    enum Types{
        Unknow = -1,
        G_GEO_SUCCESS             = 200,
        G_GEO_BAD_REQUEST         = 400,
        G_GEO_SERVER_ERROR        = 500,
        G_GEO_MISSING_QUERY       = 601,
        G_GEO_MISSING_ADDRESS     = 601,
        G_GEO_UNKNOWN_ADDRESS     = 602,
        G_GEO_UNAVAILABLE_ADDRESS = 603,
        G_GEO_UNKNOWN_DIRECTIONS  = 604,
        G_GEO_BAD_KEY             = 610, // The given key is either invalid or does not match the domain for which it was given.
        G_GEO_TOO_MANY_QUERIES    = 620

    };

    static QString strBytype(Types const& value)
    {
        QMetaObject metaObjec = GeoCoderStatusCode().staticMetaObject;
        QMetaEnum metaEnum = metaObjec.enumerator(metaObjec.indexOfEnumerator("Types"));
        return metaEnum.valueToKey(value);
    }

    static Types typeBystr(const QString& value)
    {
        QMetaObject metaObject = GeoCoderStatusCode().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        Types ret = (Types)metaEnum.keyToValue(value.toLatin1());
        return ret;
    }

    static QStringList TypesList()
    {
        QStringList ret;
        QMetaObject metaObject = GeoCoderStatusCode().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
            ret.append(metaEnum.key(i));
        }
        return ret;
    }
};
}


#endif // GEOCODERSTATUSCODE_H
