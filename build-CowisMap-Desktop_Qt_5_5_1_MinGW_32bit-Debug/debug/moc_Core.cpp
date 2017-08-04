/****************************************************************************
** Meta object code from reading C++ file 'Core.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CowisMap/internals/Core.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Core.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cowisinternals__Core_t {
    QByteArrayData data[19];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cowisinternals__Core_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cowisinternals__Core_t qt_meta_stringdata_cowisinternals__Core = {
    {
QT_MOC_LITERAL(0, 0, 20), // "cowisinternals::Core"
QT_MOC_LITERAL(1, 21, 24), // "OnCurrentPositionChanged"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 27), // "cowisinternals::PointLatLng"
QT_MOC_LITERAL(4, 75, 5), // "point"
QT_MOC_LITERAL(5, 81, 18), // "OnTileLoadComplete"
QT_MOC_LITERAL(6, 100, 18), // "OnTilesStillToLoad"
QT_MOC_LITERAL(7, 119, 6), // "number"
QT_MOC_LITERAL(8, 126, 15), // "OnTileLoadStart"
QT_MOC_LITERAL(9, 142, 9), // "OnMapDrag"
QT_MOC_LITERAL(10, 152, 16), // "OnMapZoomChanged"
QT_MOC_LITERAL(11, 169, 16), // "OnMapTypeChanged"
QT_MOC_LITERAL(12, 186, 14), // "Maptype::Types"
QT_MOC_LITERAL(13, 201, 4), // "type"
QT_MOC_LITERAL(14, 206, 16), // "OnEmptyTileError"
QT_MOC_LITERAL(15, 223, 4), // "zoom"
QT_MOC_LITERAL(16, 228, 16), // "cowiscore::Point"
QT_MOC_LITERAL(17, 245, 3), // "pos"
QT_MOC_LITERAL(18, 249, 18) // "OnNeedInvalidation"

    },
    "cowisinternals::Core\0OnCurrentPositionChanged\0"
    "\0cowisinternals::PointLatLng\0point\0"
    "OnTileLoadComplete\0OnTilesStillToLoad\0"
    "number\0OnTileLoadStart\0OnMapDrag\0"
    "OnMapZoomChanged\0OnMapTypeChanged\0"
    "Maptype::Types\0type\0OnEmptyTileError\0"
    "zoom\0cowiscore::Point\0pos\0OnNeedInvalidation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cowisinternals__Core[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    1,   63,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,
       9,    0,   67,    2, 0x06 /* Public */,
      10,    0,   68,    2, 0x06 /* Public */,
      11,    1,   69,    2, 0x06 /* Public */,
      14,    2,   72,    2, 0x06 /* Public */,
      18,    0,   77,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 16,   15,   17,
    QMetaType::Void,

       0        // eod
};

void cowisinternals::Core::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Core *_t = static_cast<Core *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnCurrentPositionChanged((*reinterpret_cast< cowisinternals::PointLatLng(*)>(_a[1]))); break;
        case 1: _t->OnTileLoadComplete(); break;
        case 2: _t->OnTilesStillToLoad((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnTileLoadStart(); break;
        case 4: _t->OnMapDrag(); break;
        case 5: _t->OnMapZoomChanged(); break;
        case 6: _t->OnMapTypeChanged((*reinterpret_cast< Maptype::Types(*)>(_a[1]))); break;
        case 7: _t->OnEmptyTileError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< cowiscore::Point(*)>(_a[2]))); break;
        case 8: _t->OnNeedInvalidation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Core::*_t)(cowisinternals::PointLatLng );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnCurrentPositionChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Core::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnTileLoadComplete)) {
                *result = 1;
            }
        }
        {
            typedef void (Core::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnTilesStillToLoad)) {
                *result = 2;
            }
        }
        {
            typedef void (Core::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnTileLoadStart)) {
                *result = 3;
            }
        }
        {
            typedef void (Core::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnMapDrag)) {
                *result = 4;
            }
        }
        {
            typedef void (Core::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnMapZoomChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (Core::*_t)(Maptype::Types );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnMapTypeChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (Core::*_t)(int , cowiscore::Point );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnEmptyTileError)) {
                *result = 7;
            }
        }
        {
            typedef void (Core::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Core::OnNeedInvalidation)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject cowisinternals::Core::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cowisinternals__Core.data,
      qt_meta_data_cowisinternals__Core,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cowisinternals::Core::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cowisinternals::Core::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cowisinternals__Core.stringdata0))
        return static_cast<void*>(const_cast< Core*>(this));
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(const_cast< Core*>(this));
    return QObject::qt_metacast(_clname);
}

int cowisinternals::Core::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void cowisinternals::Core::OnCurrentPositionChanged(cowisinternals::PointLatLng _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void cowisinternals::Core::OnTileLoadComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void cowisinternals::Core::OnTilesStillToLoad(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void cowisinternals::Core::OnTileLoadStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void cowisinternals::Core::OnMapDrag()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void cowisinternals::Core::OnMapZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void cowisinternals::Core::OnMapTypeChanged(Maptype::Types _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void cowisinternals::Core::OnEmptyTileError(int _t1, cowiscore::Point _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void cowisinternals::Core::OnNeedInvalidation()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
