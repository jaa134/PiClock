#include "piclockapp.h"
#include "managers/databasemanager.h"
#include "QApplication"
#include "QScreen"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager::initDb();

    PiClockApp w;
    w.move(QGuiApplication::primaryScreen()->geometry().center() - w.rect().center());
    w.show();
    w.init();

    return a.exec();
}
