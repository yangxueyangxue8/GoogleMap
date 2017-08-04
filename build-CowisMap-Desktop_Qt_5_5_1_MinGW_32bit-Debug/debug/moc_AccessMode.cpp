/****************************************************************************
** Meta object code from reading C++ file 'AccessMode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CowisMap/mapcore/AccessMode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AccessMode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cowiscore__AccessMode_t {
    QByteArrayData data[5];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cowiscore__AccessMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cowiscore__AccessMode_t qt_meta_stringdata_cowiscore__AccessMode = {
    {
QT_MOC_LITERAL(0, 0, 21), // "cowiscore::AccessMode"
QT_MOC_LITERAL(1, 22, 5), // "Types"
QT_MOC_LITERAL(2, 28, 10), // "ServerOnly"
QT_MOC_LITERAL(3, 39, 14), // "ServerAndCache"
QT_MOC_LITERAL(4, 54, 9) // "CacheOnly"

    },
    "cowiscore::AccessMode\0Types\0ServerOnly\0"
    "ServerAndCache\0CacheOnly"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cowiscore__AccessMode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    3,   18,

 // enum data: key, value
       2, uint(cowiscore::AccessMode::ServerOnly),
       3, uint(cowiscore::AccessMode::ServerAndCache),
       4, uint(cowiscore::AccessMode::CacheOnly),

       0        // eod
};

void cowiscore::AccessMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject cowiscore::AccessMode::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cowiscore__AccessMode.data,
      qt_meta_data_cowiscore__AccessMode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cowiscore::AccessMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cowiscore::AccessMode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cowiscore__AccessMode.stringdata0))
        return static_cast<void*>(const_cast< AccessMode*>(this));
    return QObject::qt_metacast(_clname);
}

int cowiscore::AccessMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
