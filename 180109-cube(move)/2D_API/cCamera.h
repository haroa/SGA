#pragma once
#include "cVector3.h"
#include "cMatrix.h"
class cCamera
{
private:
	float		m_fDistance;	// 큐브 기준 카메라 거리
	cVector3	m_vEye;			// 카메라 위치
	cVector3	m_vLookAt;		// 바라보는 위치
	cVector3	m_vUp;			// 임의의 업 벡터

	cMatrix		m_matView;
	cMatrix		m_matProj;

	float		m_fRotX;
	float		m_fRotY;
	bool		m_isRButtonDown;
	POINT		m_ptPrevMouse;

public:
	cCamera();
	~cCamera();

	void Setup();
	void Update(cVector3* pTarget = NULL);

	cMatrix GetViewProjMatrix() { return m_matView * m_matProj; }
};

