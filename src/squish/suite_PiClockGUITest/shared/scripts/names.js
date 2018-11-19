import { RegularExpression, Wildcard } from 'objectmaphelper.js';

export var piClockAppPiClockApp = {"name": "PiClockApp", "type": "PiClockApp", "visible": 1};
export var piClockAppLayoutQStackedWidget = {"name": "layout", "type": "QStackedWidget", "visible": 1, "window": piClockAppPiClockApp};
export var layoutSettingsButtonQPushButton = {"container": piClockAppLayoutQStackedWidget, "name": "settingsButton", "type": "QPushButton", "visible": 1};
export var layoutOptionsQTabWidget = {"container": piClockAppLayoutQStackedWidget, "name": "options", "type": "QTabWidget", "visible": 1};
export var layoutQtTabwidgetStackedwidgetQStackedWidget = {"container": piClockAppLayoutQStackedWidget, "name": "qt_tabwidget_stackedwidget", "type": "QStackedWidget", "visible": 1};
export var qtTabwidgetStackedwidgetAlarmsQWidget = {"container": layoutQtTabwidgetStackedwidgetQStackedWidget, "name": "alarms", "type": "QWidget", "visible": 1};
export var alarmsAlarmGameEditQComboBox = {"container": qtTabwidgetStackedwidgetAlarmsQWidget, "name": "alarmGameEdit", "type": "QComboBox", "visible": 1};
export var layoutSettingsSaveButtonQPushButton = {"container": piClockAppLayoutQStackedWidget, "name": "settingsSaveButton", "type": "QPushButton", "visible": 1};
export var alarmsAlarmListDragListWidget = {"container": qtTabwidgetStackedwidgetAlarmsQWidget, "name": "alarmList", "type": "DragListWidget", "visible": 1};
export var alarmsAlarmTimeOptionsDragListWidget = {"container": qtTabwidgetStackedwidgetAlarmsQWidget, "name": "alarmTimeOptions", "type": "DragListWidget", "visible": 1};
export var alarmsAlarmSetButtonQPushButton = {"container": qtTabwidgetStackedwidgetAlarmsQWidget, "name": "alarmSetButton", "type": "QPushButton", "visible": 1};
export var alarmListRemoveButtonQPushButton = {"container": alarmsAlarmListDragListWidget, "name": "removeButton", "occurrence": 2, "type": "QPushButton", "visible": 1};
export var alarmListRemoveButtonQPushButton_2 = {"container": alarmsAlarmListDragListWidget, "name": "removeButton", "type": "QPushButton", "visible": 1};
export var layoutSettingsCancelButtonQPushButton = {"container": piClockAppLayoutQStackedWidget, "name": "settingsCancelButton", "type": "QPushButton", "visible": 1};
