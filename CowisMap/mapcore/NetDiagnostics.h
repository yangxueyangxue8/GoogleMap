#ifndef NETDIAGNOSTICS_H
#define NETDIAGNOSTICS_H
#include <QString>
class NetDiagnostics
{
public:
    NetDiagnostics();
    int networkerrors;
    int emptytitles;
    int timeouts;
    int runningThreads;
    int titlesFromMem;
    int titlesFromNet;
    int titlesFromDB;
    QString toString()
    {
        return QString("Network errors:%1\nEmpty titles:%2\nTimeOuts:%3\nRunningThreads:%4\nTitlesFromMem:%5\nTitlesFromNet:%6\nTitlesFromDB:%7").arg(networkerrors).arg(emptytitles).arg(timeouts).arg(runningThreads).arg(titlesFromMem).arg(titlesFromNet).arg(titlesFromDB);
    }
};

#endif // NETDIAGNOSTICS_H
