import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    mouseClick(waitForObject(names.generalClockTimeFormatOptionsQComboBox), 202, 12, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.generalClockTimeFormatOptionsQComboBox, "24 Hour (17:00)"), 178, 18, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
    clickButton(waitForObject(names.layoutMainButtonQPushButton));
}
