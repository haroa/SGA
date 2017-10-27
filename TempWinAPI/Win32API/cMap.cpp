#include "stdafx.h"
#include "cMap.h"


cMap::cMap()
{
	g_pTimerManager->AddSimpleTimer("kupa1");
	g_pTimerManager->AddSimpleTimer("fire");
}


cMap::~cMap()
{
}

void cMap::Setup()
{
	m_cBuffer = g_pImageManager->FindImage("Buffer");
	m_pImage = g_pImageManager->FindImage("Map");
	m_cObject = g_pImageManager->FindImage("Object");
	m_Object2 = g_pImageManager->FindImage("Object2");
	m_goomba = g_pImageManager->FindImage("goomba");
	m_kupa = g_pImageManager->FindImage("kupa");
	m_fPosX = 0.0f;

	m_fPosY = 70.0f;
	m_bMoveRight = true;
	m_bMoveRight2 = true;
	m_fObjectX = 1880.0f;
	m_fObjectY = 400.0f;
	m_fObjectX2 = 4400.0f;
	m_fObjectY2 = 500.0f;
	m_rtOb1 = RectMake(m_fObjectX, m_fObjectY, 70, 30);
	m_rtOb2 = RectMake(m_fObjectX2, m_fObjectY2, 70, 30);
	m_ob1Speedplus = 1.0f;
	m_os1Speedminus = -1.0f;
	m_ob2Speedplus = 1.0f;
	m_os2Speedminus = -1.0f;
	m_goombaX = 300.0f;
	m_goombaY = 430.0f;
	m_goombart = RectMake(m_goombaX, m_goombaY, 100, 100);
	m_bMoveRight3 = true;
	m_kupaX = 4800.0f;
	m_kupaY = 330.0f;
	m_kupart = RectMake(m_kupaX, m_kupaY, 200, 200);
}

void cMap::Update()
{
	MoveEnemy();
	MoveObject();
	m_rtOb1 = RectMake(m_fObjectX + m_fPosX, m_fObjectY, 70, 30);
	m_rtOb2 = RectMake(m_fObjectX2 + m_fPosX, m_fObjectY2, 70, 30);
	m_goombart = RectMake(m_goombaX + m_fPosX, m_goombaY, 100,100);
	m_kupart = RectMake(m_kupaX + m_fPosX, m_kupaY, 200, 200);

	if (g_pTimerManager->TickSimpleTimer("kupa1") > 10)
	{
		g_pTimerManager->ResetSimpleTimer("kupa1");
		m_kupa->SetFrameX(m_kupa->GetFrameX() + 1);
		if (m_kupa->GetFrameX() > 3)
		{
			m_kupa->SetFrameX(0);
		}
	}
	if (g_pTimerManager->TickSimpleTimer("fire") > 100)
	{
		g_pTimerManager->ResetSimpleTimer("fire");
		MakeFire();
	}
	MoveFire();
}

void cMap::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->Render(m_cBuffer->GetMemDC(), m_fPosX, m_fPosY, 5500, 520);
		m_cObject->Render(m_cBuffer->GetMemDC(), m_fObjectX + m_fPosX, m_fObjectY, 60, 20);
		m_Object2->Render(m_cBuffer->GetMemDC(), m_fObjectX2 + m_fPosX, m_fObjectY2, 60, 20);
		m_goomba->FrameRender(m_cBuffer->GetMemDC(), m_goombaX + m_fPosX, m_goombaY,100,100, m_goomba->GetFrameX(), m_goomba->GetFrameY());
		RenderFire();
		m_kupa->FrameRender(m_cBuffer->GetMemDC(), m_kupaX + m_fPosX, m_kupaY, 100, 100, m_kupa->GetFrameX(), m_kupa->GetFrameY());
		m_cBuffer->Render(g_hDC, 0,0);
	}
		//Rectangle(g_hDC, m_rtOb1.left, m_rtOb1.top, m_rtOb1.right, m_rtOb1.bottom);
		//Rectangle(g_hDC, m_rtOb2.left, m_rtOb2.top, m_rtOb2.right, m_rtOb2.bottom);
		//Rectangle(g_hDC, m_goombart.left, m_goombart.top, m_goombart.right, m_goombart.bottom);
		//for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
		//{
		//	Rectangle(g_hDC, iter->GetBody().left, iter->GetBody().top, iter->GetBody().right, iter->GetBody().bottom);
		//}
}

void cMap::MoveObject()
{
	if (m_bMoveRight && m_fObjectX < 2700)
	{
		m_fObjectX += 1;
		if (m_fObjectX >= 2700)
			m_bMoveRight = false;
	}
	else if (m_fObjectX > 1880)
	{
		m_fObjectX -= 1;
		if (m_fObjectX <= 1880)
			m_bMoveRight = true;
	}

	if (m_bMoveRight2 && m_fObjectX2 < 4600)
	{
		m_fObjectX2 += 1;
		if (m_fObjectX2 >= 4600)
			m_bMoveRight2 = false;
	}
	else if (m_fObjectX2 > 4400)
	{
		m_fObjectX2 -= 1;
		if (m_fObjectX2 <= 4400)
			m_bMoveRight2 = true;
	}
}

void cMap::MoveEnemy()
{
	if (m_bMoveRight3 && m_goombaX < 320)
	{
		m_goombaX += 1;
		if (m_goombaX >= 320)
			m_bMoveRight3 = false;
	}
	else if (m_goombaX > 100)
	{
		m_goombaX -= 1;
		if (m_goombaX <= 100)
			m_bMoveRight3 = true;
	}
}

void cMap::MakeFire()
{
	m_cFire.Setup();

	m_veccfire.push_back(m_cFire);
}

void cMap::RenderFire()
{
	for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
	{
		iter->Render();
	}
}

void cMap::MoveFire()
{
	for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
	{
		iter->SetPosX(iter->GetPosX() - 3);
	}
}
