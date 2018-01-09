#include "stdafx.h"
#include "cVector3.h"
#include "cMatrix.h"


cVector3::cVector3()
{
}


cVector3::cVector3(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z)
{
}

cVector3::~cVector3()
{
}

bool cVector3::operator==(cVector3& v)
{
	if (fabs(x - v.x) >= FLT_EPSILON)
		return false;

	if (fabs(y - v.y) >= FLT_EPSILON)
		return false;

	if (fabs(z - v.z) >= FLT_EPSILON)
		return false;

	return true;
}

bool cVector3::operator!=(cVector3& v)
{
	return !(*this == v);
}

cVector3 cVector3::operator+(cVector3& v)
{
	return cVector3(x + v.x, y + v.y, z + v.z);
}

cVector3 cVector3::operator-(cVector3& v)
{
	return cVector3(x - v.x, y - v.y, z - v.z);
}

cVector3 cVector3::operator*(float f)
{
	return cVector3(x * f, y * f, z * f);
}

cVector3 operator * (float f, cVector3& v)
{
	return v * f;
}

float cVector3::Length()
{
	return sqrtf(LengthSq());
}

float cVector3::LengthSq()
{
	return x * x + y * y + z * z;
}

cVector3 cVector3::Normalize()
{
	float l = Length();
	return cVector3(x / l, y / l, z / l);
}

float cVector3::Dot(cVector3& v1, cVector3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

cVector3 cVector3::Cross(cVector3& v1, cVector3& v2)
{
	return cVector3(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}

void cVector3::TransformCoord(cMatrix* pMat)
{
	cVector3 v;

	v.x = x * (*pMat)[0][0] + y * (*pMat)[1][0] + z * (*pMat)[2][0] + 1.0f * (*pMat)[3][0];
	v.y = x * (*pMat)[0][1] + y * (*pMat)[1][1] + z * (*pMat)[2][1] + 1.0f * (*pMat)[3][1];
	v.z = x * (*pMat)[0][2] + y * (*pMat)[1][2] + z * (*pMat)[2][2] + 1.0f * (*pMat)[3][2];
	float w = x * (*pMat)[0][3] + y * (*pMat)[1][3] + z * (*pMat)[2][3] + 1.0f * (*pMat)[3][3];

	if (fabs(w) > FLT_EPSILON)	// w가 0이 아닌 경우
	{
		v.x /= w;
		v.y /= w;
		v.z /= w;
	}

	x = v.x;
	y = v.y;
	z = v.z;
}

void cVector3::TransformNormal(cMatrix* pMat)
{
	cVector3 v;

	v.x = x * (*pMat)[0][0] + y * (*pMat)[1][0] + z * (*pMat)[2][0];
	v.y = x * (*pMat)[0][1] + y * (*pMat)[1][1] + z * (*pMat)[2][1];
	v.z = x * (*pMat)[0][2] + y * (*pMat)[1][2] + z * (*pMat)[2][2];

	x = v.x;
	y = v.y;
	z = v.z;
}
