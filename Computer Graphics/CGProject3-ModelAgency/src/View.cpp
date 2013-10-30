#include <math.h>
#include "View.h"

/* =================================== */

CameraPose::CameraPose()
{
    // At origin facing down -Z axis
    mX = mY = mZ = 0.0;

    // Identity matrix matches 0 quaternion
    mM[0] = mM[4] = mM[8] = 1.0;
    mM[1] = mM[2] = mM[3] = 0.0;
    mM[5] = mM[6] = mM[7] = 0.0;
}

CameraPose::CameraPose(const CameraPose &pCP)
{
    // Copy all numerial values
    mX = pCP.mX; mY = pCP.mY; mZ = pCP.mZ;
    mM[0] = pCP.mM[0]; mM[3] = pCP.mM[3]; mM[6] = pCP.mM[6];
    mM[1] = pCP.mM[1]; mM[4] = pCP.mM[4]; mM[7] = pCP.mM[7];
    mM[2] = pCP.mM[2]; mM[5] = pCP.mM[5]; mM[8] = pCP.mM[8];
}

CameraPose::~CameraPose() {}

void CameraPose::GetPosition(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const
{
    pX = mX; pY = mY; pZ = mZ;
}

const CG_REAL* CameraPose::GetOrientationMatrix() const { return mM; }

void CameraPose::Nudge(const CG_REAL &pDX, const CG_REAL &pDY, const CG_REAL &pDZ)
{
    mX += pDX; mY += pDY; mZ += pDZ;
}

CameraPose* CameraPose::MakeFromQuaternion(const CG_REAL &pX, const CG_REAL &pY, const CG_REAL &pZ,
                                           const CG_REAL pQuatI, const CG_REAL pQuatJ,
                                           const CG_REAL pQuatK, const CG_REAL pQuatQ)
{
    // Allocate a new object
    CameraPose *lNewPose = new CameraPose();
    if(lNewPose == NULL) return NULL;

    // Assign location data
    lNewPose->mX = pX; lNewPose->mY = pY; lNewPose->mZ = pZ;

    // Compute orientation matrix from quaternion
    CameraPose::QuatToMatrix(lNewPose->mM, pQuatI, pQuatJ, pQuatK, pQuatQ);

    return lNewPose;
}

CameraPose* CameraPose::MakeFromLookAt(const CG_REAL &pX, const CG_REAL &pY, const CG_REAL &pZ,
                                       const CG_REAL pAtX, const CG_REAL pAtY, const CG_REAL pAtZ,
                                       const CG_REAL pUpX, const CG_REAL pUpY, const CG_REAL pUpZ)
{
    // Construct the view (F) and up (U) vectors
    CG_REAL lU[3] = { pUpX, pUpY, pUpZ };
    CG_REAL lF[3] = { pAtX - pX, pAtY - pY, pAtZ - pZ };

    // Check to make sure U and F are not zero-length (or nearly so)
    if(sqrt(VEC_LEN_SQ(lU)) < 0.000001 || sqrt(VEC_LEN_SQ(lF)) < 0.000001)
        return NULL;

    // Construct the third vector as a cross product
    CG_REAL lS[3] = { 0.0, 0.0, 0.0 };
    CROSSPROD(lF, lU, lS);

    // Check for a degenerate S (if F and U are too nearly parallel)
    CG_REAL len = 0;
    if((len = sqrt(VEC_LEN_SQ(lS))) < 0.0001)
    {
        if(fabs(lU[2] - len) < 0.0001) lU[2] -= 1.0;
        else if(fabs(lU[1] - len) < 0.0001) lU[1] -= 1.0;
        else if(fabs(lU[0] - len) < 0.0001) lU[0] -= 1.0;

        CROSSPROD(lF, lU, lS);
    }

    // Now, make sure F and U are orthogonal (think right-angle) by crossing S and F
    CROSSPROD(lS, lF, lU);

    // Normalize everything
    CG_REAL lenF = sqrt(VEC_LEN_SQ(lF)); NORMALIZE(lF, lenF);
    CG_REAL lenU = sqrt(VEC_LEN_SQ(lU)); NORMALIZE(lU, lenU);
    CG_REAL lenS = sqrt(VEC_LEN_SQ(lS)); NORMALIZE(lS, lenS);

    // Build the new CameraPose
    CameraPose* lNewPose = new CameraPose();
    if(lNewPose == NULL) return NULL;

    // Copy the position
    lNewPose->mX = pX;
    lNewPose->mY = pY;
    lNewPose->mZ = pZ;

    // Build the rotation matrix (column-major to match OpenGL matrices)
    lNewPose->mM[0] =  lS[0]; lNewPose->mM[3] =  lS[1]; lNewPose->mM[6] =  lS[2];
    lNewPose->mM[1] =  lU[0]; lNewPose->mM[4] =  lU[1]; lNewPose->mM[7] =  lU[2];
    lNewPose->mM[2] = -lF[0]; lNewPose->mM[5] = -lF[1]; lNewPose->mM[8] = -lF[2];

    return lNewPose;
}

void CameraPose::QuatToMatrix(CG_REAL *pM, const double &x, const double &y, const double &z, const double &w)
{
    pM[0] = 1.0 - 2.0*y*y - 2.0*z*z;    pM[3] = 2.0*x*y - 2.0*w*z;          pM[6] = 2.0*x*z + 2.0*w*y;
    pM[1] = 2.0*x*y + 2.0*w*z;          pM[4] = 1.0 - 2.0*x*x - 2.0*z*z;    pM[7] = 2.0*y*z - 2.0*w*x;
    pM[2] = 2.0*x*z - 2.0*w*y;          pM[5] = 2.0*y*z + 2.0*w*x;          pM[8] = 1.0 - 2.0*x*x - 2.0 *y*y;
}

void CameraPose::MatrixToQuat(const CG_REAL *pM, double &x, double &y, double &z, double &w)
{
    double r00 = pM[0], r10 = pM[1], r20 = pM[2];
    double r01 = pM[3], r11 = pM[4], r21 = pM[5];
    double r02 = pM[6], r12 = pM[7], r22 = pM[8];

    double trace = r00 + r11 + r22;

    if( trace > 0 )
    {
        double s = 0.5 / sqrt(trace+ 1.0);
        w = 0.25 / s;
        x = ( r21 - r12 ) * s;
        y = ( r02 - r20 ) * s;
        z = ( r10 - r01 ) * s;
    }
    else
    {
        if ( r00 > r11 && r00 > r22 )
        {
            double s = 2.0 * sqrt( 1.0 + r00 - r11 - r22);
            w = (r21 - r12 ) / s;
            x = 0.25 * s;
            y = (r01 + r10 ) / s;
            z = (r02 + r20 ) / s;
        }
        else if (r11 > r22)
        {
            double s = 2.0 * sqrt( 1.0 + r11 - r00 - r22);
            w = (r02 - r20 ) / s;
            x = (r01 + r10 ) / s;
            y = 0.25 * s;
            z = (r12 + r21 ) / s;
        }
        else
        {
            double s = 2.0 * sqrt( 1.0 + r22 - r00 - r11 );
            w = (r10 - r01 ) / s;
            x = (r02 + r20 ) / s;
            y = (r12 + r21 ) / s;
            z = 0.25 * s;
        }
    }
}

/* =================================== */

CameraDistortion::CameraDistortion()
{
    // Distortion parameters
    mImageCenterX = mImageCenterY = 0.0f;
    mRadialDistortion[0] = mRadialDistortion[1] = mRadialDistortion[2] = 1.0f;
    mTangentialDistortion[0] = mTangentialDistortion[1] = 1.0f;

    // Pin-hole projection parameters (32mm width is old default in Blender)
    mImageAspect = 1.0f; mSensorWidthMM = 32;
    mFocalLengthMM = 45.0f; mFOVDeg = 39.1463f;
}


CameraDistortion::CameraDistortion(const CG_REAL pFocalLengthMM, const CG_REAL pSensorWidthMM, const CG_REAL pImageAspect,
                                   const CG_REAL pImageCenterX, const CG_REAL pImageCenterY,
                                   const CG_REAL pRadial1, const CG_REAL pRadial2, const CG_REAL pRadial3,
                                   const CG_REAL pTangent1, const CG_REAL pTangent2)
{
    mFocalLengthMM = pFocalLengthMM;
    mSensorWidthMM = pSensorWidthMM;

    mImageAspect = pImageAspect;
    mImageCenterX = pImageCenterX;
    mImageCenterY = pImageCenterY;

    mRadialDistortion[0] = pRadial1;
    mRadialDistortion[1] = pRadial2;
    mRadialDistortion[2] = pRadial3;

    mTangentialDistortion[0] = pTangent1;
    mTangentialDistortion[1] = pTangent2;

    // Compute field-of-view from focal length and sensor width
    mFOVDeg = FLtoFOV(mFocalLengthMM, mSensorWidthMM);
}

CameraDistortion::CameraDistortion(const CameraDistortion &pCD)
{
    mImageCenterX = pCD.mImageCenterX;
    mImageCenterY = pCD.mImageCenterY;

    mRadialDistortion[0] = pCD.mRadialDistortion[0];
    mRadialDistortion[1] = pCD.mRadialDistortion[1];
    mRadialDistortion[2] = pCD.mRadialDistortion[2];

    mTangentialDistortion[0] = pCD.mTangentialDistortion[0];
    mTangentialDistortion[1] = pCD.mTangentialDistortion[1];

    mImageAspect = pCD.mImageAspect;
    mSensorWidthMM = pCD.mSensorWidthMM;
    mFocalLengthMM = pCD.mFocalLengthMM;
    mFOVDeg = pCD.mFOVDeg;
}

CameraDistortion::~CameraDistortion() {}

void CameraDistortion::GetSensorData(CG_REAL &pCenterX, CG_REAL &pCenterY, CG_REAL &pWidth, CG_REAL &pAspect) const
{
    pCenterX = mImageCenterX;
    pCenterY = mImageCenterY;
    pWidth = mSensorWidthMM;
    pAspect = mImageAspect;
}

void CameraDistortion::GetLensData(CG_REAL &pFocalLengthMM, CG_REAL &pFOVDeg) const
{
    pFocalLengthMM = mFocalLengthMM;
    pFOVDeg = mFOVDeg;
}

void CameraDistortion::GetDistortionData(CG_REAL &pRadial1, CG_REAL &pRadial2, CG_REAL &pRadial3,
                                         CG_REAL &pTangent1, CG_REAL &pTangent2) const
{
    pRadial1 = mRadialDistortion[0];
    pRadial2 = mRadialDistortion[1];
    pRadial3 = mRadialDistortion[2];

    pTangent1 = mTangentialDistortion[0];
    pTangent2 = mTangentialDistortion[1];
}

void CameraDistortion::GetFrustumData(CG_REAL &pAspect, CG_REAL &pFOVDeg) const
{
    pAspect = mImageAspect;
    pFOVDeg = mFOVDeg;
}
