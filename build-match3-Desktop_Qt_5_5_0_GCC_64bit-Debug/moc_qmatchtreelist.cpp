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
    QByteArrayData data[17];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMatchTreeList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMatchTreeList_t qt_meta_stringdata_QMatchTreeList = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QMatchTreeList"
QT_MOC_LITERAL(1, 15, 12), // "scoreChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "getWidth"
QT_MOC_LITERAL(4, 38, 9), // "getHeight"
QT_MOC_LITERAL(5, 48, 8), // "rowCount"
QT_MOC_LITERAL(6, 57, 6), // "parent"
QT_MOC_LITERAL(7, 64, 9), // "getSource"
QT_MOC_LITERAL(8, 74, 4), // "type"
QT_MOC_LITERAL(9, 79, 10), // "doMovement"
QT_MOC_LITERAL(10, 90, 5), // "index"
QT_MOC_LITERAL(11, 96, 19), // "findMatchOnVertical"
QT_MOC_LITERAL(12, 116, 21), // "findMatchOnHorizontal"
QT_MOC_LITERAL(13, 138, 11), // "fillMatches"
QT_MOC_LITERAL(14, 150, 8), // "matching"
QT_MOC_LITERAL(15, 159, 7), // "getType"
QT_MOC_LITERAL(16, 167, 5) // "score"

    },
    "QMatchTreeList\0scoreChanged\0\0getWidth\0"
    "getHeight\0rowCount\0parent\0getSource\0"
    "type\0doMovement\0index\0findMatchOnVertical\0"
    "findMatchOnHorizontal\0fillMatches\0"
    "matching\0getType\0score"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMatchTreeList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,   90, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x02 /* Public */,
       4,    0,   71,    2, 0x02 /* Public */,
       5,    1,   72,    2, 0x02 /* Public */,
       7,    1,   75,    2, 0x02 /* Public */,
       9,    1,   78,    2, 0x02 /* Public */,
      11,    0,   81,    2, 0x02 /* Public */,
      12,    0,   82,    2, 0x02 /* Public */,
      13,    1,   83,    2, 0x02 /* Public */,
      14,    0,   86,    2, 0x02 /* Public */,
      15,    1,   87,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QModelIndex,    6,
    QMetaType::QString, QMetaType::Int,    8,
    QMetaType::Bool, QMetaType::Int,   10,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Bool,
    QMetaType::Int, QMetaType::Int,   10,

 // properties: name, type, flags
      16, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void QMatchTreeList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scoreChanged(); break;
        case 1: { int _r = _t->getWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getSource((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->doMovement((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->findMatchOnVertical();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->findMatchOnHorizontal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->fillMatches((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: { bool _r = _t->matching();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->getType((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QMatchTreeList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMatchTreeList::scoreChanged)) {
                *result = 0;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getScore(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScore(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMatchTreeList::scoreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
