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
	m_fPosX = ((m_pcPlayer->GetBody().right - m_pcPlayer->GetBody().left) / 2) - m_pcPlayer->GetPosX();
	m_fPosY = ((m_pcPlayer->GetBody().bottom - m_pcPlayer->GetBody().top) / 2) - m_pcPlayer->GetPosY();
	m_nSizeW = 20;
	m_nSizeH = 20;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeedY = 5.0f;
}

void cPbullet::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPbullet::Render()
{
	Rectangle(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}
