/****************************************************************************
** Meta object code from reading C++ file 'alarmpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../App/PiClock/alarmPage/alarmpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlarmPage_t {
    QByteArrayData data[11];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlarmPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlarmPage_t qt_meta_stringdata_AlarmPage = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AlarmPage"
QT_MOC_LITERAL(1, 10, 11), // "chunkLoaded"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "onSettingsSaved"
QT_MOC_LITERAL(4, 39, 9), // "navToMain"
QT_MOC_LITERAL(5, 49, 10), // "navToAlarm"
QT_MOC_LITERAL(6, 60, 10), // "Game::Type"
QT_MOC_LITERAL(7, 71, 16), // "Game::Difficulty"
QT_MOC_LITERAL(8, 88, 10), // "onGameOver"
QT_MOC_LITERAL(9, 99, 17), // "updatePointsLabel"
QT_MOC_LITERAL(10, 117, 19) // "updateRemainingTime"

    },
    "AlarmPage\0chunkLoaded\0\0onSettingsSaved\0"
    "navToMain\0navToAlarm\0Game::Type\0"
    "Game::Difficulty\0onGameOver\0"
    "updatePointsLabel\0updateRemainingTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlarmPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    2,   52,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    1,   58,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 7,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void AlarmPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlarmPage *_t = static_cast<AlarmPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->chunkLoaded(); break;
        case 1: _t->onSettingsSaved(); break;
        case 2: _t->navToMain(); break;
        case 3: _t->navToAlarm((*reinterpret_cast< Game::Type(*)>(_a[1])),(*reinterpret_cast< Game::Difficulty(*)>(_a[2]))); break;
        case 4: _t->onGameOver(); break;
        case 5: _t->updatePointsLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateRemainingTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AlarmPage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlarmPage::chunkLoaded)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AlarmPage::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AlarmPage.data,
    qt_meta_data_AlarmPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AlarmPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlarmPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmPage.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AlarmPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AlarmPage::chunkLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
