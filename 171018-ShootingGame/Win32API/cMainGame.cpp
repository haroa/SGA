#include "stdafx.h"
#include "cMainGame.h"



cMainGame::cMainGame()
{
	m_nBossShotDelay = 10;
	m_nPlayerShotDelay = 5;

	g_pImageManager->AddImage("Boss", "images/Boss.bmp", 464, 356, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet1", "images/Bullet1.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet2", "images/Bullet2.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Player", "images/Player.bmp", 64,191, 1, 3, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("PlayerBullet", "images/Bullet3.bmp", 15, 31, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Gaugebg", "images/Gaugebg.bmp", 480, 50, 1, 2, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Gaugebar", "images/Gaugebar.bmp", 456, 112, 1, 8, true, RGB(255, 0, 255));
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
			m_nBossShotDelay = 10;
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
		m_cBoss.Update();
		HitPlayerBulletBoss();
		HitPlayerBulletTurret();
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
	// 흰색으로 이미지를 칠한다.
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
	char str[300];
	sprintf_s(str, "보스총알 갯수 : %d    플레총알 갯수 : %d",m_veccbBullet.size(),m_veccpBullet.size());
	TextOut(g_hDC, 10, 10, str, strlen(str));

	sprintf_s(str, "왼쪽1 체력 : %f    왼쪽2 체력 : %f", m_cTurret.GetHpLeft1(), m_cTurret.GetHpLeft2());
	TextOut(g_hDC, 10, 30, str, strlen(str));

	sprintf_s(str, "오른쪽1 체력 : %f    오른쪽2 체력 : %f", m_cTurret.GetHpRight1(), m_cTurret.GetHpRight2());
	TextOut(g_hDC, 10, 50, str, strlen(str));

	sprintf_s(str, "머리 체력 : %f", m_cBoss.GetHitPointHp());
	TextOut(g_hDC, 10, 70, str, strlen(str));

	sprintf_s(str, "전체 체력 : %f   비율 : %f",m_fNowBossHp, m_fSaveBossHp);
	TextOut(g_hDC, 10, 70, str, strlen(str));
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
	sprintf_s(str, "게임 오버", "게임 오버");
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

void cMainGame::HitPlayerBulletBoss()
{
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end();)
	{
		RECT HITBOSSFACE;
		if (IntersectRect(&HITBOSSFACE, &iter->GetBody(),&m_cBoss.GetHitPoint()))
		{
			m_cBoss.SetHitPointHp(m_cBoss.GetHitPointHp() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void cMainGame::HitPlayerBulletTurret()
{
	for (auto iter = m_veccpBullet.begin(); iter != m_veccpBullet.end();)
	{
		RECT HITTURRET;
		if (IntersectRect(&HITTURRET, &m_cTurret.GetBodyLeft1(), &iter->GetBody()))
		{
			m_cTurret.SetHpLeft1(m_cTurret.GetHpLeft1() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cTurret.GetBodyLeft2(), &iter->GetBody()))
		{
			m_cTurret.SetHpLeft2(m_cTurret.GetHpLeft2() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cTurret.GetBodyRight1(), &iter->GetBody()))
		{
			m_cTurret.SetHpRight1(m_cTurret.GetHpRight1() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cTurret.GetBodyRight2(), &iter->GetBody()))
		{
			m_cTurret.SetHpRight2(m_cTurret.GetHpRight2() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
