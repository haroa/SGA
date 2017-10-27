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
	m_fPosX = 4850.0f;
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
		m_pImage->Render(m_Buffer->GetMemDC(), m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
}
