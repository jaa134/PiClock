#include "piclockapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PiClockApp w;
    w.show();
    w.init();

    return a.exec();
}
