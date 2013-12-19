#include "ObjectFactory.h"
#include "ObjectNode.h"

#include <QFileInfo>
#include <QMessageBox>

ObjectNode* ObjectFactory::loadMesh(const QString &pMeshFile)
{
    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();

    // Read an OBJ mesh file (Note: this will automatically center and scale the object to unit size)
    lObject->readFile(pMeshFile.toStdString(), true, true);
    lObject->meshGroupsToChildren();
    lObject->setName(QFileInfo(pMeshFile).baseName());

    return lObject;
}

ObjectNode* ObjectFactory::buildCube()
{
    // A counter used to name the cubes
    static int lsCubeCount = 1;

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName(QString("Cube %1").arg(lsCubeCount));
    lsCubeCount++;

    // Add the bottom four vertices
    lObject->addVertex(-1.0, -1.0, -1.0);  // 0
    lObject->addVertex( 1.0, -1.0, -1.0);  // 1
    lObject->addVertex( 1.0, -1.0,  1.0);  // 2
    lObject->addVertex(-1.0, -1.0,  1.0);  // 3

    // Add the top four vertices
    lObject->addVertex(-1.0,  1.0, -1.0);  // 4
    lObject->addVertex( 1.0,  1.0, -1.0);  // 5
    lObject->addVertex( 1.0,  1.0,  1.0);  // 6
    lObject->addVertex(-1.0,  1.0,  1.0);  // 7

    // Add the six face normals
    lObject->addNormal( 1.0, 0.0, 0.0);    // 0
    lObject->addNormal(-1.0, 0.0, 0.0);    // 1

    lObject->addNormal(0.0,  1.0, 0.0);    // 2
    lObject->addNormal(0.0, -1.0, 0.0);    // 3

    lObject->addNormal(0.0, 0.0,  1.0);    // 4
    lObject->addNormal(0.0, 0.0, -1.0);    // 5

    // Add the 12 faces (six square faces split into triangles)

    // Bottom face (-Y)
    lObject->addTriangle(0, 1, 2, 3, 3, 3);
    lObject->addTriangle(2, 3, 0, 3, 3, 3);

    // Top face (Y)
    lObject->addTriangle(7, 6, 5, 2, 2, 2);
    lObject->addTriangle(5, 4, 7, 2, 2, 2);

    // Front face (Z)
    lObject->addTriangle(3, 2, 6, 4, 4, 4);
    lObject->addTriangle(6, 7, 3, 4, 4, 4);

    // Right face (X)
    lObject->addTriangle(2, 1, 5, 0, 0, 0);
    lObject->addTriangle(5, 6, 2, 0, 0, 0);

    // Back face (-Z)
    lObject->addTriangle(1, 0, 4, 5, 5, 5);
    lObject->addTriangle(4, 5, 1, 5, 5, 5);

    // Left face (-X)
    lObject->addTriangle(0, 3, 7, 1, 1, 1);
    lObject->addTriangle(7, 4, 0, 1, 1, 1);

    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData())
    {
        printf("There was an error creating the cube node object.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildCylinder(int pSlices)
{
    // A counter used to name the cylinders
    static int lsCylinderCount = 1;

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName(QString("Cylinder %1").arg(lsCylinderCount));
    lsCylinderCount++;

    // Add top vertex and normal
    lObject->addVertex(0, 1, 0);
    lObject->addNormal(0, 1, 0);

    // Add top circle vertices and normals
    double lTheta = 0, lThetaInc = 2*M_PI/pSlices;
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        double lCos = cos(lTheta), lSin = sin(lTheta);
        lObject->addVertex(lCos, 1.0, lSin);
        lObject->addNormal(lCos, 0.0, lSin);
        lTheta += lThetaInc;
    }

    // Add bottom circle vertices
    lTheta = 0;
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        double lCos = cos(lTheta), lSin = sin(lTheta);
        lObject->addVertex(lCos, -1.0, lSin);
        lTheta += lThetaInc;
    }

    // Add bottom vertex and normal
    lObject->addVertex(0, -1, 0);
    lObject->addNormal(0, -1, 0);

    // Make top cap
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        lObject->addTriangle((lSlice)+1, 0, ((lSlice+1)%pSlices) + 1,
                             0, 0, 0);
    }

    // Make bottom cap
    int lSPole = lObject->getVertexCount()-1;
    int lSVert = pSlices+1;
    int lOffset = pSlices+1;

    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        lObject->addTriangle(lSPole, lSlice+lOffset, ((lSlice+1)%pSlices)+lOffset,
                             lSVert, lSVert, lSVert);
    }

    // Make cylinder body
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        lObject->addTriangle((lSlice)+1, ((lSlice+1)%pSlices) + 1, lSlice+lOffset,
                             (lSlice)+1, ((lSlice+1)%pSlices) + 1, (lSlice)+1);

        lObject->addTriangle(((lSlice+1)%pSlices) + 1, ((lSlice+1)%pSlices)+lOffset, lSlice+lOffset,
                             ((lSlice+1)%pSlices) + 1, ((lSlice+1)%pSlices) + 1, (lSlice)+1);
    }

    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData())
    {
        printf("There was an error creating the cylinder node object.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildSphere(int pSlices, int pStacks)
{
    // A counter used to name the spheres
    static int lsSphereCount = 1;

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName(QString("Sphere %1").arg(lsSphereCount));
    lsSphereCount++;

    // Add top vertex and normal
    lObject->addVertex(0, 1, 0);
    lObject->addNormal(0, 1, 0);

    // Add middle vertices and normals
    double lTheta = 0, lThetaInc = 2*M_PI/pSlices;
    double lPhi = 0, lPhiInc = M_PI/pStacks;

    for(int lStack=1; lStack<pStacks; lStack++)
    {
        lPhi += lPhiInc; lTheta = 0;
        for(int lSlice=0; lSlice<pSlices; lSlice++)
        {
            double lCosT = cos(lTheta), lSinT = sin(lTheta);
            double lCosP = cos(lPhi), lSinP = sin(lPhi);
            lObject->addVertex(lCosT*lSinP, lCosP, lSinT*lSinP);
            lObject->addNormal(lCosT*lSinP, lCosP, lSinT*lSinP);
            lTheta += lThetaInc;
        }
    }

    // Add bottom vertex and normal
    lObject->addVertex(0, -1, 0);
    lObject->addNormal(0, -1, 0);

    // Make top cap
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        lObject->addTriangle((lSlice)+1, 0, ((lSlice+1)%pSlices) + 1,
                             (lSlice)+1, 0, ((lSlice+1)%pSlices) + 1);
    }

    // Make Center stacks
    for(int lStack=1; lStack<pStacks-1; lStack++)
    {
        int lCur = (lStack-1)*pSlices + 1;
        int lNext = lCur + pSlices;
        for(int lSlice=0; lSlice<pSlices; lSlice++)
        {
            lObject->addTriangle((lSlice)+lCur, ((lSlice+1)%pSlices) + lCur, ((lSlice+1)%pSlices) + lNext,
                                 (lSlice)+lCur, ((lSlice+1)%pSlices) + lCur, ((lSlice+1)%pSlices) + lNext);

            lObject->addTriangle((lSlice)+lCur, ((lSlice+1)%pSlices) + lNext, ((lSlice)%pSlices) + lNext,
                                 (lSlice)+lCur, ((lSlice+1)%pSlices) + lNext, ((lSlice)%pSlices) + lNext);
        }
    }

    // Make bottom cap
    int lSPole = lObject->getVertexCount()-1;
    int lSVert = lSPole-pSlices;
    for(int lSlice=0; lSlice<pSlices; lSlice++)
    {
        lObject->addTriangle(lSPole, lSlice+lSVert, ((lSlice+1)%pSlices)+lSVert,
                             lSPole, lSlice+lSVert, ((lSlice+1)%pSlices)+lSVert);
    }

    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData())
    {
        printf("There was an error creating the sphere node object.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildHumanoidWalk()
{
    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName("Humanoid");

    ObjectNode* lTorsoGeom = buildCylinder(30);
    lTorsoGeom->setName("Torso Geometry");
    lTorsoGeom->setScale(0.2, 0.9, 0.2);

    ObjectNode* lTorso = new ObjectNode();
    lTorso->setName("Torso Node");
    lTorso->setTranslate(0, 0.25, 0);
    lTorso->addChild(lTorsoGeom);

    ObjectNode* lHipsGeom = buildCylinder(30);
    lHipsGeom->setName("Hips Geom");
    lHipsGeom->setRotate(0, 0, 90);
    lHipsGeom->setScale(0.2, 0.6, 0.2);

    ObjectNode* lHips = new ObjectNode();
    lHips->setName("Hips");
    lHips->setTranslate(0, -0.9, 0);
    lHips->addChild(lHipsGeom);

    ObjectNode* lShouldersGeom = buildCylinder(30);
    lShouldersGeom->setName("Shoulders Geom");
    lShouldersGeom->setRotate(0, 0, 90);
    lShouldersGeom->setScale(0.2, 0.9, 0.2);

    ObjectNode* lShoulders = new ObjectNode();
    lShoulders->setName("Shoulders");
    lShoulders->setTranslate(0.0, 0.9, 0.0);
    lShoulders->addChild(lShouldersGeom);

    ObjectNode* lLeftArm = buildArm();
    lLeftArm->setName("Left Arm");
    lLeftArm->setTranslate(-0.95, -0.55, 0.0);
    lLeftArm->setCenterOfRotation(0.0, 0.55, 0.0);

    ObjectNode* lRightArm = buildArm();
    lRightArm->setName("Right Arm");
    lRightArm->setTranslate(0.95, -0.55, 0.0);
    lRightArm->setCenterOfRotation(0.0, 0.55, 0.0);

    ObjectNode* lLeftLeg = buildLeg();
    lLeftLeg->setName("Left Leg");
    lLeftLeg->setTranslate(-0.65, -0.75, 0.0);
    lLeftLeg->setCenterOfRotation(0.0, 0.75, 0.0);

    ObjectNode* lRightLeg = buildLeg();
    lRightLeg->setName("Right Leg");
    lRightLeg->setTranslate(0.65, -0.75, 0.0);
    lRightLeg->setCenterOfRotation(0.0, 0.75, 0.0);

    ObjectNode* lHeadGeom = buildSphere(30, 30);
    lHeadGeom->setName("Head Geom");
    lHeadGeom->setScale(0.4, 0.4, 0.4);

    ObjectNode* lHead = new ObjectNode();
    lHead->setName("Head");
    lHead->setTranslate(0.0, 0.33, 0.0);
    lHead->addChild(lHeadGeom);

    ObjectNode* lNeckGeom = buildCylinder(30);
    lNeckGeom->setName("Neck Geom");
    lNeckGeom->setScale(0.2, 0.3, 0.15);

    ObjectNode* lNeck = new ObjectNode();
    lNeck->setName("Neck");
    lNeck->setTranslate(0.0, 0.4, 0.0);
    lNeck->addChild(lNeckGeom);

    lNeck->addChild(lHead);
    lShoulders->addChild(lNeck);
    lShoulders->addChild(lRightArm);
    lShoulders->addChild(lLeftArm);
    lTorso->addChild(lShoulders);
    lHips->addChild(lLeftLeg);
    lHips->addChild(lRightLeg);
    lTorso->addChild(lHips);
    lObject->addChild(lTorso);

    lObject->setTranslate(0.0, 0.2, 0.0);
    lObject->setScale(0.8, 0.8, 0.8);
    lObject->setKeyframe(0);

    return lObject;
}

ObjectNode* ObjectFactory::buildHumanoidOther()
{
    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName("Humanoid");

    ObjectNode* lTorsoGeom = buildCylinder(30);
    lTorsoGeom->setName("Torso Geometry");
    lTorsoGeom->setScale(0.2, 0.9, 0.2);

    ObjectNode* lTorso = new ObjectNode();
    lTorso->setName("Torso Node");
    lTorso->setTranslate(0, 0.25, 0);
    lTorso->addChild(lTorsoGeom);

    ObjectNode* lHipsGeom = buildCylinder(30);
    lHipsGeom->setName("Hips Geom");
    lHipsGeom->setRotate(0, 0, 90);
    lHipsGeom->setScale(0.2, 0.6, 0.2);

    ObjectNode* lHips = new ObjectNode();
    lHips->setName("Hips");
    lHips->setTranslate(0, -0.9, 0);
    lHips->addChild(lHipsGeom);

    ObjectNode* lShouldersGeom = buildCylinder(30);
    lShouldersGeom->setName("Shoulders Geom");
    lShouldersGeom->setRotate(0, 0, 90);
    lShouldersGeom->setScale(0.2, 0.9, 0.2);

    ObjectNode* lShoulders = new ObjectNode();
    lShoulders->setName("Shoulders");
    lShoulders->setTranslate(0.0, 0.9, 0.0);
    lShoulders->addChild(lShouldersGeom);

    ObjectNode* lLeftArm = buildArm();
    lLeftArm->setName("Left Arm");
    lLeftArm->setTranslate(-0.95, -0.55, 0.0);
    lLeftArm->setCenterOfRotation(0.0, 0.55, 0.0);

    ObjectNode* lRightArm = buildArm();
    lRightArm->setName("Right Arm");
    lRightArm->setTranslate(0.95, -0.55, 0.0);
    lRightArm->setCenterOfRotation(0.0, 0.55, 0.0);

    ObjectNode* lLeftLeg = buildLeg();
    lLeftLeg->setName("Left Leg");
    lLeftLeg->setTranslate(-0.65, -0.75, 0.0);
    lLeftLeg->setCenterOfRotation(0.0, 0.75, 0.0);

    ObjectNode* lRightLeg = buildLeg();
    lRightLeg->setName("Right Leg");
    lRightLeg->setTranslate(0.65, -0.75, 0.0);
    lRightLeg->setCenterOfRotation(0.0, 0.75, 0.0);

    ObjectNode* lHeadGeom = buildSphere(30, 30);
    lHeadGeom->setName("Head Geom");
    lHeadGeom->setScale(0.4, 0.4, 0.4);

    ObjectNode* lHead = new ObjectNode();
    lHead->setName("Head");
    lHead->setTranslate(0.0, 0.33, 0.0);
    lHead->addChild(lHeadGeom);

    ObjectNode* lNeckGeom = buildCylinder(30);
    lNeckGeom->setName("Neck Geom");
    lNeckGeom->setScale(0.2, 0.3, 0.15);

    ObjectNode* lNeck = new ObjectNode();
    lNeck->setName("Neck");
    lNeck->setTranslate(0.0, 0.4, 0.0);
    lNeck->addChild(lNeckGeom);

    lNeck->addChild(lHead);
    lShoulders->addChild(lNeck);
    lShoulders->addChild(lRightArm);
    lShoulders->addChild(lLeftArm);
    lTorso->addChild(lShoulders);
    lHips->addChild(lLeftLeg);
    lHips->addChild(lRightLeg);
    lTorso->addChild(lHips);
    lObject->addChild(lTorso);

    lObject->setTranslate(0.0, 0.2, 0.0);
    lObject->setScale(0.8, 0.8, 0.8);


    return lObject;
}

ObjectNode* ObjectFactory::buildArm()
{
    ObjectNode* lArmGeom = buildCylinder(30);
    lArmGeom->setName("Arm Geom");
    lArmGeom->setScale(0.2, 0.5, 0.2);

    ObjectNode* lArm = new ObjectNode();
    lArm->setName("Arm");
    lArm->addChild(lArmGeom);

    ObjectNode* lHandGeom = buildCube();
    lHandGeom->setName("Hand Geom");
    lHandGeom->setScale(0.2, 0.2, 0.2);

    ObjectNode* lHand = new ObjectNode();
    lHand->setName("Hand");
    lHand->setTranslate(0.0, -0.7, 0.0);
    lHand->addChild(lHandGeom);

    // Build and return the hierarchy
    lArm->addChild(lHand);
    return lArm;
}

ObjectNode* ObjectFactory::buildLeg()
{
    ObjectNode* lLegGeom = buildCylinder(30);
    lLegGeom->setName("Leg Geom");
    lLegGeom->setScale(0.2, 0.75, 0.2);

    ObjectNode* lLeg = new ObjectNode();
    lLeg->setName("Leg");
    lLeg->addChild(lLegGeom);

    ObjectNode* lFootGeom = buildCube();
    lFootGeom->setName("Foot Geom");
    lFootGeom->setScale(0.2, 0.1, 0.33);

    ObjectNode* lFoot = new ObjectNode();
    lFoot->setName("Foot");
    lFoot->addChild(lFootGeom);
    lFoot->setTranslate(0.0, -0.85, -0.15);

    // Build and return the hierarchy
    lLeg->addChild(lFoot);
    return lLeg;
}
