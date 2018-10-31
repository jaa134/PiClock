#include "QtTest/QTest"
#include "QDebug"
#include "applicationtest.h"
#include "managers/alarmmanagertests.h"
#include "managers/settingsmanagertests.h"
#include "managers/widgetmanagertests.h"
#include "models/alarmtests.h"

bool runTest(QObject *testObject) {
    return QTest::qExec(testObject, 0, nullptr);
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    int testingStatus = 0;

    //app
    ApplicationTest appTest;
    testingStatus |= runTest(&appTest);

    //managers
    AlarmManagerTests alarmManagerTests;
    testingStatus |= runTest(&alarmManagerTests);
    SettingsManagerTests settingsManagerTests;
    testingStatus |= runTest(&settingsManagerTests);
    WidgetManagerTests widgetManagerTests;
    testingStatus |= runTest(&widgetManagerTests);

    //models
    AlarmTests alarmTests;
    testingStatus |= runTest(&alarmTests);

    //widgets

    //games

    return testingStatus;
}

