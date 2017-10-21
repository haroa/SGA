#include "stdafx.h"
#include "cStart.h"


cStart::cStart()
{

}


cStart::~cStart()
{

}

void cStart::Setup()
{
	m_pImage = g_pImageManager->FindImage("Start");
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY * 0.5f;
}

void cStart::Update()
{

}

void cStart::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	}
}
