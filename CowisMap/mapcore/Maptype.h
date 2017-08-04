/******************************************************************************
* @brief map type
* @author Xue yang
* @date   2017/07/15
******************************************************************************/
#ifndef MAPTYPE_H
#define MAPTYPE_H

#include <QObject>
#include <QMetaEnum>
#include <QMetaObject>
#include <QStringList>
namespace cowiscore {

class Maptype : public QObject
{
    Q_OBJECT
    Q_ENUMS(Types)
public:
    enum Types
    {
        GoogleMap       = 1,
        GoogleSatellite = 4,
        GoogleLabels    = 8,
        GoogleTerrain   = 16,
        GoogleHybrid    = 20,

        GoogleMapChina       = 22,
        GoogleSatelliteChina = 24,
        GoogleLabelsChina    = 26,
        GoogleTerrainChina   = 28,
        GoogleHybridChina    = 29,

        OpenStreetMap              = 32,
        OpenStreetOsm              = 33,
        OpenStreetMapSurfer        = 34,
        OpenStreetMapSurferTerrain = 35,

        YahooMap       = 64,
        YahooSatellite = 128,
        YahooLabels    = 256,
        YahooHybrid    = 333,

        BingMap       = 444,
        BingSatellite = 555,
        BingHybrid    = 666,

        ArcGIS_Map               = 777,
        ArcGIS_Satellite         = 788,
        ArcGIS_ShadedRelief      = 799,
        ArcGIS_Terrain           = 811,
        ArcGIS_MapsLT_Map        = 1000,
        ArcGIS_MapsLT_OrtoFoto   = 1001,
        ArcGIS_MapsLT_Map_Labels = 1002,
        ArcGIS_MapsLT_Map_Hybrid = 1003,

        PergoTurkeyMap = 2001,
        SigPacSpainMap = 3001,

        GoogleMapKorea       = 4001,
        GoogleSatelliteKorea = 4002,
        GoogleLabelsKorea    = 4003,
        GoogleHybridKorea    = 4005,

        YandexMapRu = 5000

    };

    static QString StrByType(Types const& value)
    {
        QMetaObject metaObject = Maptype().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        QString str = metaEnum.valueToKey(value);
        return str;
    }

    static Types TypeByStr(QString const& value)
    {
        QMetaObject metaObject = Maptype().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        Types ret = (Types)metaEnum.keysToValue(value.toLatin1());
        return ret;
    }

    static QStringList TypeList()
    {
        QStringList ret;
        QMetaObject metaObject = Maptype().staticMetaObject;
        QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("Types"));
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
            ret.append(metaEnum.key(i));
        }
        return ret;
    }

};

}


#endif // MAPTYPE_H
