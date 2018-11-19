/*
 * class for the world clock widget
 */
#include "worldclock.h"
using namespace std;
/*
 * function to display 12 hour times for different cities
 */
void WorldClock::displayTimes12Hour() {
    QDateTime utcTime = QDateTime::currentDateTime().toUTC();
    cout << "Current time in UTC: " << utcTime.toString().toStdString() << endl;
    cout << "Current time in New York City, NY: " << utcTime.addSecs(-18000).toString("h:mm:ss").toStdString() << endl;
    cout << "Current time in Los Angeles, California: " << utcTime.addSecs(-28800).toString("h:mm:ss").toStdString() << endl;
    cout << "Current time in Dubai, UAE: " << utcTime.addSecs(14400).toString("h:mm:ss").toStdString() << endl;
    cout << "Current time in Beijing, China: " << utcTime.addSecs(28800).toString("h:mm:ss").toStdString() << endl;
    cout << "Current time in Tokyo, Japan: " << utcTime.addSecs(32400).toString("h:mm:ss").toStdString() << endl;
}
/*
 * function to display 24 hour times for different cities
 */
void WorldClock::displayTimes24Hour() {
    QDateTime utcTime = QDateTime::currentDateTime().toUTC();
    cout << "Current time in UTC: " << utcTime.toString().toStdString() << endl;
    cout << "Current time in New York City, NY: " << utcTime.addSecs(-18000).toString("H:mm:ss").toStdString() << endl;
    cout << "Current time in Los Angeles, California: " << utcTime.addSecs(-28800).toString("H:mm:ss").toStdString() << endl;
    cout << "Current time in Dubai, UAE: " << utcTime.addSecs(14400).toString("H:mm:ss").toStdString() << endl;
    cout << "Current time in Beijing, China: " << utcTime.addSecs(28800).toString("H:mm:ss").toStdString() << endl;
    cout << "Current time in Tokyo, Japan: " << utcTime.addSecs(32400).toString("H:mm:ss").toStdString() << endl;
}
/*
 * fucntion to run the clock
 */
void WorldClock::exec()
{
    displayTimes12Hour();
    displayTimes24Hour();
}

