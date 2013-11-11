#-------------------------------------------------
#
# Project created by Seth Berrier 2012-09-10
# - Updated 10/22/2013 by Seth Berrier
#
#-------------------------------------------------
# Animatrix.pro:
#   This file defines all the pieces of our
# program for 'qmake', a component of Qt.  It is
# processed by qmake in order to generate the
# build files for your system (usually Makefiles
# but could be a .sln or an xcode project).  You
# can open this file directly in Qt Creator to
# edit and manage the project in Qt's own IDE.
#-------------------------------------------------

# The Qt modules we need (GUIs, OpenGL and the core of Qt)
QT += core gui opengl

# Make sure each object will get rebuilt when a dependent header changes
CONFIG += depend_includepath

# If using Qt 5 or greater then we need to add the 'widgets' module as well
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# The name of this application (and it's type, an app)
TARGET = Animatrix
TEMPLATE = app

# Where to put all the intermediate files generated during compilation
OBJECTS_DIR = obj/
MOC_DIR = moc/
UI_DIR = ui/

# Add this so we don't have to append 'include' in front of every .h file
INCLUDEPATH += include/

# All the source code that is part of this project
SOURCES += src/main.cpp\
    src/AnimatrixMainWindow.cpp \
    src/OpenGLRenderable.cpp \
    src/MeshGLWidget.cpp \
    src/GL3DShaderWidget.cpp \
    src/View.cpp \
    src/ObjMesh.cpp \
    src/MaterialProperties.cpp \
    src/Tesselator.cpp \
    src/Trackball.cpp \
    src/TrackballWidget.cpp \
    src/HierarchicalMeshModel.cpp \
    src/ObjectNode.cpp \
    src/ObjectFactory.cpp \
    src/GLRenderMatrixContext.cpp

HEADERS += include/AnimatrixMainWindow.h \
    include/OpenGLRenderable.h \
    include/CGCommon.h \
    include/MeshGLWidget.h \
    include/GL3DShaderWidget.h \
    include/View.h \
    include/ObjMesh.h \
    include/MaterialProperties.h \
    include/Tesselator.h \
    include/Trackball.h \
    include/TrackballWidget.h \
    include/ObjectNode.h \
    include/HierarchicalMeshModel.h \
    include/ObjectFactory.h \
    include/GLRenderMatrixContext.h

# The 'form' files that define the layout of the GUI and various dialogs
FORMS += forms/AnimatrixMainWindow.ui \
    forms/CylinderDialog.ui \
    forms/SphereDialog.ui \
    forms/GenericDialog.ui

# The shaders used by OpenGL
OTHER_FILES += \
    shaders/Material.vert \
    shaders/Material.frag

# Resource file that includes the shaders
RESOURCES += Animatrix.qrc
