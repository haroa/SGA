#include "stdafx.h"
#include "cTbulletLeft1.h"


cTbulletLeft1::cTbulletLeft1()
{

}


cTbulletLeft1::~cTbulletLeft1()
{

}

void cTbulletLeft1::Setup()
{
	m_nSizeW = 32;
	m_nSizeH = 32;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_isActive = true;

	m_StartX = m_fPosX;
	m_StartY = m_fPosY;
	m_DestX = m_fPosX;
	m_DestY = WINSIZEY;
	m_ft = 0.0f;
	m_pImage = g_pImageManager->FindImage("Left1");
}

void cTbulletLeft1::Update()
{
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cTbulletLeft1::Render()
{
#ifdef _DEBUG
		Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);

#endif // _DEBUG
	if (m_isActive)
	{
		if (m_pImage != NULL)
		{
			m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
		}
	}
	else
	{

	}
}
