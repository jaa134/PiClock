import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    scrollTo(waitForObject(names.generalSlideDurationSliderQSlider), 10);
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
