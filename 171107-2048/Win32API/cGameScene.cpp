#include "stdafx.h"
#include "cGameScene.h"


cGameScene::cGameScene()
{
}


cGameScene::~cGameScene()
{
}

void cGameScene::Setup()
{
	m_cMap.Setup();
	m_fJumpPower = 16.0f;
	SetLanding();
	m_fGravity = 0.0f;
}

void cGameScene::Update()
{
}


void cGameScene::Render()
{
	m_cMap.Render();
	//char str[128];
	//sprintf(str, "게임 레벨 : %d    딜레이 : %d",);
	//TextOut(g_hDC, 10, 320, str, strlen(str));
}

void cGameScene::SetLanding()
{
	m_fGravity = 0.0f;
	m_isJumpping = false;
}

void cGameScene::PlayerController()
{
	//if (g_pKeyManager->isStayKeyDown('A'))
	//{
	//}
	//else if (g_pKeyManager->isStayKeyDown('D'))
	//{
	//}
	//else if (g_pKeyManager->isStayKeyDown('S'))
	//{
	//}
	//else
	//{
	//}
	//
	//if (!m_isJumpping && g_pKeyManager->isOnceKeyDown(VK_SPACE))
	//{
	//	m_isJumpping = true;
	//}
	//
	//if (m_isJumpping)
	//{
	//	m_cPlayer.SetPosY(m_cPlayer.GetPosY() - m_fJumpPower + m_fGravity);
	//	m_fGravity += GRAVITY;
	//
	//	// 점프 후 내려오는 중에 착지 설정
	//	if (m_fGravity > m_fJumpPower)
	//	{
	//		float probeX = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 2;
	//		float probeY = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH() + m_fGravity;
	//
	//		if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 3) == false)
	//			SetLanding();
	//	}
	//}
}

void cGameScene::MiniMapRender()
{
//	m_cMap.GetImg()->Render(m_pminiMap->GetMemDC(), 0, 0, 550,60);
//	m_pObject->Render(m_pminiMap->GetMemDC(), m_cMap.GetObjectX() / 10, m_cMap.GetObjectY() / 10, 6, 2);
//	m_pObject2->Render(m_pminiMap->GetMemDC(), m_cMap.GetObjectX2() / 10, m_cMap.GetObjectY2() / 10, 6, 2);
//	m_clearobject->Render(m_pminiMap->GetMemDC(), m_cMap.GetclearObjectX() / 10, m_cMap.GetclearObjectY() / 10, 2, 2);
//	if (m_cMap.GetgoombaActive())
//	{
//		m_pGoomba->Render(m_pminiMap->GetMemDC(),m_cMap.GetGoombaX() / 10, m_cMap.GetGoombaY() / 10,10,10);
//	}
//	else
//	{
//
//	}
//	//m_fire->Render(m_pminiMap->GetMemDC(), m_fire->GetPosX() / 10, m_fire->GetPosY() / 10, 10, 10);
//	m_pKupa->FrameRender(m_pminiMap->GetMemDC(), m_cMap.GetKupaX() / 10, m_cMap.GetkupaY() / 20, 0, 0);
//	m_item->Render(m_pminiMap->GetMemDC(), m_cMap.GetitemX() / 10, m_cMap.GetitemY() / 10, 3, 3);
//	PlayerMiniRender();
//	m_pminiMap->Render(g_hDC, 0,0,WINSIZEX,WINSIZEY / 5);
}

void cGameScene::PlayerMiniRender()
{
	//HPEN hPen = (HPEN)CreatePen(0, 10, RGB(255, 0, 0));
	//HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);
	//
	//EllipseMakeCenter(m_pminiMap->GetMemDC(),((m_cPlayer.GetBody().left + (m_cPlayer.GetSizeW() / 2) - m_cMap.GetPosX() ) / 10),((m_cPlayer.GetBody().top + m_cPlayer.GetsizeH() / 2) / 10), 5,5);
	//BoudingLineMake(m_pminiMap->GetMemDC(), ((0 - m_cMap.GetPosX()) / 10), 0 / 10, 100,60);
	//
	//DeleteObject(hSelectPen);
	//DeleteObject(hPen);
}
