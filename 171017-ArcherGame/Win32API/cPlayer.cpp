#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayerImage = NULL;
}


cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_pPlayerImage = g_pImageManager->FindImage("Player");
	m_nSizeW = 40;
	m_nSizeH = 40;
	m_fPosX = 200.0f;
	m_fPosY = WINSIZEY * 0.5f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPlayer::Update()
{

}

void cPlayer::Render()
{
#ifdef _DEBUG
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
#endif

	if (m_pPlayerImage != NULL)
	{
		m_pPlayerImage->Render(g_hDC,m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}

}
