#include "stdafx.h"
#include "cFire.h"


cFire::cFire()
{
	
}


cFire::~cFire()
{

}

void cFire::Setup()
{
	m_pImage = g_pImageManager->FindImage("fire");
	m_Buffer = g_pImageManager->FindImage("Buffer");
	m_fPosX = 500.0f;
	m_fPosY = 340.0f;
	m_nSizeW = 24;
	m_nSizeH = 16;
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cFire::Update()
{
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);

}

void cFire::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);

	char str[128];
	sprintf(str, "게임 레벨 : %f", m_MapPosX);
	TextOut(g_hDC, 10, 300, str, strlen(str));
}
