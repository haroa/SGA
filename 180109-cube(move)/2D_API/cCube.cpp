#include "stdafx.h"
#include "cCube.h"


cCube::cCube()
	: m_fRotX(0)
	, m_fRotY(0)
	, m_fRotZ(0)
	, m_vPosition(0, 0, 0)
{
	m_matWorld = cMatrix::Identity(4);
}


cCube::~cCube()
{
}

void cCube::Setup()
{
	// ť�긦 �׸��� ���� 8���� ��ǥ
	// �ո�
	m_vecVertex.push_back(cVector3(-1.0f,-1.0f,-1.0f)); // 0
	m_vecVertex.push_back(cVector3(-1.0f, 1.0f,-1.0f));	// 1
	m_vecVertex.push_back(cVector3( 1.0f, 1.0f,-1.0f));	// 2
	m_vecVertex.push_back(cVector3( 1.0f,-1.0f,-1.0f));	// 3
	// �ĸ�
	m_vecVertex.push_back(cVector3(-1.0f,-1.0f, 1.0f));	// 4
	m_vecVertex.push_back(cVector3(-1.0f, 1.0f, 1.0f));	// 5
	m_vecVertex.push_back(cVector3( 1.0f, 1.0f, 1.0f));	// 6
	m_vecVertex.push_back(cVector3( 1.0f,-1.0f, 1.0f));	// 7

	// �ﰢ�� 12���� �׸��� ���ؼ� �� 3���� ��ǥ�� 36���� ��ǥ ������ �ʿ���
	// ��� �ﰢ���� ������� ���� �ð�������� �׸���.
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(7);

	m_vecIndex.push_back(1);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(2);

	m_vecIndex.push_back(4);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(4);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(0);

	m_vecIndex.push_back(7);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(7);
	m_vecIndex.push_back(5);
	m_vecIndex.push_back(4);

	m_vecIndex.push_back(3);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(3);
	m_vecIndex.push_back(6);
	m_vecIndex.push_back(7);

	m_vecIndex.push_back(0);
	m_vecIndex.push_back(1);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(0);
	m_vecIndex.push_back(2);
	m_vecIndex.push_back(3);
}

void cCube::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
		m_fRotY -= 0.1f;
	else if (GetAsyncKeyState('D') & 0x8000)
		m_fRotY += 0.1f;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_fRotX += 0.1f;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_fRotX -= 0.1f;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fRotZ -= 0.1f;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fRotZ += 0.1f;

	//cMatrix matRotS = cMatrix::Scale(2.0f, 2.0f, 2.0f);
	cMatrix matRotX = cMatrix::RotateX(m_fRotX);
	cMatrix matRotY = cMatrix::RotateY(m_fRotY);
	cMatrix matRotZ = cMatrix::RotateZ(m_fRotZ);

	m_matWorld = matRotX * matRotY * matRotZ;
}

void cCube::Render(HDC hdc, cMatrix& matViewProj, cMatrix& matViewPort)
{
	for (int i = 0; i < m_vecIndex.size(); i += 3)
	{
		cVector3 v0 = m_vecVertex[m_vecIndex[i + 0]];
		cVector3 v1 = m_vecVertex[m_vecIndex[i + 1]];
		cVector3 v2 = m_vecVertex[m_vecIndex[i + 2]];

		cMatrix matWVP = m_matWorld * matViewProj;

		v0.TransformCoord(&matWVP); //��ġ?�׷�����?
		v1.TransformCoord(&matWVP);
		v2.TransformCoord(&matWVP);

		// �ĸ� �߷� ���� : �������� �����̽������� �� ���ʹ� Z�� ��� ����(0, 0, 1) �̴�.
		cVector3 v01 = v1 - v0;
		cVector3 v02 = v2 - v0;
		
		cVector3 n = cVector3::Cross(v01, v02);
		// �����δ�Ʈ ��� == 0 (90��), < 0 (90�� ���� ũ��), > 0 (90�� ���� �۴�)
		
		float number = cVector3::Dot(n, cVector3(0, 0, 1));	

		if (number > 0) continue;

		v0.TransformCoord(&matViewPort);
		v1.TransformCoord(&matViewPort);
		v2.TransformCoord(&matViewPort);

		MoveToEx(hdc, v0.x, v0.y, NULL);
		LineTo(hdc, v1.x, v1.y);
		LineTo(hdc, v2.x, v2.y);
		LineTo(hdc, v0.x, v0.y);
	}
}
