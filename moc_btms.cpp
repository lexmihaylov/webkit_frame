/****************************************************************************
** Meta object code from reading C++ file 'btms.h'
**
** Created: Wed Feb 13 13:36:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "btms.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btms.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Btms[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,    6,    5,    5, 0x0a,
      67,    5,    5,    5, 0x0a,
      93,   86,    5,    5, 0x0a,
     116,  110,    5,    5, 0x0a,
     136,    5,    5,    5, 0x0a,
     152,  150,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Btms[] = {
    "Btms\0\0qnr,errlist\0"
    "sslErrorHandler(QNetworkReply*,QList<QSslError>)\0"
    "pageStartLoading()\0status\0pageLoaded(bool)\0"
    "frame\0doPrint(QWebFrame*)\0addJSObject()\0"
    "i\0updateProgress(int)\0"
};

const QMetaObject Btms::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Btms,
      qt_meta_data_Btms, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Btms::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Btms::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Btms::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Btms))
        return static_cast<void*>(const_cast< Btms*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Btms::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sslErrorHandler((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        case 1: pageStartLoading(); break;
        case 2: pageLoaded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: doPrint((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 4: addJSObject(); break;
        case 5: updateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
