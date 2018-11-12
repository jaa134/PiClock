#include "guitest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    guiTest w;
    w.show();

    return a.exec();
}
