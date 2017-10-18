#include "stdafx.h"
#include "cBbullet.h"
#include "cBoss.h"
#include "cPlayer.h"


cBbullet::cBbullet()
{

}


cBbullet::~cBbullet()
{

}

void cBbullet::Setup()
{
	m_fPosX = m_pcBoss->GetPosX();
	m_fPosY = m_pcBoss->GetPosY();
	m_nSizeW = 10;
	m_nSizeH = 10;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeed = 5.0f;
	m_fradius = 5;
	m_fangle = GetAngle(m_pcPlayer->GetPosX(), m_pcPlayer->GetPosY(), m_fPosX, m_fPosY);
	//cosf(iter->angle / 180 * PI) * iter->speed;
	//-sinf(iter->angle / 180 * PI) * iter->speed;
	m_fSpeedX = -cosf(m_fangle / 180 * PI) * m_fSpeed;
	m_fSpeedY = -sinf(m_fangle / 180 * PI) * m_fSpeed;
	m_isActive = true;
}

void cBbullet::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cBbullet::Render()
{
	if (m_isActive)
	{
		Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	}
	else
	{

	}
}
