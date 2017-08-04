/******************************************************************************
* @brief get map layer
* @author Xue yang
* @date   2017/07/15
******************************************************************************/
#ifndef ALLLAYERSOFTYPE_H
#define ALLLAYERSOFTYPE_H
#include "Maptype.h"
#include <QVector>

namespace cowiscore {
class AllLayersOfType
{
public:
    AllLayersOfType();
    QVector<Maptype::Types> GetAllLayersOfType(const Maptype::Types &type);
};
}


#endif // ALLLAYERSOFTYPE_H
