/****************************************************************************
** Meta object code from reading C++ file 'qmatchtreelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../match3/qmatchtreelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmatchtreelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMatchTreeList_t {
    QByteArrayData data[14];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMatchTreeList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMatchTreeList_t qt_meta_stringdata_QMatchTreeList = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QMatchTreeList"
QT_MOC_LITERAL(1, 15, 8), // "getWidth"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "getHeight"
QT_MOC_LITERAL(4, 35, 8), // "rowCount"
QT_MOC_LITERAL(5, 44, 6), // "parent"
QT_MOC_LITERAL(6, 51, 9), // "getSource"
QT_MOC_LITERAL(7, 61, 4), // "type"
QT_MOC_LITERAL(8, 66, 10), // "doMovement"
QT_MOC_LITERAL(9, 77, 5), // "index"
QT_MOC_LITERAL(10, 83, 19), // "findMatchOnVertical"
QT_MOC_LITERAL(11, 103, 21), // "findMatchOnHorizontal"
QT_MOC_LITERAL(12, 125, 11), // "fillMatches"
QT_MOC_LITERAL(13, 137, 8) // "matching"

    },
    "QMatchTreeList\0getWidth\0\0getHeight\0"
    "rowCount\0parent\0getSource\0type\0"
    "doMovement\0index\0findMatchOnVertical\0"
    "findMatchOnHorizontal\0fillMatches\0"
    "matching"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMatchTreeList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x02 /* Public */,
       3,    0,   60,    2, 0x02 /* Public */,
       4,    1,   61,    2, 0x02 /* Public */,
       6,    1,   64,    2, 0x02 /* Public */,
       8,    1,   67,    2, 0x02 /* Public */,
      10,    0,   70,    2, 0x02 /* Public */,
      11,    0,   71,    2, 0x02 /* Public */,
      12,    1,   72,    2, 0x02 /* Public */,
      13,    0,   75,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QModelIndex,    5,
    QMetaType::QString, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Bool,

       0        // eod
};

void QMatchTreeList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->getWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->getHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getSource((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: _t->doMovement((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { bool _r = _t->findMatchOnVertical();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->findMatchOnHorizontal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->fillMatches((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->matching();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject QMatchTreeList::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_QMatchTreeList.data,
      qt_meta_data_QMatchTreeList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMatchTreeList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMatchTreeList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMatchTreeList.stringdata0))
        return static_cast<void*>(const_cast< QMatchTreeList*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int QMatchTreeList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
