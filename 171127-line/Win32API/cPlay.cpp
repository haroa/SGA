#include "stdafx.h"
#include "cPlay.h"

void cPlay::Setup()
{
	m_cBall.Setup();
}

void cPlay::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
	{
		MakeBall();
	}

	for (auto iter = m_vecBall.begin(); iter != m_vecBall.end(); iter++)
	{
		RECT rt = RectMakeCenter(iter->GetPosX(), iter->GetPosY(), SIZE, SIZE);
		if (g_pKeyManager->isStayKeyDown(VK_LBUTTON) && PtInRect(&rt, g_ptMouse))
		{

		}
	}
}

void cPlay::Render()
{
	EllipseMakeCenter(g_hDC, m_cBall.GetPosX(), m_cBall.GetPosY(), 50, 50);

	for (int i = 0; i < m_vecBall.size(); i++)
	{
		RectangleMakeCenter(g_hDC, m_vecBall[i].GetPosX(), m_vecBall[i].GetPosY(), SIZE, SIZE);
	}
	char infoMsg[100];
	sprintf_s(infoMsg, "X : %f       Y : %f", m_fPosX, m_fPosY);
	TextOut(g_hDC, 200, 100, infoMsg, (int)strlen(infoMsg));
}

void cPlay::MakeBall()
{
	cBall newtarget;

	newtarget.SetPosX(g_ptMouse.x);
	newtarget.SetPosY(g_ptMouse.y);

	m_vecBall.push_back(newtarget);
}
