#include "stdafx.h"
#include "cMainGame.h"
#include "cCube.h"
#include "cGrid.h"
#include "cCamera.h"


cMainGame::cMainGame()
	: m_pCube(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
{
}


cMainGame::~cMainGame()
{
	if (m_pCube)
		delete m_pCube;
	if (m_pGrid)
		delete m_pGrid;
	if (m_pCamera)
		delete m_pCamera;
}

void cMainGame::Setup()
{
	HDC hdc = GetDC(g_hWnd);

	m_hMemDC = CreateCompatibleDC(hdc);

	RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	m_hBitmap = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
	m_hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);

	ReleaseDC(g_hWnd, hdc);

	m_pCube = new cCube;
	m_pCube->Setup();
	
	m_pGrid = new cGrid;
	m_pCamera = new cCamera;
	m_pCamera->Setup();
}

void cMainGame::Update()
{
	if (m_pCube)
		m_pCube->Update();
	if (m_pCamera)
		m_pCamera->Update(&m_pCube->GetPosition());

}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(m_hMemDC, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);


	//cVector3 vEye(0, 0, -5);
	//cMatrix matRotX = cMatrix::RotateX(0.0f);
	//vEye.TransformCoord(&matRotX);
	//
	//
	//cMatrix matView = cMatrix::View(&vEye, new cVector3(0, 0, 0),
	//	new cVector3(0, 1, 0));
	//cMatrix matProj = cMatrix::Projection(PI / 4.0f, rc.right / (float)rc.bottom, 1, 1000);
	//cMatrix matViewProj = matView * matProj;

	cMatrix matViewPort = cMatrix::Viewport(0, 0, rc.right, rc.bottom, 0, 1);
	if (m_pGrid)
		m_pGrid->Render(m_hMemDC, m_pCamera->GetViewProjMatrix()*matViewPort);

	if (m_pCube)
		m_pCube->Render(m_hMemDC, m_pCamera->GetViewProjMatrix(), matViewPort);

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, m_hMemDC, 0, 0, SRCCOPY);
}