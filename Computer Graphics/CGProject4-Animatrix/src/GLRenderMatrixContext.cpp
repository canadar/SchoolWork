#include "CGCommon.h"

#include "GLRenderMatrixContext.h"
#include "View.h"

#include <QGLShaderProgram>

GLRenderMatrixContext::GLRenderMatrixContext()
{
    mProjMatrix.setToIdentity();
    mModelMatrix.setToIdentity();
    mViewMatrix.setToIdentity();

    mAutoPassToGL = false;
    mShader = NULL;
}

// Setup auto passing
void GLRenderMatrixContext::setShader(QGLShaderProgram* pShader)
{
    mShader = pShader;
    passProjToOpenGL(mShader);
    passModelToOpenGL(mShader);
    passViewToOpenGL(mShader);
}

void GLRenderMatrixContext::enableAutoPassingToGL(bool pEnable, QGLShaderProgram *pShader)
{
    mAutoPassToGL = pEnable;
    if(mAutoPassToGL)
    {
        if(pShader != NULL)
        {
            mShader = pShader;
            mShader->bind();
        }

        passProjToOpenGL(mShader);
        passModelToOpenGL(mShader);
        passViewToOpenGL(mShader);
    }
}

// Send information to OpenGL
void GLRenderMatrixContext::passProjToOpenGL(QGLShaderProgram *pShader)
{
    CG_GL_ERROR_CHECK

    // If a shader is provided then pass as uniform variable
    if(pShader != NULL)
    {
        pShader->setUniformValue("projMatrix", mProjMatrix);
        CG_GL_ERROR_CHECK
    }
    else // Use compatibility profile and OpenGL ModelView matrix
    {
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(mProjMatrix.constData());
        CG_GL_ERROR_CHECK
    }
}

void GLRenderMatrixContext::passModelToOpenGL(QGLShaderProgram *pShader)
{
    CG_GL_ERROR_CHECK

    // If a shader is provided then pass as uniform variable
    if(pShader != NULL)
    {
        pShader->setUniformValue("modelMatrix", mModelMatrix);
        pShader->setUniformValue("normalMatrix", mModelMatrix.normalMatrix());
        CG_GL_ERROR_CHECK
    }
    else // Use compatibility profile and OpenGL ModelView matrix
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadMatrixf(mModelMatrix.constData());
        CG_GL_ERROR_CHECK
    }
}

void GLRenderMatrixContext::passViewToOpenGL(QGLShaderProgram *pShader)
{
    CG_GL_ERROR_CHECK
    if(pShader == NULL)
    {
        fprintf(stderr, "GL Render Matrix Context: Cannot set view matrix without a shader.\n");
        fflush(stderr);
        return;
    }

    pShader->setUniformValue("viewMatrix", mViewMatrix);
    CG_GL_ERROR_CHECK
}

// Directly manipulate the proj matrix
void GLRenderMatrixContext::loadProjIdentity() { mProjMatrix.setToIdentity(); if(mAutoPassToGL) passProjToOpenGL(mShader); }
void GLRenderMatrixContext::loadProjMatrix(const QMatrix4x4 pProjMatrix) { mProjMatrix = pProjMatrix; if(mAutoPassToGL) passProjToOpenGL(mShader); }
void GLRenderMatrixContext::multProjMatrix(const QMatrix4x4 pMatrix) { mProjMatrix *= pMatrix; if(mAutoPassToGL) passProjToOpenGL(mShader); }

// Directly manipulate the model matrix
void GLRenderMatrixContext::loadModelIdentity() { mModelMatrix.setToIdentity(); if(mAutoPassToGL) passModelToOpenGL(mShader); }
void GLRenderMatrixContext::loadModelMatrix(const QMatrix4x4 pModelMatrix) { mModelMatrix = pModelMatrix; if(mAutoPassToGL) passModelToOpenGL(mShader); }
void GLRenderMatrixContext::multModelMatrix(const QMatrix4x4 pMatrix) { mModelMatrix *= pMatrix; if(mAutoPassToGL) passModelToOpenGL(mShader); }

// Directly manipulate the view matrix
void GLRenderMatrixContext::loadViewIdentity() { mViewMatrix.setToIdentity(); if(mAutoPassToGL) passViewToOpenGL(mShader); }
void GLRenderMatrixContext::loadViewMatrix(const QMatrix4x4 pViewMatrix) { mViewMatrix = pViewMatrix; if(mAutoPassToGL) passViewToOpenGL(mShader); }
void GLRenderMatrixContext::multViewMatrix(const QMatrix4x4 pMatrix) { mViewMatrix *= pMatrix; if(mAutoPassToGL) passViewToOpenGL(mShader); }

// Different ways to build the projection matrix
void GLRenderMatrixContext::frustum(float pLeft, float pRight, float pBottom, float pTop, float pNear, float pFar)
{
    mProjMatrix.frustum(pLeft, pRight, pBottom, pTop, pNear, pFar);
    if(mAutoPassToGL) passProjToOpenGL(mShader);
}

void GLRenderMatrixContext::perspective(float pVerticalFOV, float pAspectRatio, float pNear, float pFar)
{
    mProjMatrix.perspective(pVerticalFOV, pAspectRatio, pNear, pFar);
    if(mAutoPassToGL) passProjToOpenGL(mShader);
}

void GLRenderMatrixContext::ortho(float pLeft, float pRight, float pBottom, float pTop, float pNear, float pFar)
{
    mProjMatrix.ortho(pLeft, pRight, pBottom, pTop, pNear, pFar);
    if(mAutoPassToGL) passProjToOpenGL(mShader);
}

void GLRenderMatrixContext::ortho2D(float pLeft, float pRight, float pBottom, float pTop)
{
    mProjMatrix.ortho(pLeft, pRight, pBottom, pTop, -1, 1);
    if(mAutoPassToGL) passProjToOpenGL(mShader);
}

// Setup the view matrix
void GLRenderMatrixContext::lookAt(float pEyeX, float pEyeY, float pEyeZ,
                                   float pAtX, float pAtY, float pAtZ,
                                   float pUpX, float pUpY, float pUpZ)
{
    mViewMatrix.lookAt(QVector3D(pEyeX, pEyeY, pEyeZ),
                       QVector3D(pAtX, pAtY, pAtZ),
                       QVector3D(pUpX, pUpY, pUpZ));
    if(mAutoPassToGL) passViewToOpenGL(mShader);
}

void GLRenderMatrixContext::pose(CameraPose* pPose)
{
    // Sanity check
    if(pPose == NULL) return;

    // Get orientation information
    const CG_REAL* pM3 = pPose->GetOrientationMatrix();
    QMatrix4x4 lOrient(pM3[0], pM3[3], pM3[6], 0.0,
                       pM3[1], pM3[4], pM3[7], 0.0,
                       pM3[2], pM3[5], pM3[8], 0.0,
                          0.0,    0.0,    0.0, 1.0);
    mViewMatrix *= lOrient;

    // Get position information
    CG_REAL pos[3];
    pPose->GetPosition(pos[0], pos[1], pos[2]);
    mViewMatrix.translate(-pos[0], -pos[1], -pos[2]);
    mViewMatrix.optimize();

    if(mAutoPassToGL) passViewToOpenGL(mShader);
}

// Transform the view matrix
void GLRenderMatrixContext::translateView(double pTx, double pTy, double pTz)
{
    mViewMatrix.translate(pTx,pTy,pTz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passViewToOpenGL(mShader);
}

void GLRenderMatrixContext::rotateView(double pAngleInDegrees, double pRx, double pRy, double pRz)
{
    mViewMatrix.rotate(pAngleInDegrees,pRx,pRy,pRz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passViewToOpenGL(mShader);
}

void GLRenderMatrixContext::scaleView(double pSx, double pSy, double pSz)
{
    mViewMatrix.scale(pSx,pSy,pSz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passViewToOpenGL(mShader);
}

// Apply one of the three basic transformations to the model matrix
void GLRenderMatrixContext::translate(double pTx, double pTy, double pTz)
{
    mModelMatrix.translate(pTx, pTy, pTz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passModelToOpenGL(mShader);
}

void GLRenderMatrixContext::rotate(double pAngleInDegrees, double pRx, double pRy, double pRz)
{
    mModelMatrix.rotate(pAngleInDegrees,pRx,pRy,pRz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passModelToOpenGL(mShader);
}

void GLRenderMatrixContext::scale(double pSx, double pSy, double pSz)
{
    mModelMatrix.scale(pSx,pSy,pSz);
    // Pass the new matrix to OpenGL
    if(mAutoPassToGL) passModelToOpenGL(mShader);
}

// Manage the internal matrix stacks
void GLRenderMatrixContext::pushProjMatrix() { mProjMatrixStack.push(mProjMatrix); }
void GLRenderMatrixContext::popProjMatrix()
{
    if(mProjMatrixStack.isEmpty())
    {
        fprintf(stderr, "GL Render Matrix Context: Proj matrix stack underflow.\n");
        fflush(stderr);
    }
    else
    {
        mProjMatrix = mProjMatrixStack.pop();
        if(mAutoPassToGL) passProjToOpenGL(mShader);
    }
}

void GLRenderMatrixContext::pushModelMatrix() { mModelMatrixStack.push(mModelMatrix); }
void GLRenderMatrixContext::popModelMatrix()
{
    if(mModelMatrixStack.isEmpty())
    {
        fprintf(stderr, "GL Render Matrix Context: Model matrix stack underflow.\n");
        fflush(stderr);
    }
    else
    {
        mModelMatrix = mModelMatrixStack.pop();
        if(mAutoPassToGL) passModelToOpenGL(mShader);
    }
}

void GLRenderMatrixContext::pushViewMatrix() { mViewMatrixStack.push(mViewMatrix); }
void GLRenderMatrixContext::popViewMatrix()
{
    if(mViewMatrixStack.isEmpty())
    {
        fprintf(stderr, "GL Render Matrix Context: View matrix stack underflow.\n");
        fflush(stderr);
    }
    else
    {
        mViewMatrix = mViewMatrixStack.pop();
        if(mAutoPassToGL) passViewToOpenGL(mShader);
    }
}
