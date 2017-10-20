#include "stdafx.h"
#include "cBoss.h"


cBoss::cBoss()
{
	m_pImage = NULL;
}


cBoss::~cBoss()
{

}

void cBoss::Setup()
{
	m_pImage = g_pImageManager->FindImage("Boss");
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = 250.0f;
	m_nSizeW = 464;
	m_nSizeH = 356;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);	
	//=================================================================
	m_fHitPointX = m_fPosX;
	m_fHitPointY = m_fPosY;
	m_rtHitPoint = RectMakeCenter(m_fHitPointX, m_fHitPointY, 60,60);
	m_fHitPointHp = 500.0f;
	m_fAllBossHp = 2500.0f;
	m_fNowBossHp = 0.0f;
	m_cProgressBar.SetBossMaxHp(m_fAllBossHp);
	m_cProgressBar.Setup();
	m_cTurret.SetBossPosX(m_fPosX);
	m_cTurret.SetBossPosY(m_fPosY);
	m_cTurret.SetBossWidth(m_nSizeW);
	m_cTurret.SetBossHeight(m_nSizeH);
	m_cTurret.Setup();
	m_pHitPoint = g_pImageManager->FindImage("Boom5");
	m_fHitPointDelay = 5.0f;
}

void cBoss::Update()
{
	m_cProgressBar.Update();	
	m_fNowBossHp = m_fHitPointHp + m_cTurret.GetHpLeft1() + m_cTurret.GetHpLeft2() + m_cTurret.GetHpRight1() + m_cTurret.GetHpRight2();
	m_cProgressBar.SetBossNowHp(m_fNowBossHp);

	if (m_fHitPointHp <= 0.0f)
	{
		m_fHitPointDelay--;
		m_rtHitPoint = RectMakeCenter(0, 0, 0, 0);
		if (m_fHitPointDelay < 0)
		{
			m_fHitPointDelay = 5.0f;
			m_pHitPoint->SetFrameY(m_pHitPoint->GetFrameY() + 1);
		}
		if (m_pHitPoint->GetFrameY() > 7)
		{
			m_pHitPoint->SetFrameY(0);
		}
	}
	m_cTurret.Update();
}

void cBoss::Render()
{
#ifdef _DEBUG
	//Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
#endif // _DEBUG

	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
	if (m_pHitPoint != NULL)
	{
		if (m_fHitPointHp <= 0.0f)
		{
			m_pHitPoint->FrameRender(g_hDC, m_fHitPointX, m_fHitPointY, m_pHitPoint->GetFrameX(), m_pHitPoint->GetFrameY());
		}
	}
#ifdef _DEBUG
	//Rectangle(g_hDC, m_rtHitPoint.left, m_rtHitPoint.top, m_rtHitPoint.right, m_rtHitPoint.bottom);
#endif // _DEBUG
	m_cProgressBar.Render();
	m_cTurret.Render();
}
