/****************************************************************************
** Meta object code from reading C++ file 'ModelAgencyMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CGProject3-ModelAgency/include/ModelAgencyMainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModelAgencyMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModelAgencyMainWindow_t {
    QByteArrayData data[23];
    char stringdata[658];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ModelAgencyMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ModelAgencyMainWindow_t qt_meta_stringdata_ModelAgencyMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 40),
QT_MOC_LITERAL(2, 63, 0),
QT_MOC_LITERAL(3, 64, 38),
QT_MOC_LITERAL(4, 103, 23),
QT_MOC_LITERAL(5, 127, 28),
QT_MOC_LITERAL(6, 156, 32),
QT_MOC_LITERAL(7, 189, 30),
QT_MOC_LITERAL(8, 220, 33),
QT_MOC_LITERAL(9, 254, 32),
QT_MOC_LITERAL(10, 287, 33),
QT_MOC_LITERAL(11, 321, 33),
QT_MOC_LITERAL(12, 355, 38),
QT_MOC_LITERAL(13, 394, 7),
QT_MOC_LITERAL(14, 402, 43),
QT_MOC_LITERAL(15, 446, 55),
QT_MOC_LITERAL(16, 502, 42),
QT_MOC_LITERAL(17, 545, 36),
QT_MOC_LITERAL(18, 582, 13),
QT_MOC_LITERAL(19, 596, 18),
QT_MOC_LITERAL(20, 615, 24),
QT_MOC_LITERAL(21, 640, 7),
QT_MOC_LITERAL(22, 648, 8)
    },
    "ModelAgencyMainWindow\0"
    "on_actionLoad_Object_from_File_triggered\0"
    "\0on_actionSave_Object_to_File_triggered\0"
    "on_actionQuit_triggered\0"
    "on_actionMake_Cube_triggered\0"
    "on_actionMake_Cylinder_triggered\0"
    "on_actionMake_Sphere_triggered\0"
    "on_actionMake_Sculpture_triggered\0"
    "on_actionMake_Humanoid_triggered\0"
    "on_actionExtra_Credit_1_triggered\0"
    "on_actionExtra_Credit_2_triggered\0"
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

static const uint qt_meta_data_ModelAgencyMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x09,
       3,    0,  105,    2, 0x09,
       4,    0,  106,    2, 0x09,
       5,    0,  107,    2, 0x09,
       6,    0,  108,    2, 0x09,
       7,    0,  109,    2, 0x09,
       8,    0,  110,    2, 0x09,
       9,    0,  111,    2, 0x09,
      10,    0,  112,    2, 0x09,
      11,    0,  113,    2, 0x09,
      12,    1,  114,    2, 0x09,
      14,    1,  117,    2, 0x09,
      15,    1,  120,    2, 0x09,
      16,    1,  123,    2, 0x09,
      17,    1,  126,    2, 0x09,
      18,    0,  129,    2, 0x09,
      19,    0,  130,    2, 0x09,
      20,    2,  131,    2, 0x09,

 // slots: parameters
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
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   21,   22,

       0        // eod
};

void ModelAgencyMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelAgencyMainWindow *_t = static_cast<ModelAgencyMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionLoad_Object_from_File_triggered(); break;
        case 1: _t->on_actionSave_Object_to_File_triggered(); break;
        case 2: _t->on_actionQuit_triggered(); break;
        case 3: _t->on_actionMake_Cube_triggered(); break;
        case 4: _t->on_actionMake_Cylinder_triggered(); break;
        case 5: _t->on_actionMake_Sphere_triggered(); break;
        case 6: _t->on_actionMake_Sculpture_triggered(); break;
        case 7: _t->on_actionMake_Humanoid_triggered(); break;
        case 8: _t->on_actionExtra_Credit_1_triggered(); break;
        case 9: _t->on_actionExtra_Credit_2_triggered(); break;
        case 10: _t->on_actionNormal_Rendering_Mode_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_actionVisualize_Normals_as_Color_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_actionVisualize_Texture_Coordinates_as_Color_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_actionSolid_Color_Only_no_shade_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_materialUseParentCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->syncMaterials(); break;
        case 16: _t->syncTransformation(); break;
        case 17: _t->treeViewSelectionChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ModelAgencyMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ModelAgencyMainWindow.data,
      qt_meta_data_ModelAgencyMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ModelAgencyMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModelAgencyMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelAgencyMainWindow.stringdata))
        return static_cast<void*>(const_cast< ModelAgencyMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ModelAgencyMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
