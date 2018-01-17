#include "stdafx.h"
#include "cCubeMan.h"
#include "cCube.h"
#include "cCharacterController.h"


cCubeMan::cCubeMan()
	: m_pRootCube(NULL)
	, m_pController(NULL)
{
}


cCubeMan::~cCubeMan()
{
	SAFE_RELEASE(m_pRootCube);
}

void cCubeMan::Setup()
{
	g_pTextureManager->AddTexture("batman", "images/batman.png");

	D3DXMATRIXA16 matS, matT, matSRT;

	// 텍스쳐 셋팅 벡터
	vector<D3DXVECTOR2> vecT;
	vector<tagXY> vecXY;

	// 아래 위 왼쪽 앞쪽 오른쪽 뒷쪽
	SetTextureVertex(vecT, tagXY(7, 5), tagXY(2, 1));
	SetTextureVertex(vecT, tagXY(5, 5), tagXY(2, 1));
	SetTextureVertex(vecT, tagXY(7, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(5, 8), tagXY(2, 3));
	SetTextureVertex(vecT, tagXY(4, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(8, 8), tagXY(2, 3));

	// 큐브맨 몸통 (루트)
	D3DXMatrixScaling(&matS, 1.0f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, 0.0f, 3.0f, 0.0f);
	matSRT = matS * matT;
	m_pRootCube = new cCube;
	m_pRootCube->Setup(&vecT, "batman", &matSRT);
	vecT.clear();

	cCube* pCube;

	// 아래 위 왼쪽 앞쪽 오른쪽 뒷쪽
	SetTextureVertex(vecT, tagXY(4, 2), tagXY(2, 2));
	SetTextureVertex(vecT, tagXY(2, 2), tagXY(2, 2));
	SetTextureVertex(vecT, tagXY(4, 4), tagXY(2, 2));
	SetTextureVertex(vecT, tagXY(2, 4), tagXY(2, 2));
	SetTextureVertex(vecT, tagXY(0, 4), tagXY(2, 2));
	SetTextureVertex(vecT, tagXY(6, 4), tagXY(2, 2));

	// 큐브맨 머리
	D3DXMatrixScaling(&matS, 0.8f, 0.8f, 0.8f);
	D3DXMatrixTranslation(&matT, 0.0f, 4.8f, 0.0f);
	matSRT = matS * matT;
	pCube = new cCube;
	pCube->Setup(&vecT, "batman", &matSRT);
	vecT.clear();
	pCube->SetRotSpeedY(0.05f);
	m_pRootCube->AddChild(pCube);

	// 아래 위 왼쪽 앞쪽 오른쪽 뒷쪽
	SetTextureVertex(vecT, tagXY(12, 5), tagXY(1, 1));
	SetTextureVertex(vecT, tagXY(11, 5), tagXY(1, 1));
	SetTextureVertex(vecT, tagXY(12, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(11, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(10, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(13, 8), tagXY(1, 3));

	// 큐브맨 왼팔
	D3DXMATRIXA16 matR;
	D3DXMatrixRotationY(&matR, D3DX_PI);
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, -1.5f, 3.0f, 0.0f);
	matSRT = matS * matR * matT;
	pCube = new cCube;
	pCube->Setup(&vecT, "batman", &matSRT);
	pCube->SetRotSpeedX(0.05f);
	pCube->SetLocalPos(D3DXVECTOR3(0.0f, -4.0f, 0.0f));
	m_pRootCube->AddChild(pCube);

	// 큐브맨 오른팔
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, 1.5f, 3.0f, 0.0f);
	matSRT = matS * matT;
	pCube = new cCube;
	pCube->Setup(&vecT, "batman", &matSRT);
	vecT.clear();
	pCube->SetRotSpeedX(-0.05f);
	pCube->SetLocalPos(D3DXVECTOR3(0.0f, -4.0f, 0.0f));
	m_pRootCube->AddChild(pCube);

	// 무기
	D3DXMatrixScaling(&matS, 0.1f, 0.1f, 2.0f);
	D3DXMatrixTranslation(&matT, 1.5f, 2.0f, 1.0f);
	matSRT = matS * matT;
	cCube* pWeapon = new cCube;
	pWeapon->Setup(NULL, "null", &matSRT);
	pCube->AddChild(pWeapon);

	// 아래 위 왼쪽 앞쪽 오른쪽 뒷쪽
	SetTextureVertex(vecT, tagXY(2, 5), tagXY(1, 1));
	SetTextureVertex(vecT, tagXY(1, 5), tagXY(1, 1));
	SetTextureVertex(vecT, tagXY(2, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(1, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(0, 8), tagXY(1, 3));
	SetTextureVertex(vecT, tagXY(3, 8), tagXY(1, 3));

	// 큐브맨 왼쪽 다리
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, -0.5f, 1.0f, 0.0f);
	matSRT = matS * matT;
	pCube = new cCube;
	pCube->Setup(&vecT, "batman", &matSRT);
	pCube->SetRotSpeedX(-0.05f);
	pCube->SetLocalPos(D3DXVECTOR3(0.0f, -2.0f, 0.0f));
	m_pRootCube->AddChild(pCube);

	// 큐브맨 오른쪽 다리
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, 0.5f, 1.0f, 0.0f);
	matSRT = matS * matT;
	pCube = new cCube;
	pCube->Setup(&vecT, "batman", &matSRT);
	vecT.clear();
	pCube->SetRotSpeedX(0.05f);
	pCube->SetLocalPos(D3DXVECTOR3(0.0f, -2.0f, 0.0f));
	m_pRootCube->AddChild(pCube);
}

void cCubeMan::SetTextureVertex(vector<D3DXVECTOR2>& vecT, tagXY vXY, tagXY sXY)
{
	// 0 1 2     0 2 3
	vecT.push_back(D3DXVECTOR2(vXY.x / 16.0f, vXY.y / 8.0f));
	vecT.push_back(D3DXVECTOR2(vXY.x / 16.0f, (vXY.y - sXY.y) / 8.0f));
	vecT.push_back(D3DXVECTOR2((vXY.x + sXY.x) / 16.0f, (vXY.y - sXY.y) / 8.0f));

	vecT.push_back(D3DXVECTOR2(vXY.x / 16.0f, vXY.y / 8.0f));
	vecT.push_back(D3DXVECTOR2((vXY.x + sXY.x) / 16.0f, (vXY.y - sXY.y) / 8.0f));
	vecT.push_back(D3DXVECTOR2((vXY.x + sXY.x) / 16.0f, vXY.y / 8.0f));
}

void cCubeMan::Update()
{
	if (m_pRootCube)
	{
		m_pRootCube->SetIsMoving(m_pController->GetIsMoving());
		m_pRootCube->Update(m_pController->GetWorldTM());
	}
}

void cCubeMan::Render()
{
	if (m_pRootCube)
	{
		m_pRootCube->Render();
	}
}
