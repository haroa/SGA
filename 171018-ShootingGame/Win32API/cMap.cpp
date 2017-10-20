#include "stdafx.h"
#include "cMap.h"


cMap::cMap()
{
}


cMap::~cMap()
{
}

void cMap::Setup()
{
	m_pImage = g_pImageManager->FindImage("BackGround");
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY * 0.5f;	
	m_fDelay = 2.3f;
}

void cMap::Update()
{
	
	m_fDelay--;
	if (m_fDelay < 0)
	{		
		m_fDelay = 2.5f;
		m_pImage->SetFrameY(m_pImage->GetFrameY() + 1);
	}

	if (m_pImage->GetFrameY() > 9)
	{
		m_pImage->SetFrameY(0);
	}

}

void cMap::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	}
}
