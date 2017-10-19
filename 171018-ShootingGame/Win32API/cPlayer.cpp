#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pImage = NULL;
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
	m_pImage = g_pImageManager->FindImage("Player");
	
	//===============================================================
	//히트판정렉트
	m_nHitSizeH = 5;
	m_nHitSizeW = 5;
	m_rtHitPoint = RectMakeCenter(m_fPosX, m_fPosY, m_nHitSizeH, m_nHitSizeW);
	//================================================================
}

void cPlayer::Update()
{
	m_pImage->SetFrameY(0);

	if (g_pKeyManager->isStayKeyDown('A') && (int)(m_fPosX - (m_nSizeW / 2)) >= 0)
	{
		m_fPosX -= 5;
		m_pImage->SetFrameY(2);
	}
	else if (g_pKeyManager->isStayKeyDown('D') && (int)(m_fPosX + (m_nSizeW / 2)) <= WINSIZEX)
	{
		m_fPosX += 5;
		m_pImage->SetFrameY(1);
	}
	if (g_pKeyManager->isStayKeyDown('W') && (int)(m_fPosY - (m_nSizeH / 2)) >= 0)
	{
		m_fPosY -= 5;
	}
	else if (g_pKeyManager->isStayKeyDown('S') && (int)(m_fPosY + (m_nSizeH / 2)) <= WINSIZEY)
	{
		m_fPosY += 5;
	}
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_rtHitPoint = RectMakeCenter(m_fPosX, m_fPosY, m_nHitSizeH, m_nHitSizeW);
}

void cPlayer::Render()
{
#ifdef _DEBUG
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	Rectangle(g_hDC, m_rtHitPoint.left, m_rtHitPoint.top, m_rtHitPoint.right, m_rtHitPoint.bottom);
#endif // _DEBUG

	if (m_pImage != NULL)
	{
		m_pImage->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	}
}
