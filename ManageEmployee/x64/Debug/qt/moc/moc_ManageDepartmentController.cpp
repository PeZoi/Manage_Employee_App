/****************************************************************************
** Meta object code from reading C++ file 'ManageDepartmentController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ManageDepartmentController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageDepartmentController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageDepartmentController_t {
    QByteArrayData data[17];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageDepartmentController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageDepartmentController_t qt_meta_stringdata_ManageDepartmentController = {
    {
QT_MOC_LITERAL(0, 0, 26), // "ManageDepartmentController"
QT_MOC_LITERAL(1, 27, 17), // "handleRenderTable"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 10), // "onClickAdd"
QT_MOC_LITERAL(4, 57, 11), // "onClickEdit"
QT_MOC_LITERAL(5, 69, 13), // "onClickDelete"
QT_MOC_LITERAL(6, 83, 16), // "submitDepartment"
QT_MOC_LITERAL(7, 100, 15), // "DepartmentModel"
QT_MOC_LITERAL(8, 116, 10), // "department"
QT_MOC_LITERAL(9, 127, 10), // "isEditMode"
QT_MOC_LITERAL(10, 138, 21), // "DialogFormDepartment*"
QT_MOC_LITERAL(11, 160, 14), // "departmentView"
QT_MOC_LITERAL(12, 175, 16), // "handleRowClicked"
QT_MOC_LITERAL(13, 192, 11), // "QModelIndex"
QT_MOC_LITERAL(14, 204, 5), // "index"
QT_MOC_LITERAL(15, 210, 9), // "getMdView"
QT_MOC_LITERAL(16, 220, 17) // "ManageDepartment*"

    },
    "ManageDepartmentController\0handleRenderTable\0"
    "\0onClickAdd\0onClickEdit\0onClickDelete\0"
    "submitDepartment\0DepartmentModel\0"
    "department\0isEditMode\0DialogFormDepartment*\0"
    "departmentView\0handleRowClicked\0"
    "QModelIndex\0index\0getMdView\0"
    "ManageDepartment*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageDepartmentController[] = {

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
       5,    0,   52,    2, 0x0a /* Public */,
       6,    3,   53,    2, 0x0a /* Public */,
      12,    1,   60,    2, 0x0a /* Public */,
      15,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Bool, 0x80000000 | 10,    8,    9,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    0x80000000 | 16,

       0        // eod
};

void ManageDepartmentController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageDepartmentController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleRenderTable(); break;
        case 1: _t->onClickAdd(); break;
        case 2: _t->onClickEdit(); break;
        case 3: _t->onClickDelete(); break;
        case 4: _t->submitDepartment((*reinterpret_cast< const DepartmentModel(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< DialogFormDepartment*(*)>(_a[3]))); break;
        case 5: _t->handleRowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: { ManageDepartment* _r = _t->getMdView();
            if (_a[0]) *reinterpret_cast< ManageDepartment**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormDepartment* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageDepartmentController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ManageDepartmentController.data,
    qt_meta_data_ManageDepartmentController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageDepartmentController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageDepartmentController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageDepartmentController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ManageDepartmentController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
