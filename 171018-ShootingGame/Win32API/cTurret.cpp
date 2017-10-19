#include "stdafx.h"
#include "cTurret.h"
#include "cBoss.h"


cTurret::cTurret()
{
}


cTurret::~cTurret()
{
	m_BossWidth;
	m_BossHeight;
}

void cTurret::Setup()
{
	m_fPosXLeft1 = m_BossPosX - ((m_BossWidth * 0.5f) - 54.0f);
	m_fPosYLeft1 = m_BossPosY - ((m_BossHeight * 0.5f) - 95.0f);
	m_rtLeft1 = RectMakeCenter(m_fPosXLeft1, m_fPosYLeft1, 30, 70);
	m_fHpLeft1 = 500.0f;

	m_fPosXLeft2 = m_BossPosX - ((m_BossWidth * 0.5f) - 160.0f);
	m_fPosYLeft2 = m_BossPosY - ((m_BossHeight * 0.5f) - 110.0f);
	m_rtLeft2 = RectMakeCenter(m_fPosXLeft2, m_fPosYLeft2, 30, 70);
	m_fHpLeft2 = 500.0f;

	m_fPosXRight1 = m_BossPosX - ((m_BossWidth * 0.5f) - 410.0f);
	m_fPosYRight1 = m_BossPosY - ((m_BossHeight * 0.5f) - 110.0f);
	m_rtRight1 = RectMakeCenter(m_fPosXRight1, m_fPosYRight1, 30, 70);
	m_fHpRight1 = 500.0f;

	m_fPosXRight2 = m_BossPosX - ((m_BossWidth * 0.5f) - 305.0f);
	m_fPosYRight2 = m_BossPosY - ((m_BossHeight * 0.5f) - 120.0f);
	m_rtRight2 = RectMakeCenter(m_fPosXRight2, m_fPosYRight2, 30, 70);
	m_fHpRight2 = 500.0f;
}

void cTurret::Update()
{

}

void cTurret::Render()
{
	Rectangle(g_hDC, m_rtLeft1.left, m_rtLeft1.top, m_rtLeft1.right, m_rtLeft1.bottom);
	Rectangle(g_hDC, m_rtLeft2.left, m_rtLeft2.top, m_rtLeft2.right, m_rtLeft2.bottom);
	Rectangle(g_hDC, m_rtRight1.left, m_rtRight1.top, m_rtRight1.right, m_rtRight1.bottom);
	Rectangle(g_hDC, m_rtRight2.left, m_rtRight2.top, m_rtRight2.right, m_rtRight2.bottom);
}
