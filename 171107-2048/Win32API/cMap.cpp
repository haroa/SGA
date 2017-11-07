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
	//m_number1 = g_pImageManager->FindImage("2");
	//m_number2 = g_pImageManager->FindImage("4");
	//m_number3 = g_pImageManager->FindImage("8");
	//m_number4 = g_pImageManager->FindImage("16");
	//m_number5 = g_pImageManager->FindImage("32");
	//m_number6 = g_pImageManager->FindImage("64");
	//m_number7 = g_pImageManager->FindImage("128");
	//m_number8 = g_pImageManager->FindImage("256");
	//m_number9 = g_pImageManager->FindImage("512");
	//m_number10 = g_pImageManager->FindImage("1024");
	//m_number11 = g_pImageManager->FindImage("2048");
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
