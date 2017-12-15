#include "stdafx.h"
#include "cMonster.h"

void cMonster::Setup()
{
	m_fMonsterX = 1000.0f;
	m_isLeft = true;
	m_rtMonster = RectMake(m_fMonsterX, m_fMonsterY, m_nSizeW, m_nSizeH);
	g_pTimerManager->AddSimpleTimer("Monster_Idle_Left");
	g_pTimerManager->AddSimpleTimer("Monster_Move_Left");
	g_pTimerManager->AddSimpleTimer("Monster_Move_Right");	
	g_pTimerManager->AddSimpleTimer("spawn_delay");
}

void cMonster::Update()
{
	m_rtMonster = RectMake(m_fMonsterX, m_fMonsterY, m_nSizeW, m_nSizeH);
	if (m_isLeft)
	{
		m_fMonsterX -= 2;

		if (m_fMonsterX <= 0)
		{
			m_isLeft = false;
		}
	}
	else if (!m_isLeft)
	{
		m_fMonsterX += 2;

		if (m_fMonsterX + m_imgbody->GetFrameWidth() >= 2000)
		{
			m_isLeft = true;
		}
	}
}

void cMonster::Render(HDC hdc)
{
	RectangleMake(hdc, m_rtMonster);
	if (m_isLeft)
	{
		m_imgbody->FrameRendersize(hdc, m_fMonsterX, m_fMonsterY, m_nSizeW, m_nSizeH, m_nLeftMoveFrameXmin, m_nLeftMoveFrameY, m_nLeftMoveFrameXmax, m_nLeftMoveFrameY, 7 * (*m_nTest));
		cout << "테스트 사이즈 : " << m_nTest << endl;
	}
	//char str[128];
	//sprintf(str, "카운트 : %d", count);
	//TextOut(hdc, 10, 1100, str, strlen(str));
}

//void cMonster::TimterLeftFrame(int size)
//{
//	m_fMonsterX -= 2;
//	m_imgbody->SetFrameY(m_nLeftMoveFrameY);
//	if (g_pTimerManager->TickSimpleTimer("Monster_Move_Left") > 7 * size)
//	{
//		g_pTimerManager->ResetSimpleTimer("Monster_Move_Left");
//		m_imgbody->SetFrameX(m_nLeftMoveFrameXmin++);
//	}
//	if (m_imgbody->GetFrameX() > m_nLeftMoveFrameXmax)
//	{
//
//		m_nLeftMoveFrameXmin = 0;
//		m_imgbody->SetFrameX(0);
//	}
//	if (m_fMonsterX <= 0)
//	{
//		m_isLeft = false;
//	}
//}
//
//void cMonster::TimerRightFrame(int size)
//{
//	m_fMonsterX += 2;
//	m_imgbody->SetFrameY(m_nRightMoveFrameY);
//	if (g_pTimerManager->TickSimpleTimer("Monster_Move_Right") > 7 * size)
//	{
//		g_pTimerManager->ResetSimpleTimer("Monster_Move_Right");
//		m_imgbody->SetFrameX(m_nRightMoveFrameXmin++);
//	}
//	if (m_imgbody->GetFrameX() > m_nRIghtMoveFrameXmax)
//	{
//		m_nRightMoveFrameXmin = 0;
//		m_imgbody->SetFrameX(0);
//	}
//	if (m_fMonsterX + m_imgbody->GetFrameWidth() >= 2000)
//	{
//		m_isLeft = true;
//	}
//}
