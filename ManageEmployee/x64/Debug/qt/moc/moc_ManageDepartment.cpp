/****************************************************************************
** Meta object code from reading C++ file 'ManageDepartment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../ManageDepartment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageDepartment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManageDepartment_t {
    QByteArrayData data[12];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManageDepartment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManageDepartment_t qt_meta_stringdata_ManageDepartment = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ManageDepartment"
QT_MOC_LITERAL(1, 17, 8), // "modeEdit"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 17), // "handleRenderTable"
QT_MOC_LITERAL(4, 45, 14), // "handleClickAdd"
QT_MOC_LITERAL(5, 60, 10), // "handleEdit"
QT_MOC_LITERAL(6, 71, 12), // "handleDelete"
QT_MOC_LITERAL(7, 84, 16), // "getAllDepartment"
QT_MOC_LITERAL(8, 101, 9), // "QSqlQuery"
QT_MOC_LITERAL(9, 111, 16), // "handleRowClicked"
QT_MOC_LITERAL(10, 128, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 140, 5) // "index"

    },
    "ManageDepartment\0modeEdit\0\0handleRenderTable\0"
    "handleClickAdd\0handleEdit\0handleDelete\0"
    "getAllDepartment\0QSqlQuery\0handleRowClicked\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManageDepartment[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void ManageDepartment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageDepartment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->modeEdit(); break;
        case 1: _t->handleRenderTable(); break;
        case 2: _t->handleClickAdd(); break;
        case 3: _t->handleEdit(); break;
        case 4: _t->handleDelete(); break;
        case 5: { QSqlQuery _r = _t->getAllDepartment();
            if (_a[0]) *reinterpret_cast< QSqlQuery*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->handleRowClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ManageDepartment::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ManageDepartment::modeEdit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ManageDepartment::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ManageDepartment.data,
    qt_meta_data_ManageDepartment,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ManageDepartment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageDepartment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManageDepartment.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ManageDepartment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ManageDepartment::modeEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
