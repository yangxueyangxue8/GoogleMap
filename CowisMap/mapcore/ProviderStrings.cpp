#include "ProviderStrings.h"
namespace cowiscore {
const QString ProviderStrings::levelsForSigPacSpainMap[] = {"0", "1", "2", "3", "4",
                                                           "MTNSIGPAC",
                                                           "MTN2000", "MTN2000", "MTN2000", "MTN2000", "MTN2000",
                                                           "MTN200", "MTN200", "MTN200",
                                                           "MTN25", "MTN25",
                                                           "ORTOFOTOS","ORTOFOTOS","ORTOFOTOS","ORTOFOTOS"};
ProviderStrings::ProviderStrings()
{
    VersionGoogleMap       = "m@132";
    VersionGoogleSatellite = "71";//"s@165";//
    VersionGoogleLabels    = "h@132";//"h@336";//
    VersionGoogleTerrain   = "t@125,r@132";//"t@132,r@336";//
    SecGoogleWord          = "Galileo";

    VersionGoogleMapChina       = "m@132";//2017-6-22"m@218";//
    VersionGoogleSatelliteChina = "s@71";//"s@165";//
    VersionGoogleLabelsChina    = "h@132";//"h@336";//
    VersionGoogleTerrainChina   = "t@125,r@132";//"t@132,r@336";//

    VersionGoogleMapKorea       = "kr1.12";
    VersionGoogleSatelliteKorea = "66";
    VersionGoogleLabelsKorea    = "kr1t.12";

    GoogleMapsAPIKey = "ABQIAAAA5Q6wxQ6lxKS8haLVdUJaqhSjosg_0jiTTs2iXtkDVG0n0If1mBRHzhWw5VqBZX-j4NuzoVpU-UaHVg";


    VersionYahooMap = "4.3";
    VersionYahooSatellite = "1.9";
    VersionYahooLabels = "4.3";

    VersionBingMaps = "563";

    VersionYandexMap = "2.16.0";

    BingMapsClientToken = "";
}
}


