#ifndef PROVIDERSTRINGS_H
#define PROVIDERSTRINGS_H
#include <QString>
namespace cowiscore {
class ProviderStrings
{
public:
    ProviderStrings();
    static const QString levelsForSigPacSpainMap[];
    QString GoogleMapsAPIKey;
    QString VersionGoogleMap;
    QString VersionGoogleSatellite;
    QString VersionGoogleLabels;
    QString VersionGoogleTerrain;
    QString SecGoogleWord;

    QString VersionGoogleMapChina;
    QString VersionGoogleSatelliteChina;
    QString VersionGoogleLabelsChina;
    QString VersionGoogleTerrainChina;

    QString VersionGoogleMapKorea;
    QString VersionGoogleSatelliteKorea;
    QString VersionGoogleLabelsKorea;

    // Yahoo version strings
    QString VersionYahooMap;
    QString VersionYahooSatellite;
    QString VersionYahooLabels;

    // BingMaps
    QString VersionBingMaps;

    // YandexMap
    QString VersionYandexMap;
    QString BingMapsClientToken;
};
}


#endif // PROVIDERSTRINGS_H
