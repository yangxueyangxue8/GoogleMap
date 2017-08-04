#include "AllLayersOfType.h"
namespace cowiscore {

AllLayersOfType::AllLayersOfType()
{

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
QVector<Maptype::Types> AllLayersOfType::GetAllLayersOfType(const Maptype::Types &type)
{
    QVector<Maptype::Types> ret;
    switch (type)
    {
    case Maptype::GoogleHybrid:
    {
        ret.append(Maptype::GoogleSatellite);
        ret.append(Maptype::GoogleLabels);
    }
        break;
    case Maptype::GoogleHybridChina:
    {
        ret.append(Maptype::GoogleSatelliteChina);
        ret.append(Maptype::GoogleLabelsChina);
    }
        break;
    case Maptype::GoogleHybridKorea:
    {
        ret.append(Maptype::GoogleHybridKorea);
        ret.append(Maptype::GoogleLabelsKorea);
    }
        break;
    case Maptype::YahooHybrid:
    {
        ret.append(Maptype::YahooSatellite);
        ret.append(Maptype::YahooLabels);
    }
        break;
    case Maptype::ArcGIS_MapsLT_Map_Hybrid:
    {
        ret.append(Maptype::ArcGIS_MapsLT_Map_Hybrid);
        ret.append(Maptype::ArcGIS_MapsLT_Map_Labels);
    }
        break;
    default:
        ret.append(type);
        break;
    }
    return ret;
}

}

