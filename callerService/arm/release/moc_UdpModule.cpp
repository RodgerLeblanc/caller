/****************************************************************************
** Meta object code from reading C++ file 'UdpModule.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/UdpModule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UdpModule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UdpModule[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   10,   10,   10, 0x0a,

 // methods: signature, parameters, type, tag, flags
      68,   47,   10,   10, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_UdpModule[] = {
    "UdpModule\0\0reveivedData(QString)\0"
    "onReadyRead()\0_address,_port,_data\0"
    "sendMessage(QString,int,QString)\0"
};

void UdpModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UdpModule *_t = static_cast<UdpModule *>(_o);
        switch (_id) {
        case 0: _t->reveivedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onReadyRead(); break;
        case 2: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UdpModule::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UdpModule::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UdpModule,
      qt_meta_data_UdpModule, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UdpModule::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UdpModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UdpModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UdpModule))
        return static_cast<void*>(const_cast< UdpModule*>(this));
    return QObject::qt_metacast(_clname);
}

int UdpModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UdpModule::reveivedData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
