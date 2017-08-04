#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QBrush>
#include <QString>
#include <QPen>
#include <QFont>
#include "../mapcore/accessmode.h"
namespace mapcontrol {
class Configuration
{
public:
    Configuration();

    QBrush  EmptytileBrush;      //Used to draw empty map tiles

    QString EmptyTileText;       //Used for empty tiles text

    QPen    EmptyTileBorders;    //Used to draw empty tile borders

    QPen    ScalePen;            //Used to Draw the maps scale

    QPen    SelectionPen;        //Used to draw selection box

    QFont   MissingDataFont;     //

    Qt::MouseButton DragButton;  //Button used for dragging


    void SetAccessMode(cowiscore::AccessMode::Types const& type);

    cowiscore::AccessMode::Types AccessMode();


};
}


#endif // CONFIGURATION_H
