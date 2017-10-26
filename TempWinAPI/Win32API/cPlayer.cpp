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
	m_pImage = g_pImageManager->FindImage("Player");
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

void cPlayer::MiniRender()
{
	HPEN hPen = (HPEN)CreatePen(0, 3, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	EllipseMakeCenter(g_hDC,m_rtBody.left,m_rtBody.top, 10, 10);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}
