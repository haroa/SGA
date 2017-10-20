#include "stdafx.h"
#include "cTbulletLeft2.h"


cTbulletLeft2::cTbulletLeft2()
{

}


cTbulletLeft2::~cTbulletLeft2()
{

}

void cTbulletLeft2::Setup()
{
	m_fStartX = m_fPosX;
	m_fStartY = m_fPosY;
	m_fViaX = WINSIZEX * 0.5f;
	m_fViaY = WINSIZEY * 0.5f;
	m_fDestX = m_fPosX;
	m_fDestY = WINSIZEY;
	m_ft = 0.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 32, 32);
	m_isActive = true;
}

void cTbulletLeft2::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 32, 32);
}

void cTbulletLeft2::Render()
{
	if (m_isActive)
	{
		Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	}
	else
	{

	}
}
