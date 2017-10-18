#include "stdafx.h"
#include "cBoss.h"


cBoss::cBoss()
{

}


cBoss::~cBoss()
{

}

void cBoss::Setup()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = 200.0f;
	m_nSizeW = 464;
	m_nSizeH = 356;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cBoss::Update()
{

}

void cBoss::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}
