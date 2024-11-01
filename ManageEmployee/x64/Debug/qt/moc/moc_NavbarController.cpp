/****************************************************************************
** Meta object code from reading C++ file 'NavbarController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../NavbarController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavbarController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavbarController_t {
    QByteArrayData data[18];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavbarController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavbarController_t qt_meta_stringdata_NavbarController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NavbarController"
QT_MOC_LITERAL(1, 17, 16), // "logoutSuccessful"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15), // "loginSuccessful"
QT_MOC_LITERAL(4, 51, 4), // "back"
QT_MOC_LITERAL(5, 56, 17), // "handleClickLogout"
QT_MOC_LITERAL(6, 74, 16), // "handleClickLogin"
QT_MOC_LITERAL(7, 91, 20), // "handleClickCopyright"
QT_MOC_LITERAL(8, 112, 15), // "handleClickMode"
QT_MOC_LITERAL(9, 128, 15), // "handleClickExit"
QT_MOC_LITERAL(10, 144, 16), // "handleHiddenBack"
QT_MOC_LITERAL(11, 161, 14), // "handleShowBack"
QT_MOC_LITERAL(12, 176, 14), // "onLoginSuccess"
QT_MOC_LITERAL(13, 191, 15), // "onLogoutSuccess"
QT_MOC_LITERAL(14, 207, 17), // "handleSignInAdmin"
QT_MOC_LITERAL(15, 225, 4), // "pass"
QT_MOC_LITERAL(16, 230, 21), // "DialogFormLoginAdmin*"
QT_MOC_LITERAL(17, 252, 6) // "dialog"

    },
    "NavbarController\0logoutSuccessful\0\0"
    "loginSuccessful\0back\0handleClickLogout\0"
    "handleClickLogin\0handleClickCopyright\0"
    "handleClickMode\0handleClickExit\0"
    "handleHiddenBack\0handleShowBack\0"
    "onLoginSuccess\0onLogoutSuccess\0"
    "handleSignInAdmin\0pass\0DialogFormLoginAdmin*\0"
    "dialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavbarController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    2,   91,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::QString, 0x80000000 | 16,   15,   17,

       0        // eod
};

void NavbarController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavbarController *>(_o);
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
        case 12: _t->handleSignInAdmin((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DialogFormLoginAdmin*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DialogFormLoginAdmin* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavbarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavbarController::logoutSuccessful)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavbarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavbarController::loginSuccessful)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavbarController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavbarController::back)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NavbarController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NavbarController.data,
    qt_meta_data_NavbarController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NavbarController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavbarController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavbarController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NavbarController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void NavbarController::logoutSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NavbarController::loginSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NavbarController::back()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
