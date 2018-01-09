#pragma once
#include "cVector3.h"
#include "cMatrix.h"
class cCamera
{
private:
	float		m_fDistance;	// ť�� ���� ī�޶� �Ÿ�
	cVector3	m_vEye;			// ī�޶� ��ġ
	cVector3	m_vLookAt;		// �ٶ󺸴� ��ġ
	cVector3	m_vUp;			// ������ �� ����

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

