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
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFormEmployee_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFormEmployee_t qt_meta_stringdata_DialogFormEmployee = {
    {
QT_MOC_LITERAL(0, 0, 18), // "DialogFormEmployee"
QT_MOC_LITERAL(1, 19, 18), // "excuteDBSuccessful"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 15), // "editModeChanged"
QT_MOC_LITERAL(4, 55, 12), // "handleSubmit"
QT_MOC_LITERAL(5, 68, 7), // "setMode"
QT_MOC_LITERAL(6, 76, 11), // "_isEditMode"
QT_MOC_LITERAL(7, 88, 8), // "setValue"
QT_MOC_LITERAL(8, 97, 9), // "QSqlQuery"
QT_MOC_LITERAL(9, 107, 6), // "result"
QT_MOC_LITERAL(10, 114, 14), // "validateExists"
QT_MOC_LITERAL(11, 129, 2), // "id"
QT_MOC_LITERAL(12, 132, 5), // "email"
QT_MOC_LITERAL(13, 138, 18), // "handleUploadAvatar"
QT_MOC_LITERAL(14, 157, 17) // "renderDepartments"

    },
    "DialogFormEmployee\0excuteDBSuccessful\0"
    "\0editModeChanged\0handleSubmit\0setMode\0"
    "_isEditMode\0setValue\0QSqlQuery\0result\0"
    "validateExists\0id\0email\0handleUploadAvatar\0"
    "renderDepartments"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFormEmployee[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    1,   57,    2, 0x0a /* Public */,
       7,    1,   60,    2, 0x0a /* Public */,
      10,    2,   63,    2, 0x0a /* Public */,
      13,    0,   68,    2, 0x0a /* Public */,
      14,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogFormEmployee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogFormEmployee *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->excuteDBSuccessful(); break;
        case 1: _t->editModeChanged(); break;
        case 2: _t->handleSubmit(); break;
        case 3: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< QSqlQuery(*)>(_a[1]))); break;
        case 5: { bool _r = _t->validateExists((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->handleUploadAvatar(); break;
        case 7: _t->renderDepartments(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogFormEmployee::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormEmployee::excuteDBSuccessful)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DialogFormEmployee::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormEmployee::editModeChanged)) {
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DialogFormEmployee::excuteDBSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DialogFormEmployee::editModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
