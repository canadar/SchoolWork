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
    float theta = 0;
    //TOP CAP

    lObject->addVertex(0.0,1.0,0.0);//Vertex 0
    for(int i = 1; i < pSlices+1; i++){
        theta = 2.0f * 3.1415926f * float(i) / float(pSlices);
        float x = 1.0 * cosf(theta);
        float y = 1.0 * sinf(theta);
        lObject->addVertex(x,1,y);//vertices # 0 - pSlices
    }
    lObject->addNormal(0.0,1.0,0.0);//Bottom #0
    for(int j = 1; j < pSlices; j++){
        lObject->addTriangle(0,j,j+1,0,0,0);
    }
    lObject->addTriangle(0,pSlices,1,0,0,0);


    //BUILD BOTTOM CAP
    lObject->addVertex(0.0,-1.0,0.0);//Vertex pSlice +1
    for(int i = pSlices+2; i < 2*pSlices+2; i++){
        theta = 2.0f * 3.1415926f * float(i) / float(pSlices);
        float x = 1.0 * cosf(theta);
        float y = 1.0 * sinf(theta);
        lObject->addVertex(x,-1,y);
    }
    lObject->addNormal(0.0,-1.0,0.0);//Bottom #0
    for(int j = pSlices+2; j < lObject->getVertexCount()-1; j++){
        lObject->addTriangle(pSlices+1,j,j+1,1,1,1);
    }
    lObject->addTriangle(pSlices+1,2*pSlices+1,pSlices+2,1,1,1);


    //BUILD CYLINDRICAL PART OF CYLINDER
    lObject->addNormal(0.0,0.0,1.0);
    lObject->addNormal(0.0,0.0,-1.0);
    for(int x = 1; x < pSlices+1; x++){
        if(x == 1){
           lObject->addTriangle(1,2*pSlices+1, pSlices,3,3,3);
           lObject->addTriangle(1,pSlices+2,2*pSlices+1,3,3,3);
        }
        else{
            lObject->addTriangle(x,x-1,pSlices+x,2,2,2);
            lObject->addTriangle(x,pSlices+x,pSlices+x+1,2,2,2);
        }
    }

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

    float theta = 0;
    float phi = 0;
    lObject->addVertex(0,1,0);//Vertex 1: The North Pole
    lObject->addVertex(0,-1,0);//Vertex 2: The South Pole

    for(int i = 0; i < pStacks; i++){

    }


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


    //Building the Base
    ObjectNode *base;
    base = buildCylinder(40);
    base->setName("Base");
    base->setScale(2.35,0.05,2.35);


    //Poles



    //Bell Connector
    ObjectNode *connector;
    connector = buildCylinder(10);
    connector->setName("Connector");
    connector->setScale(0.15,0.15,0.15);
    connector->setTranslate(0.0,2.0,0.0);

    //Benches:
     ObjectNode* benchSeat1; //Bench 1
     benchSeat1 = buildCube();
     benchSeat1->setScale(0.06,0.81,0.17);
     benchSeat1->setTranslate(0.68,4.78,0);

     ObjectNode* benchSeat2; //Bench 2
     benchSeat2 = buildCube();
     benchSeat2->setScale(0.06,0.81,0.17);
     benchSeat2->setTranslate(-0.68,4.78,0);

     ObjectNode* benchSeat3; //Bench 3
     benchSeat3 = buildCube();
     benchSeat3->setScale(0.06,0.81,0.17);
     benchSeat3->setTranslate(0,4.78,0.68);
     benchSeat3->setRotate(90,0,1,0);

     ObjectNode* benchSeat4; //Bench 4
     benchSeat4 = buildCube();
     benchSeat4->setScale(0.06,0.81,0.17);
     benchSeat4->setTranslate(0,4.78,-0.68);
     benchSeat4->setRotate(90,0,1,0);


    //Add Objects to the sculpture
     //Add benches to the base
     base->addChild(benchSeat1);
     base->addChild(benchSeat2);
     base->addChild(benchSeat3);
     base->addChild(benchSeat4);


    lObject->addChild(base);
    lObject->addChild(connector);
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
