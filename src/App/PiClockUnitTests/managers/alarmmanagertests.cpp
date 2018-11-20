#include "alarmmanagertests.h"
#include "QTest"
#include "managers/alarmmanager.h"
#include "managers/settingsmanager.h"
#include "models/alarm.h"

void AlarmManagerTests::Test() {
    AlarmManager *a = new AlarmManager();
    delete a;
}
