#-------------------------------------------------
#
# Project created by QtCreator 2017-07-15T10:41:00
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CowisMap
TEMPLATE = app


SOURCES += main.cpp\
        Mainwindow.cpp \
    mapcore/AllLayersOfType.cpp \
    mapcore/Cache.cpp \
    mapcore/PureImageCache.cpp \
    mapcore/Point.cpp \
    mapcore/Size.cpp \
    mapcore/CacheItemQueue.cpp \
    mapcore/NetDiagnostics.cpp \
    mapcore/RawTitle.cpp \
    mapcore/KiberTileCache.cpp \
    mapcore/LanguageType.cpp \
    mapcore/MemoryCache.cpp \
    mapcore/Urlfactory.cpp \
    mapcore/ProviderStrings.cpp \
    internals/PointLatLng.cpp \
    mapcore/Placemark.cpp \
    mapcore/TitleCacheQueue.cpp \
    mapcore/PureImageProxy.cpp \
    mapcore/OPMaps.cpp \
    internals/Sizelatlng.cpp \
    internals/RectLatLng.cpp \
    internals/Rectangle.cpp \
    internals/Core.cpp \
    internals/LoadTask.cpp \
    internals/PureProjection.cpp \
    internals/Tile.cpp \
    internals/TileMatrix.cpp \
    internals/projections/lks94projection.cpp \
    internals/projections/MercatorProjection.cpp \
    internals/projections/MercatorProjectionYandex.cpp \
    internals/projections/PlateCarreeProjection.cpp \
    internals/projections/PlateCarreeProjectionPergo.cpp \
    mapwidget/Configuration.cpp

HEADERS  += Mainwindow.h \
    mapcore/Maptype.h \
    mapcore/AccessMode.h \
    mapcore/AllLayersOfType.h \
    mapcore/Cache.h \
    mapcore/PureImageCache.h \
    mapcore/Point.h \
    mapcore/Size.h \
    mapcore/CacheItemQueue.h \
    mapcore/NetDiagnostics.h \
    mapcore/GeoCoderStatusCode.h \
    mapcore/RawTitle.h \
    mapcore/KiberTileCache.h \
    mapcore/LanguageType.h \
    mapcore/MemoryCache.h \
    mapcore/Urlfactory.h \
    mapcore/ProviderStrings.h \
    internals/PointLatLng.h \
    mapcore/Placemark.h \
    mapcore/TitleCacheQueue.h \
    mapcore/PureImageProxy.h \
    mapcore/OPMaps.h \
    internals/Sizelatlng.h \
    internals/RectLatLng.h \
    internals/Rectangle.h \
    internals/Core.h \
    internals/MouseWheelZoomType.h \
    internals/LoadTask.h \
    internals/PureProjection.h \
    internals/Tile.h \
    internals/TileMatrix.h \
    internals/projections/lks94projection.h \
    internals/projections/MercatorProjection.h \
    internals/projections/MercatorProjectionYandex.h \
    internals/projections/PlateCarreeProjection.h \
    internals/projections/PlateCarreeProjectionPergo.h \
    mapwidget/Configuration.h
