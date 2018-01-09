#include "stdafx.h"
#include "cCube.h"


cCube::cCube()
	:m_fRotX(0)
	, m_fRotY(0)
	, m_fRotZ(0)
	, m_vPosition(0, 0, 0)
	, m_fmoveZ(0.1f)
	, m_fmoveX(0.1f)
{
	m_matWorld = cMatrix::Identity(4);
}


cCube::~cCube()
{
}

void cCube::Setup()
{
	// 큐브를 그리기 위한 8개의 좌표
	// 앞면
	m_vecVertex.push_back(cVector3(-1.0f,-1.0f,-1.0f));
	m_vecVertex.push_back(cVector3(-1.0f, 1.0f,-1.0f));
	m_vecVertex.push_back(cVector3( 1.0f, 1.0f,-1.0f));
	m_vecVertex.push_back(cVector3( 1.0f,-1.0f,-1.0f));
	// 뒷면
	m_vecVertex.push_back(cVector3(-1.0f,-1.0f, 1.0f));
	m_vecVertex.push_back(cVector3(-1.0f, 1.0f, 1.0f));
	m_vecVertex.push_back(cVector3( 1.0f, 1.0f, 1.0f));
	m_vecVertex.push_back(cVector3( 1.0f,-1.0f, 1.0f));

	//삼각형 12개를 그리기 위해서 각 3개의 좌표씩 36개의 좌표설정이 필요
	//모든 삼각형은 정면방향 기준 시계방향으로 그린다.
	//앞면
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(3);
	//우측
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(7);
	//뒷면
	m_vecIndex.push_back(7);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(7);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(4);
	//좌측
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(0);

	//윗면
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(2);

	//아래
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(7);
}

void cCube::Update()
{
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('A') & 0x8000)
		m_fRotY -= 0.1f;
	else if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('D') & 0x8000)
		m_fRotY += 0.1f;
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_UP) & 0x8000)
		m_fRotX += 0.1f;
	else if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_fRotX -= 0.1f;
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fRotZ -= 0.1f;
	else if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fRotZ += 0.1f;
	
	
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_fmoveZ += 0.1f;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_fmoveZ -= 0.1f;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fmoveX -= 0.1f;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fmoveX += 0.1f;

	cMatrix matRotX = cMatrix::RotateX(m_fRotX);
	cMatrix matRotY = cMatrix::RotateY(m_fRotY);
	cMatrix matRotZ = cMatrix::RotateZ(m_fRotZ);
	
	
	//cVector3 matPos = m_vPosition;
	m_vPosition.z = m_fmoveZ;
	m_vPosition.x = m_fmoveX;

	cMatrix trance = cMatrix::Translation(m_vPosition);


	m_matWorld = matRotX * matRotY * matRotZ * trance;


}

void cCube::Render(HDC hdc, cMatrix& matViewProj, cMatrix& matViewPort)
{
	for (int i = 0; i < m_vecIndex.size(); i += 3)
	{
		cVector3 v0 = m_vecVertex[m_vecIndex[i + 0]];
		cVector3 v1 = m_vecVertex[m_vecIndex[i + 1]];
		cVector3 v2 = m_vecVertex[m_vecIndex[i + 2]];
		
		cMatrix matWVP = m_matWorld * matViewProj;

		v0.TransformCoord(&matWVP);
		v1.TransformCoord(&matWVP);
		v2.TransformCoord(&matWVP);

		cVector3 v01 = v1 - v0;
		cVector3 v02 = v2 - v0;

		cVector3 n = cVector3::Cross(v01, v02);

		if (cVector3::Dot(n, cVector3(0, 0, 1)) > 0) continue;

		v0.TransformCoord(&matViewPort);
		v1.TransformCoord(&matViewPort);
		v2.TransformCoord(&matViewPort);

		MoveToEx(hdc, v0.x, v0.y, NULL);
		LineTo(hdc, v1.x, v1.y);
		LineTo(hdc, v2.x, v2.y);
		LineTo(hdc, v0.x, v0.y);
	}
}
