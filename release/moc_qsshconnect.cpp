/****************************************************************************
** Meta object code from reading C++ file 'qsshconnect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qsshconnect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsshconnect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSshConnect_t {
    QByteArrayData data[28];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSshConnect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSshConnect_t qt_meta_stringdata_QSshConnect = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QSshConnect"
QT_MOC_LITERAL(1, 12, 8), // "errorStr"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "_errorStr"
QT_MOC_LITERAL(4, 32, 10), // "pingStatus"
QT_MOC_LITERAL(5, 43, 7), // "_status"
QT_MOC_LITERAL(6, 51, 10), // "connStatus"
QT_MOC_LITERAL(7, 62, 10), // "_statusStr"
QT_MOC_LITERAL(8, 73, 11), // "recvDevPara"
QT_MOC_LITERAL(9, 85, 7), // "DevPara"
QT_MOC_LITERAL(10, 93, 8), // "_devPara"
QT_MOC_LITERAL(11, 102, 11), // "recvDevHost"
QT_MOC_LITERAL(12, 114, 8), // "_devHost"
QT_MOC_LITERAL(13, 123, 11), // "recvDevPort"
QT_MOC_LITERAL(14, 135, 8), // "_devPort"
QT_MOC_LITERAL(15, 144, 11), // "recvDevUser"
QT_MOC_LITERAL(16, 156, 8), // "_devUser"
QT_MOC_LITERAL(17, 165, 13), // "recvDevPasswd"
QT_MOC_LITERAL(18, 179, 10), // "_devPasswd"
QT_MOC_LITERAL(19, 190, 16), // "recvDevUploadDir"
QT_MOC_LITERAL(20, 207, 13), // "_devUploadDir"
QT_MOC_LITERAL(21, 221, 12), // "recvShellCmd"
QT_MOC_LITERAL(22, 234, 9), // "_shellCmd"
QT_MOC_LITERAL(23, 244, 7), // "connect"
QT_MOC_LITERAL(24, 252, 10), // "disConnect"
QT_MOC_LITERAL(25, 263, 6), // "upload"
QT_MOC_LITERAL(26, 270, 6), // "update"
QT_MOC_LITERAL(27, 277, 4) // "ping"

    },
    "QSshConnect\0errorStr\0\0_errorStr\0"
    "pingStatus\0_status\0connStatus\0_statusStr\0"
    "recvDevPara\0DevPara\0_devPara\0recvDevHost\0"
    "_devHost\0recvDevPort\0_devPort\0recvDevUser\0"
    "_devUser\0recvDevPasswd\0_devPasswd\0"
    "recvDevUploadDir\0_devUploadDir\0"
    "recvShellCmd\0_shellCmd\0connect\0"
    "disConnect\0upload\0update\0ping"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSshConnect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   98,    2, 0x0a /* Public */,
      11,    1,  101,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x0a /* Public */,
      15,    1,  107,    2, 0x0a /* Public */,
      17,    1,  110,    2, 0x0a /* Public */,
      19,    1,  113,    2, 0x0a /* Public */,
      21,    1,  116,    2, 0x0a /* Public */,
      23,    0,  119,    2, 0x0a /* Public */,
      24,    0,  120,    2, 0x0a /* Public */,
      25,    0,  121,    2, 0x0a /* Public */,
      26,    0,  122,    2, 0x0a /* Public */,
      27,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSshConnect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSshConnect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->errorStr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->pingStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->connStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->recvDevPara((*reinterpret_cast< DevPara(*)>(_a[1]))); break;
        case 4: _t->recvDevHost((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->recvDevPort((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->recvDevUser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->recvDevPasswd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->recvDevUploadDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->recvShellCmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->connect(); break;
        case 11: _t->disConnect(); break;
        case 12: _t->upload(); break;
        case 13: _t->update(); break;
        case 14: _t->ping(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSshConnect::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSshConnect::errorStr)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QSshConnect::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSshConnect::pingStatus)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QSshConnect::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSshConnect::connStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSshConnect::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QSshConnect.data,
    qt_meta_data_QSshConnect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSshConnect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSshConnect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSshConnect.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSshConnect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QSshConnect::errorStr(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSshConnect::pingStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSshConnect::connStatus(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
