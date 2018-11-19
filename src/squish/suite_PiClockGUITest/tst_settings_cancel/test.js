import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    mouseClick(waitForObject(names.generalClockTimeFormatOptionsQComboBox), 233, 29, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.generalClockTimeFormatOptionsQComboBox, "24 Hour (17:00)"), 226, 11, Qt.NoModifier, Qt.LeftButton);
    doubleClick(waitForObject(names.layoutSettingsCancelButtonQPushButton), 72, 20, Qt.NoModifier, Qt.LeftButton);
    scrollTo(waitForObject(names.generalSlideDurationSliderQSlider), 30);
    clickButton(waitForObject(names.layoutSettingsCancelButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Alarms");
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:20am"), 103, 9, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    mouseClick(waitForObjectItem(names.alarmsAlarmTimeOptionsDragListWidget, "12:40am"), 18, 3, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.alarmsAlarmGameEditQComboBox), 26, 33, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmGameEditQComboBox, "Tic Tac Toe"), 30, 29, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObject(names.alarmsAlarmDifficultyEditQComboBox), 44, 15, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.alarmsAlarmDifficultyEditQComboBox, "Medium"), 46, 8, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.alarmsAlarmSetButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsCancelButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Widgets");
    clickButton(waitForObject(names.widgetsForecastCheckboxQCheckBox));
    clickButton(waitForObject(names.widgetsQuotesCheckboxQCheckBox));
    clickButton(waitForObject(names.widgetsWclockCheckboxQCheckBox));
    clickButton(waitForObject(names.layoutSettingsCancelButtonQPushButton));
}
