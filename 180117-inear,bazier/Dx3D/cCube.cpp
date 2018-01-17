#include "stdafx.h"
#include "cCube.h"


cCube::cCube()
	: m_vLocalPos(0, 0, 0)
	, m_fRotX(0)
	, m_fRotY(0)
	, m_fRotXSpeed(0)
	, m_fRotYSpeed(0)
	, m_isMoving(false)
	, m_vCenter(0, 0, 0)
	, m_fRadius(1.0f)
	, m_pTexture(NULL)
{
	D3DXMatrixIdentity(&m_matWorld);
}


cCube::~cCube()
{
}

void cCube::Setup(vector<D3DXVECTOR2>* vecT, string key, D3DXMATRIXA16* pMat/*= NULL*/)
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

	if (pMat)
	{
		for (int i = 0; i < vecVertex.size(); ++i)
			D3DXVec3TransformCoord(&vecVertex[i], &vecVertex[i], pMat);

		D3DXVec3TransformCoord(&m_vCenter, &m_vCenter, &m_matWorld);

		// 반지름 사이즈는 xyz 축중 가장 큰 값으로 결정 된다.
		float size = pMat->_11;

		if (size < pMat->_22) size = pMat->_22;
		if (size < pMat->_33) size = pMat->_33;

		m_fRadius = size;
	}

	vector<int>	vecIndex;
	// 아랫면
	vecIndex.push_back(4);
	vecIndex.push_back(0);
	vecIndex.push_back(3);
	vecIndex.push_back(4);
	vecIndex.push_back(3);
	vecIndex.push_back(7);
	// 윗쪽
	vecIndex.push_back(1);
	vecIndex.push_back(5);
	vecIndex.push_back(6);
	vecIndex.push_back(1);
	vecIndex.push_back(6);
	vecIndex.push_back(2);
	// 왼쪽
	vecIndex.push_back(4);
	vecIndex.push_back(5);
	vecIndex.push_back(1);
	vecIndex.push_back(4);
	vecIndex.push_back(1);
	vecIndex.push_back(0);
	// 앞면
	vecIndex.push_back(7);
	vecIndex.push_back(6);
	vecIndex.push_back(5);
	vecIndex.push_back(7);
	vecIndex.push_back(5);
	vecIndex.push_back(4);
	// 오른쪽
	vecIndex.push_back(3);
	vecIndex.push_back(2);
	vecIndex.push_back(6);
	vecIndex.push_back(3);
	vecIndex.push_back(6);
	vecIndex.push_back(7);
	// 뒷면
	vecIndex.push_back(0);
	vecIndex.push_back(1);
	vecIndex.push_back(2);
	vecIndex.push_back(0);
	vecIndex.push_back(2);
	vecIndex.push_back(3);

	if (vecT == NULL)
		SetPCVertex(vecVertex, vecIndex);
	else
	{
		m_pTexture = g_pTextureManager->GetTexture(key);
		SetPTVertex(vecVertex, vecIndex, vecT);
	}
}

void cCube::SetPCVertex(vector<D3DXVECTOR3>& vecV, vector<int>& vecI)
{
	D3DCOLOR c;

	for (int i = 0; i < vecI.size(); ++i)
	{
		if (i % 6 == 0)
			c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);

		m_vecPCVertex.push_back(ST_PC_VERTEX(vecV[vecI[i]], c));
	}
}

void cCube::SetPTVertex(vector<D3DXVECTOR3>& vecV, vector<int>& vecI,
	vector<D3DXVECTOR2>* vecT)
{
	for (int i = 0; i < vecI.size(); ++i)
	{
		m_vecPTVertex.push_back(ST_PT_VERTEX(vecV[vecI[i]], (*vecT)[i % (*vecT).size()]));
	}
}

void cCube::Update(D3DXMATRIXA16* pParent/*= NULL*/)
{
	//D3DXMatrixIdentity(&m_matWorld);

	// X 축의 로테이션 값 계산
	if (m_isMoving)
	{
		m_fRotY = 0.0f;	// 앞만 봐라!

		m_fRotX += m_fRotXSpeed;

		if (m_fRotX >= D3DX_PI / 4 - D3DX_16F_EPSILON ||
			m_fRotX <= -D3DX_PI / 4 + D3DX_16F_EPSILON)
			m_fRotXSpeed *= -1;
	}
	else
	{
		m_fRotX = 0.0f;	// 차렷

		// Y 축의 로테이션 값 계산
		m_fRotY += m_fRotYSpeed;

		if (m_fRotY >= D3DX_PI / 3 - D3DX_16F_EPSILON ||
			m_fRotY <= -D3DX_PI / 3 + D3DX_16F_EPSILON)
			m_fRotYSpeed *= -1;
	}

	D3DXMATRIXA16 matRX, matRY, matRT, matInvRT, matT;

	D3DXMatrixRotationX(&matRX, m_fRotX);
	D3DXMatrixRotationY(&matRY, m_fRotY);

	D3DXMatrixTranslation(&matRT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);
	D3DXMatrixTranslation(&matInvRT, -m_vLocalPos.x, -m_vLocalPos.y, -m_vLocalPos.z);

	D3DXMatrixTranslation(&matT, m_vCenter.x, m_vCenter.y, m_vCenter.z);

	// 회전축을 이동 시키고 회전을 시킨 뒤 원래 위치로 복구
	m_matWorld = matRT * matRX * matRY * matInvRT * matT;

	if (pParent)
		m_matWorld *= *pParent;

	for (int i = 0; i < m_vecChild.size(); ++i)
		m_vecChild[i]->Update(&m_matWorld);
}

void cCube::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetTexture(0, m_pTexture);

	if (!m_vecPCVertex.empty())
	{
		g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecPCVertex.size() / 3,
			&m_vecPCVertex[0], sizeof(ST_PC_VERTEX));
	}
	else if (!m_vecPTVertex.empty())
	{
		g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecPTVertex.size() / 3,
			&m_vecPTVertex[0], sizeof(ST_PT_VERTEX));
	}

	for (int i = 0; i < m_vecChild.size(); ++i)
		m_vecChild[i]->Render();
}

void cCube::AddChild(cCube* pCube)
{
	m_vecChild.push_back(pCube);
}

void cCube::Release()
{
	for (int i = 0; i < m_vecChild.size(); ++i)
		m_vecChild[i]->Release();

	delete this;
}

void cCube::SetIsMoving(bool move)
{
	m_isMoving = move;

	for (int i = 0; i < m_vecChild.size(); ++i)
		m_vecChild[i]->SetIsMoving(move);
}

void cCube::Collision(D3DXVECTOR3& center, float radius)
{
	D3DXVECTOR3 v = m_vCenter - center;
	float length = D3DXVec3Length(&v);

	if (length < m_fRadius + radius) // 충돌
	{
		D3DXVec3Normalize(&v, &v);
		m_vCenter += v * 1.0f;
	}
}