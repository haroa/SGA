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
	m_fMoveX = 0.0f;
	m_fMoveY = 0.0f;
	m_nSizeW = 15;
	m_nSizeH = 31;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeedY = 15.0f;
	m_isActive = true;
	m_pImage = g_pImageManager->FindImage("PlayerBullet");
#ifdef _DEBUG
	m_fBulletDmg = 100.0f;
#else
	m_fBulletDmg = 0.5f;
#endif // _DEBUG

}

void cPbullet::Update()
{
	m_fPosX += m_fMoveX;
	m_fPosY += m_fMoveY;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPbullet::Render()
{
#ifdef _DEBUG

	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
#endif // _DEBUG

	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
}
