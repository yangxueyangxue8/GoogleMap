/****************************************************************************
** Meta object code from reading C++ file 'GeoCoderStatusCode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CowisMap/mapcore/GeoCoderStatusCode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeoCoderStatusCode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cowiscore__GeoCoderStatusCode_t {
    QByteArrayData data[13];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cowiscore__GeoCoderStatusCode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cowiscore__GeoCoderStatusCode_t qt_meta_stringdata_cowiscore__GeoCoderStatusCode = {
    {
QT_MOC_LITERAL(0, 0, 29), // "cowiscore::GeoCoderStatusCode"
QT_MOC_LITERAL(1, 30, 5), // "Types"
QT_MOC_LITERAL(2, 36, 6), // "Unknow"
QT_MOC_LITERAL(3, 43, 13), // "G_GEO_SUCCESS"
QT_MOC_LITERAL(4, 57, 17), // "G_GEO_BAD_REQUEST"
QT_MOC_LITERAL(5, 75, 18), // "G_GEO_SERVER_ERROR"
QT_MOC_LITERAL(6, 94, 19), // "G_GEO_MISSING_QUERY"
QT_MOC_LITERAL(7, 114, 21), // "G_GEO_MISSING_ADDRESS"
QT_MOC_LITERAL(8, 136, 21), // "G_GEO_UNKNOWN_ADDRESS"
QT_MOC_LITERAL(9, 158, 25), // "G_GEO_UNAVAILABLE_ADDRESS"
QT_MOC_LITERAL(10, 184, 24), // "G_GEO_UNKNOWN_DIRECTIONS"
QT_MOC_LITERAL(11, 209, 13), // "G_GEO_BAD_KEY"
QT_MOC_LITERAL(12, 223, 22) // "G_GEO_TOO_MANY_QUERIES"

    },
    "cowiscore::GeoCoderStatusCode\0Types\0"
    "Unknow\0G_GEO_SUCCESS\0G_GEO_BAD_REQUEST\0"
    "G_GEO_SERVER_ERROR\0G_GEO_MISSING_QUERY\0"
    "G_GEO_MISSING_ADDRESS\0G_GEO_UNKNOWN_ADDRESS\0"
    "G_GEO_UNAVAILABLE_ADDRESS\0"
    "G_GEO_UNKNOWN_DIRECTIONS\0G_GEO_BAD_KEY\0"
    "G_GEO_TOO_MANY_QUERIES"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cowiscore__GeoCoderStatusCode[] = {

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
       1, 0x0,   11,   18,

 // enum data: key, value
       2, uint(cowiscore::GeoCoderStatusCode::Unknow),
       3, uint(cowiscore::GeoCoderStatusCode::G_GEO_SUCCESS),
       4, uint(cowiscore::GeoCoderStatusCode::G_GEO_BAD_REQUEST),
       5, uint(cowiscore::GeoCoderStatusCode::G_GEO_SERVER_ERROR),
       6, uint(cowiscore::GeoCoderStatusCode::G_GEO_MISSING_QUERY),
       7, uint(cowiscore::GeoCoderStatusCode::G_GEO_MISSING_ADDRESS),
       8, uint(cowiscore::GeoCoderStatusCode::G_GEO_UNKNOWN_ADDRESS),
       9, uint(cowiscore::GeoCoderStatusCode::G_GEO_UNAVAILABLE_ADDRESS),
      10, uint(cowiscore::GeoCoderStatusCode::G_GEO_UNKNOWN_DIRECTIONS),
      11, uint(cowiscore::GeoCoderStatusCode::G_GEO_BAD_KEY),
      12, uint(cowiscore::GeoCoderStatusCode::G_GEO_TOO_MANY_QUERIES),

       0        // eod
};

void cowiscore::GeoCoderStatusCode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject cowiscore::GeoCoderStatusCode::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cowiscore__GeoCoderStatusCode.data,
      qt_meta_data_cowiscore__GeoCoderStatusCode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cowiscore::GeoCoderStatusCode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cowiscore::GeoCoderStatusCode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cowiscore__GeoCoderStatusCode.stringdata0))
        return static_cast<void*>(const_cast< GeoCoderStatusCode*>(this));
    return QObject::qt_metacast(_clname);
}

int cowiscore::GeoCoderStatusCode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
