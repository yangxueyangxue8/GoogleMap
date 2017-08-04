#ifndef LOADTASK_H
#define LOADTASK_H
#include "../mapcore/Point.h"
namespace cowisinternals {
class LoadTask
{
    friend bool operator ==(LoadTask const& lhs, LoadTask const& rhs);
public:
    cowiscore::Point Pos;
    int Zoom;
    
    LoadTask()
    {
        Pos = cowiscore::Point(-1, -1);
        Zoom = -1;
        
    }
    
    LoadTask(cowiscore::Point pos, int zoom)
    {
        Pos = pos;
        Zoom = zoom;
        
    }
    bool HasValue()
    {
        return !(Zoom == -1);
    }
    
    QString ToString()
    {
        return QString::number(Zoom) + "-" + Pos.toString();
    }
};
}


#endif // LOADTASK_H
