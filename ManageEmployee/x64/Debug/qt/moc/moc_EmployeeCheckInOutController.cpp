/****************************************************************************
** Meta object code from reading C++ file 'EmployeeCheckInOutController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../EmployeeCheckInOutController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EmployeeCheckInOutController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EmployeeCheckInOutController_t {
    QByteArrayData data[19];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmployeeCheckInOutController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmployeeCheckInOutController_t qt_meta_stringdata_EmployeeCheckInOutController = {
    {
QT_MOC_LITERAL(0, 0, 28), // "EmployeeCheckInOutController"
QT_MOC_LITERAL(1, 29, 18), // "setupRealTimeClock"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 14), // "updateDateTime"
QT_MOC_LITERAL(4, 64, 14), // "onClickShowAll"
QT_MOC_LITERAL(5, 79, 20), // "handleSelectEmployee"
QT_MOC_LITERAL(6, 100, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 112, 5), // "index"
QT_MOC_LITERAL(8, 118, 27), // "handleSelectEmployeeByCombo"
QT_MOC_LITERAL(9, 146, 4), // "name"
QT_MOC_LITERAL(10, 151, 12), // "loadEmployee"
QT_MOC_LITERAL(11, 164, 23), // "handleSubmitForPassword"
QT_MOC_LITERAL(12, 188, 16), // "processStreaming"
QT_MOC_LITERAL(13, 205, 11), // "updateFrame"
QT_MOC_LITERAL(14, 217, 20), // "const unsigned char*"
QT_MOC_LITERAL(15, 238, 9), // "imageData"
QT_MOC_LITERAL(16, 248, 8), // "imageLen"
QT_MOC_LITERAL(17, 257, 10), // "imageWidth"
QT_MOC_LITERAL(18, 268, 11) // "imageHeight"

    },
    "EmployeeCheckInOutController\0"
    "setupRealTimeClock\0\0updateDateTime\0"
    "onClickShowAll\0handleSelectEmployee\0"
    "QModelIndex\0index\0handleSelectEmployeeByCombo\0"
    "name\0loadEmployee\0handleSubmitForPassword\0"
    "processStreaming\0updateFrame\0"
    "const unsigned char*\0imageData\0imageLen\0"
    "imageWidth\0imageHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmployeeCheckInOutController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,
      12,    0,   70,    2, 0x0a /* Public */,
      13,    4,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,

       0        // eod
};

void EmployeeCheckInOutController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EmployeeCheckInOutController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setupRealTimeClock(); break;
        case 1: _t->updateDateTime(); break;
        case 2: _t->onClickShowAll(); break;
        case 3: _t->handleSelectEmployee((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->handleSelectEmployeeByCombo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->loadEmployee(); break;
        case 6: _t->handleSubmitForPassword(); break;
        case 7: _t->processStreaming(); break;
        case 8: _t->updateFrame((*reinterpret_cast< const unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EmployeeCheckInOutController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EmployeeCheckInOutController.data,
    qt_meta_data_EmployeeCheckInOutController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EmployeeCheckInOutController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmployeeCheckInOutController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeeCheckInOutController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EmployeeCheckInOutController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
