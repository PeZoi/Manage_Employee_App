/****************************************************************************
** Meta object code from reading C++ file 'ManageAttendanceEventsController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ManageAttendanceEventsController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageAttendanceEventsController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageAttendanceEventsController_t {
    QByteArrayData data[22];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageAttendanceEventsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageAttendanceEventsController_t qt_meta_stringdata_ManageAttendanceEventsController = {
    {
QT_MOC_LITERAL(0, 0, 32), // "ManageAttendanceEventsController"
QT_MOC_LITERAL(1, 33, 10), // "onClickAdd"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 11), // "onClickEdit"
QT_MOC_LITERAL(4, 57, 13), // "onClickDelete"
QT_MOC_LITERAL(5, 71, 14), // "handleCheckout"
QT_MOC_LITERAL(6, 86, 20), // "handleSelectEmployee"
QT_MOC_LITERAL(7, 107, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 119, 5), // "index"
QT_MOC_LITERAL(9, 125, 17), // "handleRenderTable"
QT_MOC_LITERAL(10, 143, 6), // "filter"
QT_MOC_LITERAL(11, 150, 12), // "handleSubmit"
QT_MOC_LITERAL(12, 163, 17), // "_employeeSelected"
QT_MOC_LITERAL(13, 181, 10), // "isEditMode"
QT_MOC_LITERAL(14, 192, 27), // "DialogFormAttendanceEvents*"
QT_MOC_LITERAL(15, 220, 6), // "dialog"
QT_MOC_LITERAL(16, 227, 16), // "handleRowClicked"
QT_MOC_LITERAL(17, 244, 17), // "handleFilterRange"
QT_MOC_LITERAL(18, 262, 5), // "value"
QT_MOC_LITERAL(19, 268, 12), // "filterEvents"
QT_MOC_LITERAL(20, 281, 27), // "QList<AttendanceEventModel>"
QT_MOC_LITERAL(21, 309, 9) // "eventList"

    },
    "ManageAttendanceEventsController\0"
    "onClickAdd\0\0onClickEdit\0onClickDelete\0"
    "handleCheckout\0handleSelectEmployee\0"
    "QModelIndex\0index\0handleRenderTable\0"
    "filter\0handleSubmit\0_employeeSelected\0"
    "isEditMode\0DialogFormAttendanceEvents*\0"
    "dialog\0handleRowClicked\0handleFilterRange\0"
    "value\0filterEvents\0QList<AttendanceEventModel>\0"
    "eventList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageAttendanceEventsController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    1,   73,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x2a /* Public | MethodCloned */,
      11,    3,   80,    2, 0x0a /* Public */,
      16,    1,   87,    2, 0x0a /* Public */,
      17,    1,   90,    2, 0x0a /* Public */,
      19,    2,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, 0x80000000 | 14,   12,   13,   15,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   18,
    0x80000000 | 20, 0x80000000 | 20, QMetaType::QString,   21,   10,

       0        // eod
};

void ManageAttendanceEventsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageAttendanceEventsController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClickAdd(); break;
        case 1: _t->onClickEdit(); break;
        case 2: _t->onClickDelete(); break;
        case 3: _t->handleCheckout(); break;
        case 4: _t->handleSelectEmployee((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->handleRenderTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->handleRenderTable(); break;
        case 7: _t->handleSubmit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< DialogFormAttendanceEvents*(*)>(_a[3]))); break;
        case 8: _t->handleRowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->handleFilterRange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: { QList<AttendanceEventModel> _r = _t->filterEvents((*reinterpret_cast< const QList<AttendanceEventModel>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<AttendanceEventModel>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormAttendanceEvents* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageAttendanceEventsController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ManageAttendanceEventsController.data,
    qt_meta_data_ManageAttendanceEventsController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageAttendanceEventsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageAttendanceEventsController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageAttendanceEventsController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ManageAttendanceEventsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
