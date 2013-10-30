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

    // These commands will suppres unused parameter warnings (remove them once the method is complete)
    Q_UNUSED(pSlices);

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName(QString("Cylinder %1").arg(lsCylinderCount));
    lsCylinderCount++;

    // TODO: Create a node object for a unit cylinder using the subdivision parameters above
    //    - Base circle should be at Y = -1 and have a radius of 1
    //    - Top circle should be at Y = 1 and also have a radius of 1
    //    - See buildCube for an example of how to use the ObjectNode object lObject
    //    - Use addVertex, addNormal and addTriangle
    //    - Be sure to leave in the allocation above and the call to parseRawData() below
    //    - Your vertices must wind counter-clockwise and normals must point outwards

    // Process the vertex, normal and face data just added to the object

    //Will be building cylinders here: but how???????
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

    // These commands will suppres unused parameter warnings (remove them once the method is complete)
    Q_UNUSED(pSlices); Q_UNUSED(pStacks);

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName(QString("Sphere %1").arg(lsSphereCount));
    lsSphereCount++;

    // TODO: Create a node object for a unit sphere using the subdivision parameters above
    //    - The south pole should be at Y = -1 and the north pole at Y = 1
    //    - The radius of the sphere should be 1
    //    - See buildCube for an example of how to use the ObjectNode object lObject
    //    - Use addVertex, addNormal and addTriangle
    //    - Be sure to leave in the allocation above and the call to parseRawData() below
    //    - Your vertices must wind counter-clockwise and normals must point outwards

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

ObjectNode* ObjectFactory::buildSculpture()
{
    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName("Sculpture");

    // TODO: Create a node object for the sculpture indicated in the instructions (should be hierarchical)
    //    - Make other methods to construct the individual parts as actual meshes (similar to buildCube())
    //    - Set appropriate names and then transform them as needed
    //    - Use addChild on lObject to put the sub-parts together into one sculpture
    //    - Be sure to leave in the allocation above but you may not need to call parseRawData below

    // HERE IS AN EXAMPLE TO WORK FROM, DELETE THIS AND MAKE YOUR OWN!!!
    QMessageBox::information(NULL, "Teacher's Example", "This is the example sculpture.  You must replace it with your own.\n\n"
                         "Note that it will not look correct until you implement hierarchical transformations.", QMessageBox::Ok);

    ObjectNode *cube1, *cube2, *cube3, *cube4;
    cube1 = buildCube();
    cube1->setTranslate(-1.1, -1.1, 0);
    cube1->setScale(0.8, 0.8, 0.2);

    cube2 = buildCube();
    cube2->setTranslate( 1.1, -1.1, 0);
    cube2->setScale(0.8, 0.8, 0.2);

    cube3 = buildCube();
    cube3->setTranslate( 1.1,  1.1, 0);
    cube3->setScale(0.8, 0.8, 0.2);

    cube4 = buildCube();
    cube4->setTranslate(-1.1,  1.1, 0);
    cube4->setScale(0.8, 0.8, 0.2);

    lObject->addChild(cube1);
    lObject->addChild(cube2);
    lObject->addChild(cube3);
    lObject->addChild(cube4);
    // END OF EXAMPLE

    // Only do this if you add vertices, normals or faces to the lObject itself (not required)
    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData(false, false, true))
    {
        printf("There was an error creating the sculpture node object.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildHumanoid()
{
    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();
    lObject->setName("Humanoid");

    // TODO: Create a node object for a humanoid character (must be hierarchical)
    //    - Each part of your humanoid should be a primitive object that is already defined above
    //    - Call the appropriate build method to make the individual parts
    //    - Set appropriate names for each part and then use addChild to build an appropriate hierarchy
    //    - Do NOT attach all parts to lObject, build and intuitive skeletal hierarchy
    //    - Be sure to leave in the allocation above
    //    - As with scuplture, you may not need to call parseRawData below

    // Only do this if you add vertices, normals or faces to the lObject itself (not required)
    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData(false, false, true))
    {
        printf("There was an error creating the humanoid node object.\n");
        fflush(stdout);

        // Cleanup
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildExtraObject1(double pParam1, double pParam2, double pParam3)
{
    // These commands will suppress the "Unused parameter" warnings
    Q_UNUSED(pParam1); Q_UNUSED(pParam2); Q_UNUSED(pParam3);

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();

    // TODO: Create a node object for some other object as suggested in the instructions or approved by the professor
    //    - You may or may not need to use the parameters they are just there in case you need them (it will depend on what shape you choose)
    //    - See buildCube for an example of how to use the ObjectNode object lObject
    //    - Use addVertex, addNormal and addTriangle
    //    - Be sure to leave in the allocation above and the call to parseRawData() below

    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData(false, false, true))
    {
        printf("There was an error creating the node object for extra credit object 1.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}

ObjectNode* ObjectFactory::buildExtraObject2(double pParam1, double pParam2, double pParam3)
{
    // These commands will suppress the "Unused parameter" warnings
    Q_UNUSED(pParam1); Q_UNUSED(pParam2); Q_UNUSED(pParam3);

    // Allocate a new node object
    ObjectNode* lObject = new ObjectNode();

    // TODO: Create a node object for some other object as suggested in the instructions or approved by the professor
    //    - You may or may not need to use the parameters they are just there in case you need them (it will depend on what shape you choose)
    //    - See buildCube for an example of how to use the ObjectNode object lObject
    //    - Use addVertex, addNormal and addTriangle
    //    - Be sure to leave in the allocation above and the call to parseRawData() below

    // Process the vertex, normal and face data just added to the object
    if(!lObject->parseRawData(false, false, true))
    {
        printf("There was an error creating the node object for extra credit object 2.\n");
        fflush(stdout);

        // Cleanup
        delete lObject;
        return NULL;
    }

    return lObject;
}
