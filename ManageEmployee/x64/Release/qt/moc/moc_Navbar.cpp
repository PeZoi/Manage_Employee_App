/****************************************************************************
** Meta object code from reading C++ file 'Navbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../Navbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Navbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Navbar_t {
    QByteArrayData data[14];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Navbar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Navbar_t qt_meta_stringdata_Navbar = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Navbar"
QT_MOC_LITERAL(1, 7, 16), // "logoutSuccessful"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "loginSuccessful"
QT_MOC_LITERAL(4, 41, 4), // "back"
QT_MOC_LITERAL(5, 46, 17), // "handleClickLogout"
QT_MOC_LITERAL(6, 64, 16), // "handleClickLogin"
QT_MOC_LITERAL(7, 81, 20), // "handleClickCopyright"
QT_MOC_LITERAL(8, 102, 15), // "handleClickMode"
QT_MOC_LITERAL(9, 118, 15), // "handleClickExit"
QT_MOC_LITERAL(10, 134, 16), // "handleHiddenBack"
QT_MOC_LITERAL(11, 151, 14), // "handleShowBack"
QT_MOC_LITERAL(12, 166, 14), // "onLoginSuccess"
QT_MOC_LITERAL(13, 181, 15) // "onLogoutSuccess"

    },
    "Navbar\0logoutSuccessful\0\0loginSuccessful\0"
    "back\0handleClickLogout\0handleClickLogin\0"
    "handleClickCopyright\0handleClickMode\0"
    "handleClickExit\0handleHiddenBack\0"
    "handleShowBack\0onLoginSuccess\0"
    "onLogoutSuccess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Navbar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Navbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Navbar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logoutSuccessful(); break;
        case 1: _t->loginSuccessful(); break;
        case 2: _t->back(); break;
        case 3: _t->handleClickLogout(); break;
        case 4: _t->handleClickLogin(); break;
        case 5: _t->handleClickCopyright(); break;
        case 6: _t->handleClickMode(); break;
        case 7: _t->handleClickExit(); break;
        case 8: _t->handleHiddenBack(); break;
        case 9: _t->handleShowBack(); break;
        case 10: _t->onLoginSuccess(); break;
        case 11: _t->onLogoutSuccess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Navbar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Navbar::logoutSuccessful)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Navbar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Navbar::loginSuccessful)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Navbar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Navbar::back)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Navbar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Navbar.data,
    qt_meta_data_Navbar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Navbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Navbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Navbar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Navbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Navbar::logoutSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Navbar::loginSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Navbar::back()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
