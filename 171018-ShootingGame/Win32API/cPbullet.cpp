#include "stdafx.h"
#include "cPbullet.h"
#include "cPlayer.h"


cPbullet::cPbullet()
{

}


cPbullet::~cPbullet()
{

}

void cPbullet::Setup()
{
	m_fPosX = m_pcPlayer->GetPosX();
	m_fPosY = m_pcPlayer->GetPosY();
	m_nSizeW = 10;
	m_nSizeH = 10;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeedY = 5.0f;
}

void cPbullet::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPbullet::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}
