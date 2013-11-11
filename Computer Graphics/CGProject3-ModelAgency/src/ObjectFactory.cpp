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
    float theta = 0;
    //TOP CAP

    lObject->addVertex(0.0,1.0,0.0);//Vertex 0
    for(int i = 1; i < pSlices+1; i++){
        theta = 2.0f * 3.1415926f * float(i) / float(pSlices);
        float x = 1.0 * cosf(theta);
        float y = 1.0 * sinf(theta);
        lObject->addVertex(x,1,y);//vertices # 0 - pSlices
    }
    for(int j = 1; j < pSlices; j++){
        lObject->addTriangle(0,j,j+1,0,j,j+1);
    }
    lObject->addTriangle(0,pSlices,1,0,pSlices,1);


    //BUILD BOTTOM CAP
    lObject->addVertex(0.0,-1.0,0.0);//Vertex pSlice +1
    for(int i = pSlices+2; i < 2*pSlices+2; i++){
        theta = 2.0f * 3.1415926f * float(i) / float(pSlices);
        float x = 1.0 * cosf(theta);
        float y = 1.0 * sinf(theta);
        lObject->addVertex(x,-1,y);
    }
    for(int j = pSlices+2; j < lObject->getVertexCount()-1; j++){
        lObject->addTriangle(pSlices+1,j,j+1,pSlices+1,j,j+1);
    }
    lObject->addTriangle(pSlices+1,2*pSlices+1,pSlices+2,pSlices+1,2*pSlices,pSlices+2);


    //BUILD CYLINDRICAL PART OF CYLINDER
    for(int x = 1; x < pSlices+1; x++){
        if(x == 1){
           lObject->addTriangle(1,2*pSlices+1, pSlices,1,2*pSlices+1,pSlices);
           lObject->addTriangle(1,pSlices+2,2*pSlices+1,1,pSlices+2,2*pSlices+1);
        }
        else{
            lObject->addTriangle(x,x-1,pSlices+x,x,x-1,pSlices+x);
            lObject->addTriangle(x,pSlices+x,pSlices+x+1,x,pSlices+x,pSlices+x+1);
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
    float x;
    float y;
    float z;
    float incTheta = M_PI*2.0/pSlices;
    float incPhi = M_PI/pStacks;
    float theta = 0;
    float phi = incPhi;

    int topVert1 = pSlices+1;
    int topVert2 = pSlices+2;
    int bottomVert1 = 1;
    int bottomVert2 = 2;

    //North Pole
    lObject->addVertex(0,1,0);
    lObject->addNormal(0,1,0);

    //adding the verticies from top to bottom
    for(int i = 0; i < pStacks-1; i++){
        y = cos(phi);
            for(int j=0; j<pSlices;j++){
                x = fabs(sin(phi))*cos(theta);
                z = fabs(sin(phi))*sin(theta);
                lObject->addVertex(x,y,z);
                lObject->addNormal(x,y,z);
                theta += incTheta;
        }
        phi += incPhi;
    }

    //South Pole
    lObject->addVertex(0,-1,0);
    lObject->addNormal(0,-1,0);

    int layer = 0;
    for(int i = 1; i < pStacks-1; i++){
        for(int j = 1; j<pSlices; j++){
            lObject->addTriangle(bottomVert1, bottomVert2, topVert1,bottomVert1, bottomVert2, topVert1);
            lObject->addTriangle(bottomVert2,topVert1,topVert2,bottomVert2,topVert1,topVert2);

            topVert1++;
            topVert2++;
            bottomVert1++;
            bottomVert2++;
        }

        lObject->addTriangle(bottomVert1, (layer*pSlices + 1), topVert1, bottomVert1, (layer*pSlices + 1), topVert1);
        lObject->addTriangle((layer*pSlices+1), topVert1,bottomVert2, (layer*pSlices+1), topVert1, bottomVert2);

        layer++;
        topVert1++;
        topVert2++;
        bottomVert1++;
        bottomVert2++;
    }

    int topVert = topVert2-1;
    topVert1 = topVert - pSlices;
    topVert2 = topVert1+1;
    bottomVert1 = 1;
    bottomVert2 = 1;

    for(int i = 1; i < pSlices; i++){
        lObject->addTriangle(0,bottomVert1, bottomVert2, 0, bottomVert1, bottomVert2);
        lObject->addTriangle(topVert, topVert1, topVert2, topVert, topVert1, topVert2);
        topVert1++;
        topVert2++;
        bottomVert1++;
        bottomVert2++;
    }

    lObject->addTriangle(0, bottomVert1, 1, 0 , bottomVert1, 1);
    lObject->addTriangle(topVert, topVert1, topVert - pSlices, topVert, topVert1, topVert - pSlices);

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
    //Building the Base
    ObjectNode *base;
    base = buildCylinder(40);
    base->setName("Base");
    base->setScale(2.35,0.05,2.35);
    //Support Structures

    ObjectNode *pole1[10];
    for(int i = 1; i <=10 ; i++){
        pole1[i] = buildCube();
        pole1[i]->setTranslate(0.07*i,2.06,-0.08*i);
        pole1[i]->setRotate(-42,0,0.01,0);
        pole1[i]->setScale(0.11,0.08,0.02);
        lObject->addChild(pole1[i]);
    }

    ObjectNode *pole2[10];
    for(int i = 1; i <=10; i++){
        pole2[i] = buildCube();
        pole2[i]->setTranslate(-0.11*i,2.06,-0.10*i);
        pole2[i]->setRotate(47,0,0.01,0);
        pole2[i]->setScale(0.11,0.08,0.02);
        lObject->addChild(pole2[i]);
    }

    ObjectNode *pole3[10];
    for(int i = 1; i <=10; i++){
        pole3[i] = buildCube();
        pole3[i]->setTranslate(-0.12*i,2.06,0.12*i);
        pole3[i]->setRotate(-42,0,0.01,0);
        pole3[i]->setScale(0.11,0.08,0.02);
        lObject->addChild(pole3[i]);
    }

    ObjectNode *pole4[10];
    for(int i = 1; i <=10; i++){
        pole4[i] = buildCube();
        pole4[i]->setTranslate(0.12*i,2.06,0.12*i);
        pole4[i]->setRotate(46,0,0.01,0);
        pole4[i]->setScale(0.11,0.08,0.02);
        lObject->addChild(pole4[i]);
    }

    //Bell Connector
    ObjectNode *connector;
    connector = buildCylinder(10);
    connector->setName("Connector");
    connector->setScale(0.15,0.15,0.15);
    connector->setTranslate(0.0,2.0,0.0);

    //Building the Bell
    ObjectNode *bell[40];
    for(int i = 0; i < 40; i++){
        bell[i] = buildCylinder(10);
        bell[i]->setScale(0.15*i,0.12,0.15*i);
        bell[i]->setTranslate(0.0,-0.12*i,0.0);
        connector->addChild(bell[i]);
    }
    //Benches:
     ObjectNode* benchSeat1; //Bench 1
     benchSeat1 = buildCube();
     benchSeat1->setScale(0.06,0.81,0.17);
     benchSeat1->setTranslate(0.68,4.78,0);

     //Bench 1 Legs
     ObjectNode* benchLeg1;
     ObjectNode* benchLeg2;
     benchLeg1 = buildCube();
     benchLeg2 = buildCube();
     benchLeg1->setScale(0.48,2.42,0.22);
     benchLeg2->setScale(0.48,2.42,0.22);
     benchLeg1->setTranslate(0.00,-2.37,-0.65);
     benchLeg2->setTranslate(0.00,-2.09,0.65);
     benchSeat1->addChild(benchLeg1);
     benchSeat1->addChild(benchLeg2);

     ObjectNode* benchSeat2; //Bench 2
     benchSeat2 = buildCube();
     benchSeat2->setScale(0.06,0.81,0.17);
     benchSeat2->setTranslate(-0.68,4.78,0);
     //Bench 2 Legs
     ObjectNode* benchLeg3;
     ObjectNode* benchLeg4;
     benchLeg3 = buildCube();
     benchLeg4 = buildCube();
     benchLeg3->setScale(0.48,2.42,0.22);
     benchLeg4->setScale(0.48,2.42,0.22);
     benchLeg3->setTranslate(0.00,-2.37,-0.65);
     benchLeg4->setTranslate(0.00,-2.09,0.65);
     benchSeat2->addChild(benchLeg1);
     benchSeat2->addChild(benchLeg2);

     ObjectNode* benchSeat3; //Bench 3
     benchSeat3 = buildCube();
     benchSeat3->setScale(0.06,0.81,0.17);
     benchSeat3->setTranslate(0,4.78,0.68);
     benchSeat3->setRotate(90,0,1,0);
     //Bench 3 Legs
     ObjectNode* benchLeg5;
     ObjectNode* benchLeg6;
     benchLeg5 = buildCube();
     benchLeg6 = buildCube();
     benchLeg5->setScale(0.48,2.42,0.22);
     benchLeg6->setScale(0.48,2.42,0.22);
     benchLeg5->setTranslate(0.00,-2.37,-0.65);
     benchLeg6->setTranslate(0.00,-2.09,0.65);
     benchSeat3->addChild(benchLeg5);
     benchSeat3->addChild(benchLeg6);

     ObjectNode* benchSeat4; //Bench 4
     benchSeat4 = buildCube();
     benchSeat4->setScale(0.06,0.81,0.17);
     benchSeat4->setTranslate(0,4.78,-0.68);
     benchSeat4->setRotate(90,0,1,0);

     //Bench 4 Legs
     ObjectNode* benchLeg7;
     ObjectNode* benchLeg8;
     benchLeg7 = buildCube();
     benchLeg8 = buildCube();
     benchLeg7->setScale(0.48,2.42,0.22);
     benchLeg8->setScale(0.48,2.42,0.22);
     benchLeg7->setTranslate(0.00,-2.37,-0.65);
     benchLeg8->setTranslate(0.00,-2.09,0.65);
     benchSeat4->addChild(benchLeg7);
     benchSeat4->addChild(benchLeg8);


    //Add Objects to the sculpture
     //Add benches to the base
     base->addChild(benchSeat1);
     base->addChild(benchSeat2);
     base->addChild(benchSeat3);
     base->addChild(benchSeat4);

    //Add the Base and Connector parent objects to lObject
    lObject->addChild(base);
    lObject->addChild(connector);

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

    //Torso - Neck - Head
    ObjectNode* torso = new ObjectNode();
    torso = buildCube();
    torso->setScale(0.29,0.50,0.38);
    ObjectNode* neck = new ObjectNode();
    neck = buildCube();
    neck->setTranslate(0.00,1.18,0.00);
    neck->setScale(0.09,0.19,0.09);
    ObjectNode* head = new ObjectNode();
    head = buildCube();
    head->setTranslate(0,2.51,0);
    head->setScale(7.64,2.00,5.40);

    //Arms
    ObjectNode* armLeft = new ObjectNode();
    armLeft = buildCylinder(20);
    armLeft->setTranslate(0,0.96,-1.66);
    armLeft->setRotate(62.00,-6.03,0.00,0.17);
    armLeft->setScale(0.31,0.83,0.18);
    ObjectNode* armRight = new ObjectNode();
    armRight = buildCylinder(20);
    armRight->setTranslate(0.00, 0.96, 1.66 );
    armRight->setRotate(62.00, 6.03,0.00 ,0.17 );
    armRight->setScale(0.31 ,0.83 , 0.18);

    //Legs
    ObjectNode* legLeft = new ObjectNode();
    legLeft = buildCylinder(20);
    legLeft->setTranslate(0.78 ,-1.35 ,0.71 );
    legLeft->setRotate(62.00,0.17 ,0.00 , 6.03);
    legLeft->setScale(0.20 ,1.27 ,0.18 );

    ObjectNode* legRight = new ObjectNode();
    legRight = buildCylinder(20);
    legRight->setTranslate(0.78 ,-1.56 ,-0.71 );
    legRight->setRotate(62.00,0.17 ,0.00 , 6.03);
    legRight->setScale(0.20 ,1.27 ,0.18 );

    //Hands
    ObjectNode* handLeft = new ObjectNode();
    handLeft = buildCube();
    handLeft->setTranslate(-0.09 ,1.22 ,0.02 );
    handLeft->setScale(1.30 ,0.23 , 1.14);
    ObjectNode* handRight = new ObjectNode();
    handRight = buildCube();
    handRight->setTranslate(-0.09 , 1.22, 0.02);
    handRight->setScale(1.30 ,0.23 ,1.14 );

    //Feet
    ObjectNode* footLeft = new ObjectNode();
    footLeft = buildCube();
    footLeft->setTranslate(-0.50 ,-1.18 ,0.00 );
    footLeft->setScale(1.47 ,0.15 ,1.36 );
    ObjectNode* footRight = new ObjectNode();
    footRight = buildCube();
    footRight->setTranslate(-0.45 ,-0.88 ,0.00 );
    footRight->setScale(1.47 ,0.15 ,1.36 );

    //Assigning children to parents.

    neck->addChild(head);

    //Adding hands to the Arms
    armLeft->addChild(handLeft);
    armRight->addChild(handRight);

    //Adding feet to the legs
    legLeft->addChild(footLeft);
    legRight->addChild(footRight);

    torso->addChild(neck);
    //Adding Legs and Arms to the torso
    torso->addChild(armLeft);
    torso->addChild(armRight);
    torso->addChild(legLeft);
    torso->addChild(legRight);

    //Add Torso to the lObject
    lObject->addChild(torso);

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
