#include "stdafx.h"
#include "cMainGame.h"



cMainGame::cMainGame()
{
	m_nBossShotDelay = 8;
	m_nPlayerShotDelay = 5;

	g_pImageManager->AddImage("Boss", "images/Boss.bmp", 464, 356, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet1", "images/Bullet1.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet2", "images/Bullet2.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Player", "images/Player.bmp", 64,191, 1, 3, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("PlayerBullet", "images/Bullet3.bmp", 15, 31, true, RGB(255, 0, 255));
}

cMainGame::~cMainGame()
{
	
}

void cMainGame::Setup()
{
	
}

void cMainGame::Update()
{
	cGameNode::Update();
	switch (m_GameState)
	{
	case GAME_READY:
		Reset();
		SystemEnter();
		break;
	case GAME_COUNT:
		PlayerController();
		if (m_nBossShotDelay < 0)
		{
			m_nBossShotDelay = 8;
			ShotBossBullet();
		}
		m_nBossShotDelay--;
		BossBulletMove();
		BossBulletActiveFalse();
		BossBulletErase();
		HitBossBulletPlayer();
		PlayerShotBullet();
		PlayerMoveBullet();
		PlayerBulletActiveFalse();
		PlayerBulletErase();
		break;
	case GAME_PLAYING:
		break;
	case GAME_OVER:
		SystemEnter();
		BossBulletAllErase();
		break;
	case GAME_CLEAR:
		break;
	}

}

void cMainGame::Render()
{
	// Èò»öÀ¸·Î ÀÌ¹ÌÁö¸¦ Ä¥ÇÑ´Ù.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	switch (m_GameState)
	{
	case GAME_READY:
		AllRender();
		break;
	case GAME_COUNT:
		AllRender();
		break;
	case GAME_PLAYING:
		break;
	case GAME_OVER:
		GameOverRender();
		break;
	case GAME_CLEAR:
		break;
	default:
		break;
	}


	//	TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	
}

void cMainGame::Reset()
{
	m_cPlayer.Setup();
	m_cBoss.Setup();
}

void cMainGame::GameStartRender()
{

}

void cMainGame::SystemEnter()
{
	if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		switch (m_GameState)
		{
		case GAME_READY:
			m_GameState = GAME_COUNT;
			break;
		case GAME_COUNT:
			break;
		case GAME_PLAYING:
			break;
		case GAME_OVER:
			m_GameState = GAME_READY;
			break;
		case GAME_CLEAR:
			break;
		}
	}
}

void cMainGame::PlayerController()
{
	m_cPlayer.Update();
}

void cMainGame::RepeatGame()
{

}

void cMainGame::AllRender()
{
	m_cBoss.Render();
	m_cPlayer.Render();
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end(); ++iter)
	{
		iter->Render();
	}
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end(); ++iter)
	{
		iter->Render();
	}
	char str[128];
	sprintf_s(str, "º¸½ºÃÑ¾Ë °¹¼ö : %d    ÇÃ·¹ÃÑ¾Ë °¹¼ö : %d",m_veccbBullet.size(),m_veccpBullet.size());
	TextOut(g_hDC, 10, 10, str, strlen(str));
}

void cMainGame::ShotBossBullet()
{
	cBbullet BossBullet;
	BossBullet.SetPlayer(&m_cPlayer);
	BossBullet.SetBoss(&m_cBoss);

	BossBullet.Setup();

	m_veccbBullet.push_back(BossBullet);
}

void cMainGame::BossBulletMove()
{
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end(); ++iter)
	{
		iter->SetPosX(iter->GetPosX() + iter->GetSpeedX());
		iter->SetPosY(iter->GetPosY() + iter->GetSpeedY());
		iter->Update();
	}
}

void cMainGame::BossBulletActiveFalse()
{
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end(); ++iter)
	{
		if (iter->GetPosX() < 0 || iter->GetPosX() > WINSIZEX || iter->GetPosY() < 0 || iter->GetPosY() > WINSIZEY)
		{
			iter->SetIsActive(false);
		}
	}
}

void cMainGame::BossBulletErase()
{
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end();)
	{
		if (!iter->GetIsActive())
		{
			iter = m_veccbBullet.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cMainGame::HitBossBulletPlayer()
{
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end(); iter++)
	{
		RECT rt;
		if (IntersectRect(&rt, &m_cPlayer.GetHitPoint(), &iter->GetBody()))
		{
			//m_GameState = GAME_OVER;
		}
	}
}

void cMainGame::GameOverRender()
{
	char str[128];
	sprintf_s(str, "°ÔÀÓ ¿À¹ö", "°ÔÀÓ ¿À¹ö");
	TextOut(g_hDC, WINSIZEX / 2,WINSIZEY / 2, str, strlen(str));
}

void cMainGame::BossBulletAllErase()
{
	for (auto iter = m_veccbBullet.begin(); iter != m_veccbBullet.end();)
	{
		if (iter->GetIsActive())
		{
			iter = m_veccbBullet.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cMainGame::PlayerMakeBullet()
{
	cPbullet PlayerBullet;

	PlayerBullet.SetPlayer(&m_cPlayer);
	PlayerBullet.Setup();

	m_veccpBullet.push_back(PlayerBullet);
}

void cMainGame::PlayerMoveBullet()
{
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end(); ++iter)
	{
		iter->SetPosY(iter->GetPosY() - iter->GetSpeedY());
		iter->Update();
	}
}

void cMainGame::PlayerShotBullet()
{
	if (g_pKeyManager->isStayKeyDown(VK_SPACE))
	{
		m_nPlayerShotDelay--;
		if (m_nPlayerShotDelay < 0)
		{
			m_nPlayerShotDelay = 5;
			PlayerMakeBullet();

		}
	}
}

void cMainGame::PlayerBulletActiveFalse()
{
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end(); iter++)
	{
		if (iter->GetPosX() < 0 || iter->GetPosX() > WINSIZEX || iter->GetPosY() < 0 || iter->GetPosY() > WINSIZEY)
		{
			iter->SetIsActive(false);
		}
	}
}

void cMainGame::PlayerBulletErase()
{
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end();)
	{
		if (!iter->GetIsActive())
		{
			iter = m_veccpBullet.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
