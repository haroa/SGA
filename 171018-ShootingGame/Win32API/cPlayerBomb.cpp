#include "stdafx.h"
#include "cPlayerBomb.h"


cPlayerBomb::cPlayerBomb()
{

}


cPlayerBomb::~cPlayerBomb()
{

}

void cPlayerBomb::Setup()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY - 120.0f;
	m_nSizeW = 500;
	m_nSizeH = 500;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPlayerBomb::Update()
{

}

void cPlayerBomb::Render()
{
	Rectangle(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}
