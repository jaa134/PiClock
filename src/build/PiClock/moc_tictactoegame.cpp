/****************************************************************************
** Meta object code from reading C++ file 'tictactoegame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../App/PiClock/alarmPage/tictactoegame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tictactoegame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TicTacToeGame_t {
    QByteArrayData data[15];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TicTacToeGame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TicTacToeGame_t qt_meta_stringdata_TicTacToeGame = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TicTacToeGame"
QT_MOC_LITERAL(1, 14, 13), // "pointsUpdated"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "gameOver"
QT_MOC_LITERAL(4, 38, 10), // "onButton00"
QT_MOC_LITERAL(5, 49, 10), // "onButton01"
QT_MOC_LITERAL(6, 60, 10), // "onButton02"
QT_MOC_LITERAL(7, 71, 10), // "onButton10"
QT_MOC_LITERAL(8, 82, 10), // "onButton11"
QT_MOC_LITERAL(9, 93, 10), // "onButton12"
QT_MOC_LITERAL(10, 104, 10), // "onButton20"
QT_MOC_LITERAL(11, 115, 10), // "onButton21"
QT_MOC_LITERAL(12, 126, 10), // "onButton22"
QT_MOC_LITERAL(13, 137, 19), // "requestComputerMove"
QT_MOC_LITERAL(14, 157, 19) // "requestNewGameBoard"

    },
    "TicTacToeGame\0pointsUpdated\0\0gameOver\0"
    "onButton00\0onButton01\0onButton02\0"
    "onButton10\0onButton11\0onButton12\0"
    "onButton20\0onButton21\0onButton22\0"
    "requestComputerMove\0requestNewGameBoard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TicTacToeGame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   83,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TicTacToeGame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TicTacToeGame *_t = static_cast<TicTacToeGame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointsUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->gameOver(); break;
        case 2: _t->onButton00(); break;
        case 3: _t->onButton01(); break;
        case 4: _t->onButton02(); break;
        case 5: _t->onButton10(); break;
        case 6: _t->onButton11(); break;
        case 7: _t->onButton12(); break;
        case 8: _t->onButton20(); break;
        case 9: _t->onButton21(); break;
        case 10: _t->onButton22(); break;
        case 11: _t->requestComputerMove(); break;
        case 12: _t->requestNewGameBoard(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TicTacToeGame::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToeGame::pointsUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TicTacToeGame::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TicTacToeGame::gameOver)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TicTacToeGame::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TicTacToeGame.data,
    qt_meta_data_TicTacToeGame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TicTacToeGame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TicTacToeGame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TicTacToeGame.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TicTacToeGame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TicTacToeGame::pointsUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TicTacToeGame::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
