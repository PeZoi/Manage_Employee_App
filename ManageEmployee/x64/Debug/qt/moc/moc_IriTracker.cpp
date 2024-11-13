/****************************************************************************
** Meta object code from reading C++ file 'IriTracker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../IriTracker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IriTracker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IriTracker_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IriTracker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IriTracker_t qt_meta_stringdata_IriTracker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IriTracker"
QT_MOC_LITERAL(1, 11, 16), // "newImageCaptured"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 20), // "const unsigned char*"
QT_MOC_LITERAL(4, 50, 9), // "imageData"
QT_MOC_LITERAL(5, 60, 8), // "imageLen"
QT_MOC_LITERAL(6, 69, 11), // "imageHeight"
QT_MOC_LITERAL(7, 81, 10), // "imageWidth"
QT_MOC_LITERAL(8, 92, 15), // "captureFinished"
QT_MOC_LITERAL(9, 108, 24), // "capture_without_callback"
QT_MOC_LITERAL(10, 133, 9), // "IICHandle"
QT_MOC_LITERAL(11, 143, 4), // "hdev"
QT_MOC_LITERAL(12, 148, 3) // "run"

    },
    "IriTracker\0newImageCaptured\0\0"
    "const unsigned char*\0imageData\0imageLen\0"
    "imageHeight\0imageWidth\0captureFinished\0"
    "capture_without_callback\0IICHandle\0"
    "hdev\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IriTracker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       8,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   44,    2, 0x0a /* Public */,
      12,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, 0x80000000 | 10,   11,
    QMetaType::QString,

       0        // eod
};

void IriTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IriTracker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newImageCaptured((*reinterpret_cast< const unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->captureFinished(); break;
        case 2: { int _r = _t->capture_without_callback((*reinterpret_cast< IICHandle(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->run();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IriTracker::*)(const unsigned char * , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::newImageCaptured)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::captureFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject IriTracker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_IriTracker.data,
    qt_meta_data_IriTracker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IriTracker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IriTracker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IriTracker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IriTracker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void IriTracker::newImageCaptured(const unsigned char * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IriTracker::captureFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
