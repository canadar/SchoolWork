#ifndef VIEW_H_
#define VIEW_H_

#include "CGCommon.h"

#include <string>

// Data describing camera position and orientation w/ and optional silhouette image
class CameraPose
{
public:
    CameraPose();
    CameraPose(const CameraPose &pCP);
    virtual ~CameraPose();

    // Accessor functions
    void GetPosition(CG_REAL &pX, CG_REAL &pY, CG_REAL &pZ) const;
    const CG_REAL* GetOrientationMatrix() const;

    void Nudge(const CG_REAL &pDX, const CG_REAL &pDY, const CG_REAL &pDZ);

    // Build a pose from a 'quaternion' coordinate description
    static CameraPose* MakeFromQuaternion(const CG_REAL &pX, const CG_REAL &pY, const CG_REAL &pZ,
                                          const CG_REAL pQuatI = 0.0, const CG_REAL pQuatJ = 0.0,
                                          const CG_REAL pQuatK = 0.0, const CG_REAL pQuatQ = 1.0);

    // Build a pose from a 'LookAt' coordinate description (a la gluLookat())
    static CameraPose* MakeFromLookAt(const CG_REAL &pX, const CG_REAL &pY, const CG_REAL &pZ,
                                      const CG_REAL pAtX = 0.0, const CG_REAL pAtY = 0.0, const CG_REAL pAtZ = 0.0,
                                      const CG_REAL pUpX = 0.0, const CG_REAL pUpY = 1.0, const CG_REAL pUpZ = 0.0);


protected:
    // Data describing the optics of this view
    // (position, projection and distortion)
    CG_REAL mX, mY, mZ;			// World position
    CG_REAL mM[9];				// Orientation Matrix

    // Built in quaternion conversion functions
    static void QuatToMatrix(CG_REAL *pM, const double &pi, const double &pj, const double &pk, const double &pQr);
    static void MatrixToQuat(const CG_REAL *pM, double &pi, double &pj, double &pk, double &pQr);
};

// Data for distortion introduced by a typical camera lens
class CameraDistortion
{
public:
    CameraDistortion();
    CameraDistortion(const CameraDistortion &pCD);
    CameraDistortion(const CG_REAL pFocalLengthMM, const CG_REAL pSensorWidthMM = 32, const CG_REAL pImageAspect = 1.0,
                     const CG_REAL pImageCenterX = 0.0, const CG_REAL pImageCenterY = 0.0,
                     const CG_REAL mRadial1 = 0.0, const CG_REAL mRadial2 = 0.0, const CG_REAL mRadial3 = 0.0,
                     const CG_REAL mTangent1 = 0.0, const CG_REAL mTangent2 = 0.0);

    virtual ~CameraDistortion();

    // Accessor funcitons
    void GetSensorData(CG_REAL &pCenterX, CG_REAL &pCenterY, CG_REAL &pWidth, CG_REAL &pAspect) const;
    void GetLensData(CG_REAL &pFocalLengthMM, CG_REAL &pFOVDeg) const;
    void GetDistortionData(CG_REAL &pRadial1, CG_REAL &pRadial2, CG_REAL &pRadial3, CG_REAL &pTangent1, CG_REAL &pTangent2) const;
    void GetFrustumData(CG_REAL &pAspect, CG_REAL &pFOVDeg) const;

    // Convert from focal length in mm to field-of-view in degrees (and back)
    static CG_REAL FLtoFOV(CG_REAL pFLmm, CG_REAL pSensorWmm)
    {
        return (360.0f*(float)::atan2(pSensorWmm, 2.0f*pFLmm)/M_PI);
    }

    static CG_REAL FOVtoFL(CG_REAL pFOV, CG_REAL pSensorWmm)
    {
        return (pSensorWmm/(2.0f*(float)::tan(M_PI*pFOV/360.0f)));
    }

protected:
    // Optical center of the lens (in pixels)
    CG_REAL mImageCenterX, mImageCenterY;

    // Distortion model parameters
    CG_REAL mRadialDistortion[3], mTangentialDistortion[2];

    // Lens focal length and image sensor/film plane width (in mm)
    CG_REAL mFocalLengthMM, mSensorWidthMM;

    // Field of view in degrees and image aspect ratio
    CG_REAL mFOVDeg, mImageAspect;
};

#endif /* VIEW_H_ */
