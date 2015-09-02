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
    QByteArrayData data[21];
    char stringdata0[180];
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
QT_MOC_LITERAL(3, 29, 12), // "stepsChanged"
QT_MOC_LITERAL(4, 42, 4), // "smth"
QT_MOC_LITERAL(5, 47, 8), // "getWidth"
QT_MOC_LITERAL(6, 56, 9), // "getHeight"
QT_MOC_LITERAL(7, 66, 8), // "rowCount"
QT_MOC_LITERAL(8, 75, 6), // "parent"
QT_MOC_LITERAL(9, 82, 9), // "getSource"
QT_MOC_LITERAL(10, 92, 4), // "type"
QT_MOC_LITERAL(11, 97, 10), // "doMovement"
QT_MOC_LITERAL(12, 108, 5), // "index"
QT_MOC_LITERAL(13, 114, 8), // "matching"
QT_MOC_LITERAL(14, 123, 7), // "getType"
QT_MOC_LITERAL(15, 131, 8), // "getScore"
QT_MOC_LITERAL(16, 140, 8), // "getSteps"
QT_MOC_LITERAL(17, 149, 9), // "isMatched"
QT_MOC_LITERAL(18, 159, 8), // "backSwap"
QT_MOC_LITERAL(19, 168, 5), // "score"
QT_MOC_LITERAL(20, 174, 5) // "steps"

    },
    "QMatchTreeList\0scoreChanged\0\0stepsChanged\0"
    "smth\0getWidth\0getHeight\0rowCount\0"
    "parent\0getSource\0type\0doMovement\0index\0"
    "matching\0getType\0getScore\0getSteps\0"
    "isMatched\0backSwap\0score\0steps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMatchTreeList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  106, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   87,    2, 0x02 /* Public */,
       6,    0,   88,    2, 0x02 /* Public */,
       7,    1,   89,    2, 0x02 /* Public */,
       9,    1,   92,    2, 0x02 /* Public */,
      11,    1,   95,    2, 0x02 /* Public */,
      13,    0,   98,    2, 0x02 /* Public */,
      14,    1,   99,    2, 0x02 /* Public */,
      15,    0,  102,    2, 0x02 /* Public */,
      16,    0,  103,    2, 0x02 /* Public */,
      17,    0,  104,    2, 0x02 /* Public */,
      18,    0,  105,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, QMetaType::QModelIndex,    8,
    QMetaType::QString, QMetaType::Int,   10,
    QMetaType::Bool, QMetaType::Int,   12,
    QMetaType::Bool,
    QMetaType::Int, QMetaType::Int,   12,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Bool,

 // properties: name, type, flags
      19, QMetaType::Int, 0x00495103,
      20, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void QMatchTreeList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scoreChanged(); break;
        case 1: _t->stepsChanged(); break;
        case 2: _t->smth(); break;
        case 3: { int _r = _t->getWidth();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getHeight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->rowCount((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->getSource((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->doMovement((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->matching();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->getType((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->getScore();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->getSteps();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->isMatched();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->backSwap();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
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
        {
            typedef void (QMatchTreeList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMatchTreeList::stepsChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QMatchTreeList::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QMatchTreeList::smth)) {
                *result = 2;
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
        case 1: *reinterpret_cast< int*>(_v) = _t->getSteps(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QMatchTreeList *_t = static_cast<QMatchTreeList *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setScore(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setSteps(*reinterpret_cast< int*>(_v)); break;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMatchTreeList::scoreChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QMatchTreeList::stepsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QMatchTreeList::smth()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
