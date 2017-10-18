#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{

}


cPlayer::~cPlayer()
{

}

void cPlayer::Setup()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY - 100.0f;
	m_nSizeW = 57;
	m_nSizeH = 67;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	
	//===============================================================
	//히트판정렉트
	m_nHitSizeH = 5;
	m_nHitSizeW = 5;
	m_rtHitPoint = RectMakeCenter(m_fPosX, m_fPosY, m_nHitSizeH, m_nHitSizeW);
	//================================================================
}

void cPlayer::Update()
{
	if (g_pKeyManager->isStayKeyDown(VK_LEFT) && (int)(m_fPosX - (m_nSizeW / 2)) >= 0)
	{
		m_fPosX -= 5;
	}
	if (g_pKeyManager->isStayKeyDown(VK_UP) && (int)(m_fPosY - (m_nSizeH / 2)) >= 0)
	{
		m_fPosY -= 5;
	}
	if (g_pKeyManager->isStayKeyDown(VK_RIGHT) && (int)(m_fPosX + (m_nSizeW / 2)) <= WINSIZEX)
	{
		m_fPosX += 5;
	}
	if (g_pKeyManager->isStayKeyDown(VK_DOWN) && (int)(m_fPosY + (m_nSizeH / 2)) <= WINSIZEY)
	{
		m_fPosY += 5;
	}
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_rtHitPoint = RectMakeCenter(m_fPosX, m_fPosY, m_nHitSizeH, m_nHitSizeW);
}

void cPlayer::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	Rectangle(g_hDC, m_rtHitPoint.left, m_rtHitPoint.top, m_rtHitPoint.right, m_rtHitPoint.bottom);
}
