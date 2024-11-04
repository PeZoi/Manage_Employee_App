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
    QByteArrayData data[12];
    char stringdata0[188];
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
QT_MOC_LITERAL(11, 164, 23) // "handleSubmitForPassword"

    },
    "EmployeeCheckInOutController\0"
    "setupRealTimeClock\0\0updateDateTime\0"
    "onClickShowAll\0handleSelectEmployee\0"
    "QModelIndex\0index\0handleSelectEmployeeByCombo\0"
    "name\0loadEmployee\0handleSubmitForPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmployeeCheckInOutController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
