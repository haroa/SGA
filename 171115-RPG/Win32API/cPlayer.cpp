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
	m_rtBody = RectMake(m_fPosX, m_fPosY, 50, 50);
}

void cPlayer::Update()
{
	m_rtBody = RectMake(m_fPosX, m_fPosY, 50, 50);
	Move();
}

void cPlayer::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);

}

void cPlayer::Move()
{
	if (g_pKeyManager->isStayKeyDown('A') && m_fPosX >= 0)
	{
		m_fPosX -= 5.0f;
	}
	if (g_pKeyManager->isStayKeyDown('D') && m_fPosX <= WINSIZEX - 260)
	{
		m_fPosX += 5.0f;
	}
	if (g_pKeyManager->isStayKeyDown('W') && m_fPosY > 0)
	{
		m_fPosY -= 5.0f;
	}
	if (g_pKeyManager->isStayKeyDown('S') && m_fPosY < WINSIZEY - 50)
	{
		m_fPosY += 5.0f;
	}
}
