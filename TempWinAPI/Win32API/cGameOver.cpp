#include "stdafx.h"
#include "cGameOver.h"


cGameOver::cGameOver()
{
}


cGameOver::~cGameOver()
{
}

void cGameOver::Setup()
{
	m_pImage = g_pImageManager->FindImage("over");
}

void cGameOver::Update()
{
}

void cGameOver::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC, 0, 0, 800, 600);
	}
}
