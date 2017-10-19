#include "stdafx.h"
#include "cProgressBar.h"


cProgressBar::cProgressBar()
{
	m_pHpBar = NULL;
	m_pFrameBar = NULL;
}


cProgressBar::~cProgressBar()
{
	
}

void cProgressBar::Setup()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY * 0.5f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 1000, 30);
}

void cProgressBar::Update()
{

}

void cProgressBar::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}
