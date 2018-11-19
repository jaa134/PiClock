import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:00am"), 67, 14, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:10am"), 114, 24, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.alarmsAlarmGameEditQComboBox), 124, 23, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmGameEditQComboBox, "Tic Tac Toe"), 114, 15, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.alarmsAlarmDifficultyEditQComboBox), 60, 21, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmDifficultyEditQComboBox, "Medium"), 53, 21, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:40am"), 73, 2, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.qtTabwidgetStackedwidgetAlarmsQWidget), 252, 95, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
}
