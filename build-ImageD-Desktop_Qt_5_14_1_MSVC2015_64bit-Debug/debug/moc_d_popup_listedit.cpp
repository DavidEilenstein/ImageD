/****************************************************************************
** Meta object code from reading C++ file 'd_popup_listedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Code/d_popup_listedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'd_popup_listedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_D_Popup_ListEdit_t {
    QByteArrayData data[9];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_D_Popup_ListEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_D_Popup_ListEdit_t qt_meta_stringdata_D_Popup_ListEdit = {
    {
QT_MOC_LITERAL(0, 0, 16), // "D_Popup_ListEdit"
QT_MOC_LITERAL(1, 17, 13), // "ShowSelection"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "on_pushButton_Add_clicked"
QT_MOC_LITERAL(4, 58, 25), // "on_pushButton_All_clicked"
QT_MOC_LITERAL(5, 84, 28), // "on_pushButton_Remove_clicked"
QT_MOC_LITERAL(6, 113, 27), // "on_pushButton_Clear_clicked"
QT_MOC_LITERAL(7, 141, 27), // "on_pushButton_Reset_clicked"
QT_MOC_LITERAL(8, 169, 26) // "on_pushButton_Done_clicked"

    },
    "D_Popup_ListEdit\0ShowSelection\0\0"
    "on_pushButton_Add_clicked\0"
    "on_pushButton_All_clicked\0"
    "on_pushButton_Remove_clicked\0"
    "on_pushButton_Clear_clicked\0"
    "on_pushButton_Reset_clicked\0"
    "on_pushButton_Done_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_D_Popup_ListEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void D_Popup_ListEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<D_Popup_ListEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowSelection(); break;
        case 1: _t->on_pushButton_Add_clicked(); break;
        case 2: _t->on_pushButton_All_clicked(); break;
        case 3: _t->on_pushButton_Remove_clicked(); break;
        case 4: _t->on_pushButton_Clear_clicked(); break;
        case 5: _t->on_pushButton_Reset_clicked(); break;
        case 6: _t->on_pushButton_Done_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject D_Popup_ListEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_D_Popup_ListEdit.data,
    qt_meta_data_D_Popup_ListEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *D_Popup_ListEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *D_Popup_ListEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_D_Popup_ListEdit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int D_Popup_ListEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
