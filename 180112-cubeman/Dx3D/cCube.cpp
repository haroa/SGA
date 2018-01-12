#include "stdafx.h"
#include "cCube.h"


cCube::cCube(D3DXVECTOR3 scale, D3DXVECTOR3 rot, D3DXVECTOR3 trans, BODY_KIND kind, bool controll)
{	
	m_fRotX = 0;
	m_fRotY = 0;
	m_fRotZ = 0;


	D3DXMatrixScaling(&m_matScale, scale.x, scale.y, scale.z);
	
	D3DXMATRIXA16 childX, childY, childZ;
	D3DXMatrixRotationX(&childX, rot.x);
	D3DXMatrixRotationY(&childY, rot.y);
	D3DXMatrixRotationZ(&childZ, rot.z);

	m_matRot = childX * childY * childZ;

	m_vPosition = trans;

	D3DXMatrixTranslation(&m_matTrans, m_vPosition.x, m_vPosition.y, m_vPosition.z);

	m_matWorld = m_matScale * m_matRot * m_matTrans;

	

	m_iscontroll = controll;
}


cCube::~cCube()
{
}

void cCube::Setup()
{
	vector<D3DXVECTOR3> vecVertex;
	vecVertex.push_back(D3DXVECTOR3(-1.0f,-1.0f,-1.0f));	// 0
	vecVertex.push_back(D3DXVECTOR3(-1.0f, 1.0f,-1.0f));	// 1
	vecVertex.push_back(D3DXVECTOR3( 1.0f, 1.0f,-1.0f));	// 2
	vecVertex.push_back(D3DXVECTOR3( 1.0f,-1.0f,-1.0f));	// 3
	vecVertex.push_back(D3DXVECTOR3(-1.0f,-1.0f, 1.0f));	// 4
	vecVertex.push_back(D3DXVECTOR3(-1.0f, 1.0f, 1.0f));	// 5
	vecVertex.push_back(D3DXVECTOR3( 1.0f, 1.0f, 1.0f));	// 6
	vecVertex.push_back(D3DXVECTOR3( 1.0f,-1.0f, 1.0f));	// 7

	vector<int>	vecIndex;
	vecIndex.push_back(4);
	vecIndex.push_back(0);
	vecIndex.push_back(3);
	vecIndex.push_back(4);
	vecIndex.push_back(3);
	vecIndex.push_back(7);

	vecIndex.push_back(1);
	vecIndex.push_back(5);
	vecIndex.push_back(6);
	vecIndex.push_back(1);
	vecIndex.push_back(6);
	vecIndex.push_back(2);

	vecIndex.push_back(4);
	vecIndex.push_back(5);
	vecIndex.push_back(1);
	vecIndex.push_back(4);
	vecIndex.push_back(1);
	vecIndex.push_back(0);

	vecIndex.push_back(7);
	vecIndex.push_back(6);
	vecIndex.push_back(5);
	vecIndex.push_back(7);
	vecIndex.push_back(5);
	vecIndex.push_back(4);

	vecIndex.push_back(3);
	vecIndex.push_back(2);
	vecIndex.push_back(6);
	vecIndex.push_back(3);
	vecIndex.push_back(6);
	vecIndex.push_back(7);

	vecIndex.push_back(0);
	vecIndex.push_back(1);
	vecIndex.push_back(2);
	vecIndex.push_back(0);
	vecIndex.push_back(2);
	vecIndex.push_back(3);

	D3DCOLOR c;

	for (int i = 0; i < vecIndex.size(); ++i)
	{
		if (i % 6 == 0)
			c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

		m_vecPCVertex.push_back(ST_PC_VERTEX(vecVertex[vecIndex[i]], c));
	}

	m_isJumpping = false;
	m_fJumppower = 15.0f;
	m_fGravity = 0.0f;
}

void cCube::Update(cCube* cube)
{
	if (m_iscontroll)
	{
		if (GetAsyncKeyState('A') & 0x8000)
			m_fRotY -= 0.1f;
		else if (GetAsyncKeyState('D') & 0x8000)
			m_fRotY += 0.1f;
	}

	D3DXMATRIXA16 matRotX, matRotY, matRotZ;
	D3DXMatrixRotationX(&matRotX, m_fRotX);
	D3DXMatrixRotationY(&matRotY, m_fRotY);
	D3DXMatrixRotationZ(&matRotZ, m_fRotZ);

	m_matRot = matRotX * matRotY * matRotZ;

	// 이동 방향 설정, 기본 이동 방향인 z축 양수 방향을 설정하고
	// 큐브의 회전 값을 이동 방향에도 적용 시켜서 이동 방향을 계산한다.
	D3DXVECTOR3 vDir(0, 0, 1);
	D3DXVECTOR3 vJump(0, m_fJumppower, 0);
	D3DXVECTOR3 vGravity(0, m_fGravity, 0);
	D3DXVec3TransformNormal(&vDir, &vDir, &(m_matRot));

	if (m_iscontroll)
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			m_vPosition = m_vPosition + vDir * 0.1f;
			m_ismove = true;
		}
		else if (GetAsyncKeyState('S') & 0x8000)
		{
			m_vPosition = m_vPosition - vDir * 0.1f;
			m_ismove = true;
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x8001 && !m_isJumpping)
		{
			m_isJumpping = true;
		}
	}
	if (m_isJumpping)
	{
		m_vPosition = m_vPosition + vJump * 0.1f - vGravity;
		m_fGravity += 0.1f;
	}
	if (m_fGravity > m_vPosition.y && m_isJumpping)
	{
		m_fGravity = 0.0f;
		m_isJumpping = false;
		m_vPosition.y = 8.75f;
	}
	
	//D3DXMATRIXA16 matTrans;
	D3DXMatrixTranslation(&m_matTrans, m_vPosition.x, m_vPosition.y, m_vPosition.z);


	if (m_iscontroll)
	{
		m_matWorld = m_matScale * m_matRot * m_matTrans;
	}
	else
	{
		m_matWorld = m_matScale * m_matTrans * cube->GetWorld();
	}
	if (!m_vecChildCube.empty())
	{
		for (int i = 0; i < m_vecChildCube.size(); i++)
		{
			m_vecChildCube[i]->Update(cube);
		}
	}
}

void cCube::Render(LPDIRECT3DDEVICE9& pD3DDevice)
{
	pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecPCVertex.size() / 3,
		&m_vecPCVertex[0], sizeof(ST_PC_VERTEX));

	if (!m_vecChildCube.empty())
	{
		for (int i = 0; i < m_vecChildCube.size(); i++)
		{
			m_vecChildCube[i]->Render(pD3DDevice);
		}
	}
}
