#ifndef OBJECTNODE_H
#define OBJECTNODE_H

#include "CGCommon.h"
#include <QList>
#include <QString>

#include <GLRenderMatrixContext.h>

// Forward declaration
class ObjMesh;
class MaterialProperties;
class QGLShaderProgram;
struct MeshGroup;

class ObjectNode
{
public:
    ObjectNode();
    ObjectNode(ObjMesh *pMesh, MeshGroup *pGroup);
    ~ObjectNode();

    // Set or retrieve the node name
    const QString& getName() const;
    void setName(QString);

    // Mesh metrics
    int getVertexCount() const;
    int getFaceCount() const;

    // Parent-child metrics
    int childIndex() const;
    ObjectNode* parentMesh();
    int getChildCount() const;

    // Convert groups to children
    void meshGroupsToChildren();

    // Support for linking children to this object node
    ObjectNode* makeNewChild(QString pName = QString());

    void addChild(ObjectNode* pChild);
    ObjectNode *getChild(int index = 0);
    QList<ObjectNode*>& getChildren();

    // Iterate through children
    ObjectNode *getFirstChild();
    ObjectNode *getNextChild();

    void setMaterials(MaterialProperties* pNewMat);
    MaterialProperties* getMaterials();

    // Center of rotaiton
    void setCenterOfRotation(CG_REAL pX, CG_REAL pY, CG_REAL pZ);
    void getCenterOfRotation(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const;

    // Query the transformation values
    void getTranslation(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const;
    void getScale(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const;
    void getRotate(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const;

    // Explicitly set this object's transformation
    void setTranslate(CG_REAL pX, CG_REAL pY, CG_REAL pZ);
    void setScale(CG_REAL pX, CG_REAL pY, CG_REAL pZ);
    void setRotate(CG_REAL pX, CG_REAL pRY, CG_REAL pRZ);

    // Adjust this object's transformation
    void addTranslate(CG_REAL pX, CG_REAL pY, CG_REAL pZ);
    void addScale(CG_REAL pX, CG_REAL pY, CG_REAL pZ);
    void addRotate(CG_REAL pX, CG_REAL pY, CG_REAL pZ);

    // Switch this node and all of its children to the indicated frame
    void changeFrame(uint32_t pFrameNumber);

    // Store the current transformation as a keyframe
    void storeKeyframe(uint32_t pFrameNumber);

    // Load the values from the specified frame interpolating if necessary
    void loadFrame(uint32_t pFrameNumber);

    // Methods that pass through to the Mesh
    void addGroup(std::string pGroupName);
    void addVertex(float pX, float pY, float pZ);
    void addNormal(float pI, float pJ, float pK);
    void addTriangle(uint32_t vA, uint32_t vB, uint32_t vC,
                     uint32_t nA, uint32_t nB, uint32_t nC);

    // Parse the raw data (added with above three functions)
    bool parseRawData(bool pReScale = false, bool pReCenter = false, bool pAllowEmpty = false);

    // Managing mesh normals
    void computePerFaceNormals(bool pOverwrite = false);
    void smoothNormals();

    // Read an OBJ file into the mesh for this node (does not use any children)
    bool readFile(std::string pFilename, bool pReScale = false, bool pReCenter = false);

    // Save the mesh for this node as an OBJ file (does not save any children)
    bool writeFile(std::string pFilename) const;

    // Draw this object (and all of its children)
    void draw(GLRenderMatrixContext &pMatrix, QGLShaderProgram *pShader = NULL) const;

    // Draw this object's (and all of its children's) normals
    void drawNormals(GLRenderMatrixContext &pMatrix, QGLShaderProgram *pShader = NULL) const;

    // Used for a reference to a bad node (do not use directly except for comparison)
    static ObjectNode badNode;

protected:
    // Helper methods for internal use
    void setParentChildMetrics(ObjectNode* pParentMesh, int pChildIndex);
    void applyTransformation(GLRenderMatrixContext &pMatrix) const;

    // This method should interpolate the values in prevTrans and nextTrans then store them in Interp
    void interpolateFrameValues(float* pPrevTrans, float* pNextTrans, float* pInterp,
                                int pFrameNumber, uint32_t pPrevFrame, uint32_t pNextFrame);

    // Easy helpers to copy or construct keyframe values
    float* makeKeyframeValues() const;
    void copyKeyframeValues(const float* pKeyframe);

    // The name for this node
    QString mName;

    // Transformation variables
    float mTx, mTy, mTz;
    float mSx, mSy, mSz;
    float mRx, mRy, mRz;        

    // Center of rotation
    float mRotCentX, mRotCentY, mRotCentZ;

    // Animation Keyframes (frame # and transform data)
    QMap<uint32_t, float*> mKeyframes;

    // For iterating through the children
    mutable int mChildIteratorIndex;

    // Pointer to parent and position in parent's list
    ObjectNode* mParentMesh;
    int mChildIndex;

    // The mesh or mesh group for this node
    ObjMesh *mNodeMesh;
    MeshGroup *mMeshGroup;
    bool mDontDrawMesh;

    // The materials for this node
    MaterialProperties *mMtrl;

    // Linked children nodes
    QList<ObjectNode*> mNodeChildren;

    // A counter for all nodes created so far
    static int msObjectCount;
};

#endif // OBJECTNODE_H
