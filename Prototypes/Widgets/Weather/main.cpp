#include <QCoreApplication>
#include "weather.h"

/*
 * Main function that runs the trivia game.
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Weather w;
    w.getWeather();

    return a.exec();
}
