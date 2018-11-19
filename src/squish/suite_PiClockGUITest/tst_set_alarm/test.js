import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    mouseClick(waitForObject(names.layoutTimeQLabel), 211, 71, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:40am"), 57, 11, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
