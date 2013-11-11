#include "AnimatrixMainWindow.h"
#include "ui_AnimatrixMainWindow.h"
#include "ui_SphereDialog.h"
#include "ui_CylinderDialog.h"
#include "ui_GenericDialog.h"

#include "ObjectFactory.h"
#include "ObjectNode.h"
#include "HierarchicalMeshModel.h"
#include "MaterialProperties.h"

#include <QFileDialog>
#include <QMessageBox>

AnimatrixMainWindow::AnimatrixMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnimatrixMainWindow)
{
    // Setup the UI form
    ui->setupUi(this);
    ui->actionQuit->setShortcut(QKeySequence::Quit);

    // Connect actions to GLWidget
    connect(ui->actionShow_Bounding_Box_and_Axies, SIGNAL(toggled(bool)), ui->mainGLWidget, SLOT(enableAxies(bool)));
    connect(ui->actionShow_Vertex_Normals, SIGNAL(toggled(bool)), ui->mainGLWidget, SLOT(enableNormals(bool)));
    connect(ui->actionCycle_Wireframe_Mode, SIGNAL(triggered()), ui->mainGLWidget, SLOT(cycleWireframeMode()));
    connect(ui->actionCompute_Per_face_Normals, SIGNAL(triggered()), ui->mainGLWidget, SLOT(computePerFaceNormals()));
    connect(ui->actionSmooth_all_Normals, SIGNAL(triggered()), ui->mainGLWidget, SLOT(smoothAllNormals()));

    mPlaybackTimerID = 0;
    mBlockSyncSlots = false;
    mAllowUncheck = false;
}

AnimatrixMainWindow::~AnimatrixMainWindow()
{
    delete ui;
}

void AnimatrixMainWindow::syncMaterials()
{
    if(mBlockSyncSlots) return;

    QModelIndex lCurrent = ui->treeView->currentIndex();
    if(!lCurrent.isValid()) return;

    ObjectNode* lCurObj = static_cast<ObjectNode*>(lCurrent.internalPointer());
    if(lCurObj == NULL) return;

    MaterialProperties *lMat = lCurObj->getMaterials();
    if(lMat != NULL)
    {
        lMat->setAmbient(ui->ambRSpinBox->value(), ui->ambGSpinBox->value(), ui->ambBSpinBox->value());
        lMat->setDiffuse(ui->diffRSpinBox->value(), ui->diffGSpinBox->value(), ui->diffBSpinBox->value());
        lMat->setSpecular(ui->specRSpinBox->value(), ui->specGSpinBox->value(), ui->specBSpinBox->value());
        lMat->setSpecularExp(ui->shineSpinBox->value());
    }

    ui->mainGLWidget->updateGL();
}

void AnimatrixMainWindow::syncTransformation()
{
    if(mBlockSyncSlots) return;

    QModelIndex lCurrent = ui->treeView->currentIndex();
    if(!lCurrent.isValid()) return;

    ObjectNode* lCurObj = static_cast<ObjectNode*>(lCurrent.internalPointer());
    if(lCurObj == NULL) return;

    lCurObj->setCenterOfRotation(ui->rotCenterXSpinBox->value(), ui->rotCenterYSpinBox->value(), ui->rotCenterZSpinBox->value());
    lCurObj->setTranslate(ui->translationXSpinBox->value(), ui->translationYSpinBox->value(), ui->translationZSpinBox->value());
    lCurObj->setRotate(ui->rotaiotnXSpinBox->value(), ui->rotaitonYSpinBox->value(), ui->rotaitonZSpinBox->value());
    lCurObj->setScale(ui->scaleXSpinBox->value(), ui->scaleYSpinBox->value(), ui->scaleZSpinBox->value());

    ui->mainGLWidget->updateGL();
}

// Animation controls
void AnimatrixMainWindow::on_animationFrameSlider_valueChanged(int value)
{
    // Update values from frame
    ui->mainGLWidget->changeCurrentFrame(value);

    // Sync those new values back to the UI
    QModelIndex lCurrent = ui->treeView->currentIndex();
    if(!lCurrent.isValid()) return;

    ObjectNode* lCurObj = static_cast<ObjectNode*>(lCurrent.internalPointer());
    if(lCurObj == NULL) return;

    mBlockSyncSlots = true;
    setTransformationValues(lCurObj);
    mBlockSyncSlots = false;
}

void AnimatrixMainWindow::on_setKeyframeButton_clicked()
{
    QModelIndex lCurrent = ui->treeView->currentIndex();
    if(!lCurrent.isValid())
    {
        QMessageBox::warning(this, "Select a Node", "Please select a node before setting a keyframe.");
        return;
    }

    ObjectNode* lCurObj = static_cast<ObjectNode*>(lCurrent.internalPointer());
    if(lCurObj == NULL) return;

    lCurObj->storeKeyframe(ui->animationFrameSlider->value());
}

void AnimatrixMainWindow::on_playButton_clicked()
{
    if(mPlaybackTimerID == 0)
    {
        mPlaybackTimerID = startTimer(33);
        ui->playButton->setText("Stop");
        ui->animationFrameSlider->setEnabled(false);
    }
    else
    {
        killTimer(mPlaybackTimerID);
        mPlaybackTimerID = 0;
        ui->playButton->setText("Play");
        ui->animationFrameSlider->setEnabled(true);
    }
}

void AnimatrixMainWindow::timerEvent(QTimerEvent* event)
{
    if(event->timerId() == mPlaybackTimerID)
    {
        int lCurFrame = ui->animationFrameSlider->value();
        ui->animationFrameSlider->setValue((lCurFrame+1)%(ui->animationFrameSlider->maximum()+1));
    }
}

void AnimatrixMainWindow::on_materialUseParentCheckBox_toggled(bool checked)
{
    if(checked)
    {
        int result = QMessageBox::warning(this, "Delete properties", "You will lose the material properties for this node.  Are you sure?",
                             QMessageBox::Cancel, QMessageBox::Yes);
        if(result == QMessageBox::Cancel)
        {
            ui->materialUseParentCheckBox->blockSignals(true);
            ui->materialUseParentCheckBox->setChecked(false);
            ui->materialUseParentCheckBox->blockSignals(false);
            return;
        }
    }

    QModelIndex lIndex = ui->treeView->currentIndex();
    if(!lIndex.isValid()) return;
    ObjectNode *lCurObj = static_cast<ObjectNode*>(lIndex.internalPointer());
    if(lCurObj == NULL) return;

    if(checked)
    {
        delete lCurObj->getMaterials();
        lCurObj->setMaterials(NULL);
    }
    else
    {
        MaterialProperties *lNewMat;
        if(lCurObj->parentMesh() != NULL && lCurObj->parentMesh()->getMaterials() != NULL)
        {
            lNewMat = new MaterialProperties(*lCurObj->parentMesh()->getMaterials());
        }
        else lNewMat = new MaterialProperties();

        setMaterialValues(lNewMat);
        lCurObj->setMaterials(lNewMat);
    }

    setMaterialUIState(checked);
}

inline void AnimatrixMainWindow::setMaterialUIState(bool checked)
{
    ui->ambRSpinBox->setDisabled(checked);
    ui->ambGSpinBox->setDisabled(checked);
    ui->ambBSpinBox->setDisabled(checked);

    ui->diffRSpinBox->setDisabled(checked);
    ui->diffGSpinBox->setDisabled(checked);
    ui->diffBSpinBox->setDisabled(checked);

    ui->specRSpinBox->setDisabled(checked);
    ui->specGSpinBox->setDisabled(checked);
    ui->specBSpinBox->setDisabled(checked);

    ui->shineSpinBox->setDisabled(checked);
}

inline void AnimatrixMainWindow::clearObjectUIData()
{
    ui->ambRSpinBox->setValue(0);
    ui->ambGSpinBox->setValue(0);
    ui->ambBSpinBox->setValue(0);

    ui->diffRSpinBox->setValue(0);
    ui->diffGSpinBox->setValue(0);
    ui->diffBSpinBox->setValue(0);

    ui->specRSpinBox->setValue(0);
    ui->specGSpinBox->setValue(0);
    ui->specBSpinBox->setValue(0);
    ui->shineSpinBox->setValue(0);

    ui->appearanceGroupBox->setEnabled(false);

    ui->translationXSpinBox->setValue(0);
    ui->translationYSpinBox->setValue(0);
    ui->translationZSpinBox->setValue(0);

    ui->scaleXSpinBox->setValue(1);
    ui->scaleYSpinBox->setValue(1);
    ui->scaleZSpinBox->setValue(1);

    ui->rotaiotnXSpinBox->setValue(0);
    ui->rotaitonYSpinBox->setValue(0);
    ui->rotaitonZSpinBox->setValue(0);

    ui->rotCenterXSpinBox->setValue(0);
    ui->rotCenterYSpinBox->setValue(0);
    ui->rotCenterZSpinBox->setValue(0);

    ui->transformationGroupBox->setEnabled(false);
}

void AnimatrixMainWindow::treeViewSelectionChanged(const QModelIndex & current, const QModelIndex & previous)
{
    Q_UNUSED(previous);

    mBlockSyncSlots = true;
    if(!current.isValid())
    {
        clearObjectUIData();
        mBlockSyncSlots = false;
        return;
    }

    ObjectNode* lCurObj = static_cast<ObjectNode*>(current.internalPointer());
    if(lCurObj == NULL)
    {
        clearObjectUIData();
        mBlockSyncSlots = false;
        return;
    }

    // Appearance data (coming soon)
    MaterialProperties *lMtrl = lCurObj->getMaterials();
    setMaterialValues(lMtrl);

    // Transformation data
    setTransformationValues(lCurObj);

    mBlockSyncSlots = false;
}

inline void AnimatrixMainWindow::setMaterialValues(MaterialProperties *pMtrl)
{
    ui->materialUseParentCheckBox->blockSignals(true);

    if(pMtrl == NULL)
    {
        ui->materialUseParentCheckBox->setChecked(true);
        setMaterialUIState(true);
    }
    else
    {
        ui->materialUseParentCheckBox->setChecked(false);
        setMaterialUIState(false);

        const QColor &lAmb = pMtrl->getAmbient();
        ui->ambRSpinBox->setValue(lAmb.red());
        ui->ambGSpinBox->setValue(lAmb.green());
        ui->ambBSpinBox->setValue(lAmb.blue());

        const QColor &lDiff = pMtrl->getDiffuse();
        ui->diffRSpinBox->setValue(lDiff.red());
        ui->diffGSpinBox->setValue(lDiff.green());
        ui->diffBSpinBox->setValue(lDiff.blue());

        const QColor &lSpec = pMtrl->getSpecular();
        ui->specRSpinBox->setValue(lSpec.red());
        ui->specGSpinBox->setValue(lSpec.green());
        ui->specBSpinBox->setValue(lSpec.blue());

        ui->shineSpinBox->setValue(pMtrl->getSpecularExp());
    }

    ui->appearanceGroupBox->setEnabled(true);
    ui->materialUseParentCheckBox->blockSignals(false);
}

inline void AnimatrixMainWindow::setTransformationValues(ObjectNode *pCurObj)
{
    CG_REAL lX, lY, lZ;
    pCurObj->getTranslation(lX, lY, lZ);
    ui->translationXSpinBox->setValue(lX);
    ui->translationYSpinBox->setValue(lY);
    ui->translationZSpinBox->setValue(lZ);

    pCurObj->getScale(lX, lY, lZ);
    ui->scaleXSpinBox->setValue(lX);
    ui->scaleYSpinBox->setValue(lY);
    ui->scaleZSpinBox->setValue(lZ);

    pCurObj->getRotate(lX, lY, lZ);
    ui->rotaiotnXSpinBox->setValue(lX);
    ui->rotaitonYSpinBox->setValue(lY);
    ui->rotaitonZSpinBox->setValue(lZ);

    pCurObj->getCenterOfRotation(lX, lY, lZ);
    ui->rotCenterXSpinBox->setValue(lX);
    ui->rotCenterYSpinBox->setValue(lY);
    ui->rotCenterZSpinBox->setValue(lZ);

    ui->transformationGroupBox->setEnabled(true);
}

inline void AnimatrixMainWindow::processNewObject(ObjectNode* pNewObject)
{
    // Build model for the tree view
    HierarchicalMeshModel* lModel = new HierarchicalMeshModel(pNewObject, ui->treeView);
    ui->treeView->setModel(lModel);
    connect(ui->treeView->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this, SLOT(treeViewSelectionChanged(QModelIndex,QModelIndex)));

    // Cleanup the ui
    clearObjectUIData();

    // Some reasonable column widths
    ui->treeView->setColumnWidth(0, 200);
    ui->treeView->setColumnWidth(1, 60);
    ui->treeView->setColumnWidth(2, 60);

    // Give the object to the OpenGL widget
    ui->mainGLWidget->takeObject(pNewObject);
}

void AnimatrixMainWindow::on_actionSave_Object_to_File_triggered()
{
    const ObjectNode* lObject = ui->mainGLWidget->getObject();
    if(lObject == NULL)
    {
        QMessageBox::warning(this, "Error saving", "Nothing to save.  Please create an object first.");
        return;
    }

    QString lFilename = QFileDialog::getSaveFileName(this, "Please specify a file name for the object", "", "Wavefront obj (*.obj)");
    if(lFilename.isEmpty()) return;

    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    bool result = lObject->writeFile(lFilename.toStdString());
    QApplication::restoreOverrideCursor();

    if(!result)
    {
        QMessageBox::warning(this, "Error saving", "There was an error saving the mesh.  See standard output for more information.");
    }
}

void AnimatrixMainWindow::on_actionLoad_Object_from_File_triggered()
{
    QString mFilename = QFileDialog::getOpenFileName(this, "Please select an object file to open", "", "Wavefront obj (*.obj);;All Files (*.*)");
    if(mFilename.isEmpty()) return;

    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    ObjectNode* lNewObject = ObjectFactory::loadMesh(mFilename);
    QApplication::restoreOverrideCursor();

    if(lNewObject != NULL) processNewObject(lNewObject);
    else
    {
        QMessageBox::warning(this, "Error loading", "There was an error reading the mesh.  See standard output for more information.");
    }
}

void AnimatrixMainWindow::on_actionQuit_triggered()
{
    exit(0);
}

// Calls to make the humanoid
void AnimatrixMainWindow::on_actionMake_Humanoid_Walk_triggered()
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    ObjectNode* lNewObject = ObjectFactory::buildHumanoidWalk();
    QApplication::restoreOverrideCursor();

    if(lNewObject != NULL) processNewObject(lNewObject);
    else
    {
        QMessageBox::warning(this, "Error making walking humanoid", "There was an error constructing the walking humanoid mesh. See standard output for more information.");
    }
}

void AnimatrixMainWindow::on_actionMake_Humanoid_Other_triggered()
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    ObjectNode* lNewObject = ObjectFactory::buildHumanoidOther();
    QApplication::restoreOverrideCursor();

    if(lNewObject != NULL) processNewObject(lNewObject);
    else
    {
        QMessageBox::warning(this, "Error making other humanoid", "There was an error constructing the other humanoid mesh. See standard output for more information.");
    }
}

void AnimatrixMainWindow::on_actionNormal_Rendering_Mode_toggled(bool checked)
{
    if(checked)
    {
        mAllowUncheck = true;
        ui->mainGLWidget->changeRenderingMode(PHONG_MATERIAL_MODE_SHADED);
        ui->actionSolid_Color_Only_no_shade->setChecked(false);
        ui->actionVisualize_Normals_as_Color->setChecked(false);
        ui->actionVisualize_Texture_Coordinates_as_Color->setChecked(false);
        mAllowUncheck = false;
    }
    else if(!mAllowUncheck)
    {
        ui->actionNormal_Rendering_Mode->blockSignals(true);
        ui->actionNormal_Rendering_Mode->setChecked(true);
        ui->actionNormal_Rendering_Mode->blockSignals(false);
    }
}

void AnimatrixMainWindow::on_actionVisualize_Normals_as_Color_toggled(bool checked)
{
    if(checked)
    {
        mAllowUncheck = true;
        ui->mainGLWidget->changeRenderingMode(PHONG_MATERIAL_MODE_NORMALS);
        ui->actionNormal_Rendering_Mode->setChecked(false);
        ui->actionSolid_Color_Only_no_shade->setChecked(false);
        ui->actionVisualize_Texture_Coordinates_as_Color->setChecked(false);
        mAllowUncheck = false;
    }
    else if(!mAllowUncheck)
    {
        ui->actionVisualize_Normals_as_Color->blockSignals(true);
        ui->actionVisualize_Normals_as_Color->setChecked(true);
        ui->actionVisualize_Normals_as_Color->blockSignals(false);
    }
}

void AnimatrixMainWindow::on_actionVisualize_Texture_Coordinates_as_Color_toggled(bool checked)
{
    if(checked)
    {
        mAllowUncheck = true;
        ui->mainGLWidget->changeRenderingMode(PHONG_MATERIAL_MODE_TEX_CORDS);
        ui->actionNormal_Rendering_Mode->setChecked(false);
        ui->actionSolid_Color_Only_no_shade->setChecked(false);
        ui->actionVisualize_Normals_as_Color->setChecked(false);
        mAllowUncheck = false;
    }
    else if(!mAllowUncheck)
    {
        ui->actionVisualize_Texture_Coordinates_as_Color->blockSignals(true);
        ui->actionVisualize_Texture_Coordinates_as_Color->setChecked(true);
        ui->actionVisualize_Texture_Coordinates_as_Color->blockSignals(false);
    }
}

void AnimatrixMainWindow::on_actionSolid_Color_Only_no_shade_toggled(bool checked)
{
    if(checked)
    {
        mAllowUncheck = true;
        ui->mainGLWidget->changeRenderingMode(PHONG_MATERIAL_MODE_SOLID_COLOR);
        ui->actionNormal_Rendering_Mode->setChecked(false);
        ui->actionVisualize_Normals_as_Color->setChecked(false);
        ui->actionVisualize_Texture_Coordinates_as_Color->setChecked(false);
        mAllowUncheck = false;
    }
    else if(!mAllowUncheck)
    {
        ui->actionSolid_Color_Only_no_shade->blockSignals(true);
        ui->actionSolid_Color_Only_no_shade->setChecked(true);
        ui->actionSolid_Color_Only_no_shade->blockSignals(false);
    }
}
