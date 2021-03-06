/********************************************************************************
** Form generated from reading UI file 'ModelAgencyMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELAGENCYMAINWINDOW_H
#define UI_MODELAGENCYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MeshGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ModelAgencyMainWindow
{
public:
    QAction *actionQuit;
    QAction *actionLoad_Object_from_File;
    QAction *actionSave_Object_to_File;
    QAction *actionMake_Cube;
    QAction *actionMake_Sphere;
    QAction *actionMake_Cylinder;
    QAction *actionMake_Sculpture;
    QAction *actionExtra_Credit_1;
    QAction *actionExtra_Credit_2;
    QAction *actionMake_Humanoid;
    QAction *actionShow_Bounding_Box_and_Axies;
    QAction *actionCycle_Wireframe_Mode;
    QAction *actionShow_Vertex_Normals;
    QAction *actionNormal_Rendering_Mode;
    QAction *actionVisualize_Normals_as_Color;
    QAction *actionSolid_Color_Only_no_shade;
    QAction *actionVisualize_Texture_Coordinates_as_Color;
    QAction *actionCompute_Per_face_Normals;
    QAction *actionSmooth_all_Normals;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *treeView;
    QGroupBox *appearanceGroupBox;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *materialUseParentCheckBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QSpinBox *ambRSpinBox;
    QSpinBox *ambGSpinBox;
    QSpinBox *ambBSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *diffRSpinBox;
    QSpinBox *diffGSpinBox;
    QSpinBox *diffBSpinBox;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSpinBox *specRSpinBox;
    QSpinBox *specGSpinBox;
    QSpinBox *specBSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QDoubleSpinBox *shineSpinBox;
    QGroupBox *transformationGroupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *translationLabel;
    QDoubleSpinBox *translationXSpinBox;
    QDoubleSpinBox *translationYSpinBox;
    QDoubleSpinBox *translationZSpinBox;
    QFrame *line;
    QGridLayout *gridLayout;
    QDoubleSpinBox *rotationAngleSpinBox;
    QLabel *rotPivotLabel;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *rotaiotnXSpinBox;
    QDoubleSpinBox *rotaitonYSpinBox;
    QDoubleSpinBox *rotaitonZSpinBox;
    QLabel *rotationLabel;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QLabel *scaleLabel;
    QDoubleSpinBox *scaleXSpinBox;
    QDoubleSpinBox *scaleYSpinBox;
    QDoubleSpinBox *scaleZSpinBox;
    MeshGLWidget *mainGLWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuMesh;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelAgencyMainWindow)
    {
        if (ModelAgencyMainWindow->objectName().isEmpty())
            ModelAgencyMainWindow->setObjectName(QStringLiteral("ModelAgencyMainWindow"));
        ModelAgencyMainWindow->resize(1116, 801);
        ModelAgencyMainWindow->setMinimumSize(QSize(1116, 801));
        actionQuit = new QAction(ModelAgencyMainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionLoad_Object_from_File = new QAction(ModelAgencyMainWindow);
        actionLoad_Object_from_File->setObjectName(QStringLiteral("actionLoad_Object_from_File"));
        actionSave_Object_to_File = new QAction(ModelAgencyMainWindow);
        actionSave_Object_to_File->setObjectName(QStringLiteral("actionSave_Object_to_File"));
        actionMake_Cube = new QAction(ModelAgencyMainWindow);
        actionMake_Cube->setObjectName(QStringLiteral("actionMake_Cube"));
        actionMake_Sphere = new QAction(ModelAgencyMainWindow);
        actionMake_Sphere->setObjectName(QStringLiteral("actionMake_Sphere"));
        actionMake_Cylinder = new QAction(ModelAgencyMainWindow);
        actionMake_Cylinder->setObjectName(QStringLiteral("actionMake_Cylinder"));
        actionMake_Sculpture = new QAction(ModelAgencyMainWindow);
        actionMake_Sculpture->setObjectName(QStringLiteral("actionMake_Sculpture"));
        actionExtra_Credit_1 = new QAction(ModelAgencyMainWindow);
        actionExtra_Credit_1->setObjectName(QStringLiteral("actionExtra_Credit_1"));
        actionExtra_Credit_2 = new QAction(ModelAgencyMainWindow);
        actionExtra_Credit_2->setObjectName(QStringLiteral("actionExtra_Credit_2"));
        actionMake_Humanoid = new QAction(ModelAgencyMainWindow);
        actionMake_Humanoid->setObjectName(QStringLiteral("actionMake_Humanoid"));
        actionShow_Bounding_Box_and_Axies = new QAction(ModelAgencyMainWindow);
        actionShow_Bounding_Box_and_Axies->setObjectName(QStringLiteral("actionShow_Bounding_Box_and_Axies"));
        actionShow_Bounding_Box_and_Axies->setCheckable(true);
        actionCycle_Wireframe_Mode = new QAction(ModelAgencyMainWindow);
        actionCycle_Wireframe_Mode->setObjectName(QStringLiteral("actionCycle_Wireframe_Mode"));
        actionShow_Vertex_Normals = new QAction(ModelAgencyMainWindow);
        actionShow_Vertex_Normals->setObjectName(QStringLiteral("actionShow_Vertex_Normals"));
        actionShow_Vertex_Normals->setCheckable(true);
        actionNormal_Rendering_Mode = new QAction(ModelAgencyMainWindow);
        actionNormal_Rendering_Mode->setObjectName(QStringLiteral("actionNormal_Rendering_Mode"));
        actionNormal_Rendering_Mode->setCheckable(true);
        actionNormal_Rendering_Mode->setChecked(true);
        actionVisualize_Normals_as_Color = new QAction(ModelAgencyMainWindow);
        actionVisualize_Normals_as_Color->setObjectName(QStringLiteral("actionVisualize_Normals_as_Color"));
        actionVisualize_Normals_as_Color->setCheckable(true);
        actionSolid_Color_Only_no_shade = new QAction(ModelAgencyMainWindow);
        actionSolid_Color_Only_no_shade->setObjectName(QStringLiteral("actionSolid_Color_Only_no_shade"));
        actionSolid_Color_Only_no_shade->setCheckable(true);
        actionVisualize_Texture_Coordinates_as_Color = new QAction(ModelAgencyMainWindow);
        actionVisualize_Texture_Coordinates_as_Color->setObjectName(QStringLiteral("actionVisualize_Texture_Coordinates_as_Color"));
        actionVisualize_Texture_Coordinates_as_Color->setCheckable(true);
        actionCompute_Per_face_Normals = new QAction(ModelAgencyMainWindow);
        actionCompute_Per_face_Normals->setObjectName(QStringLiteral("actionCompute_Per_face_Normals"));
        actionSmooth_all_Normals = new QAction(ModelAgencyMainWindow);
        actionSmooth_all_Normals->setObjectName(QStringLiteral("actionSmooth_all_Normals"));
        centralWidget = new QWidget(ModelAgencyMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(83, 16));

        verticalLayout->addWidget(label);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(322, 273));
        treeView->setMaximumSize(QSize(322, 16777215));

        verticalLayout->addWidget(treeView);

        appearanceGroupBox = new QGroupBox(centralWidget);
        appearanceGroupBox->setObjectName(QStringLiteral("appearanceGroupBox"));
        appearanceGroupBox->setEnabled(false);
        sizePolicy1.setHeightForWidth(appearanceGroupBox->sizePolicy().hasHeightForWidth());
        appearanceGroupBox->setSizePolicy(sizePolicy1);
        appearanceGroupBox->setMinimumSize(QSize(322, 200));
        appearanceGroupBox->setMaximumSize(QSize(322, 200));
        verticalLayout_3 = new QVBoxLayout(appearanceGroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        materialUseParentCheckBox = new QCheckBox(appearanceGroupBox);
        materialUseParentCheckBox->setObjectName(QStringLiteral("materialUseParentCheckBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(materialUseParentCheckBox->sizePolicy().hasHeightForWidth());
        materialUseParentCheckBox->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(materialUseParentCheckBox);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(appearanceGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        ambRSpinBox = new QSpinBox(appearanceGroupBox);
        ambRSpinBox->setObjectName(QStringLiteral("ambRSpinBox"));
        ambRSpinBox->setMaximum(255);
        ambRSpinBox->setValue(0);

        horizontalLayout_9->addWidget(ambRSpinBox);

        ambGSpinBox = new QSpinBox(appearanceGroupBox);
        ambGSpinBox->setObjectName(QStringLiteral("ambGSpinBox"));
        ambGSpinBox->setMaximum(255);
        ambGSpinBox->setValue(0);

        horizontalLayout_9->addWidget(ambGSpinBox);

        ambBSpinBox = new QSpinBox(appearanceGroupBox);
        ambBSpinBox->setObjectName(QStringLiteral("ambBSpinBox"));
        ambBSpinBox->setMaximum(255);
        ambBSpinBox->setValue(0);

        horizontalLayout_9->addWidget(ambBSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(appearanceGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        diffRSpinBox = new QSpinBox(appearanceGroupBox);
        diffRSpinBox->setObjectName(QStringLiteral("diffRSpinBox"));
        diffRSpinBox->setMaximum(255);
        diffRSpinBox->setValue(0);

        horizontalLayout_3->addWidget(diffRSpinBox);

        diffGSpinBox = new QSpinBox(appearanceGroupBox);
        diffGSpinBox->setObjectName(QStringLiteral("diffGSpinBox"));
        diffGSpinBox->setMaximum(255);
        diffGSpinBox->setValue(0);

        horizontalLayout_3->addWidget(diffGSpinBox);

        diffBSpinBox = new QSpinBox(appearanceGroupBox);
        diffBSpinBox->setObjectName(QStringLiteral("diffBSpinBox"));
        diffBSpinBox->setMaximum(255);
        diffBSpinBox->setValue(0);

        horizontalLayout_3->addWidget(diffBSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(appearanceGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        specRSpinBox = new QSpinBox(appearanceGroupBox);
        specRSpinBox->setObjectName(QStringLiteral("specRSpinBox"));
        specRSpinBox->setMaximum(255);
        specRSpinBox->setValue(0);

        horizontalLayout_8->addWidget(specRSpinBox);

        specGSpinBox = new QSpinBox(appearanceGroupBox);
        specGSpinBox->setObjectName(QStringLiteral("specGSpinBox"));
        specGSpinBox->setMaximum(255);
        specGSpinBox->setValue(0);

        horizontalLayout_8->addWidget(specGSpinBox);

        specBSpinBox = new QSpinBox(appearanceGroupBox);
        specBSpinBox->setObjectName(QStringLiteral("specBSpinBox"));
        specBSpinBox->setMaximum(255);
        specBSpinBox->setValue(0);

        horizontalLayout_8->addWidget(specBSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(appearanceGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(label_2);

        shineSpinBox = new QDoubleSpinBox(appearanceGroupBox);
        shineSpinBox->setObjectName(QStringLiteral("shineSpinBox"));
        shineSpinBox->setMaximum(2048);
        shineSpinBox->setSingleStep(0.1);
        shineSpinBox->setValue(0);

        horizontalLayout_5->addWidget(shineSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout->addWidget(appearanceGroupBox);

        transformationGroupBox = new QGroupBox(centralWidget);
        transformationGroupBox->setObjectName(QStringLiteral("transformationGroupBox"));
        transformationGroupBox->setEnabled(false);
        sizePolicy.setHeightForWidth(transformationGroupBox->sizePolicy().hasHeightForWidth());
        transformationGroupBox->setSizePolicy(sizePolicy);
        transformationGroupBox->setMinimumSize(QSize(322, 213));
        transformationGroupBox->setMaximumSize(QSize(322, 213));
        verticalLayout_7 = new QVBoxLayout(transformationGroupBox);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        translationLabel = new QLabel(transformationGroupBox);
        translationLabel->setObjectName(QStringLiteral("translationLabel"));

        horizontalLayout_7->addWidget(translationLabel);

        translationXSpinBox = new QDoubleSpinBox(transformationGroupBox);
        translationXSpinBox->setObjectName(QStringLiteral("translationXSpinBox"));
        translationXSpinBox->setMinimum(-999.99);
        translationXSpinBox->setMaximum(999.99);
        translationXSpinBox->setSingleStep(0.01);

        horizontalLayout_7->addWidget(translationXSpinBox);

        translationYSpinBox = new QDoubleSpinBox(transformationGroupBox);
        translationYSpinBox->setObjectName(QStringLiteral("translationYSpinBox"));
        translationYSpinBox->setMinimum(-999.99);
        translationYSpinBox->setMaximum(999.99);
        translationYSpinBox->setSingleStep(0.01);

        horizontalLayout_7->addWidget(translationYSpinBox);

        translationZSpinBox = new QDoubleSpinBox(transformationGroupBox);
        translationZSpinBox->setObjectName(QStringLiteral("translationZSpinBox"));
        translationZSpinBox->setMinimum(-999.99);
        translationZSpinBox->setMaximum(999.99);
        translationZSpinBox->setSingleStep(0.01);

        horizontalLayout_7->addWidget(translationZSpinBox);


        verticalLayout_7->addLayout(horizontalLayout_7);

        line = new QFrame(transformationGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rotationAngleSpinBox = new QDoubleSpinBox(transformationGroupBox);
        rotationAngleSpinBox->setObjectName(QStringLiteral("rotationAngleSpinBox"));
        rotationAngleSpinBox->setMinimum(-180);
        rotationAngleSpinBox->setMaximum(180);
        rotationAngleSpinBox->setSingleStep(1);

        gridLayout->addWidget(rotationAngleSpinBox, 0, 1, 1, 1);

        rotPivotLabel = new QLabel(transformationGroupBox);
        rotPivotLabel->setObjectName(QStringLiteral("rotPivotLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(rotPivotLabel->sizePolicy().hasHeightForWidth());
        rotPivotLabel->setSizePolicy(sizePolicy4);
        rotPivotLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(rotPivotLabel, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        rotaiotnXSpinBox = new QDoubleSpinBox(transformationGroupBox);
        rotaiotnXSpinBox->setObjectName(QStringLiteral("rotaiotnXSpinBox"));
        rotaiotnXSpinBox->setMinimum(-999.99);
        rotaiotnXSpinBox->setMaximum(999.99);
        rotaiotnXSpinBox->setSingleStep(0.01);
        rotaiotnXSpinBox->setValue(0);

        horizontalLayout_2->addWidget(rotaiotnXSpinBox);

        rotaitonYSpinBox = new QDoubleSpinBox(transformationGroupBox);
        rotaitonYSpinBox->setObjectName(QStringLiteral("rotaitonYSpinBox"));
        rotaitonYSpinBox->setMinimum(-999.99);
        rotaitonYSpinBox->setMaximum(999.99);
        rotaitonYSpinBox->setSingleStep(0.01);

        horizontalLayout_2->addWidget(rotaitonYSpinBox);

        rotaitonZSpinBox = new QDoubleSpinBox(transformationGroupBox);
        rotaitonZSpinBox->setObjectName(QStringLiteral("rotaitonZSpinBox"));
        rotaitonZSpinBox->setMinimum(-999.99);
        rotaitonZSpinBox->setMaximum(999.99);
        rotaitonZSpinBox->setSingleStep(0.01);

        horizontalLayout_2->addWidget(rotaitonZSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        rotationLabel = new QLabel(transformationGroupBox);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));

        gridLayout->addWidget(rotationLabel, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        line_2 = new QFrame(transformationGroupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scaleLabel = new QLabel(transformationGroupBox);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));

        horizontalLayout->addWidget(scaleLabel);

        scaleXSpinBox = new QDoubleSpinBox(transformationGroupBox);
        scaleXSpinBox->setObjectName(QStringLiteral("scaleXSpinBox"));
        scaleXSpinBox->setMinimum(-999.99);
        scaleXSpinBox->setMaximum(999.99);
        scaleXSpinBox->setSingleStep(0.01);
        scaleXSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleXSpinBox);

        scaleYSpinBox = new QDoubleSpinBox(transformationGroupBox);
        scaleYSpinBox->setObjectName(QStringLiteral("scaleYSpinBox"));
        scaleYSpinBox->setMinimum(-999.99);
        scaleYSpinBox->setMaximum(999.99);
        scaleYSpinBox->setSingleStep(0.01);
        scaleYSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleYSpinBox);

        scaleZSpinBox = new QDoubleSpinBox(transformationGroupBox);
        scaleZSpinBox->setObjectName(QStringLiteral("scaleZSpinBox"));
        scaleZSpinBox->setMinimum(-999.99);
        scaleZSpinBox->setMaximum(999.99);
        scaleZSpinBox->setSingleStep(0.01);
        scaleZSpinBox->setValue(1);

        horizontalLayout->addWidget(scaleZSpinBox);


        verticalLayout_7->addLayout(horizontalLayout);


        verticalLayout->addWidget(transformationGroupBox);


        horizontalLayout_4->addLayout(verticalLayout);

        mainGLWidget = new MeshGLWidget(centralWidget);
        mainGLWidget->setObjectName(QStringLiteral("mainGLWidget"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(mainGLWidget->sizePolicy().hasHeightForWidth());
        mainGLWidget->setSizePolicy(sizePolicy5);
        mainGLWidget->setMinimumSize(QSize(671, 681));

        horizontalLayout_4->addWidget(mainGLWidget);

        ModelAgencyMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ModelAgencyMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1116, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuMesh = new QMenu(menuBar);
        menuMesh->setObjectName(QStringLiteral("menuMesh"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        ModelAgencyMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelAgencyMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ModelAgencyMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ModelAgencyMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ModelAgencyMainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(treeView);
        label_7->setBuddy(ambRSpinBox);
        label_5->setBuddy(diffRSpinBox);
        label_6->setBuddy(specRSpinBox);
        label_2->setBuddy(shineSpinBox);
        translationLabel->setBuddy(translationXSpinBox);
        rotPivotLabel->setBuddy(rotaiotnXSpinBox);
        rotationLabel->setBuddy(rotationAngleSpinBox);
        scaleLabel->setBuddy(scaleXSpinBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(treeView, ambRSpinBox);
        QWidget::setTabOrder(ambRSpinBox, ambGSpinBox);
        QWidget::setTabOrder(ambGSpinBox, ambBSpinBox);
        QWidget::setTabOrder(ambBSpinBox, diffRSpinBox);
        QWidget::setTabOrder(diffRSpinBox, diffGSpinBox);
        QWidget::setTabOrder(diffGSpinBox, diffBSpinBox);
        QWidget::setTabOrder(diffBSpinBox, specRSpinBox);
        QWidget::setTabOrder(specRSpinBox, specGSpinBox);
        QWidget::setTabOrder(specGSpinBox, specBSpinBox);
        QWidget::setTabOrder(specBSpinBox, shineSpinBox);
        QWidget::setTabOrder(shineSpinBox, translationXSpinBox);
        QWidget::setTabOrder(translationXSpinBox, translationYSpinBox);
        QWidget::setTabOrder(translationYSpinBox, translationZSpinBox);
        QWidget::setTabOrder(translationZSpinBox, rotationAngleSpinBox);
        QWidget::setTabOrder(rotationAngleSpinBox, rotaiotnXSpinBox);
        QWidget::setTabOrder(rotaiotnXSpinBox, rotaitonYSpinBox);
        QWidget::setTabOrder(rotaitonYSpinBox, rotaitonZSpinBox);
        QWidget::setTabOrder(rotaitonZSpinBox, scaleXSpinBox);
        QWidget::setTabOrder(scaleXSpinBox, scaleYSpinBox);
        QWidget::setTabOrder(scaleYSpinBox, scaleZSpinBox);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMesh->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(actionLoad_Object_from_File);
        menuFile->addAction(actionSave_Object_to_File);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuMesh->addAction(actionCompute_Per_face_Normals);
        menuMesh->addAction(actionSmooth_all_Normals);
        menuMesh->addSeparator();
        menuMesh->addAction(actionMake_Cube);
        menuMesh->addAction(actionMake_Cylinder);
        menuMesh->addAction(actionMake_Sphere);
        menuMesh->addSeparator();
        menuMesh->addAction(actionMake_Sculpture);
        menuMesh->addAction(actionMake_Humanoid);
        menuMesh->addSeparator();
        menuMesh->addAction(actionExtra_Credit_1);
        menuMesh->addAction(actionExtra_Credit_2);
        menuView->addAction(actionShow_Bounding_Box_and_Axies);
        menuView->addAction(actionShow_Vertex_Normals);
        menuView->addSeparator();
        menuView->addAction(actionCycle_Wireframe_Mode);
        menuView->addSeparator();
        menuView->addAction(actionNormal_Rendering_Mode);
        menuView->addAction(actionSolid_Color_Only_no_shade);
        menuView->addAction(actionVisualize_Normals_as_Color);
        menuView->addAction(actionVisualize_Texture_Coordinates_as_Color);

        retranslateUi(ModelAgencyMainWindow);
        QObject::connect(translationXSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(translationYSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(translationZSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(rotationAngleSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(rotaiotnXSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(rotaitonYSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(rotaitonZSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(scaleXSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(scaleYSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(scaleZSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncTransformation()));
        QObject::connect(ambRSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(ambGSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(ambBSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(diffRSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(diffGSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(diffBSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(specRSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(specGSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(specBSpinBox, SIGNAL(valueChanged(int)), ModelAgencyMainWindow, SLOT(syncMaterials()));
        QObject::connect(shineSpinBox, SIGNAL(valueChanged(double)), ModelAgencyMainWindow, SLOT(syncMaterials()));

        QMetaObject::connectSlotsByName(ModelAgencyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ModelAgencyMainWindow)
    {
        ModelAgencyMainWindow->setWindowTitle(QApplication::translate("ModelAgencyMainWindow", "Model Agency", 0));
        actionQuit->setText(QApplication::translate("ModelAgencyMainWindow", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Quit the Project", 0));
#endif // QT_NO_TOOLTIP
        actionLoad_Object_from_File->setText(QApplication::translate("ModelAgencyMainWindow", "Load Object from File ...", 0));
#ifndef QT_NO_TOOLTIP
        actionLoad_Object_from_File->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Load a mesh from an OBJ file.", 0));
#endif // QT_NO_TOOLTIP
        actionSave_Object_to_File->setText(QApplication::translate("ModelAgencyMainWindow", "Save Object to File ...", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_Object_to_File->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Save the current mesh object to an OBJ file.", 0));
#endif // QT_NO_TOOLTIP
        actionMake_Cube->setText(QApplication::translate("ModelAgencyMainWindow", "Make Cube", 0));
#ifndef QT_NO_TOOLTIP
        actionMake_Cube->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make a cube mesh and add it to the GL Widget", 0));
#endif // QT_NO_TOOLTIP
        actionMake_Sphere->setText(QApplication::translate("ModelAgencyMainWindow", "Make Sphere", 0));
#ifndef QT_NO_TOOLTIP
        actionMake_Sphere->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make a sphere mesh and add it the GL Widget", 0));
#endif // QT_NO_TOOLTIP
        actionMake_Cylinder->setText(QApplication::translate("ModelAgencyMainWindow", "Make Cylinder", 0));
#ifndef QT_NO_TOOLTIP
        actionMake_Cylinder->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make a cylinder mesh and add it to the GL widget", 0));
#endif // QT_NO_TOOLTIP
        actionMake_Sculpture->setText(QApplication::translate("ModelAgencyMainWindow", "Make Sculpture", 0));
#ifndef QT_NO_TOOLTIP
        actionMake_Sculpture->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make the sculpture mesh and add it to the GL Widget", 0));
#endif // QT_NO_TOOLTIP
        actionExtra_Credit_1->setText(QApplication::translate("ModelAgencyMainWindow", "Extra Credit 1", 0));
#ifndef QT_NO_TOOLTIP
        actionExtra_Credit_1->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make the 1st extra credit mesh if it is implemented.", 0));
#endif // QT_NO_TOOLTIP
        actionExtra_Credit_2->setText(QApplication::translate("ModelAgencyMainWindow", "Extra Credit 2", 0));
#ifndef QT_NO_TOOLTIP
        actionExtra_Credit_2->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Make the 2nd extra credit mesh if it is implemented.", 0));
#endif // QT_NO_TOOLTIP
        actionMake_Humanoid->setText(QApplication::translate("ModelAgencyMainWindow", "Make Humanoid", 0));
#ifndef QT_NO_TOOLTIP
        actionMake_Humanoid->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Create the humanoid mesh and add it to the GL Widget.", 0));
#endif // QT_NO_TOOLTIP
        actionShow_Bounding_Box_and_Axies->setText(QApplication::translate("ModelAgencyMainWindow", "Show Bounding Box and Axies", 0));
        actionCycle_Wireframe_Mode->setText(QApplication::translate("ModelAgencyMainWindow", "Cycle Wireframe Mode", 0));
        actionShow_Vertex_Normals->setText(QApplication::translate("ModelAgencyMainWindow", "Show Vertex Normals", 0));
        actionNormal_Rendering_Mode->setText(QApplication::translate("ModelAgencyMainWindow", "Standard Rendering Mode", 0));
        actionVisualize_Normals_as_Color->setText(QApplication::translate("ModelAgencyMainWindow", "Visualize Normals as Color", 0));
#ifndef QT_NO_TOOLTIP
        actionVisualize_Normals_as_Color->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Visualize Normals as Color", 0));
#endif // QT_NO_TOOLTIP
        actionSolid_Color_Only_no_shade->setText(QApplication::translate("ModelAgencyMainWindow", "Solid Color Only (no shade)", 0));
        actionVisualize_Texture_Coordinates_as_Color->setText(QApplication::translate("ModelAgencyMainWindow", "Visualize Texture Coordinates as Color", 0));
        actionCompute_Per_face_Normals->setText(QApplication::translate("ModelAgencyMainWindow", "Compute Per-face Normals", 0));
        actionSmooth_all_Normals->setText(QApplication::translate("ModelAgencyMainWindow", "Smooth all Normals", 0));
        label->setText(QApplication::translate("ModelAgencyMainWindow", "Mesh Object:", 0));
        appearanceGroupBox->setTitle(QApplication::translate("ModelAgencyMainWindow", "Appearance", 0));
        materialUseParentCheckBox->setText(QApplication::translate("ModelAgencyMainWindow", "Use Parent Properties", 0));
        label_7->setText(QApplication::translate("ModelAgencyMainWindow", "Ambient:", 0));
#ifndef QT_NO_TOOLTIP
        ambRSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Red component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ambGSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Green component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ambBSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Blue component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("ModelAgencyMainWindow", "Diffuse:", 0));
#ifndef QT_NO_TOOLTIP
        diffRSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Red component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        diffGSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Green component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        diffBSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Blue component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("ModelAgencyMainWindow", "Specualr:", 0));
#ifndef QT_NO_TOOLTIP
        specRSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Red component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        specGSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Green component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        specBSpinBox->setToolTip(QApplication::translate("ModelAgencyMainWindow", "Blue component (0 - 255)", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("ModelAgencyMainWindow", "Shininess:", 0));
        transformationGroupBox->setTitle(QApplication::translate("ModelAgencyMainWindow", "Transformation", 0));
        translationLabel->setText(QApplication::translate("ModelAgencyMainWindow", "Trans:", 0));
        rotPivotLabel->setText(QApplication::translate("ModelAgencyMainWindow", "Axis", 0));
        rotationLabel->setText(QApplication::translate("ModelAgencyMainWindow", "Rotation:", 0));
        scaleLabel->setText(QApplication::translate("ModelAgencyMainWindow", "Scale:", 0));
        menuFile->setTitle(QApplication::translate("ModelAgencyMainWindow", "File", 0));
        menuMesh->setTitle(QApplication::translate("ModelAgencyMainWindow", "Mesh", 0));
        menuView->setTitle(QApplication::translate("ModelAgencyMainWindow", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class ModelAgencyMainWindow: public Ui_ModelAgencyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELAGENCYMAINWINDOW_H
