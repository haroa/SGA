#include "stdafx.h"
#include "cMainGame.h"
#include "cCube.h"


cMainGame::cMainGame()
	: m_pCube(NULL)
{
}


cMainGame::~cMainGame()
{
	if (m_pCube)
		delete m_pCube;
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
}

void cMainGame::Update()
{
	if (m_pCube)
		m_pCube->Update();
}

void cMainGame::Render(HDC hdc)
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	PatBlt(m_hMemDC, rc.left, rc.top, rc.right, rc.bottom, WHITENESS);

	cVector3 vEye(0, 0, -5);
	cMatrix matRotX = cMatrix::RotateX(PI / 4);
	vEye.TransformCoord(&matRotX);

	cMatrix matView = cMatrix::View(&vEye, new cVector3(0, 0, 0),
		new cVector3(0, 1, 0));
	cMatrix matProj = cMatrix::Projection(PI / 4.0f, rc.right / (float)rc.bottom, 1, 1000);
	cMatrix matViewProj = matView * matProj;

	cMatrix matViewPort = cMatrix::Viewport(0, 0, rc.right, rc.bottom, 0, 1);

	if (m_pCube)
		m_pCube->Render(m_hMemDC, matViewProj, matViewPort);

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, m_hMemDC, 0, 0, SRCCOPY);
}