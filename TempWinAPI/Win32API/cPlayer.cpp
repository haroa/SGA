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
	m_pBuffer = g_pImageManager->FindImage("MiniMap");
	m_pImage = g_pImageManager->FindImage("Player");
	m_pMap = g_pImageManager->FindImage("Map");
	m_fPosX = 70.0f;
	m_fPosY = 0.0f;
	m_nSizeW = 50.0f;
	m_nSizeH = 60.0f;
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPlayer::Update()
{
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cPlayer::Render()
{
	//Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	if (m_pImage != NULL)
	{
		m_pImage->FrameRender(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	}
}
