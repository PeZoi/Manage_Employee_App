/****************************************************************************
** Meta object code from reading C++ file 'MainWindowController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../MainWindowController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindowController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindowController_t {
    QByteArrayData data[10];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindowController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindowController_t qt_meta_stringdata_MainWindowController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MainWindowController"
QT_MOC_LITERAL(1, 21, 16), // "handleHiddenMenu"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "handleShowMenu"
QT_MOC_LITERAL(4, 54, 28), // "handleHiddenManageDepartment"
QT_MOC_LITERAL(5, 83, 26), // "handleShowManageDepartment"
QT_MOC_LITERAL(6, 110, 26), // "handleHiddenManageEmployee"
QT_MOC_LITERAL(7, 137, 24), // "handleShowManageEmployee"
QT_MOC_LITERAL(8, 162, 17), // "getMainWindowView"
QT_MOC_LITERAL(9, 180, 11) // "MainWindow*"

    },
    "MainWindowController\0handleHiddenMenu\0"
    "\0handleShowMenu\0handleHiddenManageDepartment\0"
    "handleShowManageDepartment\0"
    "handleHiddenManageEmployee\0"
    "handleShowManageEmployee\0getMainWindowView\0"
    "MainWindow*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindowController[] = {

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
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 9,

       0        // eod
};

void MainWindowController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleHiddenMenu(); break;
        case 1: _t->handleShowMenu(); break;
        case 2: _t->handleHiddenManageDepartment(); break;
        case 3: _t->handleShowManageDepartment(); break;
        case 4: _t->handleHiddenManageEmployee(); break;
        case 5: _t->handleShowManageEmployee(); break;
        case 6: { MainWindow* _r = _t->getMainWindowView();
            if (_a[0]) *reinterpret_cast< MainWindow**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindowController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MainWindowController.data,
    qt_meta_data_MainWindowController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindowController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindowController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainWindowController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
