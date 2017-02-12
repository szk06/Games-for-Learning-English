/****************************************************************************
** Meta object code from reading C++ file 'lev4game.h'
**
** Created: Fri Dec 2 18:46:19 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "game_4/lev4game.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lev4game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_lev4game[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      35,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_lev4game[] = {
    "lev4game\0\0shuffle_letters_widget()\0"
    "exchange_letters_widget()\0"
};

void lev4game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        lev4game *_t = static_cast<lev4game *>(_o);
        switch (_id) {
        case 0: _t->shuffle_letters_widget(); break;
        case 1: _t->exchange_letters_widget(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData lev4game::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject lev4game::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_lev4game,
      qt_meta_data_lev4game, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &lev4game::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *lev4game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *lev4game::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_lev4game))
        return static_cast<void*>(const_cast< lev4game*>(this));
    return QWidget::qt_metacast(_clname);
}

int lev4game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
