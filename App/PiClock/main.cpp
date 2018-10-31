#include "piclockapp.h"
#include "models/alarm.h"
#include "QApplication"

int main(int argc, char *argv[])
{
    qRegisterMetaType<Alarm::Data>("Alarm::Data");
    qRegisterMetaTypeStreamOperators<Alarm::Data>("Alarm::Data");
    qRegisterMetaTypeStreamOperators<QList<Alarm::Data>>("QList<Alarm::Data>");
    QApplication a(argc, argv);
    PiClockApp w;
    w.show();
    w.init();

    return a.exec();
}
