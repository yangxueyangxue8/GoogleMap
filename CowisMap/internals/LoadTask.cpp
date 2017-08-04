#include "LoadTask.h"
namespace cowisinternals {


bool operator ==(const LoadTask &lhs, const LoadTask &rhs)
{
    return ((lhs.Pos == rhs.Pos) && (lhs.Zoom == rhs.Zoom));
}

}

