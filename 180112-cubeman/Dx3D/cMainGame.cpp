#include "stdafx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cCube.h"


cMainGame::cMainGame()
	: m_pD3D(NULL)
	, m_pD3DDevice(NULL)
	, m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pCube(NULL)
{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCube);

	SAFE_RELEASE(m_pD3DDevice);
	SAFE_RELEASE(m_pD3D);
}

void cMainGame::Setup()
{
	srand(time(NULL));
	rand();

	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9 stCaps;		// 장치에 대한 정보를 얻어옴
	int nVertexProcessing;	// 버텍스를 처리 하는 방식

	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);

	if (stCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	D3DPRESENT_PARAMETERS stD3DPP;
	ZeroMemory(&stD3DPP, sizeof(D3DPRESENT_PARAMETERS));
	stD3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3DPP.Windowed = true;
	stD3DPP.BackBufferFormat = D3DFMT_UNKNOWN;		// 픽셀 포맷 p79
	stD3DPP.EnableAutoDepthStencil = true;			// 깊이 버퍼 자동 관리
	stD3DPP.AutoDepthStencilFormat = D3DFMT_D16;	// 깊이 버퍼 p82

	HRESULT hr = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&stD3DPP,
		&m_pD3DDevice);

	/* DX에서는 조명이 기본적으로 켜져 있는 상태이다. */
	/* 기본 칼라 값을 사용 할 때는 조명을 꺼야 색상이 표현 된다. */
	m_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	m_pCamera = new cCamera;
	m_pCamera->Setup(m_pD3DDevice);

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pCube = new cCube(D3DXVECTOR3(2, 2.5, 1.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 8.75, 0), BODY, true);
	m_pCube->Setup();

	cCube* head = new cCube(D3DXVECTOR3(0.5,0.5,0.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1.5, 0), HEAD, false);
	head->Setup();
	m_pCube->Addchild(head);

	cCube* Larm = new cCube(D3DXVECTOR3(0.25, 1.25, 0.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(-1.25, -0.25, 0), LARM, false);
	Larm->Setup();
	m_pCube->Addchild(Larm);
	
	cCube* Rarm = new cCube(D3DXVECTOR3(0.25, 1.25, 0.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1.25, -0.25, 0), RARM, false);
	Rarm->Setup();
	m_pCube->Addchild(Rarm);
	
	cCube* Lleg = new cCube(D3DXVECTOR3(0.25, 1.25, 0.25), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(-0.5, -2.25, 0), LLEG, false);
	Lleg->Setup();
	m_pCube->Addchild(Lleg);
	
	cCube* Rleg = new cCube(D3DXVECTOR3(0.25, 1.25, 0.25), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5, -2.25, 0), RLEG, false);
	Rleg->Setup();
	m_pCube->Addchild(Rleg);
}

void cMainGame::Update()
{
	if (m_pCube)
		m_pCube->Update(m_pCube);

	if (m_pCamera)
		m_pCamera->Update(m_pD3DDevice, m_pCube->GetPosition());
}

void cMainGame::Render()
{
	m_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	m_pD3DDevice->BeginScene();

	if (m_pGrid)
		m_pGrid->Render(m_pD3DDevice);

	if (m_pCube)
		m_pCube->Render(m_pD3DDevice);

	m_pD3DDevice->EndScene();

	m_pD3DDevice->Present(0, 0, 0, 0);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}