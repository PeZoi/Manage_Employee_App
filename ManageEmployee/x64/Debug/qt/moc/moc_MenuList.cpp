/****************************************************************************
** Meta object code from reading C++ file 'MenuList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../MenuList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MenuList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuList_t {
    QByteArrayData data[8];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuList_t qt_meta_stringdata_MenuList = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MenuList"
QT_MOC_LITERAL(1, 9, 17), // "onClickDepartment"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "onClickEmployee"
QT_MOC_LITERAL(4, 44, 23), // "onClickAttendanceEvents"
QT_MOC_LITERAL(5, 68, 16), // "onClickException"
QT_MOC_LITERAL(6, 85, 15), // "onClickBulletin"
QT_MOC_LITERAL(7, 101, 12) // "onClickTools"

    },
    "MenuList\0onClickDepartment\0\0onClickEmployee\0"
    "onClickAttendanceEvents\0onClickException\0"
    "onClickBulletin\0onClickTools"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    0,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MenuList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClickDepartment(); break;
        case 1: _t->onClickEmployee(); break;
        case 2: _t->onClickAttendanceEvents(); break;
        case 3: _t->onClickException(); break;
        case 4: _t->onClickBulletin(); break;
        case 5: _t->onClickTools(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickDepartment)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickEmployee)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickAttendanceEvents)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickException)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickBulletin)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MenuList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MenuList::onClickTools)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject MenuList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MenuList.data,
    qt_meta_data_MenuList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MenuList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MenuList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MenuList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MenuList::onClickDepartment()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MenuList::onClickEmployee()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MenuList::onClickAttendanceEvents()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MenuList::onClickException()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MenuList::onClickBulletin()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MenuList::onClickTools()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
