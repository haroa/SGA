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
	m_pImage = g_pImageManager->FindImage("background");

	m_fPosX = 0.0f;
	m_fPosY = 0.0f;
}

void cMap::Update()
{

}

void cMap::Render()
{
	m_pImage->Render(g_hDC, m_fPosX, m_fPosY);
}
