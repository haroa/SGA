#include "stdafx.h"
#include "cTbulletRight2.h"


cTbulletRight2::cTbulletRight2()
{
}


cTbulletRight2::~cTbulletRight2()
{
}

void cTbulletRight2::Setup()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 32, 32);
	m_ft = 0.0f;
	m_isActive = true;
}

void cTbulletRight2::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 32, 32);
}

void cTbulletRight2::Render()
{
	if (m_isActive)
	{
		Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	}
	else
	{

	}
}
