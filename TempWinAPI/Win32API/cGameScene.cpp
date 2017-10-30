#include "stdafx.h"
#include "cGameScene.h"


cGameScene::cGameScene()
{
	m_pImage = NULL;
	g_pTimerManager->AddSimpleTimer("Player-Left");
	g_pTimerManager->AddSimpleTimer("Player-Right");
	g_pTimerManager->AddSimpleTimer("fire");
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
	m_pObject = g_pImageManager->FindImage("Object");
	m_pObject2 = g_pImageManager->FindImage("Object2");
	m_pGoomba = g_pImageManager->FindImage("goomba");
	m_pKupa = g_pImageManager->FindImage("kupa");
	m_fire = g_pImageManager->FindImage("fire");
	m_bPlayerDie = false;
}

void cGameScene::Update()
{
	EnemycollPlayer();
	ObjectcollPlayer();
	m_cMap.Update();
	m_cPlayer.Update();
	PlayerController();

	if (m_cPlayer.GetBody().bottom >= WINSIZEY)
	{
		m_bPlayerDie = true;
	}
	if (g_pTimerManager->TickSimpleTimer("fire") > 100)
	{
		g_pTimerManager->ResetSimpleTimer("fire");
		MakeFire();
	}
	MoveFire();
}

void cGameScene::Render()
{
	//if (m_cMap.GetImg() != NULL)
	//{
	//	m_cMap.GetImg()->Render(m_pImage->GetMemDC(), 0,0, 5500, 600);
	//	m_pImage->Render(g_hDC, m_cMap.GetPosX(), m_cMap.GetPosY());
	//}
	//Rectangle(g_hDC, m_cMap.GetOB1().left, m_cMap.GetOB1().top, m_cMap.GetOB1().right, m_cMap.GetOB1().bottom);
	m_cMap.Render();
	MiniMapRender();
	m_cPlayer.Render();
	RenderFire();
	char str[128];
	sprintf(str, "게임 레벨 : %d", m_veccfire.size());
	TextOut(g_hDC, 10, 320, str, strlen(str));
}

void cGameScene::SetLanding()
{
	m_fGravity = 0.0f;
	m_isJumpping = false;
}

void cGameScene::PlayerController()
{

	PixelCollisionbottom();
	PixelCollisionHead();

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
		if (m_cMap.GetPosX() >= 0)
		{
			m_cMap.SetPosX(0);
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
			for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
			{
				iter->SetPosX(iter->GetPosX() - 3);
			}
		}
	}
	else if (g_pKeyManager->isStayKeyDown('S'))
	{
		m_cPlayer.GetImg()->SetFrameY(5);
		m_cPlayer.GetImg()->SetFrameX(0);
	}
	else
	{
		m_cPlayer.GetImg()->SetFrameY(0);
		m_cPlayer.GetImg()->SetFrameX(0);
	}

	if (!m_isJumpping && g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{
		m_isJumpping = true;
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
			float probeX = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 2;
			float probeY = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH() + m_fGravity;

			if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 3) == false)
				SetLanding();
		}
	}
}

void cGameScene::MiniMapRender()
{
	m_cMap.GetImg()->Render(m_pminiMap->GetMemDC(), 0, 0, 550,60);
	m_pObject->Render(m_pminiMap->GetMemDC(), m_cMap.GetObjectX() / 10, m_cMap.GetObjectY() / 10, 6, 2);
	m_pObject2->Render(m_pminiMap->GetMemDC(), m_cMap.GetObjectX2() / 10, m_cMap.GetObjectY2() / 10, 6, 2);
	m_pGoomba->Render(m_pminiMap->GetMemDC(),m_cMap.GetGoombaX() / 10, m_cMap.GetGoombaY() / 10,10,10);
	m_pKupa->FrameRender(m_pminiMap->GetMemDC(), m_cMap.GetKupaX() / 10, m_cMap.GetkupaY() / 20, 0, 0);
	PlayerMiniRender();
	m_pminiMap->Render(g_hDC, 0,0,WINSIZEX,WINSIZEY / 5);
}

void cGameScene::PlayerMiniRender()
{
	HPEN hPen = (HPEN)CreatePen(0, 10, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	EllipseMakeCenter(m_pminiMap->GetMemDC(),((m_cPlayer.GetBody().left + (m_cPlayer.GetSizeW() / 2) - m_cMap.GetPosX() ) / 10),((m_cPlayer.GetBody().top + m_cPlayer.GetsizeH() / 2) / 10), 5,5);
	BoudingLineMake(m_pminiMap->GetMemDC(), ((0 - m_cMap.GetPosX()) / 10), 0 / 10, 100,60);

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}

void cGameScene::PixelCollisionHead()
{
	float probeX3 = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 2;
	float probeY3 = m_cPlayer.GetPosY() - 5.0f;

	if (g_pPixelManager->CheckPixel(m_pImage, probeX3, probeY3) == false)
	{
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() + 3);
	}
	float probeX6 = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 4;
	float probeY6 = m_cPlayer.GetPosY() - 5.0f;

	if (g_pPixelManager->CheckPixel(m_pImage, probeX6, probeY6) == false)
	{
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() + 3);
	}

	float probeX7 = m_cPlayer.GetPosX() - m_cPlayer.GetSizeW() / 4;
	float probeY7 = m_cPlayer.GetPosY() - 5.0f;

	if (g_pPixelManager->CheckPixel(m_pImage, probeX7, probeY7) == false)
	{
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() + 3);
	}

}

void cGameScene::PixelCollisionbottom()
{
	float probeX = m_cPlayer.GetPosX() + m_cPlayer.GetSizeW() / 2;
	float probeY = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH();

	if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY))
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() + 5);
	else if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 3) == false)
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() - 3);


	float probeX1 = m_cPlayer.GetPosX();
	float probeY1 = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH();

	if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 5) == false)
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() - 3);

	float probeX3 = m_cPlayer.GetPosX() - m_cPlayer.GetSizeW();
	float probeY3 = m_cPlayer.GetPosY() + m_cPlayer.GetsizeH();


	if (g_pPixelManager->CheckPixel(m_pImage, probeX, probeY - 5) == false)
		m_cPlayer.SetPosY(m_cPlayer.GetPosY() - 3);
	
}

void cGameScene::ObjectcollPlayer()
{
	RECT rt;

	if (IntersectRect(&rt, &m_cPlayer.GetBody(), &m_cMap.GetOB1()))
	{
		if (m_cMap.GetMoveRight1() == true)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}
		else if (m_cMap.GetMoveRight1() == false)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		if (m_cMap.GetMoveRight1() == true && m_cPlayer.GetPosX() >= WINSIZEX / 2)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() - 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		else if (m_cMap.GetMoveRight1() == false && m_cPlayer.GetPosX() <= 100)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() + 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}	
	}

	RECT rt2;
	if (IntersectRect(&rt2, &m_cPlayer.GetBody(), &m_cMap.GetOB2()))
	{
		if (m_cMap.GetMoveRight2() == true)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}
		else if (m_cMap.GetMoveRight2() == false)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		if (m_cMap.GetMoveRight2() == true && m_cPlayer.GetPosX() >= WINSIZEX / 2)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() - 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		else if (m_cMap.GetMoveRight2() == false && m_cPlayer.GetPosX() <= 100)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() + 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}
	}
}

void cGameScene::EnemycollPlayer()
{
	RECT rt3;
	if (IntersectRect(&rt3, &m_cPlayer.GetBody(), &m_cMap.Getgoomba()))
	{
		if (m_cMap.GetMoveRight3() == true)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}
		else if (m_cMap.GetMoveRight3() == false)
		{
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		if (m_cMap.GetMoveRight3() == true && m_cPlayer.GetPosX() >= WINSIZEX / 2)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() - 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() - 1);
		}
		else if (m_cMap.GetMoveRight3() == false && m_cPlayer.GetPosX() <= 100)
		{
			m_cMap.SetPosX(m_cMap.GetPosX() + 1);
			m_cPlayer.SetPosX(m_cPlayer.GetPosX() + 1);
		}
	}
}

void cGameScene::MakeFire()
{
	cFire m_cFire;
	m_cFire.Setup();

	m_veccfire.push_back(m_cFire);
}

void cGameScene::RenderFire()
{
	for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
	{
		iter->Render();
	}
}

void cGameScene::MoveFire()
{
	for (auto iter = m_veccfire.begin(); iter != m_veccfire.end(); iter++)
	{
		iter->SetPosX(iter->GetPosX() - 3);
	}
}