#include <QCoreApplication>
#include "worldclock.h"

/*
 * Main function that runs the trivia game.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WorldClock wc;
    wc.exec();

    return a.exec();
}
