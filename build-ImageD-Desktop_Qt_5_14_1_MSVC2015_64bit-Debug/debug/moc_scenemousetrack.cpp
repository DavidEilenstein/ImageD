/****************************************************************************
** Meta object code from reading C++ file 'scenemousetrack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Code/scenemousetrack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scenemousetrack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SceneMouseTrack_t {
    QByteArrayData data[40];
    char stringdata0[732];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SceneMouseTrack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SceneMouseTrack_t qt_meta_stringdata_SceneMouseTrack = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SceneMouseTrack"
QT_MOC_LITERAL(1, 16, 10), // "mouseMoved"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 1), // "x"
QT_MOC_LITERAL(4, 30, 1), // "y"
QT_MOC_LITERAL(5, 32, 15), // "mouseMoved_Ctrl"
QT_MOC_LITERAL(6, 48, 17), // "MouseClickedAtPos"
QT_MOC_LITERAL(7, 66, 22), // "MouseClickedAtPos_Ctrl"
QT_MOC_LITERAL(8, 89, 22), // "MouseClickedAtPos_Left"
QT_MOC_LITERAL(9, 112, 27), // "MouseClickedAtPos_Left_Ctrl"
QT_MOC_LITERAL(10, 140, 23), // "MouseClickedAtPos_Right"
QT_MOC_LITERAL(11, 164, 28), // "MouseClickedAtPos_Right_Ctrl"
QT_MOC_LITERAL(12, 193, 21), // "MouseClickedAtPos_Mid"
QT_MOC_LITERAL(13, 215, 26), // "MouseClickedAtPos_Mid_Ctrl"
QT_MOC_LITERAL(14, 242, 18), // "MouseScrolledAtPos"
QT_MOC_LITERAL(15, 261, 5), // "delta"
QT_MOC_LITERAL(16, 267, 23), // "MouseScrolledAtPos_Ctrl"
QT_MOC_LITERAL(17, 291, 15), // "KeyPressed_Plus"
QT_MOC_LITERAL(18, 307, 20), // "KeyPressed_Plus_Ctrl"
QT_MOC_LITERAL(19, 328, 16), // "KeyPressed_Minus"
QT_MOC_LITERAL(20, 345, 21), // "KeyPressed_Minus_Ctrl"
QT_MOC_LITERAL(21, 367, 17), // "MouseClicked_Left"
QT_MOC_LITERAL(22, 385, 22), // "MouseClicked_Left_Ctrl"
QT_MOC_LITERAL(23, 408, 18), // "MouseClicked_Right"
QT_MOC_LITERAL(24, 427, 23), // "MouseClicked_Right_Ctrl"
QT_MOC_LITERAL(25, 451, 16), // "MouseClicked_Mid"
QT_MOC_LITERAL(26, 468, 21), // "MouseClicked_Mid_Ctrl"
QT_MOC_LITERAL(27, 490, 24), // "MouseDoubleClicked_Right"
QT_MOC_LITERAL(28, 515, 29), // "MouseDoubleClicked_Right_Ctrl"
QT_MOC_LITERAL(29, 545, 23), // "MouseDoubleClicked_Left"
QT_MOC_LITERAL(30, 569, 28), // "MouseDoubleClicked_Left_Ctrl"
QT_MOC_LITERAL(31, 598, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(32, 613, 25), // "QGraphicsSceneMouseEvent*"
QT_MOC_LITERAL(33, 639, 5), // "event"
QT_MOC_LITERAL(34, 645, 15), // "mousePressEvent"
QT_MOC_LITERAL(35, 661, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(36, 683, 10), // "wheelEvent"
QT_MOC_LITERAL(37, 694, 12), // "QWheelEvent*"
QT_MOC_LITERAL(38, 707, 13), // "keyPressEvent"
QT_MOC_LITERAL(39, 721, 10) // "QKeyEvent*"

    },
    "SceneMouseTrack\0mouseMoved\0\0x\0y\0"
    "mouseMoved_Ctrl\0MouseClickedAtPos\0"
    "MouseClickedAtPos_Ctrl\0MouseClickedAtPos_Left\0"
    "MouseClickedAtPos_Left_Ctrl\0"
    "MouseClickedAtPos_Right\0"
    "MouseClickedAtPos_Right_Ctrl\0"
    "MouseClickedAtPos_Mid\0MouseClickedAtPos_Mid_Ctrl\0"
    "MouseScrolledAtPos\0delta\0"
    "MouseScrolledAtPos_Ctrl\0KeyPressed_Plus\0"
    "KeyPressed_Plus_Ctrl\0KeyPressed_Minus\0"
    "KeyPressed_Minus_Ctrl\0MouseClicked_Left\0"
    "MouseClicked_Left_Ctrl\0MouseClicked_Right\0"
    "MouseClicked_Right_Ctrl\0MouseClicked_Mid\0"
    "MouseClicked_Mid_Ctrl\0MouseDoubleClicked_Right\0"
    "MouseDoubleClicked_Right_Ctrl\0"
    "MouseDoubleClicked_Left\0"
    "MouseDoubleClicked_Left_Ctrl\0"
    "mouseMoveEvent\0QGraphicsSceneMouseEvent*\0"
    "event\0mousePressEvent\0mouseDoubleClickEvent\0"
    "wheelEvent\0QWheelEvent*\0keyPressEvent\0"
    "QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SceneMouseTrack[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      26,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  169,    2, 0x06 /* Public */,
       5,    2,  174,    2, 0x06 /* Public */,
       6,    2,  179,    2, 0x06 /* Public */,
       7,    2,  184,    2, 0x06 /* Public */,
       8,    2,  189,    2, 0x06 /* Public */,
       9,    2,  194,    2, 0x06 /* Public */,
      10,    2,  199,    2, 0x06 /* Public */,
      11,    2,  204,    2, 0x06 /* Public */,
      12,    2,  209,    2, 0x06 /* Public */,
      13,    2,  214,    2, 0x06 /* Public */,
      14,    3,  219,    2, 0x06 /* Public */,
      16,    3,  226,    2, 0x06 /* Public */,
      17,    0,  233,    2, 0x06 /* Public */,
      18,    0,  234,    2, 0x06 /* Public */,
      19,    0,  235,    2, 0x06 /* Public */,
      20,    0,  236,    2, 0x06 /* Public */,
      21,    0,  237,    2, 0x06 /* Public */,
      22,    0,  238,    2, 0x06 /* Public */,
      23,    0,  239,    2, 0x06 /* Public */,
      24,    0,  240,    2, 0x06 /* Public */,
      25,    0,  241,    2, 0x06 /* Public */,
      26,    0,  242,    2, 0x06 /* Public */,
      27,    0,  243,    2, 0x06 /* Public */,
      28,    0,  244,    2, 0x06 /* Public */,
      29,    0,  245,    2, 0x06 /* Public */,
      30,    0,  246,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      31,    1,  247,    2, 0x0a /* Public */,
      34,    1,  250,    2, 0x0a /* Public */,
      35,    1,  253,    2, 0x0a /* Public */,
      36,    1,  256,    2, 0x0a /* Public */,
      38,    1,  259,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 37,   33,
    QMetaType::Void, 0x80000000 | 39,   33,

       0        // eod
};

void SceneMouseTrack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SceneMouseTrack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->mouseMoved_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->MouseClickedAtPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->MouseClickedAtPos_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->MouseClickedAtPos_Left((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->MouseClickedAtPos_Left_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->MouseClickedAtPos_Right((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->MouseClickedAtPos_Right_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->MouseClickedAtPos_Mid((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->MouseClickedAtPos_Mid_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->MouseScrolledAtPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->MouseScrolledAtPos_Ctrl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 12: _t->KeyPressed_Plus(); break;
        case 13: _t->KeyPressed_Plus_Ctrl(); break;
        case 14: _t->KeyPressed_Minus(); break;
        case 15: _t->KeyPressed_Minus_Ctrl(); break;
        case 16: _t->MouseClicked_Left(); break;
        case 17: _t->MouseClicked_Left_Ctrl(); break;
        case 18: _t->MouseClicked_Right(); break;
        case 19: _t->MouseClicked_Right_Ctrl(); break;
        case 20: _t->MouseClicked_Mid(); break;
        case 21: _t->MouseClicked_Mid_Ctrl(); break;
        case 22: _t->MouseDoubleClicked_Right(); break;
        case 23: _t->MouseDoubleClicked_Right_Ctrl(); break;
        case 24: _t->MouseDoubleClicked_Left(); break;
        case 25: _t->MouseDoubleClicked_Left_Ctrl(); break;
        case 26: _t->mouseMoveEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 27: _t->mousePressEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 28: _t->mouseDoubleClickEvent((*reinterpret_cast< QGraphicsSceneMouseEvent*(*)>(_a[1]))); break;
        case 29: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 30: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::mouseMoved)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::mouseMoved_Ctrl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Ctrl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Left)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Left_Ctrl)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Right)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Right_Ctrl)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Mid)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClickedAtPos_Mid_Ctrl)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseScrolledAtPos)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseScrolledAtPos_Ctrl)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::KeyPressed_Plus)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::KeyPressed_Plus_Ctrl)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::KeyPressed_Minus)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::KeyPressed_Minus_Ctrl)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Left)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Left_Ctrl)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Right)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Right_Ctrl)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Mid)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseClicked_Mid_Ctrl)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseDoubleClicked_Right)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseDoubleClicked_Right_Ctrl)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseDoubleClicked_Left)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (SceneMouseTrack::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SceneMouseTrack::MouseDoubleClicked_Left_Ctrl)) {
                *result = 25;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SceneMouseTrack::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_SceneMouseTrack.data,
    qt_meta_data_SceneMouseTrack,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SceneMouseTrack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SceneMouseTrack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SceneMouseTrack.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int SceneMouseTrack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void SceneMouseTrack::mouseMoved(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SceneMouseTrack::mouseMoved_Ctrl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SceneMouseTrack::MouseClickedAtPos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SceneMouseTrack::MouseClickedAtPos_Ctrl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SceneMouseTrack::MouseClickedAtPos_Left(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SceneMouseTrack::MouseClickedAtPos_Left_Ctrl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SceneMouseTrack::MouseClickedAtPos_Right(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SceneMouseTrack::MouseClickedAtPos_Right_Ctrl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SceneMouseTrack::MouseClickedAtPos_Mid(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SceneMouseTrack::MouseClickedAtPos_Mid_Ctrl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SceneMouseTrack::MouseScrolledAtPos(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SceneMouseTrack::MouseScrolledAtPos_Ctrl(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SceneMouseTrack::KeyPressed_Plus()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void SceneMouseTrack::KeyPressed_Plus_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void SceneMouseTrack::KeyPressed_Minus()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void SceneMouseTrack::KeyPressed_Minus_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void SceneMouseTrack::MouseClicked_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void SceneMouseTrack::MouseClicked_Left_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void SceneMouseTrack::MouseClicked_Right()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void SceneMouseTrack::MouseClicked_Right_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void SceneMouseTrack::MouseClicked_Mid()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void SceneMouseTrack::MouseClicked_Mid_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void SceneMouseTrack::MouseDoubleClicked_Right()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void SceneMouseTrack::MouseDoubleClicked_Right_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void SceneMouseTrack::MouseDoubleClicked_Left()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void SceneMouseTrack::MouseDoubleClicked_Left_Ctrl()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
