#include "systemstatisticswidgetservice.h"

SystemStatisticsWidgetService::SystemStatisticsWidgetService()
{
    //init cpu stats
    FILE* cpu_file = fopen("/proc/stat", "r");
    fscanf(cpu_file, "cpu %llu %llu %llu %llu", &lastTotalUser, &lastTotalUserLow, &lastTotalSys, &lastTotalIdle);
    fclose(cpu_file);

    //init network stats
    FILE* net_file = fopen("/proc/net/dev", "r");
    fscanf(net_file, "wlo1: %llu", &lastBytesUsed);
    fclose(net_file);

    connect(&updateTimer, &QTimer::timeout, this, &SystemStatisticsWidgetService::update);
    updateTimer.setInterval(500);
}

void SystemStatisticsWidgetService::init() {
    update();
    updateTimer.start();
}

void SystemStatisticsWidgetService::update() {
    cpuUsage = getCpuUsage();
    memoryUsage = getMemoryUsage();
    discUsage = getDiscUsage();
    networkUsage = getNetworkUsage();
    emit updated();
}

int SystemStatisticsWidgetService::getCpuUsage() {
    double percent;
    unsigned long long totalUser, totalUserLow, totalSys, totalIdle, total;

    FILE *file = fopen("/proc/stat", "r");
    fscanf(file, "cpu %llu %llu %llu %llu", &totalUser, &totalUserLow, &totalSys, &totalIdle);
    fclose(file);

    if (totalUser < lastTotalUser || totalUserLow < lastTotalUserLow ||
        totalSys < lastTotalSys || totalIdle < lastTotalIdle){
        percent = 0.0;
    }
    else{
        total = (totalUser - lastTotalUser) + (totalUserLow - lastTotalUserLow) +
            (totalSys - lastTotalSys);
        percent = total;
        total += (totalIdle - lastTotalIdle);
        percent /= total;
        percent *= 100;
    }

    lastTotalUser = totalUser;
    lastTotalUserLow = totalUserLow;
    lastTotalSys = totalSys;
    lastTotalIdle = totalIdle;

    return percent;
}

int SystemStatisticsWidgetService::getMemoryUsage() {
    struct sysinfo memInfo;
    sysinfo (&memInfo);
    unsigned long totalPhysMem = memInfo.totalram;
    unsigned long physMemUsed = memInfo.totalram - memInfo.freeram;
    return (physMemUsed / 1000.0) / (totalPhysMem / 1000.0) * 100.0;
}

int SystemStatisticsWidgetService::getDiscUsage() {
    QStorageInfo storage = QStorageInfo::root();
    qint64 totalDisc = storage.bytesTotal();
    qint64 discUsed = storage.bytesTotal() - storage.bytesAvailable();
    return (discUsed / 1000.0) / (totalDisc / 1000.0) * 100.0;
}

int SystemStatisticsWidgetService::getNetworkUsage() {
    QFile f("/proc/net/dev");
    f.open(QIODevice::ReadOnly);
    QTextStream ts(&f);
    ts.readLine();
    ts.readLine();
    QString deviceName;
    ts >> deviceName;
    unsigned long totalBytesUsed;
    ts >> totalBytesUsed;
    f.close();

    double percent;
    if (totalBytesUsed < lastBytesUsed)
        percent = 0.0;
    else {
        qint64 rate = (totalBytesUsed - lastBytesUsed) / (updateTimer.interval() / 1000.0); //bps
        int maxBandwidth = 1000000; //bps
        percent = (rate / 1000.0) / (maxBandwidth / 1000.0) * 100.0;
    }

    lastBytesUsed = totalBytesUsed;

    return percent;
}
