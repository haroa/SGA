#include "stdafx.h"
#include "Ranking.h"


Ranking::Ranking()
{
}


Ranking::~Ranking()
{
}

void Ranking::Setup()
{
	m_pImage = g_pImageManager->FindImage("Ranking");
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY * 0.5f;
}

void Ranking::Update()
{
}

void Ranking::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->FrameRender(g_hDC, m_fPosX, m_fPosY, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	}
}
