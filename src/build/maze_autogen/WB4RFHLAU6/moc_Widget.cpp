/****************************************************************************
** Meta object code from reading C++ file 'Widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../View/Widget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_s21__CaveScene_t {
    uint offsetsAndSizes[18];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[14];
    char stringdata5[7];
    char stringdata6[7];
    char stringdata7[10];
    char stringdata8[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_s21__CaveScene_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_s21__CaveScene_t qt_meta_stringdata_s21__CaveScene = {
    {
        QT_MOC_LITERAL(0, 14),  // "s21::CaveScene"
        QT_MOC_LITERAL(15, 13),  // "SetBirthLimit"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 5),  // "limit"
        QT_MOC_LITERAL(36, 13),  // "SetDeathLimit"
        QT_MOC_LITERAL(50, 6),  // "Create"
        QT_MOC_LITERAL(57, 6),  // "Update"
        QT_MOC_LITERAL(64, 9),  // "AutoTimer"
        QT_MOC_LITERAL(74, 4)   // "Draw"
    },
    "s21::CaveScene",
    "SetBirthLimit",
    "",
    "limit",
    "SetDeathLimit",
    "Create",
    "Update",
    "AutoTimer",
    "Draw"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_s21__CaveScene[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    1,   53,    2, 0x0a,    3 /* Public */,
       5,    0,   56,    2, 0x0a,    5 /* Public */,
       6,    0,   57,    2, 0x0a,    6 /* Public */,
       7,    0,   58,    2, 0x0a,    7 /* Public */,
       8,    0,   59,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::CaveScene::staticMetaObject = { {
    QMetaObject::SuperData::link<Scene::staticMetaObject>(),
    qt_meta_stringdata_s21__CaveScene.offsetsAndSizes,
    qt_meta_data_s21__CaveScene,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__CaveScene_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CaveScene, std::true_type>,
        // method 'SetBirthLimit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SetDeathLimit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'Create'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'AutoTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Draw'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::CaveScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CaveScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SetBirthLimit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->SetDeathLimit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->Create(); break;
        case 3: _t->Update(); break;
        case 4: _t->AutoTimer(); break;
        case 5: _t->Draw(); break;
        default: ;
        }
    }
}

const QMetaObject *s21::CaveScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::CaveScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__CaveScene.stringdata0))
        return static_cast<void*>(this);
    return Scene::qt_metacast(_clname);
}

int s21::CaveScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Scene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
namespace {
struct qt_meta_stringdata_s21__MazeScene_t {
    uint offsetsAndSizes[6];
    char stringdata0[15];
    char stringdata1[7];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_s21__MazeScene_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_s21__MazeScene_t qt_meta_stringdata_s21__MazeScene = {
    {
        QT_MOC_LITERAL(0, 14),  // "s21::MazeScene"
        QT_MOC_LITERAL(15, 6),  // "Create"
        QT_MOC_LITERAL(22, 0)   // ""
    },
    "s21::MazeScene",
    "Create",
    ""
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_s21__MazeScene[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::MazeScene::staticMetaObject = { {
    QMetaObject::SuperData::link<Scene::staticMetaObject>(),
    qt_meta_stringdata_s21__MazeScene.offsetsAndSizes,
    qt_meta_data_s21__MazeScene,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__MazeScene_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MazeScene, std::true_type>,
        // method 'Create'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void s21::MazeScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MazeScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Create(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *s21::MazeScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::MazeScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__MazeScene.stringdata0))
        return static_cast<void*>(this);
    return Scene::qt_metacast(_clname);
}

int s21::MazeScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Scene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_stringdata_s21__Widget_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_s21__Widget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_s21__Widget_t qt_meta_stringdata_s21__Widget = {
    {
        QT_MOC_LITERAL(0, 11)   // "s21::Widget"
    },
    "s21::Widget"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_s21__Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject s21::Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__Widget.offsetsAndSizes,
    qt_meta_data_s21__Widget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_s21__Widget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Widget, std::true_type>
    >,
    nullptr
} };

void s21::Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *s21::Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
