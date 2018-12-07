import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
   clickButton(waitForObject(names.alarmListRemoveButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
    clickButton(waitForObject(names.alarmListRemoveButtonQPushButton_2));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
