#include "stdafx.h"
#include "cCamera.h"


cCamera::cCamera()
	:m_fDistance(-10.0f)
	,m_fRotX(0)
	,m_fRotY(0)
{
}


cCamera::~cCamera()
{
}

void cCamera::Setup()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	//cVector3 vEye(0, 0, -5);
	//cMatrix matRotX = cMatrix::RotateX(0.0f);
	//vEye.TransformCoord(&matRotX);
	//cMatrix matView = cMatrix::View(&vEye, new cVector3(0, 0, 0),
	//	new cVector3(0, 1, 0));
	//cMatrix matProj = cMatrix::Projection(PI / 4.0f, rc.right / (float)rc.bottom, 1, 1000);
	//cMatrix matViewProj = matView * matProj;
	// 프로젝션 매트릭스 셋팅
	m_vEye = cVector3(0, 0, m_fDistance);
	m_vLookAt = cVector3(0, 0, 0);
	m_vUp = cVector3(0, 1, 0);

	m_matView = cMatrix::View(&m_vEye, &m_vLookAt, &m_vUp);
	m_matProj = cMatrix::Projection(PI / 5.0f, rc.right / (float)rc.bottom, 1, 1000);
}

void cCamera::Update(cVector3* pTarget)
{
	// 뷰 매트릭스 셋팅 - 타겟 == 큐브의 포지션
	//float		m_fRotX;
	//float		m_fRotY;
	//bool		m_isRButtonDown;
	//POINT		m_ptPrevMouse;

	if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
		m_fRotX += 0.1f;
	else if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
		m_fRotX -= 0.1f;
	if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
		m_fRotY -= 0.1f;
	else if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
		m_fRotY += 0.1f;

	cMatrix matRotX = cMatrix::RotateX(m_fRotX);
	cMatrix matRotY = cMatrix::RotateY(m_fRotY);

	cVector3 temp = m_vEye;
	temp.TransformCoord(&matRotX);
	temp.TransformCoord(&matRotY);

	temp = temp + *pTarget;
	m_matView = cMatrix::View(&temp, pTarget, &m_vUp);
}
