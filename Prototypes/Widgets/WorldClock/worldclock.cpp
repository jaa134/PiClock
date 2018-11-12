#include "worldclock.h"
#include "QTimeZone"

using namespace std;

void WorldClock::displayTimes(QString format) {
    QDateTime dt = QDateTime::currentDateTimeUtc();

    if (format == HOURFORMAT12)
        cout << "12 hour format:" << endl;
    if (format == HOURFORMAT24)
        cout << "24 hour format:" << endl;

    int secsInHour = 3600;
    cout << "Los Angeles: " << dt.addSecs(PST * secsInHour).toString(format).toStdString() << endl;
    cout << "New York City: " << dt.addSecs(EST * secsInHour).toString(format).toStdString() << endl;
    cout << "Beijing: " << dt.addSecs(CCT * secsInHour).toString(format).toStdString() << endl;
    cout << "London: " << dt.addSecs(UTC * secsInHour).toString(format).toStdString() << endl;
    cout << "Tokyo: " << dt.addSecs(TOK * secsInHour).toString(format).toStdString() << endl;
    cout << "Dubai: " << dt.addSecs(DUB * secsInHour).toString(format).toStdString() << endl;
    cout << endl;
}

void WorldClock::exec()
{
    displayTimes(HOURFORMAT12);
    displayTimes(HOURFORMAT24);
}
