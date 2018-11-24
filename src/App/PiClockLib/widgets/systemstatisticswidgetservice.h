#ifndef SYSTEMSTATISTICSWIDGETSERVICE_H
#define SYSTEMSTATISTICSWIDGETSERVICE_H

#include "widgetservice.h"
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "QStorageInfo"
#include "QTextStream"

class SystemStatisticsWidgetService : public WidgetService
{
public:
    int cpuUsage;
    int memoryUsage;
    int discUsage;
    int networkUsage;
    SystemStatisticsWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    int getCpuUsage();
    int getMemoryUsage();
    int getDiscUsage();
    int getNetworkUsage();

    //cpu stats
    unsigned long long lastTotalUser, lastTotalUserLow, lastTotalSys, lastTotalIdle;

    //network stats
    unsigned long long lastBytesUsed;

private slots:
    void update() Q_DECL_OVERRIDE;
};

#endif // SYSTEMSTATISTICSWIDGETSERVICE_H
