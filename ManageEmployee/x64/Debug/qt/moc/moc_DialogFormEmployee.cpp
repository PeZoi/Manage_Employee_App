/****************************************************************************
** Meta object code from reading C++ file 'DialogFormEmployee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../DialogFormEmployee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogFormEmployee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogFormEmployee_t {
    QByteArrayData data[15];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFormEmployee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFormEmployee_t qt_meta_stringdata_DialogFormEmployee = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DialogFormEmployee"
QT_MOC_LITERAL(1, 19, 6), // "submit"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "EmployeeModel"
QT_MOC_LITERAL(4, 41, 8), // "employee"
QT_MOC_LITERAL(5, 50, 10), // "isEditMode"
QT_MOC_LITERAL(6, 61, 19), // "DialogFormEmployee*"
QT_MOC_LITERAL(7, 81, 12), // "employeeView"
QT_MOC_LITERAL(8, 94, 12), // "uploadAvatar"
QT_MOC_LITERAL(9, 107, 12), // "employeeForm"
QT_MOC_LITERAL(10, 120, 19), // "isEditMode_employee"
QT_MOC_LITERAL(11, 140, 12), // "handleSubmit"
QT_MOC_LITERAL(12, 153, 7), // "setMode"
QT_MOC_LITERAL(13, 161, 11), // "_isEditMode"
QT_MOC_LITERAL(14, 173, 8) // "setValue"

    },
    "DialogFormEmployee\0submit\0\0EmployeeModel\0"
    "employee\0isEditMode\0DialogFormEmployee*\0"
    "employeeView\0uploadAvatar\0employeeForm\0"
    "isEditMode_employee\0handleSubmit\0"
    "setMode\0_isEditMode\0setValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFormEmployee[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       8,    2,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   51,    2, 0x0a /* Public */,
      12,    1,   52,    2, 0x0a /* Public */,
      14,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void DialogFormEmployee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogFormEmployee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->submit((*reinterpret_cast< EmployeeModel(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< DialogFormEmployee*(*)>(_a[3]))); break;
        case 1: _t->uploadAvatar((*reinterpret_cast< DialogFormEmployee*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->handleSubmit(); break;
        case 3: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< EmployeeModel(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormEmployee* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormEmployee* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogFormEmployee::*)(EmployeeModel , bool , DialogFormEmployee * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormEmployee::submit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DialogFormEmployee::*)(DialogFormEmployee * , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormEmployee::uploadAvatar)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogFormEmployee::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogFormEmployee.data,
    qt_meta_data_DialogFormEmployee,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogFormEmployee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogFormEmployee::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogFormEmployee.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogFormEmployee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DialogFormEmployee::submit(EmployeeModel _t1, bool _t2, DialogFormEmployee * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DialogFormEmployee::uploadAvatar(DialogFormEmployee * _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE