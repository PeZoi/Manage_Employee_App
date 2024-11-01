/****************************************************************************
** Meta object code from reading C++ file 'ManageEmployeeController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ManageEmployeeController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageEmployeeController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageEmployeeController_t {
    QByteArrayData data[25];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageEmployeeController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageEmployeeController_t qt_meta_stringdata_ManageEmployeeController = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ManageEmployeeController"
QT_MOC_LITERAL(1, 25, 17), // "handleRenderTable"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 10), // "onClickAdd"
QT_MOC_LITERAL(4, 55, 11), // "onClickEdit"
QT_MOC_LITERAL(5, 67, 13), // "onClickDelete"
QT_MOC_LITERAL(6, 81, 19), // "handleToggleEnabled"
QT_MOC_LITERAL(7, 101, 2), // "id"
QT_MOC_LITERAL(8, 104, 7), // "checked"
QT_MOC_LITERAL(9, 112, 18), // "handleUploadAvatar"
QT_MOC_LITERAL(10, 131, 19), // "DialogFormEmployee*"
QT_MOC_LITERAL(11, 151, 12), // "employeeForm"
QT_MOC_LITERAL(12, 164, 19), // "isEditMode_employee"
QT_MOC_LITERAL(13, 184, 17), // "renderDepartments"
QT_MOC_LITERAL(14, 202, 27), // "Ui::DialogFormEmployeeClass"
QT_MOC_LITERAL(15, 230, 14), // "submitEmployee"
QT_MOC_LITERAL(16, 245, 13), // "EmployeeModel"
QT_MOC_LITERAL(17, 259, 8), // "employee"
QT_MOC_LITERAL(18, 268, 10), // "isEditMode"
QT_MOC_LITERAL(19, 279, 12), // "employeeView"
QT_MOC_LITERAL(20, 292, 16), // "handleRowClicked"
QT_MOC_LITERAL(21, 309, 11), // "QModelIndex"
QT_MOC_LITERAL(22, 321, 5), // "index"
QT_MOC_LITERAL(23, 327, 9), // "getMeView"
QT_MOC_LITERAL(24, 337, 15) // "ManageEmployee*"

    },
    "ManageEmployeeController\0handleRenderTable\0"
    "\0onClickAdd\0onClickEdit\0onClickDelete\0"
    "handleToggleEnabled\0id\0checked\0"
    "handleUploadAvatar\0DialogFormEmployee*\0"
    "employeeForm\0isEditMode_employee\0"
    "renderDepartments\0Ui::DialogFormEmployeeClass\0"
    "submitEmployee\0EmployeeModel\0employee\0"
    "isEditMode\0employeeView\0handleRowClicked\0"
    "QModelIndex\0index\0getMeView\0ManageEmployee*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageEmployeeController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    2,   68,    2, 0x0a /* Public */,
       9,    2,   73,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      15,    3,   81,    2, 0x0a /* Public */,
      20,    1,   88,    2, 0x0a /* Public */,
      23,    0,   91,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Bool,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   11,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Bool, 0x80000000 | 10,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    0x80000000 | 24,

       0        // eod
};

void ManageEmployeeController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageEmployeeController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleRenderTable(); break;
        case 1: _t->onClickAdd(); break;
        case 2: _t->onClickEdit(); break;
        case 3: _t->onClickDelete(); break;
        case 4: _t->handleToggleEnabled((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->handleUploadAvatar((*reinterpret_cast< DialogFormEmployee*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->renderDepartments((*reinterpret_cast< Ui::DialogFormEmployeeClass(*)>(_a[1]))); break;
        case 7: _t->submitEmployee((*reinterpret_cast< const EmployeeModel(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< DialogFormEmployee*(*)>(_a[3]))); break;
        case 8: _t->handleRowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: { ManageEmployee* _r = _t->getMeView();
            if (_a[0]) *reinterpret_cast< ManageEmployee**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormEmployee* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormEmployee* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageEmployeeController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ManageEmployeeController.data,
    qt_meta_data_ManageEmployeeController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageEmployeeController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageEmployeeController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageEmployeeController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ManageEmployeeController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
