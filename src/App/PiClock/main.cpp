#include "piclockapp.h"
#include "managers/databasemanager.h"
#include "models/alarm.h"
#include "QApplication"
#include "QtDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager::initDb();

    PiClockApp w;
    w.show();
    w.init();

    return a.exec();
}
