#include "stdafx.h"
#include "cPantheonMap.h"

void cPantheonMap::Setup()
{
	m_pImgBG = g_pImageManager->FindImage("MapleTownBG");
	m_pImgUI = g_pImageManager->FindImage("UI");
	m_fPosX = 0.0f;
	m_fPosY = 0.0f;
}

void cPantheonMap::Update()
{
}

void cPantheonMap::Render(HDC hdc)
{
	m_pImgBG->Render(hdc, m_fPosX, m_fPosY);

	char str[128];
	sprintf(str, "%f", m_fPosX);
	TextOut(g_hDC, 100, 300, str, strlen(str));
}
