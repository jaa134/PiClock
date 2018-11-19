import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
    mouseClick(waitForObject(names.alarmsAlarmDifficultyEditQComboBox), 94, 8, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmDifficultyEditQComboBox, "Hard"), 87, 12, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.alarmsAlarmGameEditQComboBox), 116, 19, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmGameEditQComboBox, "Tic Tac Toe"), 111, 5, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:30am"), 91, 22, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
