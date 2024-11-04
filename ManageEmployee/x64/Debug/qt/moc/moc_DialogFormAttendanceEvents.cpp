/****************************************************************************
** Meta object code from reading C++ file 'DialogFormAttendanceEvents.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../DialogFormAttendanceEvents.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DialogFormAttendanceEvents.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogFormAttendanceEvents_t {
    QByteArrayData data[14];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogFormAttendanceEvents_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogFormAttendanceEvents_t qt_meta_stringdata_DialogFormAttendanceEvents = {
    {
QT_MOC_LITERAL(0, 0, 26), // "DialogFormAttendanceEvents"
QT_MOC_LITERAL(1, 27, 6), // "submit"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 17), // "_employeeSelected"
QT_MOC_LITERAL(4, 53, 10), // "isEditMode"
QT_MOC_LITERAL(5, 64, 27), // "DialogFormAttendanceEvents*"
QT_MOC_LITERAL(6, 92, 6), // "dialog"
QT_MOC_LITERAL(7, 99, 12), // "handleSubmit"
QT_MOC_LITERAL(8, 112, 7), // "setMode"
QT_MOC_LITERAL(9, 120, 11), // "_isEditMode"
QT_MOC_LITERAL(10, 132, 8), // "setValue"
QT_MOC_LITERAL(11, 141, 27), // "QList<AttendanceEventModel>"
QT_MOC_LITERAL(12, 169, 6), // "events"
QT_MOC_LITERAL(13, 176, 25) // "handleCheckTimeCheckInOut"

    },
    "DialogFormAttendanceEvents\0submit\0\0"
    "_employeeSelected\0isEditMode\0"
    "DialogFormAttendanceEvents*\0dialog\0"
    "handleSubmit\0setMode\0_isEditMode\0"
    "setValue\0QList<AttendanceEventModel>\0"
    "events\0handleCheckTimeCheckInOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogFormAttendanceEvents[] = {

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
       1,    3,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,
      10,    1,   50,    2, 0x0a /* Public */,
      13,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, 0x80000000 | 5,    3,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::QString,

       0        // eod
};

void DialogFormAttendanceEvents::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogFormAttendanceEvents *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->submit((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< DialogFormAttendanceEvents*(*)>(_a[3]))); break;
        case 1: _t->handleSubmit(); break;
        case 2: _t->setMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setValue((*reinterpret_cast< const QList<AttendanceEventModel>(*)>(_a[1]))); break;
        case 4: { QString _r = _t->handleCheckTimeCheckInOut();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormAttendanceEvents* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogFormAttendanceEvents::*)(QString , bool , DialogFormAttendanceEvents * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogFormAttendanceEvents::submit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogFormAttendanceEvents::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogFormAttendanceEvents.data,
    qt_meta_data_DialogFormAttendanceEvents,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogFormAttendanceEvents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogFormAttendanceEvents::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogFormAttendanceEvents.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogFormAttendanceEvents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogFormAttendanceEvents::submit(QString _t1, bool _t2, DialogFormAttendanceEvents * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
