import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    mouseClick(waitForObject(names.generalClockTimeFormatOptionsQComboBox), 244, 20, Qt.NoModifier, Qt.LeftButton);
    mouseClick(waitForObjectItem(names.generalClockTimeFormatOptionsQComboBox, "12 Hour (5:00pm)"), 228, 36, Qt.NoModifier, Qt.LeftButton);
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
    sendEvent("QCloseEvent", waitForObject(names.piClockAppPiClockApp));
}
