/****************************************************************************
** Meta object code from reading C++ file 'alarmmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../App/PiClockLib/managers/alarmmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarmmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlarmManager_t {
    QByteArrayData data[8];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlarmManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlarmManager_t qt_meta_stringdata_AlarmManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AlarmManager"
QT_MOC_LITERAL(1, 13, 12), // "alarmStarted"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "Game::Type"
QT_MOC_LITERAL(4, 38, 16), // "Game::Difficulty"
QT_MOC_LITERAL(5, 55, 12), // "alarmStopped"
QT_MOC_LITERAL(6, 68, 9), // "stopAlarm"
QT_MOC_LITERAL(7, 78, 10) // "startAlarm"

    },
    "AlarmManager\0alarmStarted\0\0Game::Type\0"
    "Game::Difficulty\0alarmStopped\0stopAlarm\0"
    "startAlarm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlarmManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   40,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AlarmManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlarmManager *_t = static_cast<AlarmManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->alarmStarted((*reinterpret_cast< Game::Type(*)>(_a[1])),(*reinterpret_cast< Game::Difficulty(*)>(_a[2]))); break;
        case 1: _t->alarmStopped(); break;
        case 2: _t->stopAlarm(); break;
        case 3: _t->startAlarm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AlarmManager::*)(Game::Type , Game::Difficulty );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlarmManager::alarmStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AlarmManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlarmManager::alarmStopped)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AlarmManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AlarmManager.data,
    qt_meta_data_AlarmManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AlarmManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlarmManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlarmManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AlarmManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AlarmManager::alarmStarted(Game::Type _t1, Game::Difficulty _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlarmManager::alarmStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
