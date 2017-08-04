#include "Core.h"
#include <QWaitCondition>
#include <QVector>

namespace cowisinternals {

Core::Core():MouseWheelZooming(false),
    currentPosition(0, 0),
    currentPositionPixel(0, 0),
    LastLocationInBounds(-1, -1),
    sizeOfMapArea(0, 0),
    minOfTiles(0, 0),
    maxOfTiles(0, 0),
    zoom(0),
    projection(NULL),
    isDragging(false),
    TooltipTextPadding(10, 10),
    mapType(Maptype::GoogleMapChina),
    loaderLimit(5),
    maxZoom(21),
    runningThreads(0),
    started(false)
{
    mousewheelzoomtype = MouseWheelZoomType::MousePositionAndCenter;
    SetProjection(NULL);//////////
    this->setAutoDelete(false);
    ProcessLoadTaskCallback.setMaxThreadCount(10);
    renderOffset = Point(0, 0);
    dragPoint    = Point(0, 0);
    CanDragMap   = true;
    tilesToload  = 0;
    //maps
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Core::~Core()
{
    if (projection)
    {
        delete projection;
    }
    ProcessLoadTaskCallback.waitForDone();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::run()
{
    MrunningThreads.lock();
    ++runningThreads;
    MrunningThreads.unlock();

    bool last = false;
    LoadTask task;

    MtileLoadQueue.lock();
    {
        if (tileLoatqueue.count() > 0)
        {
            task = tileLoatqueue.dequeue();
            {
                last = (tileLoatqueue.count() == 0);
            }
        }
    }
    MtileLoadQueue.unlock();

    if (task.HasValue())
    {
        //if (loaderLimit.tryAcquire(1, ))
        {
            MtileToload.lock();
            --tilesToload;
            MtileToload.unlock();
            {
                {
                    Tile* m = Matrix.TileAt(task.Pos);
                    if (m == 0 || m->Overlays.count() == 0)
                    {
                        Tile* t = new Tile(task.Zoom, task.Pos);
                        QVector<Maptype::Types> layers ;//= ;//
                        foreach (Maptype::Types tl, layers)
                        {
                            int retry = 0;
                            do
                            {
                                QByteArray img;
                                if(tl == Maptype::PergoTurkeyMap)
                                {
                                    ;//img
                                }
                                else
                                {
                                    ;//
                                }
                                if (img.length() != 0)
                                {
                                    Moverlays.lock();
                                    {
                                        t->Overlays.append(img);
                                    }
                                    Moverlays.unlock();
                                    break;
                                }
                                else if(false)///
                                {
                                    {
                                        QWaitCondition wait;
                                        QMutex m;
                                        m.lock();
                                        wait.wait(&m, 500);
                                    }
                                }
                            }
                            while(++retry);//////////
                        }
                        if(t->Overlays.count() > 0)
                        {
                            Matrix.SetTileAt(task.Pos, t);
                            emit OnNeedInvalidation();
                        }
                        else
                        {
                            delete t;
                            t = 0;
                            emit OnNeedInvalidation();
                        }
                    }
                }
                {
                    if (last)
                    {
                        //
                        //
                        //
                        MtileDrawingList.lock();
                        {
                            Matrix.ClearPointsNotin(tileDrawingList);
                        }
                        MtileDrawingList.unlock();
                        emit OnTileLoadComplete();

                        emit OnNeedInvalidation();
                    }
                }
            }
            emit OnTilesStillToLoad(tilesToload < 0 ? 0 : tilesToload);
            loaderLimit.release();
        }
        MrunningThreads.lock();
        --runningThreads;
        MrunningThreads.unlock();
    }

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::SetCurrentPosition(const PointLatLng &value)
{
    if (!IsDragging())
    {
        currentPosition = value;
        SetCurrentPositionGPixel(Projection()->FromLatLngToPixel(value, Zoom()));
        if (started)
        {
            GoToCurrentPosition();
            emit OnCurrentPositionChanged(currentPosition);
        }
    }
    else
    {
        currentPosition = value;
        SetCurrentPositionGPixel(Projection()->FromLatLngToPixel(value, Zoom()));

        if (started)
        {
            emit OnCurrentPositionChanged(currentPosition);
        }
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::SetZoom(const int &value)
{
    if(!isDragging)
    {
        zoom = value;
        minOfTiles = Projection()->GetTileMatrixMinXY(value);
        maxOfTiles = Projection()->GetTileMatrixMaxXY(value);
        currentPositionPixel = Projection()->FromLatLngToPixel(currentPosition, value);
        if(started)
        {
            MtileLoadQueue.lock();
            tileLoatqueue.clear();
            MtileLoadQueue.unlock();
            MtileToload.lock();
            tilesToload = 0;
            MtileToload.unlock();
            Matrix.Clear();
            GoToCurrentPositionOnZoom();
            UpdateBounds();
            emit OnMapDrag();
            emit OnMapZoomChanged();
            emit OnNeedInvalidation();
        }
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::UpdateBounds()
{
    MtileDrawingList.lock();
    {
        FindTilesAround(tileDrawingList);
        emit OnTileLoadStart();

        foreach (Point p, tileDrawingList)
        {
            LoadTask task = LoadTask(p, Zoom());
            {
                MtileLoadQueue.lock();
                {
                    if (!tileLoatqueue.contains(task))
                    {
                        MtileToload.lock();
                        ++tilesToload;
                        MtileToload.unlock();
                        tileLoatqueue.enqueue(task);
                        ProcessLoadTaskCallback.start(this);
                    }
                }
                MtileLoadQueue.unlock();
            }
        }
    }
    MtileDrawingList.unlock();
    UpdateGroundResolution();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::SetMapType(const Maptype::Types &value)
{
   if (value != GetMapType())
   {
       mapType = value;
       switch (value)
       {
       case Maptype::ArcGIS_Map:
       case Maptype::ArcGIS_Satellite:
       case Maptype::ArcGIS_ShadedRelief:
       case Maptype::ArcGIS_Terrain:
       {
           if (Projection()->Type() != "PlateCarreeProjection")
           {
               //SetProjection(new PlateCarr);
               maxZoom = 13;
           }
       }

           break;
       case Maptype::ArcGIS_MapsLT_Map_Hybrid:
       case Maptype::ArcGIS_MapsLT_Map_Labels:
       case Maptype::ArcGIS_MapsLT_Map:
       case Maptype::ArcGIS_MapsLT_OrtoFoto:
       {
           if (Projection()->Type() != "LKS94Projection")
           {
               //SetProjection();
               maxZoom = 11;
           }
       }
           break;
       case Maptype::PergoTurkeyMap:
       {
           if (Projection()->Type() != "PlateCarreeProjectionPergo")
           {
               //SetProjection();
               maxZoom = 17;
           }
       }
           break;
       case Maptype::YandexMapRu:
       {
           if (Projection()->Type() != "MercatorProjectionYandex")
           {
              // SetProjection();
               maxZoom = 13;
           }
       }
           break;
       case Maptype::BingHybrid:
       case Maptype::BingMap:
       case Maptype::BingSatellite:
       {
           if (Projection()->Type() != "MercatorProjection")
           {
              // SetProjection();
           }
           maxZoom = 20;
       }
       break;

       default:
       {
           if (Projection()->Type() != "MercatorProjection")
           {
              //SetProjection();
           }
           maxZoom = 20;
       }
           break;
       }
       minOfTiles = Projection()->GetTileMatrixMinXY(Zoom());
       maxOfTiles = Projection()->GetTileMatrixMaxXY(Zoom());

       SetCurrentPositionGPixel(Projection()->FromLatLngToPixel(CurrentPosition(), Zoom()));
       if (started)
       {
           CanceAsyncTasks();
           OnMapSizeChange(Width, Height);
           GoToCurrentPosition();
           ReloadMap();
           GoToCurrentPosition();
           emit OnMapTypeChanged(value);
       }
   }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::StartSystem()
{
    if (!started)
    {
        started = true;
        ReloadMap();
        GoToCurrentPosition();
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::UpdateCenterTileXYLocation()
{
    PointLatLng center   = FromLocalToLatLng(Width / 2, Height / 2);
    Point centerPixel    = Projection()->FromLatLngToPixel(center, Zoom());
    centerTileXYLocation = Projection()->FromPixelToTileXY(centerPixel);

}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::OnMapSizeChange(const int &width, const int &height)
{
    Width  = width;
    Height = height;
    sizeOfMapArea.setWidth(1 + (Width / Projection()->TileSize().Width()) / 2);
    sizeOfMapArea.setHeight(1 + (Height / Projection()->TileSize().Height()) / 2);

    UpdateCenterTileXYLocation();
    if (started)
    {
        UpdateBounds();
        emit OnCurrentPositionChanged(currentPosition);
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::OnMapClose()
{
    CanceAsyncTasks();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
GeoCoderStatusCode::Types Core::SetCurrentPositionByKeywords(const QString &keys)
{
    GeoCoderStatusCode::Types status = GeoCoderStatusCode::Unknow;
    PointLatLng pos ;////
    if (!pos.IsEmpty() && (status == GeoCoderStatusCode::G_GEO_SUCCESS))
    {
        SetCurrentPosition(pos);
    }
    return status;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Rectangle Core::CurrentViewArea()
{
    PointLatLng p = Projection()->FromPixelToLatLng(-renderOffset.X(), -renderOffset.Y(), Zoom());
    double rlng = Projection()->FromPixelToLatLng(-renderOffset.X() + Width, -renderOffset.Y(), Zoom()).Lng();
    double blat = Projection()->FromPixelToLatLng(-renderOffset.X(), -renderOffset.Y() + Height, Zoom()).Lat();
    return Rectangle::FromLTRB(p.Lng(), p.Lat(), rlng, blat);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
PointLatLng Core::FromLocalToLatLng(const int &x, const int &y)
{
    return Projection()->FromPixelToLatLng(Point(x - renderOffset.X(), y - renderOffset.Y()), Zoom());
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
Point Core::FromLatLngToLocal(const PointLatLng &latlng)
{
    Point pLocal = Projection()->FromLatLngToPixel(latlng, Zoom());
    pLocal.offset(renderOffset);
    return pLocal;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
int Core::GetMaxZoomToFitRect(const RectLatLng &rect)
{
    int zoom = 0;
    for (int i = 1; i <= MaxZoom(); i++)
    {
        Point p1 = Projection()->FromLatLngToPixel(rect.LocationToLeft(), i);
        Point p2 = Projection()->FromLatLngToPixel(rect.Bottom(), rect.Right(), i);

        if (((p2.X() - p1.X()) <= Width + 10) && (p2.Y() - p1.Y()) <= Height + 10)
        {
            zoom = i;
        }
        else
        {
            break;
        }
    }
    return zoom;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::BeginDrag(const Point &pt)
{
    dragPoint.setX(pt.X() - renderOffset.X());
    dragPoint.setY(pt.Y() - renderOffset.Y());
    isDragging = true;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::EndDrag()
{
    isDragging = false;
    emit OnNeedInvalidation();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::ReloadMap()
{
    if (started)
    {
        MtileLoadQueue.lock();
        {
            tileLoatqueue.clear();
        }
        MtileLoadQueue.unlock();
        MtileToload.lock();
        tilesToload = 0;
        MtileToload.unlock();
        Matrix.Clear();
        emit OnNeedInvalidation();
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::GoToCurrentPosition()
{
    renderOffset = Point::Empty;
    centerTileXYLocationLast = Point::Empty;
    dragPoint = Point::Empty;
    Drag(Point(-(GetcurrentPositionGPixel().X() - Width / 2), -(GetcurrentPositionGPixel().Y() - Height / 2)));
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::DragOffset(const Point &offset)
{
    renderOffset.offset(offset);

    UpdateCenterTileXYLocation();
    if(centerTileXYLocation != centerTileXYLocationLast)
    {
        centerTileXYLocationLast = centerTileXYLocation;
        UpdateBounds();
    }
    {
        LastLocationInBounds = CurrentPosition();
        SetCurrentPosition(FromLocalToLatLng((int) Width / 2, (int) Height / 2));
    }
    emit OnNeedInvalidation();
    emit OnMapDrag();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::Drag(const Point &pt)
{
    renderOffset.setX(pt.X() - dragPoint.X());
    renderOffset.setY(pt.Y() - dragPoint.Y());

    UpdateCenterTileXYLocation();

    if (centerTileXYLocation != centerTileXYLocationLast)
    {
        centerTileXYLocationLast = centerTileXYLocation;
        UpdateBounds();
    }
    if (IsDragging())
    {
        LastLocationInBounds = CurrentPosition();
        SetCurrentPosition(FromLocalToLatLng((int)Width / 2, (int) Height / 2));
    }
    emit OnNeedInvalidation();
    emit OnMapDrag();
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::CanceAsyncTasks()
{
    if (started)
    {
        ProcessLoadTaskCallback.waitForDone();
        MtileLoadQueue.lock();
        {
            tileLoatqueue.clear();
        }
        MtileLoadQueue.unlock();

        MtileToload.lock();
        tilesToload = 0;
        MtileToload.unlock();
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::FindTilesAround(QList<Point> &list)
{
    list.clear();
    for (int i = -sizeOfMapArea.Width(); i <= sizeOfMapArea.Width(); i++)
    {
        for (int j = - sizeOfMapArea.Height(); j <= sizeOfMapArea.Height(); j++)
        {
            Point p = centerTileXYLocation;
            p.setX(p.X() + i);
            p.setY(p.Y() + j);

            if (p.X() >= minOfTiles.Width() && p.Y() >= minOfTiles.Height() && p.X() <= maxOfTiles.Width() && p.Y() <= maxOfTiles.Height())
            {
                if (!list.contains(p))
                {
                    list.append(p);
                }
            }
        }
    }
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::UpdateGroundResolution()
{
    double res  = Projection()->GetGroundResolution(Zoom(), CurrentPosition().Lat());
    pxRes100m   = (int) (100.0 / res);
    pxRes1000m  = (int) (1000.0 / res);
    pxRes10km   = (int) (10000.0 / res);
    pxRes100km  = (int) (100000.0 /res);
    pxRes1000km = (int) (1000000.0 / res);
    pxres5000km = (int) (5000000.0 / res);
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
NetDiagnostics Core::GetDiagnostics()
{
    MrunningThreads.lock();
    //
    diag.runningThreads = runningThreads;
    MrunningThreads.unlock();
    return diag;
}
/********************************************************************************
* @version   1.0
* @parameter
* @Function:
* @return
*******************************************************************************/
void Core::GoToCurrentPositionOnZoom()
{
    renderOffset = Point::Empty;
    centerTileXYLocationLast = Point::Empty;
    dragPoint = Point::Empty;

    if (MouseWheelZooming)
    {
        if (mousewheelzoomtype != MouseWheelZoomType::MousePositionWithoutCenter)
        {
            Point pt = Point(-(GetcurrentPositionGPixel().X() - Width / 2), -(GetcurrentPositionGPixel().Y() - Height / 2));
            renderOffset.setX(pt.X() - dragPoint.X());
            renderOffset.setY(pt.Y() - dragPoint.Y());
        }
        else
        {
            renderOffset.setX(-GetcurrentPositionGPixel().X() - dragPoint.X());
            renderOffset.setY(-GetcurrentPositionGPixel().Y() - dragPoint.Y());
            renderOffset.offset(mouseLastZoom);
        }
    }
    else
    {
        mouseLastZoom = Point::Empty;
        Point pt = Point(-(GetcurrentPositionGPixel().X() - Width / 2), -(GetcurrentPositionGPixel().Y() - Height / 2));
        renderOffset.setX(pt.X() - dragPoint.X());
        renderOffset.setY(pt.Y() - dragPoint.Y());
    }
    UpdateCenterTileXYLocation();
}


}


