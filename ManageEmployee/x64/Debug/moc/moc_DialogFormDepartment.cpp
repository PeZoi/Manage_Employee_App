/****************************************************************************
** Meta object code from reading C++ file 'DialogFormDepartment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DialogFormDepartment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogFormDepartment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogFormDepartment_t {
    QByteArrayData data[10];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFormDepartment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFormDepartment_t qt_meta_stringdata_DialogFormDepartment = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogFormDepartment"
QT_MOC_LITERAL(1, 21, 18), // "excuteDBSuccessful"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 12), // "handleSubmit"
QT_MOC_LITERAL(4, 54, 7), // "setName"
QT_MOC_LITERAL(5, 62, 4), // "name"
QT_MOC_LITERAL(6, 67, 14), // "setDescription"
QT_MOC_LITERAL(7, 82, 11), // "description"
QT_MOC_LITERAL(8, 94, 7), // "setMode"
QT_MOC_LITERAL(9, 102, 11) // "_isEditMode"

    },
    "DialogFormDepartment\0excuteDBSuccessful\0"
    "\0handleSubmit\0setName\0name\0setDescription\0"
    "description\0setMode\0_isEditMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFormDepartment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void DialogFormDepartment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogFormDepartment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->excuteDBSuccessful(); break;
        case 1: _t->handleSubmit(); break;
        case 2: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setDescription((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogFormDepartment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormDepartment::excuteDBSuccessful)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogFormDepartment::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogFormDepartment.data,
    qt_meta_data_DialogFormDepartment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogFormDepartment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogFormDepartment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogFormDepartment.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogFormDepartment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DialogFormDepartment::excuteDBSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
