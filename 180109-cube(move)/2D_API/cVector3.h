#pragma once

class cMatrix;

class cVector3
{
public:
	cVector3();
	cVector3(float _x, float _y, float _z);
	~cVector3();

public:
	float x, y, z;

	bool operator == (cVector3& v);
	bool operator != (cVector3& v);
	cVector3 operator + (cVector3& v);
	cVector3 operator - (cVector3& v);
	cVector3 operator * (float f);
	friend cVector3 operator * (float f, cVector3& v);

	float Length();		// 실제 길이
	float LengthSq();	// 길이의 제곱 (크기 비교 할 때 쓴다)
	cVector3 Normalize();
	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);

	void TransformCoord(cMatrix* pmat); // 포인트
	void TransformNormal(cMatrix* pmat); // 벡터
};