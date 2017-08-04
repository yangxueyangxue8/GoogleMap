#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QRunnable>
#include <QQueue>
#include <QMutex>
#include <QSemaphore>
#include <QThreadPool>
#include "PointLatLng.h"
#include "../mapcore/Point.h"
#include "Rectangle.h"
#include "MouseWheelZoomType.h"
#include "../mapcore/Size.h"
#include "LoadTask.h"
#include "../mapcore/Maptype.h"
#include "../mapcore/NetDiagnostics.h"
#include "../mapcore/GeoCoderStatusCode.h"
#include "PureProjection.h"
#include "TileMatrix.h"

using namespace cowiscore;
namespace cowisinternals {
class Core : public QObject,public QRunnable
{
    Q_OBJECT


public:
   // explicit Core(QObject *parent = 0);
    Core();
    ~Core();
    void run();
    PointLatLng CurrentPosition()const {return currentPosition;}
    void SetCurrentPosition(const PointLatLng& value);

    cowiscore::Point GetcurrentPositionGPixel()const {return currentPositionPixel;}
    //void SetcurrentPositionGPixel(const cowiscore::Point& vlaue){}

    cowiscore::Point GetrenderOffset()const {return renderOffset;}
    void SetrenderOffset(const cowiscore::Point& value){renderOffset = value;}

    cowiscore::Point GetcenterTileXYLocation()const{return centerTileXYLocation;}
    void SetcenterTileXYLocation(cowiscore::Point const& value){centerTileXYLocation = value;}

    cowiscore::Point GetcenterTileXYLocationLast()const {return centerTileXYLocationLast;}
    void SetcenterTileXYLocationLast(cowiscore::Point const& value){centerTileXYLocationLast = value;}

    cowiscore::Point GetdragPoint()const {return dragPoint;}
    void SetdragPoint(const cowiscore::Point& value){dragPoint = value;}

    cowiscore::Point GetmouseDown()const {return mouseDown;}
    void SetmouseDown(cowiscore::Point const& value){mouseDown = value;}

    cowiscore::Point GetmouseCurrent()const {return mouseCurrent;}
    void SetmouseCurrent(cowiscore::Point const& value){mouseCurrent = value;}

    cowiscore::Point GetmouseLastZoom()const {return mouseLastZoom;}
    void SetmouseLastZoom(const cowiscore::Point& value){mouseLastZoom = value;}

    MouseWheelZoomType::Types GetMouseWheelZoomType()const {return mousewheelzoomtype;}
    void SetMouseWheelZoomType(const MouseWheelZoomType::Types& value){mousewheelzoomtype = value;}

    PointLatLng GetLastLocationInBounds()const {return LastLocationInBounds;}
    void SetLastLocationInBounds(PointLatLng const& value){LastLocationInBounds = value;}

    Size GetsizeOfMapArea()const{return sizeOfMapArea;}
    void SetsizeOfMapArea(const Size& value){sizeOfMapArea = value;}

    Size GetminOfTiles()const {return minOfTiles;}
    void SetminOfTiles(const Size& value){minOfTiles = value;}

    Size GetmaxOfTiles()const {return maxOfTiles;}
    void SetmaxOfTiles(const Size& value){maxOfTiles = value;}

    Rectangle GettileRect()const {return tileRect;}
    void SettileRect(const Rectangle& value){tileRect = value;}

    cowiscore::Point GettilePoint()const{return tilePoint;}
    void SettilePoint(const cowiscore::Point& value){tilePoint = value;}

    Rectangle GetCurrentRegion()const {return CurrentRegion;}
    void SetCurrentRegion(const Rectangle& value){CurrentRegion = value;}

    QList<cowiscore::Point> tileDrawingList;

    PureProjection* Projection()
    {
        return projection;
    }
    void SetProjection(PureProjection* value)
    {
        if (projection)
        {
            delete projection;
        }
        projection = value;
        tileRect = Rectangle(cowiscore::Point(0, 0), value->TileSize());
    }


    bool IsDragging()const{return isDragging;}

    int Zoom()const {return zoom;}
    void SetZoom(const int& value);//{zoom = value;}

    int MaxZoom()const {return maxZoom;}
    //void SetMaxZoom(int value){maxZoom = value;}

    void UpdateBounds();

    Maptype::Types GetMapType()const {return mapType;}
    void SetMapType(const Maptype::Types& value);//{mapType = value;}

    void StartSystem();

    void UpdateCenterTileXYLocation();

    void OnMapSizeChange(int const& width, int const& height);

    void OnMapClose();

    GeoCoderStatusCode::Types SetCurrentPositionByKeywords(QString const& keys);

    Rectangle CurrentViewArea();

    PointLatLng FromLocalToLatLng(int const& x, int const& y);
    Point FromLatLngToLocal(PointLatLng const& latlng);

    int GetMaxZoomToFitRect(RectLatLng const& rect);

    void BeginDrag(cowiscore::Point const& pt);

    void EndDrag();

    void ReloadMap();

    void GoToCurrentPosition();
    bool MouseWheelZooming;

    void DragOffset(cowiscore::Point const& offset);
    void Drag(cowiscore::Point const& pt);

    void CanceAsyncTasks();

    void FindTilesAround(QList<cowiscore::Point>& list);

    void UpdateGroundResolution();

    bool isStarted()const {return started;}

    TileMatrix Matrix;
    NetDiagnostics GetDiagnostics();
    
signals:
    void OnCurrentPositionChanged(cowisinternals::PointLatLng point);
    void OnTileLoadComplete();
    void OnTilesStillToLoad(int number);
    void OnTileLoadStart();
    void OnMapDrag();
    void OnMapZoomChanged();
    void OnMapTypeChanged(Maptype::Types type);
    void OnEmptyTileError(int zoom, cowiscore::Point pos);
    void OnNeedInvalidation();
    
private:
    PointLatLng currentPosition;
    cowiscore::Point currentPositionPixel;
    cowiscore::Point renderOffset;
    cowiscore::Point centerTileXYLocation;
    cowiscore::Point centerTileXYLocationLast;
    cowiscore::Point dragPoint;
    Rectangle        tileRect;
    cowiscore::Point mouseDown;
    bool             CanDragMap;
    cowiscore::Point mouseCurrent;
    PointLatLng      LastLocationInBounds;
    cowiscore::Point mouseLastZoom;
    
    MouseWheelZoomType::Types mousewheelzoomtype;
     
    Size  sizeOfMapArea;
    Size  minOfTiles;
    Size  maxOfTiles;
    
    cowiscore::Point tilePoint;
    Rectangle  CurrentRegion;
    
    QQueue<LoadTask> tileLoatqueue;
    
    int zoom;
    PureProjection* projection;

    bool isDragging;
    QMutex MtileLoadQueue;
    QMutex Moverlays;
    QMutex MtileDrawingList;
    
    Size TooltipTextPadding;
    Maptype::Types mapType;
    
    QSemaphore loaderLimit;
    QThreadPool ProcessLoadTaskCallback;
    QMutex MtileToload;
    int tilesToload;
    int maxZoom;
    QMutex MrunningThreads;
    int runningThreads;
    NetDiagnostics diag;
protected:
    bool started;
    int Width;
    int Height;
    int pxRes100m;
    int pxRes1000m;
    int pxRes10km;
    int pxRes100km;
    int pxRes1000km;
    int pxres5000km;
    void SetCurrentPositionGPixel(cowiscore::Point const& value)
    {
        currentPositionPixel = value;
    }
    void GoToCurrentPositionOnZoom();
    
};
}


#endif // CORE_H
