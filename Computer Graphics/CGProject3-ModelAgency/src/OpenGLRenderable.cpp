#include "OpenGLRenderable.h"
#include <QGLShaderProgram>

OpenGLRenderable::OpenGLRenderable(double pFOV, double pNear, double pFar)
{
    mShader = NULL;
    mAllowAliasing = false;

    mW = mH = -1;
    mHorizFOV = pFOV;
    mNear = pNear;
    mFar = pFar;

    mOrtho2D = false;
}

OpenGLRenderable::OpenGLRenderable(bool p2DContent)
{
    if(!p2DContent) OpenGLRenderable();
    else
    {
        mW = mH = -1;
        mShader = NULL;
        mAllowAliasing = false;
        mHorizFOV = mNear = mFar = 0.0;
        mOrtho2D = true;
    }
}

OpenGLRenderable::~OpenGLRenderable()
{
    if(mShader != NULL) delete mShader;
}

void OpenGLRenderable::initializeGLRenderable(bool pAllowAliasing)
{
    static bool sMakingCurrent = false;
    CG_GL_ERROR_CHECK
    if(!sMakingCurrent)
    {
        sMakingCurrent = true;
        if(!makeGLContextCurrent())
        {
            printf("Error: could not enable current context (%s:%d).\n", __FILE__, __LINE__);
            fflush(stdout);
        }
        sMakingCurrent = false;
    }

    /* EDIT: GLEW support is disabled for now, may bring back later
    // Initialize GLEW
    static GLenum err = glewInit();
    if(err != GLEW_OK) fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    */

    // Basic OpenGL setup
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_TEXTURE_2D);

    mAllowAliasing = pAllowAliasing;
    if(!mAllowAliasing) glEnable(GL_MULTISAMPLE);
    else glDisable(GL_MULTISAMPLE);

    if(!mOrtho2D) glEnable(GL_DEPTH_TEST);

    CG_GL_ERROR_CHECK
}

void OpenGLRenderable::resizeGLRenderable(int w, int h)
{
    mW = w; mH = h;

    CG_GL_ERROR_CHECK
    // Setup Viewport
    glViewport(0, 0, mW, mH);

    // Setup projection matrix
    glMatrixMode(GL_PROJECTION); glLoadIdentity();

    CG_GL_ERROR_CHECK
    if(mOrtho2D) gluOrtho2D(-mW/2.0, mW/2.0, -mH/2.0, mH/2.0);
    else
    {
        // Setup OpenGL projection Matrix
        double lAspect = mW/(double)mH;
        gluPerspective(mHorizFOV/lAspect, lAspect, mNear, mFar);
    }

    CG_GL_ERROR_CHECK
    // Clean model-view matrix
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    CG_GL_ERROR_CHECK
}

void OpenGLRenderable::initShader(const QString &pVTXShader, const QString &pFRGShader, bool pWithTans)
{
    initShader(mShader, pVTXShader, pFRGShader, pWithTans);

    // Set default values
    setShaderDefaults();
    CG_GL_ERROR_CHECK
}

void OpenGLRenderable::initShader(QGLShaderProgram* &pShader, const QString &pVTXShader, const QString &pFRGShader, bool pWithTans)
{
    CG_GL_ERROR_CHECK
    // Make shader
    if(pShader != NULL) delete pShader;
    pShader = new QGLShaderProgram();
    if(pShader == NULL) return;

    CG_GL_ERROR_CHECK
    // Compile and link
    if(!pShader->addShaderFromSourceFile(QGLShader::Vertex, pVTXShader) ||
       !pShader->addShaderFromSourceFile(QGLShader::Fragment, pFRGShader))
    {
        printf("Shader Compilation Error:\n%s\n", pShader->log().toLatin1().data());
        fflush(stdout);
        delete pShader; pShader = NULL;
        return;
    }

    // Uncomment the lines below to always see the compilation log from a vertex shader
//    printf("Compile Log:\n%s\n", pShader->log().toLatin1().data());
//    fflush(stdout);

    CG_GL_ERROR_CHECK
    if(pWithTans) pShader->bindAttributeLocation("tangent", 1);
    if(!pShader->link())
    {
        printf("Shader Linking Error:\n%s\n", pShader->log().toLatin1().data());
        fflush(stdout);
        delete pShader; pShader = NULL;
        return;
    }

    // Uncomment the lines below to always see the compilation log from a fragment shader
//    printf("Link Log:\n%s\n", pShader->log().toLatin1().data());
//    fflush(stdout);

    CG_GL_ERROR_CHECK
}

//=====================================//

#include <View.h>

ViewMatrixOpenGLRenderable::ViewMatrixOpenGLRenderable(double pFOV, double pNear, double pFar)
    : OpenGLRenderable(pFOV, pNear, pFar)
{
    mPose = CameraPose::MakeFromLookAt(0.0, 0.0, 2.0);
}

ViewMatrixOpenGLRenderable::~ViewMatrixOpenGLRenderable()
{
    if(mPose != NULL) delete mPose;
}

void ViewMatrixOpenGLRenderable::setCameraView(const CameraPose* pPose, const CameraDistortion* pLens)
{
    setCameraView(mShader, pPose, pLens);
}

void ViewMatrixOpenGLRenderable::setCameraView(QGLShaderProgram *pShader, const CameraPose* pPose, const CameraDistortion* pLens)
{
    CG_GL_ERROR_CHECK
    // Copy supplied pose (if not NULL)
    if(pPose != NULL) (*mPose) = (*pPose);

    CG_GL_ERROR_CHECK
    // Clear modelview matrix
    glMatrixMode(GL_MODELVIEW); glPushMatrix(); glLoadIdentity();

    CG_GL_ERROR_CHECK
    // Retrieve and prepare camera pose info
    CG_REAL pos[3];
    mPose->GetPosition(pos[0], pos[1], pos[2]);
    const CG_REAL* pM3 = mPose->GetOrientationMatrix();

    CG_GL_ERROR_CHECK
    double lM4[16] = {
        pM3[0], pM3[1], pM3[2], 0.0,
        pM3[3], pM3[4], pM3[5], 0.0,
        pM3[6], pM3[7], pM3[8], 0.0,
           0.0,    0.0,    0.0, 1.0
    };

    CG_GL_ERROR_CHECK
    // Apply to current OpenGL matrix
    glMultMatrixd(lM4);
    glTranslatef(-pos[0], -pos[1], -pos[2]);
//    glScalef(-1.0, 1.0, 1.0);
//    glRotated(-90, 0.0, 1.0, 0.0);

    // Then, tell GLSL
    if(pShader != NULL)
    {
        // Read back the resulting matrix
        double lMV4[16];
        glGetDoublev(GL_MODELVIEW_MATRIX, lMV4);

        // Build Qt Matrix object
        for(int i=0; i<16; i++)
            mViewMatrix.data()[i] = lMV4[i];

        CG_GL_ERROR_CHECK
        // Pass camera data to GLSL
        pShader->bind();
        pShader->setUniformValue("viewMatrix", mViewMatrix);

        mPose->GetPosition(pos[0], pos[1], pos[2]);
        pShader->setUniformValue("cameraPos", pos[0], pos[1], pos[2]);

        pShader->setUniformValue("lightPos", 1.0, 5.5, 8.5);
    }

    CG_GL_ERROR_CHECK
    // Clear view matrix (it's in the shader now)
    glPopMatrix();

    // Make use of supplied projection data (if not null)
    if(pLens != NULL)
    {
        // Get data relevant to viewing frustum
        CG_REAL lAspect, lFOV;
        pLens->GetFrustumData(lAspect, lFOV);

        // Aspect ratio is ignored for now
        mHorizFOV = lFOV;
        resizeGLRenderable(mW, mH);
    }

    CG_GL_ERROR_CHECK
}

//=====================================//

FixedRatio2DGLRenderable::FixedRatio2DGLRenderable(int pContentsWidth, int pContentsHeight, bool pEnableZoomAndPan) :
        OpenGLRenderable(true)
{
    mContentsWidth = pContentsWidth;
    mContentsHeight = pContentsHeight;
    mWidthScale = mHeightScale = 1.0;

    mEnableZoomAndPan = pEnableZoomAndPan;
    mZoom = 1.0f; mXOff = mYOff = 0.0f;
}

FixedRatio2DGLRenderable::~FixedRatio2DGLRenderable() {}

#define MAX(X, Y) ((X)>(Y)?(X):(Y))

void FixedRatio2DGLRenderable::setZoom(float pZoom)
{
    if(!mEnableZoomAndPan) return;
    mZoom = MAX(1.0f, pZoom);
    clampOffset();
}

void FixedRatio2DGLRenderable::setOffset(int pXOff, int pYOff)
{
    if(!mEnableZoomAndPan) return;
    mXOff = pXOff; mYOff = pYOff;
    clampOffset();
}

void FixedRatio2DGLRenderable::enableZoomAndPan(bool pEnable)
{
    mEnableZoomAndPan = pEnable;
    if(!mEnableZoomAndPan)
    {
        mZoom = 1.0f;
        mXOff = mYOff = 0.0f;
    }
}

inline void FixedRatio2DGLRenderable::clampOffset()
{
    float lHalfXMax = getOffsetRangeX()/2.0f, lHalfYMax = getOffsetRangeY()/2.0f;
    if(fabs(mXOff) > lHalfXMax)
    {
        if(mXOff > 0) mXOff = lHalfXMax;
        else mXOff = -lHalfXMax;
    }

    if(fabs(mYOff) > lHalfYMax)
    {
        if(mYOff > 0) mYOff = lHalfYMax;
        else mYOff = -lHalfYMax;
    }
}

void FixedRatio2DGLRenderable::resizeGLRenderable(int w, int h)
{
    mW = w; mH = h;
    calcWindowScale();

    // Setup viewport
    glViewport(0, 0, (GLint)mW, (GLint)mH);

    // Setup Orthographic 2D projection
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluOrtho2D(-mW/2.0, mW/2.0, -mH/2.0, mH/2.0);

    // Identity modelview transform
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

void FixedRatio2DGLRenderable::calcWindowScale()
{
    // Reset scaling
    mHeightScale = mWidthScale = 1.0;

    // Adjust scaling so image stays centered with correct aspect ratio
    float lWindowRatio = mW/(float)mH;
    float lImageRatio = mContentsWidth/(float)mContentsHeight;

    if(lImageRatio < lWindowRatio) mWidthScale = lImageRatio/lWindowRatio;
    else mHeightScale = lWindowRatio/lImageRatio;
}

void FixedRatio2DGLRenderable::setContentsDimensions(int w, int h)
{
    mContentsWidth = w;
    mContentsHeight = h;
    calcWindowScale();
}

void FixedRatio2DGLRenderable::drawContents()
{
    // Draw a single textured quad scaled to the proper ratio
    GLfloat halfWidth = mW*mWidthScale/2.0*mZoom;
    GLfloat halfHeight = mH*mHeightScale/2.0*mZoom;

    glPushMatrix();
    glTranslatef(mXOff, mYOff, 0.0);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex2f(-halfWidth, -halfHeight);

        glTexCoord2f(0.0, 1.0);
        glVertex2f(-halfWidth,  halfHeight);

        glTexCoord2f(1.0, 1.0);
        glVertex2f( halfWidth,  halfHeight);

        glTexCoord2f(1.0, 0.0);
        glVertex2f( halfWidth, -halfHeight);
    glEnd();

    glPopMatrix();
}
