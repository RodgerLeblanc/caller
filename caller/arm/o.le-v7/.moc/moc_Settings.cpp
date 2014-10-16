/****************************************************************************
** Meta object code from reading C++ file 'Settings.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Settings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Settings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   50,    9,    9, 0x08,

 // methods: signature, parameters, type, tag, flags
      92,    9,   80,    9, 0x02,
     111,  107,  102,    9, 0x02,
     129,    9,    9,    9, 0x02,
     145,    9,  137,    9, 0x02,
     160,  107,  156,    9, 0x02,
     186,  176,    9,    9, 0x02,
     213,    9,    9,    9, 0x02,
     246,  229,  220,    9, 0x02,
     270,  107,  220,    9, 0x22,

       0        // eod
};

static const char qt_meta_stringdata_Settings[] = {
    "Settings\0\0,\0settingsHaveChanged(QString,QVariant)\0"
    "path\0settingsChanged(QString)\0QStringList\0"
    "allKeys()\0bool\0key\0contains(QString)\0"
    "clear()\0QString\0fileName()\0int\0"
    "remove(QString)\0key,value\0"
    "setValue(QString,QVariant)\0sync()\0"
    "QVariant\0key,defaultValue\0"
    "value(QString,QVariant)\0value(QString)\0"
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Settings *_t = static_cast<Settings *>(_o);
        switch (_id) {
        case 0: _t->settingsHaveChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 1: _t->settingsChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { QStringList _r = _t->allKeys();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->contains((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->clear(); break;
        case 5: { QString _r = _t->fileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->remove((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->setValue((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 8: _t->sync(); break;
        case 9: { QVariant _r = _t->value((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 10: { QVariant _r = _t->value((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Settings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Settings::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Settings,
      qt_meta_data_Settings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Settings))
        return static_cast<void*>(const_cast< Settings*>(this));
    return QObject::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Settings::settingsHaveChanged(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
