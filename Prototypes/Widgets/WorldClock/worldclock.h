#ifndef WORLDCLOCK_H
#define WORLDCLOCK_H

#include "iostream"
#include "QString"
#include "QDateTime"

#define DUB (+4)
#define UTC (0)
#define EST (-5)
#define PST (-8)
#define CCT (+8)
#define MST (-7)
#define TOK (+9)

#define HOURFORMAT12 "h:mmap"
#define HOURFORMAT24 "HH:mm"

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
    void displayTimes(QString);
};

#endif // WORLDCLOCK_H




