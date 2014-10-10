/****************************************************************************
** Meta object code from reading C++ file 'Talk2WatchInterface.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Talk2WatchInterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Talk2WatchInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Talk2WatchInterface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      41,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   63,   20,   20, 0x0a,
      91,   20,   20,   20, 0x0a,

 // methods: signature, parameters, type, tag, flags
     117,   20,  112,   20, 0x02,
     141,   20,  112,   20, 0x02,
     168,   20,  112,   20, 0x02,
     216,  202,   20,   20, 0x02,
     264,  241,   20,   20, 0x02,
     357,  299,   20,   20, 0x02,
     419,   20,   20,   20, 0x02,
     478,  449,   20,   20, 0x02,
     516,   20,   20,   20, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_Talk2WatchInterface[] = {
    "Talk2WatchInterface\0\0transmissionReady()\0"
    "receivedData(QString)\0_data\0"
    "onDataReived(QString)\0onTalk2WatchLookup()\0"
    "bool\0isTalk2WatchInstalled()\0"
    "isTalk2WatchProInstalled()\0"
    "isTalk2WatchProServiceInstalled()\0"
    "_sender,_text\0sendSms(QString,QString)\0"
    "_sender,_subject,_text\0"
    "sendEmail(QString,QString,QString)\0"
    "_appName,_appVersion,_appKey,_protocol,_port,_description\0"
    "setAppValues(QString,QString,QString,QString,QString,QString)\0"
    "sendAppAuthorizationRequest()\0"
    "_title,_command,_description\0"
    "createAction(QString,QString,QString)\0"
    "forwardSourceCode()\0"
};

void Talk2WatchInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Talk2WatchInterface *_t = static_cast<Talk2WatchInterface *>(_o);
        switch (_id) {
        case 0: _t->transmissionReady(); break;
        case 1: _t->receivedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onDataReived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onTalk2WatchLookup(); break;
        case 4: { bool _r = _t->isTalk2WatchInstalled();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->isTalk2WatchProInstalled();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->isTalk2WatchProServiceInstalled();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->sendSms((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->sendEmail((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 9: _t->setAppValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 10: _t->sendAppAuthorizationRequest(); break;
        case 11: _t->createAction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 12: _t->forwardSourceCode(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Talk2WatchInterface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Talk2WatchInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Talk2WatchInterface,
      qt_meta_data_Talk2WatchInterface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Talk2WatchInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Talk2WatchInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Talk2WatchInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Talk2WatchInterface))
        return static_cast<void*>(const_cast< Talk2WatchInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int Talk2WatchInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Talk2WatchInterface::transmissionReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Talk2WatchInterface::receivedData(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
