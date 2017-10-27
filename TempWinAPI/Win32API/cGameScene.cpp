#include "stdafx.h"
#include "cGameScene.h"


cGameScene::cGameScene()
{
	m_pImage = NULL;
	g_pTimerManager->AddSimpleTimer("Player-Left");
	g_pTimerManager->AddSimpleTimer("Player-Right");
}


cGameScene::~cGameScene()
{
}

void cGameScene::Setup()
{

	m_fJumpPower = 16.0f;
	SetLanding();
	m_fGravity = 0.0f;
	m_cMap.Setup();
	m_cPlayer.Setup();
	m_pImage = g_pImageManager->FindImage("Buffer");
	m_pminiMap = g_pImageManager->FindImage("MiniMap");
}

void cGameScene::Update()
{
	m_cPlayer.Update();
	PlayerController();
}

void cGameScene::Render()
{
	//if (m_cMap.GetImg() != NULL)
	//{
	//	m_cMap.GetImg()->Render(m_pImage->GetMemDC(), 0,0, 5500, 600);
	//	m_pImage->Render(g_hDC, m_cMap.GetPosX(), m_cMap.GetPosY());
	//}
	m_cMap.Render();
	MiniMapRender();
	m_cPlayer.Render();
}

void cGameScene::SetLanding()
{
	m_fGravity = 0.0f;
	m_isJumpping = false;
}

void cGameScene::PlayerController()
{
	float probeX = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 2;
	float probeY = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH();

	if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY))
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() + 5);
	else if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 5) == false)
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() - 3);

	if (g_pKeyManager->isStayKeyDown('A'))
	{
		//m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 3);

		float probeX1 = m_cPlayer.GetPosX();
		float probeY1 = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH() / 2;
		if (g_pPixelManager->CheckPixel(m_pImage, probeX1, probeY1))
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 3);
		else if (g_pPixelManager->CheckPixel(m_pImage, probeX1 + 1, probeY1) == false)
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);

		m_cPlayer.GetImg()->SetFrameY(2);
		if (g_pTimerManager->TickSimpleTimer("Player-Left") > 10)
		{
			g_pTimerManager->ResetSimpleTimer("Player-Left");
			m_cPlayer.GetImg()->SetFrameX(m_cPlayer.GetImg()->GetFrameX() + 1);
		}
		if (m_cPlayer.GetImg()->GetFrameX() > 2)
		{
			m_cPlayer.GetImg()->SetFrameX(0);
		}

		if (m_cPlayer.GetPosX() + (m_cPlayer.GetSizeW() / 2) <= 100)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 3);
			m_cMap.SetPosX(m_cMap.GetPosX() + 3.0f);
		}

	}
	else if (g_pKeyManager->isStayKeyDown('D'))
	{
		//m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 3);

		float probeX2 = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW();
		float probeY2 = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH() / 2;
		if (g_pPixelManager->CheckPixel(m_pImage, probeX2, probeY2))
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 3);
		else if (g_pPixelManager->CheckPixel(m_pImage, probeX2 - 1, probeY2) == false)
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);

		m_cPlayer.GetImg()->SetFrameY(1);
		if (g_pTimerManager->TickSimpleTimer("Player-Right") > 10)
		{
			g_pTimerManager->ResetSimpleTimer("Player-Right");
			m_cPlayer.GetImg()->SetFrameX(m_cPlayer.GetImg()->GetFrameX() + 1);
		}
		if (m_cPlayer.GetImg()->GetFrameX() > 2)
		{
			m_cPlayer.GetImg()->SetFrameX(0);
		}
		if (m_cPlayer.GetPosX() + (m_cPlayer.GetSizeW() / 2) >= WINSIZEX / 2)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 3);
			m_cMap.SetPosX(m_cMap.GetPosX() - 3.0f);
		}

	}
	else
	{
		m_cPlayer.GetImg()->SetFrameY(0);
		m_cPlayer.GetImg()->SetFrameX(0);
	}

	if (!m_isJumpping && g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{
		m_isJumpping = true;
		m_cPlayer.GetImg()->SetFrameY(3);
		m_cPlayer.GetImg()->SetFrameX(0);
	}

	if (m_isJumpping)
	{
		m_cPlayer.GetImg()->SetFrameY(3);
		m_cPlayer.GetImg()->SetFrameX(0);
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() - m_fJumpPower + m_fGravity);
		m_fGravity += GRAVITY;

		// 점프 후 내려오는 중에 착지 설정
		if (m_fGravity > m_fJumpPower)
		{
			probeY = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH() + m_fGravity;

			if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 3) == false)
				SetLanding();
		}
	}
}

void cGameScene::MiniMapRender()
{
	m_cMap.GetImg()->Render(m_pminiMap->GetMemDC(), 0, 0, 550,60);
	PlayerMiniRender();
	m_pminiMap->Render(g_hDC, 0,0,WINSIZEX,WINSIZEY / 5);
}

void cGameScene::PlayerMiniRender()
{
	HPEN hPen = (HPEN)CreatePen(0, 10, RGB(255, 255, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	EllipseMakeCenter(m_pminiMap->GetMemDC(),((m_cPlayer.GetBody().left + (m_cPlayer.GetSizeW() / 2) - m_cMap.GetPosX() ) / 10),((m_cPlayer.GetBody().top + m_cPlayer.GetsizeH() / 2) / 10), 5,5);
	BoudingLineMake(m_pminiMap->GetMemDC(), ((0 - m_cMap.GetPosX()) / 10), 0 / 10, 60,60);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}

