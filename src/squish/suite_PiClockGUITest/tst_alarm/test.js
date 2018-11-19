import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:30am"), 103, 22, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsCancelButtonQPushButton));
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "1:00am"), 75, 20, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
    clickButton(waitForObject(names.alarmListRemoveButtonQPushButton_2));
    clickButton(waitForObject(names.layoutSettingsCancelButtonQPushButton));
    clickButton(waitForObject(names.alarmListRemoveButtonQPushButton_2));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
