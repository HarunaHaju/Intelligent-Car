/****************************************************************************
** Meta object code from reading C++ file 'carcontroler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../carcontroler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carcontroler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CarControler_t {
    QByteArrayData data[7];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarControler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarControler_t qt_meta_stringdata_CarControler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CarControler"
QT_MOC_LITERAL(1, 13, 7), // "openCam"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "closeCam"
QT_MOC_LITERAL(4, 31, 9), // "readFrame"
QT_MOC_LITERAL(5, 41, 10), // "connectCar"
QT_MOC_LITERAL(6, 52, 13) // "disconnectCar"

    },
    "CarControler\0openCam\0\0closeCam\0readFrame\0"
    "connectCar\0disconnectCar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarControler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CarControler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CarControler *_t = static_cast<CarControler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openCam(); break;
        case 1: _t->closeCam(); break;
        case 2: _t->readFrame(); break;
        case 3: _t->connectCar(); break;
        case 4: _t->disconnectCar(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CarControler::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CarControler.data,
      qt_meta_data_CarControler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CarControler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarControler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CarControler.stringdata0))
        return static_cast<void*>(const_cast< CarControler*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CarControler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
