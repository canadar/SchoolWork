#ifndef ANIMATRIXMAINWINDOW_H
#define ANIMATRIXMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AnimatrixMainWindow;
}

class ObjectNode;
class MaterialProperties;

class AnimatrixMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AnimatrixMainWindow(QWidget *parent = 0);
    ~AnimatrixMainWindow();

protected slots:
    // Animation controls
    void on_animationFrameSlider_valueChanged(int value);
    void on_setKeyframeButton_clicked();
    void on_playButton_clicked();

    // Loading and saving of object files
    void on_actionLoad_Object_from_File_triggered();
    void on_actionSave_Object_to_File_triggered();

    // Quit the application
    void on_actionQuit_triggered();

    // Create/Load various objects
    void on_actionMake_Humanoid_Walk_triggered();
    void on_actionMake_Humanoid_Other_triggered();

    // Change appearance of OpenGL renderer
    void on_actionNormal_Rendering_Mode_toggled(bool checked);
    void on_actionVisualize_Normals_as_Color_toggled(bool checked);
    void on_actionVisualize_Texture_Coordinates_as_Color_toggled(bool checked);
    void on_actionSolid_Color_Only_no_shade_toggled(bool checked);

    // Respond to the 'use parent' materials checkbox
    void on_materialUseParentCheckBox_toggled(bool checked);

    // Sync values from the GUI back to the object
    void syncMaterials();
    void syncTransformation();

    // Respond to changed selection in the TreeView
    void treeViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);

protected:
    // Event handler for our animation timer
    void timerEvent(QTimerEvent* event);

private:
    void processNewObject(ObjectNode* pNewObject);

    void clearObjectUIData();
    void setMaterialValues(MaterialProperties *pMtrl);
    void setTransformationValues(ObjectNode *pCurObj);
    void setMaterialUIState(bool checked);

    int mPlaybackTimerID;
    bool mBlockSyncSlots, mAllowUncheck;
    Ui::AnimatrixMainWindow *ui;
};

#endif // ANIMATRIXMAINWINDOW_H
