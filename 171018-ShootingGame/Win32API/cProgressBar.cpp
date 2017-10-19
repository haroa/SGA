#include "stdafx.h"
#include "cProgressBar.h"


cProgressBar::cProgressBar()
{
	m_pHpBar = NULL;
	m_pFrameBar = NULL;
}


cProgressBar::~cProgressBar()
{
	
}

void cProgressBar::Setup()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = 20.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 500, 30);
	m_pFrameBar = g_pImageManager->FindImage("Gaugebg");
	m_pHpBar = g_pImageManager->FindImage("Gaugebar");
	m_nDelay = 5;
}

void cProgressBar::Update()
{
	m_nDelay--;
	if (m_nDelay < 0)
	{
		m_nDelay = 5;
		m_pHpBar->SetFrameY(m_pHpBar->GetFrameY() + 1);
	}
	if (m_pHpBar->GetFrameY() > 7)
	{
		m_pHpBar->SetFrameY(0);
	}
}

void cProgressBar::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	if(m_pFrameBar != NULL)
	{ 
		m_pFrameBar->SetFrameY(1);
		m_pFrameBar->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pFrameBar->GetFrameX(), m_pFrameBar->GetFrameY());
		
		//m_fNowBossHp / m_fAllBossHp * m_cProgressBar.GetHpBar()->GetWidth();
		//m_cBoss.GetNowBossHp() / m_cBoss.GetAllBossHp() * m_pHpBar->GetFrameWidth()
		m_pHpBar->FrameRender(g_hDC, m_fPosX, m_fPosY, m_cBoss.GetNowBossHp() / m_cBoss.GetAllBossHp() * m_pHpBar->GetFrameWidth(), m_pHpBar->GetFrameY());


		m_pFrameBar->SetFrameY(0);
		m_pFrameBar->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pFrameBar->GetFrameX(), m_pFrameBar->GetFrameY());
	}
}
