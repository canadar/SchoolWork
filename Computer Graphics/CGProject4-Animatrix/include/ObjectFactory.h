#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <QString>

class ObjectNode;

class ObjectFactory
{
public:
    ObjectFactory();
    ~ObjectFactory();

    // Read a mesh from the specified file
    static ObjectNode* loadMesh(const QString &pMeshFile);

    // Build simple fixed geometry meshes with these methods
    static ObjectNode* buildCube();
    static ObjectNode* buildCylinder(int pSlices);
    static ObjectNode* buildSphere(int pSlices, int pStacks);

    // Two ways to build the humanoid (for the two different animations)
    static ObjectNode* buildHumanoidWalk();
    static ObjectNode* buildHumanoidOther();

    // Helper methods for our humanoids
    static ObjectNode* buildArm();
    static ObjectNode* buildLeg();
};

#endif // OBJECTFACTORY_H
