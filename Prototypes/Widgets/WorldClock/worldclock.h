#ifndef WORLDCLOCK_H
#define WORLDCLOCK_H

#include <time.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <QDateTime>

#define DUB (+4)
#define UTC (0)
#define EST (-5)
#define PST (-8)
#define CCT (+8)
#define MST (-7)
#define TOK (+9)

/*
 * class for the world clock widget
 */
class WorldClock
{

/*
 * all public global variables and functions
 */
public:
    void exec();
    void displayTimes12Hour();
    void displayTimes24Hour();
};

#endif // WORLDCLOCK_H




