#include "stdafx.h"
#include "cPlay.h"

void cPlay::Setup()
{
	m_fPosX = 100.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 100, 100);
	m_ft = 0.0f;
	m_fromX = m_fPosX;
	m_fromY = m_fPosY;
}

void cPlay::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 100, 100);

	if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
	{
		MakeBall();
	}
	for (auto iter = m_vcBall.begin(); iter != m_vcBall.end();iter++)
	{
		m_ftoX = iter->GetPosX();
		m_ftoY = iter->GetPosY();
		LinearInterpolation(m_fPosX, m_fPosY, m_fromX, m_fromY, m_ftoX, m_ftoY, m_ft);
		m_ft += 0.01;
	}
	if (m_ft >= 1.0f)
	{
		m_ft = 0.0f;
	}

	for (auto iter = m_vcBall.begin(); iter != m_vcBall.end();)
	{
		if (PtInRect(&iter->GetBody(), g_ptMouse) && g_pKeyManager->isOnceKeyDown(VK_RBUTTON))
		{
			iter = m_vcBall.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cPlay::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	for (auto iter = m_vcBall.begin(); iter != m_vcBall.end(); iter++)
	{
		iter->Render();
	}
}

void cPlay::MakeBall()
{
	cBall Ball;
	Ball.Setup();
	m_vcBall.push_back(Ball);
}
