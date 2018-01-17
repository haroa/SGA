#include "stdafx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cCube.h"
#include "cCharacterController.h"
#include "cCubeMan.h"


cMainGame::cMainGame()
	: m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pController(NULL)
	, m_pCubeMan(NULL)
	, m_pTexture(NULL)
	, m_pCube(NULL)
{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pController);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCubeMan);
	
	SAFE_RELEASE(m_pCube);
	SAFE_RELEASE(m_pTexture);

	g_pTextureManager->Destroy();
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	srand(time(NULL));
	rand();

	m_pCamera = new cCamera;
	m_pCamera->Setup();

	m_pController = new cCharacterController;

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();
	m_pCubeMan->SetController(m_pController);

	m_pCube = new cCube;
	m_pCube->Setup(NULL, "null");

	m_pController->SetHexa(m_pGrid->GetHexaPoint());
}

void cMainGame::Update()
{
	if (m_pController)
		m_pController->Update();

	if (m_pCamera)
		m_pCamera->Update(m_pController->GetPosition());

	if (m_pCubeMan)
		m_pCubeMan->Update();

	if (m_pCube)
	{
		m_pCube->Collision(*m_pController->GetPosition(), 2.0f);
		m_pCube->Update();
	}
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	g_pD3DDevice->BeginScene();

	if (m_pGrid)
		m_pGrid->Render();

	if (m_pCubeMan)
		m_pCubeMan->Render();

	if (m_pCube)
		m_pCube->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(0, 0, 0, 0);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}