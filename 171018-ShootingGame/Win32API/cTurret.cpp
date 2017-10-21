#include "stdafx.h"
#include "cTurret.h"
#include "cBoss.h"


cTurret::cTurret()
{
	m_pLeft1 = NULL;
	m_pLeft2 = NULL;
	m_pRight1 = NULL;
	m_pRight2 = NULL;
}


cTurret::~cTurret()
{
}

void cTurret::Setup()
{
#pragma region Left1
	m_pLeft1 = g_pImageManager->FindImage("Boom");
	m_fPosXLeft1 = m_BossPosX - ((m_BossWidth * 0.5f) - 54.0f);
	m_fPosYLeft1 = m_BossPosY - ((m_BossHeight * 0.5f) - 95.0f);
	m_rtLeft1 = RectMakeCenter(m_fPosXLeft1, m_fPosYLeft1, 30, 70);
	m_fHpLeft1 = 500.0f;	
#pragma endregion

#pragma region Left2
	m_pLeft2 = g_pImageManager->FindImage("Boom2");
	m_fPosXLeft2 = m_BossPosX - ((m_BossWidth * 0.5f) - 160.0f);
	m_fPosYLeft2 = m_BossPosY - ((m_BossHeight * 0.5f) - 110.0f);
	m_rtLeft2 = RectMakeCenter(m_fPosXLeft2, m_fPosYLeft2, 30, 70);
	m_fHpLeft2 = 500.0f;
#pragma endregion

#pragma region Right1
	m_pRight1 = g_pImageManager->FindImage("Boom3");
	m_fPosXRight1 = m_BossPosX - ((m_BossWidth * 0.5f) - 410.0f);
	m_fPosYRight1 = m_BossPosY - ((m_BossHeight * 0.5f) - 110.0f);
	m_rtRight1 = RectMakeCenter(m_fPosXRight1, m_fPosYRight1, 30, 70);
	m_fHpRight1 = 500.0f;
#pragma endregion

#pragma region Right2
	m_pRight2 = g_pImageManager->FindImage("Boom4");
	m_fPosXRight2 = m_BossPosX - ((m_BossWidth * 0.5f) - 305.0f);
	m_fPosYRight2 = m_BossPosY - ((m_BossHeight * 0.5f) - 120.0f);
	m_rtRight2 = RectMakeCenter(m_fPosXRight2, m_fPosYRight2, 30, 70);
	m_fHpRight2 = 500.0f;
	g_pTimerManager->AddSimpleTimer("Left1");
	g_pTimerManager->AddSimpleTimer("Left2");
	g_pTimerManager->AddSimpleTimer("Right1");
	g_pTimerManager->AddSimpleTimer("Right2");
#pragma endregion


}

void cTurret::Update()
{
#pragma region FrameRender
	if (m_fHpLeft1 <= 0.0f)
	{
		m_rtLeft1 = RectMakeCenter(0, 0, 0, 0);
		if (g_pTimerManager->TickSimpleTimer("Left1") > 5)
		{
			g_pTimerManager->ResetSimpleTimer("Left1");
			m_pLeft1->SetFrameY(m_pLeft1->GetFrameY() + 1);
		}
		if (m_pLeft1->GetFrameY() > 7)
		{
			m_pLeft1->SetFrameY(0);
		}
	}
	if (m_fHpLeft2 <= 0.0f)
	{
		m_rtLeft2 = RectMakeCenter(0, 0, 0, 0);
		if (g_pTimerManager->TickSimpleTimer("Left2") > 5)
		{
			g_pTimerManager->ResetSimpleTimer("Left2");
			m_pLeft2->SetFrameY(m_pLeft2->GetFrameY() + 1);
		}
		if (m_pLeft2->GetFrameY() > 7)
		{
			m_pLeft2->SetFrameY(0);
		}
	}
	if (m_fHpRight1 <= 0.0f)
	{
		m_rtRight1 = RectMakeCenter(0, 0, 0, 0);

		if (g_pTimerManager->TickSimpleTimer("Right1") > 5)
		{
			g_pTimerManager->ResetSimpleTimer("Right1");
			m_pRight1->SetFrameY(m_pRight1->GetFrameY() + 1);
		}
		if (m_pRight1->GetFrameY() > 7)
		{
			m_pRight1->SetFrameY(0);
		}
	}
	if (m_fHpRight2 <= 0.0f)
	{
		m_rtRight2 = RectMakeCenter(0, 0, 0, 0);

		if (g_pTimerManager->TickSimpleTimer("Right2") > 5)
		{
			g_pTimerManager->ResetSimpleTimer("Right2");
			m_pRight2->SetFrameY(m_pRight2->GetFrameY() + 1);
		}
		if (m_pRight2->GetFrameY() > 7)
		{
			m_pRight2->SetFrameY(0);
		}
	}
#pragma endregion

}

void cTurret::Render()
{
#pragma region Rectangle
#ifdef _DEBUG
	//Rectangle(g_hDC, m_rtLeft1.left, m_rtLeft1.top, m_rtLeft1.right, m_rtLeft1.bottom);
	//Rectangle(g_hDC, m_rtLeft2.left, m_rtLeft2.top, m_rtLeft2.right, m_rtLeft2.bottom);
	//Rectangle(g_hDC, m_rtRight1.left, m_rtRight1.top, m_rtRight1.right, m_rtRight1.bottom);
	//Rectangle(g_hDC, m_rtRight2.left, m_rtRight2.top, m_rtRight2.right, m_rtRight2.bottom);
#endif // _DEBUG

#pragma endregion
	if (m_pLeft1 != NULL)
	{
		if (m_fHpLeft1 <= 0.0f)
		{
			m_pLeft1->FrameRender(g_hDC, m_fPosXLeft1, m_fPosYLeft1, m_pLeft1->GetFrameX(), m_pLeft1->GetFrameY());
		}
	}
	if (m_pLeft2 != NULL)
	{
		if (m_fHpLeft2 <= 0.0f)
		{
			m_pLeft2->FrameRender(g_hDC, m_fPosXLeft2, m_fPosYLeft2, m_pLeft2->GetFrameX(), m_pLeft2->GetFrameY());
		}
	}
	if (m_pRight1 != NULL)
	{
		if (m_fHpRight1 <= 0.0f)
		{
			m_pRight1->FrameRender(g_hDC, m_fPosXRight1, m_fPosYRight1, m_pRight1->GetFrameX(), m_pRight1->GetFrameY());
		}
	}
	if (m_pRight2 != NULL)
	{
		if (m_fHpRight2 <= 0.0f)
		{
			m_pRight2->FrameRender(g_hDC, m_fPosXRight2, m_fPosYRight2, m_pRight2->GetFrameX(), m_pRight2->GetFrameY());
		}
	}
}
