#ifndef OPMAPS_H
#define OPMAPS_H
#include "MemoryCache.h"
#include "AllLayersOfType.h"
#include "Urlfactory.h"
#include "Maptype.h"
#include "Point.h"
#include "LanguageType.h"
#include "accessmode.h"
#include "NetDiagnostics.h"
#include "TitleCacheQueue.h"

namespace cowiscore {
class OPMaps:public MemoryCache,public AllLayersOfType,public Urlfactory
{
public:
    ~OPMaps();
    static OPMaps* Instance();

    bool ImportFromGMDB(const QString& file);
    bool ExportToGMDB(const QString& file);


    QByteArray GetImageFrom(const Maptype::Types& type, const cowiscore::Point& pos, const int& zoom);

    bool UseMemoryCache(){return useMemoryCache;}
    void setUseMemoryCache(bool value){useMemoryCache = value;}

    void setLanguage(const LanguageType::Types& type){Language = type;}
    LanguageType::Types GetLanguage()const {return Language;}

    void setAccessMode(const AccessMode::Types& mode){accessmode = mode;}
    AccessMode::Types GetAccessMOde() const{return accessmode;}

    int RetryLoadTile;

    NetDiagnostics GetDiagnostics();

private:
    bool useMemoryCache;
    LanguageType::Types Language;
    AccessMode::Types accessmode;
    TitleCacheQueue TileDBcacheQueue;
    OPMaps();
    OPMaps& operator =(OPMaps const&){return *this;}
    static OPMaps* m_pInstance;
    NetDiagnostics diag;
    QMutex errorvars;

};
}



#endif // OPMAPS_H
