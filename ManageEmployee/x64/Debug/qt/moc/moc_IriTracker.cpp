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
    QByteArrayData data[18];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IriTracker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IriTracker_t qt_meta_stringdata_IriTracker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "IriTracker"
QT_MOC_LITERAL(1, 11, 14), // "imageProcessed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "unsigned char*"
QT_MOC_LITERAL(4, 42, 9), // "imageData"
QT_MOC_LITERAL(5, 52, 8), // "imageLen"
QT_MOC_LITERAL(6, 61, 10), // "imageWidth"
QT_MOC_LITERAL(7, 72, 11), // "imageHeight"
QT_MOC_LITERAL(8, 84, 11), // "imageResult"
QT_MOC_LITERAL(9, 96, 14), // "resultTemplate"
QT_MOC_LITERAL(10, 111, 20), // "const unsigned char*"
QT_MOC_LITERAL(11, 132, 6), // "buffer"
QT_MOC_LITERAL(12, 139, 4), // "size"
QT_MOC_LITERAL(13, 144, 21), // "isCheckCompareSuccess"
QT_MOC_LITERAL(14, 166, 10), // "employeeId"
QT_MOC_LITERAL(15, 177, 10), // "isExistIri"
QT_MOC_LITERAL(16, 188, 5), // "check"
QT_MOC_LITERAL(17, 194, 11) // "foundDevice"

    },
    "IriTracker\0imageProcessed\0\0unsigned char*\0"
    "imageData\0imageLen\0imageWidth\0imageHeight\0"
    "imageResult\0resultTemplate\0"
    "const unsigned char*\0buffer\0size\0"
    "isCheckCompareSuccess\0employeeId\0"
    "isExistIri\0check\0foundDevice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IriTracker[] = {

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
       1,    4,   44,    2, 0x06 /* Public */,
       8,    4,   53,    2, 0x06 /* Public */,
       9,    2,   62,    2, 0x06 /* Public */,
      13,    1,   67,    2, 0x06 /* Public */,
      15,    1,   70,    2, 0x06 /* Public */,
      17,    1,   73,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

void IriTracker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IriTracker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageProcessed((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->imageResult((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->resultTemplate((*reinterpret_cast< const unsigned char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->isCheckCompareSuccess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->isExistIri((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->foundDevice((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IriTracker::*)(unsigned char * , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::imageProcessed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)(unsigned char * , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::imageResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)(const unsigned char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::resultTemplate)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::isCheckCompareSuccess)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::isExistIri)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (IriTracker::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IriTracker::foundDevice)) {
                *result = 5;
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
void IriTracker::imageProcessed(unsigned char * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IriTracker::imageResult(unsigned char * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void IriTracker::resultTemplate(const unsigned char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void IriTracker::isCheckCompareSuccess(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void IriTracker::isExistIri(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void IriTracker::foundDevice(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
