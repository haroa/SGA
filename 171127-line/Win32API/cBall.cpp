#include "stdafx.h"
#include "cBall.h"
//#include "cPlay.h"


cBall::cBall()
{

}


cBall::~cBall()
{

}

void cBall::Setup()
{
	m_fPosX = g_ptMouse.x;
	m_fPosY = g_ptMouse.y;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 30, 30);
}

void cBall::Update()
{
}

void cBall::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}
