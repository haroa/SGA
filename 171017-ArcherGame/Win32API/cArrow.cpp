#include "stdafx.h"
#include "cArrow.h"
#include "cPlayer.h"


cArrow::cArrow()
{
	m_pArrowImage = NULL;
#ifdef _DEBUG
	m_nArrowNum = 1;
#else
	m_nArrowNum = 10;
#endif // _DEBUG

}


cArrow::~cArrow()
{
}

void cArrow::Setup()
{
	/*
	float	m_fPosX;	//현재 X위치
	float	m_fPosY;	//현재 Y위치
	RECT	m_rtBody;	//렉트 박스
	float	m_fSpeedX;	//X의 위치스피드
	float	m_fSpeedY;	//Y의 위치스피드
	int		m_nDelay;	//딜레이
	int		m_nSizeW;	//가로크기
	int		m_nSizeH;	//세로크기
	*/
	m_pArrowImage = g_pImageManager->FindImage("Arrow");
	m_nSizeW = 40;
	m_nSizeH = 5;
	m_fPosX = m_pcPlayer->GetPosX() + 30;
	m_fPosY = m_pcPlayer->GetPosY();
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeedX = 0.0f;
	m_fSpeedY = 0.0f;
	m_nArrowStack = 1;
	m_fWindSpeed = 0.0f;
	m_isActive = true;
}

void cArrow::Update()
{
	Move();



}

void cArrow::Render()
{
#ifdef _DEBUG
	if (m_isActive)
	{
		Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
		if (m_pArrowImage != NULL)
		{
			m_pArrowImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
		}
	}
	else
	{

	}
#else
	if (m_isActive)
	{
		if (m_pArrowImage != NULL)
		{
			m_pArrowImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
		}
	}
	else
	{

	}
#endif // _DEBUG
	char str[128];
	sprintf_s(str, "화살 수 : %d     화살스택 : %d", m_nArrowNum, m_nArrowStack);
	TextOut(g_hDC, 10, 10, str, strlen(str));

}

void cArrow::Move()
{
	m_fPosX += m_fSpeedX;
	m_fPosY += m_fWindSpeed;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}
