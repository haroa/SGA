#include "stdafx.h"
#include "cCharacterController.h"


cCharacterController::cCharacterController()
	: m_vPosition(0, 0, 0)
	, m_vFrom(0, 0, 0)
	, m_vTo(0, 0, 0)
	, m_vVia(0, 0, 0)
	, m_fT(0.0f)
	, m_fRotY(0)
	, m_fMoveSpeed(0.1f)
	, m_isMoving(false)
	, m_isLinear(false)
	, m_isBezier(false)
	, m_vPositionA(0, 0, 0)
	, m_vPositionB(0, 0, 0)
{  
	D3DXMatrixIdentity(&m_matWorld);
}


cCharacterController::~cCharacterController()
{
}

void cCharacterController::Update()
{
	//if (GetAsyncKeyState('A') & 0x8000)
	//	m_fRotY -= 0.1f;
	//else if (GetAsyncKeyState('D') & 0x8000)
	//	m_fRotY += 0.1f;
	
	D3DXMATRIXA16 matRotY;
	D3DXMatrixRotationY(&matRotY, m_fRotY);
	
	// 이동 방향 설정, 기본 이동 방향인 z축 양수 방향을 설정하고
	// 큐브의 회전 값을 이동 방향에도 적용 시켜서 이동 방향을 계산한다.
	D3DXVECTOR3 vDir(0, 0, 1);
	D3DXVec3TransformNormal(&vDir, &vDir, &matRotY);
	//if (GetAsyncKeyState('W') & 0x8000)
	//{
	//	m_vPosition = m_vPosition + m_vFrom * 0.1f;
	//	m_isMoving = true;
	//}
	//else if (GetAsyncKeyState('S') & 0x8000)
	//{
	//	m_vPosition = m_vPosition - vDir * 0.1f;
	//	m_isMoving = true;
	//}
	//else
	//{
	//	m_isMoving = false;
	//}

	if (!m_isLinear && GetAsyncKeyState('L') & 0x8000)
	{
		m_isLinear = true;
	}
	else if (m_isLinear && GetAsyncKeyState('L') & 0x8000)
	{
		m_isLinear = false;
		m_isMoving = false;
	}
	if (GetAsyncKeyState('B') & 0x8000)
	{
		m_isBezier = true;
	}

	if (m_isLinear)
	{
		m_isMoving = true;
		static int point = 0;
		m_vTo = m_vecHexa[point];
		m_fT += 0.01f;
		D3DXVec3Lerp(&m_vPosition, &m_vFrom, &m_vTo, m_fT);
		if (m_fT >= 1.0f)
		{
			point = (point + 1) % 6;
			m_fT = 0;
			m_vFrom = m_vTo;
			m_vTo = m_vecHexa[point];
		}
		D3DXVECTOR3 vDir1 = m_vTo - m_vFrom;
		float vDir2 = vDir1.x / vDir1.z;
	}
	if (m_isBezier)
	{
		m_isMoving = true;
		static int point = 0;
		m_vVia = m_vecHexa[point + 1];
		if (point != 4)
			m_vTo = m_vecHexa[point + 2];
		else
		{
			m_vTo = m_vecHexa[0];
		}
		m_fT += 0.01f;
		D3DXVec3Lerp(&m_vPositionA, &m_vFrom, &m_vVia, m_fT);
		D3DXVec3Lerp(&m_vPositionB, &m_vVia, &m_vTo, m_fT);
		D3DXVec3Lerp(&m_vPosition, &m_vPositionA, &m_vPositionB, m_fT);
		if (m_fT >= 1.0f)
		{
			m_fT = 0;
			m_vFrom = m_vTo;
			m_vVia = m_vecHexa[point + 1];
			if (point != 4)
			{
				m_vTo = m_vecHexa[point + 2];
				point = point + 2;
			}
			else
				point = 0;
		}
		
	}
	// 0 1 2
	// 2 3 4
	// 4 5 0


	D3DXMATRIXA16 matTrans;
	D3DXMatrixTranslation(&matTrans, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	
	m_matWorld = matRotY * matTrans;
}

void cCharacterController::LinearInterpolation(OUT D3DXVECTOR3 start, IN D3DXVECTOR3 from, IN D3DXVECTOR3 to, IN D3DXVECTOR3 t)
{
	start.x = from.x * (1.0f - t.x) + to.x * t.x;
	start.z = from.z * (1.0f - t.z) + to.z * t.z;
}
