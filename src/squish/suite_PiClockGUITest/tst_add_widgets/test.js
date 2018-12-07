import * as names from 'names.js';

function main() {
    startApplication("PiClock");
    clickButton(waitForObject(names.layoutSettingsButtonQPushButton));
    clickTab(waitForObject(names.layoutOptionsQTabWidget), "Widgets");
    clickButton(waitForObject(names.widgetsWeatherCheckboxQCheckBox));
    clickButton(waitForObject(names.widgetsForecastCheckboxQCheckBox));
    clickButton(waitForObject(names.widgetsQuotesCheckboxQCheckBox));
    clickButton(waitForObject(names.widgetsWclockCheckboxQCheckBox));
    clickButton(waitForObject(names.layoutSettingsSaveButtonQPushButton));
}
