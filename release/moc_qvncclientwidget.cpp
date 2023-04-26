/****************************************************************************
** Meta object code from reading C++ file 'qvncclientwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qvncclientwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvncclientwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QVNCClientWidget_t {
    QByteArrayData data[10];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVNCClientWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVNCClientWidget_t qt_meta_stringdata_QVNCClientWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QVNCClientWidget"
QT_MOC_LITERAL(1, 17, 18), // "frameBufferUpdated"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "connected"
QT_MOC_LITERAL(4, 47, 1), // "b"
QT_MOC_LITERAL(5, 49, 28), // "sendFrameBufferUpdateRequest"
QT_MOC_LITERAL(6, 78, 11), // "incremental"
QT_MOC_LITERAL(7, 90, 13), // "setFullScreen"
QT_MOC_LITERAL(8, 104, 4), // "full"
QT_MOC_LITERAL(9, 109, 15) // "onServerMessage"

    },
    "QVNCClientWidget\0frameBufferUpdated\0"
    "\0connected\0b\0sendFrameBufferUpdateRequest\0"
    "incremental\0setFullScreen\0full\0"
    "onServerMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVNCClientWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       5,    0,   51,    2, 0x2a /* Public | MethodCloned */,
       7,    1,   52,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,

       0        // eod
};

void QVNCClientWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QVNCClientWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameBufferUpdated(); break;
        case 1: _t->connected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sendFrameBufferUpdateRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sendFrameBufferUpdateRequest(); break;
        case 4: _t->setFullScreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onServerMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QVNCClientWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QVNCClientWidget::frameBufferUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QVNCClientWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QVNCClientWidget::connected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QVNCClientWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QVNCClientWidget.data,
    qt_meta_data_QVNCClientWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QVNCClientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVNCClientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QVNCClientWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QVNCClientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void QVNCClientWidget::frameBufferUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QVNCClientWidget::connected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
