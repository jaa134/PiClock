/****************************************************************************
** Meta object code from reading C++ file 'alarm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../App/PiClock/alarmPage/alarm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'alarm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Alarm_t {
    QByteArrayData data[11];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Alarm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Alarm_t qt_meta_stringdata_Alarm = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Alarm"
QT_MOC_LITERAL(1, 6, 8), // "GameType"
QT_MOC_LITERAL(2, 15, 9), // "TicTacToe"
QT_MOC_LITERAL(3, 25, 13), // "Concentration"
QT_MOC_LITERAL(4, 39, 4), // "Math"
QT_MOC_LITERAL(5, 44, 6), // "Trivia"
QT_MOC_LITERAL(6, 51, 5), // "Simon"
QT_MOC_LITERAL(7, 57, 14), // "GameDifficulty"
QT_MOC_LITERAL(8, 72, 4), // "Easy"
QT_MOC_LITERAL(9, 77, 6), // "Medium"
QT_MOC_LITERAL(10, 84, 4) // "Hard"

    },
    "Alarm\0GameType\0TicTacToe\0Concentration\0"
    "Math\0Trivia\0Simon\0GameDifficulty\0Easy\0"
    "Medium\0Hard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Alarm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    5,   22,
       7, 0x0,    3,   32,

 // enum data: key, value
       2, uint(Alarm::TicTacToe),
       3, uint(Alarm::Concentration),
       4, uint(Alarm::Math),
       5, uint(Alarm::Trivia),
       6, uint(Alarm::Simon),
       8, uint(Alarm::Easy),
       9, uint(Alarm::Medium),
      10, uint(Alarm::Hard),

       0        // eod
};

void Alarm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Alarm::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Alarm.data,
      qt_meta_data_Alarm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Alarm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Alarm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Alarm.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Alarm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
