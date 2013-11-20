/****************************************************************************
** Meta object code from reading C++ file 'AnimatrixMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CGProject4-Animatrix/include/AnimatrixMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimatrixMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimatrixMainWindow_t {
    QByteArrayData data[22];
    char stringdata[599];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AnimatrixMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AnimatrixMainWindow_t qt_meta_stringdata_AnimatrixMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 36),
QT_MOC_LITERAL(2, 57, 0),
QT_MOC_LITERAL(3, 58, 5),
QT_MOC_LITERAL(4, 64, 28),
QT_MOC_LITERAL(5, 93, 21),
QT_MOC_LITERAL(6, 115, 40),
QT_MOC_LITERAL(7, 156, 38),
QT_MOC_LITERAL(8, 195, 23),
QT_MOC_LITERAL(9, 219, 37),
QT_MOC_LITERAL(10, 257, 38),
QT_MOC_LITERAL(11, 296, 38),
QT_MOC_LITERAL(12, 335, 7),
QT_MOC_LITERAL(13, 343, 43),
QT_MOC_LITERAL(14, 387, 55),
QT_MOC_LITERAL(15, 443, 42),
QT_MOC_LITERAL(16, 486, 36),
QT_MOC_LITERAL(17, 523, 13),
QT_MOC_LITERAL(18, 537, 18),
QT_MOC_LITERAL(19, 556, 24),
QT_MOC_LITERAL(20, 581, 7),
QT_MOC_LITERAL(21, 589, 8)
    },
    "AnimatrixMainWindow\0"
    "on_animationFrameSlider_valueChanged\0"
    "\0value\0on_setKeyframeButton_clicked\0"
    "on_playButton_clicked\0"
    "on_actionLoad_Object_from_File_triggered\0"
    "on_actionSave_Object_to_File_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionMake_Humanoid_Walk_triggered\0"
    "on_actionMake_Humanoid_Other_triggered\0"
    "on_actionNormal_Rendering_Mode_toggled\0"
    "checked\0on_actionVisualize_Normals_as_Color_toggled\0"
    "on_actionVisualize_Texture_Coordinates_as_Color_toggled\0"
    "on_actionSolid_Color_Only_no_shade_toggled\0"
    "on_materialUseParentCheckBox_toggled\0"
    "syncMaterials\0syncTransformation\0"
    "treeViewSelectionChanged\0current\0"
    "previous\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimatrixMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x09,
       4,    0,   97,    2, 0x09,
       5,    0,   98,    2, 0x09,
       6,    0,   99,    2, 0x09,
       7,    0,  100,    2, 0x09,
       8,    0,  101,    2, 0x09,
       9,    0,  102,    2, 0x09,
      10,    0,  103,    2, 0x09,
      11,    1,  104,    2, 0x09,
      13,    1,  107,    2, 0x09,
      14,    1,  110,    2, 0x09,
      15,    1,  113,    2, 0x09,
      16,    1,  116,    2, 0x09,
      17,    0,  119,    2, 0x09,
      18,    0,  120,    2, 0x09,
      19,    2,  121,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   20,   21,

       0        // eod
};

void AnimatrixMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimatrixMainWindow *_t = static_cast<AnimatrixMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_animationFrameSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_setKeyframeButton_clicked(); break;
        case 2: _t->on_playButton_clicked(); break;
        case 3: _t->on_actionLoad_Object_from_File_triggered(); break;
        case 4: _t->on_actionSave_Object_to_File_triggered(); break;
        case 5: _t->on_actionQuit_triggered(); break;
        case 6: _t->on_actionMake_Humanoid_Walk_triggered(); break;
        case 7: _t->on_actionMake_Humanoid_Other_triggered(); break;
        case 8: _t->on_actionNormal_Rendering_Mode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_actionVisualize_Normals_as_Color_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_actionVisualize_Texture_Coordinates_as_Color_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_actionSolid_Color_Only_no_shade_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_materialUseParentCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->syncMaterials(); break;
        case 14: _t->syncTransformation(); break;
        case 15: _t->treeViewSelectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject AnimatrixMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AnimatrixMainWindow.data,
      qt_meta_data_AnimatrixMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *AnimatrixMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimatrixMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AnimatrixMainWindow.stringdata))
        return static_cast<void*>(const_cast< AnimatrixMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AnimatrixMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
