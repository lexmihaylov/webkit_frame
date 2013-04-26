/****************************************************************************
** Meta object code from reading C++ file 'btmsjavascript.h'
**
** Created: Tue Feb 12 15:13:18 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "btmsjavascript.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btmsjavascript.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BtmsJavascript[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: signature, parameters, type, tag, flags
      32,   24,   16,   15, 0x02,
      57,   47,   15,   15, 0x02,
      95,   90,   16,   15, 0x02,
     120,   90,   15,   15, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_BtmsJavascript[] = {
    "BtmsJavascript\0\0QString\0command\0"
    "shell(QString)\0file,text\0"
    "filePutContents(QString,QString)\0file\0"
    "fileGetContents(QString)\0fileRemove(QString)\0"
};

const QMetaObject BtmsJavascript::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BtmsJavascript,
      qt_meta_data_BtmsJavascript, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BtmsJavascript::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BtmsJavascript::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BtmsJavascript::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BtmsJavascript))
        return static_cast<void*>(const_cast< BtmsJavascript*>(this));
    return QObject::qt_metacast(_clname);
}

int BtmsJavascript::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = shell((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: filePutContents((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: { QString _r = fileGetContents((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: fileRemove((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
