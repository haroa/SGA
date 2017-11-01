#include "stdafx.h"
#include "cFire.h"


cFire::cFire()
{
    m_MapPosX = NULL;
}


cFire::~cFire()
{

}

void cFire::Setup()
{
	m_pImage = g_pImageManager->FindImage("fire");
	m_Buffer = g_pImageManager->FindImage("Buffer");
	m_fPosX = 4820.0f;
	m_fPosY = 340.0f;
	m_nSizeW = 24;
	m_nSizeH = 16;
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_isActive = true;
}

void cFire::Update()
{
	if (m_isActive)
	{
		m_rtBody = RectMake(m_fPosX + *m_MapPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
	else
	{
		m_rtBody = RectMake(0, 0, 0, 0);
	}
}

void cFire::Render()
{
	if (m_pImage != NULL)
	{
		if (m_isActive)
		{
			m_pImage->Render(m_Buffer->GetMemDC(), m_fPosX + *m_MapPosX, m_fPosY, m_nSizeW, m_nSizeH);
		}
		else
		{

		}
		//m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
	//Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);

    if (m_MapPosX != NULL)
    {
        char str[128];
        sprintf(str, "%f", *m_MapPosX);
        TextOut(g_hDC, 10, 300, str, strlen(str));
    }
}
