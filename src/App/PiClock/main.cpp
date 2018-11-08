#include "piclockapp.h"
#include "managers/databasemanager.h"
#include "QApplication"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager::initDb();

    PiClockApp w;
    w.show();
    w.init();

    return a.exec();
}
