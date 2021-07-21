/****************************************************************************
** Meta object code from reading C++ file 'd_imagerewardsystem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/d_imagerewardsystem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_imagerewardsystem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_D_ImageRewardSystem_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_D_ImageRewardSystem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_D_ImageRewardSystem_t qt_meta_stringdata_D_ImageRewardSystem = {
    {
QT_MOC_LITERAL(0, 0, 19), // "D_ImageRewardSystem"
QT_MOC_LITERAL(1, 20, 10), // "get_reward"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 12), // "set_mode_cat"
QT_MOC_LITERAL(4, 45, 14), // "set_mode_horse"
QT_MOC_LITERAL(5, 60, 15), // "set_mode_person"
QT_MOC_LITERAL(6, 76, 8), // "show_img"
QT_MOC_LITERAL(7, 85, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 100, 9) // "net_reply"

    },
    "D_ImageRewardSystem\0get_reward\0\0"
    "set_mode_cat\0set_mode_horse\0set_mode_person\0"
    "show_img\0QNetworkReply*\0net_reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_D_ImageRewardSystem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void D_ImageRewardSystem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<D_ImageRewardSystem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->get_reward();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->set_mode_cat(); break;
        case 2: _t->set_mode_horse(); break;
        case 3: _t->set_mode_person(); break;
        case 4: _t->show_img((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject D_ImageRewardSystem::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_D_ImageRewardSystem.data,
    qt_meta_data_D_ImageRewardSystem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *D_ImageRewardSystem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *D_ImageRewardSystem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_D_ImageRewardSystem.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int D_ImageRewardSystem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
