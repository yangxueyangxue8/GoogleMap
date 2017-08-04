/****************************************************************************
** Meta object code from reading C++ file 'MouseWheelZoomType.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CowisMap/internals/MouseWheelZoomType.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MouseWheelZoomType.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cowisinternals__MouseWheelZoomType_t {
    QByteArrayData data[5];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cowisinternals__MouseWheelZoomType_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cowisinternals__MouseWheelZoomType_t qt_meta_stringdata_cowisinternals__MouseWheelZoomType = {
    {
QT_MOC_LITERAL(0, 0, 34), // "cowisinternals::MouseWheelZoo..."
QT_MOC_LITERAL(1, 35, 5), // "Types"
QT_MOC_LITERAL(2, 41, 22), // "MousePositionAndCenter"
QT_MOC_LITERAL(3, 64, 26), // "MousePositionWithoutCenter"
QT_MOC_LITERAL(4, 91, 10) // "ViewCenter"

    },
    "cowisinternals::MouseWheelZoomType\0"
    "Types\0MousePositionAndCenter\0"
    "MousePositionWithoutCenter\0ViewCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cowisinternals__MouseWheelZoomType[] = {

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
       2, uint(cowisinternals::MouseWheelZoomType::MousePositionAndCenter),
       3, uint(cowisinternals::MouseWheelZoomType::MousePositionWithoutCenter),
       4, uint(cowisinternals::MouseWheelZoomType::ViewCenter),

       0        // eod
};

void cowisinternals::MouseWheelZoomType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject cowisinternals::MouseWheelZoomType::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cowisinternals__MouseWheelZoomType.data,
      qt_meta_data_cowisinternals__MouseWheelZoomType,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *cowisinternals::MouseWheelZoomType::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cowisinternals::MouseWheelZoomType::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_cowisinternals__MouseWheelZoomType.stringdata0))
        return static_cast<void*>(const_cast< MouseWheelZoomType*>(this));
    return QObject::qt_metacast(_clname);
}

int cowisinternals::MouseWheelZoomType::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
