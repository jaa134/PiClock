#include "QtTest/QTest"
#include "QDebug"
#include "games/mathgameservicetests.h"
#include "games/tictactoegameservicetests.h"
#include "managers/alarmmanagertests.h"
#include "managers/settingsmanagertests.h"
#include "managers/widgetmanagertests.h"
#include "managers/databasemanagertests.h"
#include "models/alarmtests.h"

bool runTest(TestStub *testStub) {
    return QTest::qExec(testStub, 0, nullptr);
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    int testingStatus = 0;

    //games
    MathGameServiceTests mathGameServiceTests;
    testingStatus |= runTest(&mathGameServiceTests);
    TicTacToeGameServiceTests ticTacToeGameServiceTests;
    testingStatus |= runTest(&ticTacToeGameServiceTests);

    //managers
    AlarmManagerTests alarmManagerTests;
    testingStatus |= runTest(&alarmManagerTests);
    SettingsManagerTests settingsManagerTests;
    testingStatus |= runTest(&settingsManagerTests);
    WidgetManagerTests widgetManagerTests;
    testingStatus |= runTest(&widgetManagerTests);
    DatabaseManagerTests databaseManagerTests;
    testingStatus |= runTest(&databaseManagerTests);

    //models
    AlarmTests alarmTests;
    testingStatus |= runTest(&alarmTests);

    return testingStatus;
}

