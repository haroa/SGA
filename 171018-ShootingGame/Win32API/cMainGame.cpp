#include "stdafx.h"
#include "cMainGame.h"



cMainGame::cMainGame()
{
	m_nBossShotDelay = 20;
	m_nPlayerShotDelay = 5;

	g_pImageManager->AddImage("Boss", "images/Boss.bmp", 464, 356, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet1", "images/Bullet1.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Bullet2", "images/Bullet2.bmp", 32, 32, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Player", "images/Player.bmp", 64,191, 1, 3, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("PlayerBullet", "images/Bullet3.bmp", 15, 31, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Gaugebg", "images/Gaugebg.bmp", 480, 50, 1, 2, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Gaugebar", "images/Gaugebar.bmp", 456, 112, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("BackGround", "images/Background.bmp",700,10000, 1, 10, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Boom", "images/Boom.bmp", 53, 512, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Boom2", "images/Boom2.bmp", 53, 512, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Boom3", "images/Boom3.bmp", 53, 512, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Boom4", "images/Boom4.bmp", 53, 512, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Boom5", "images/Boom5.bmp", 53, 512, 1, 8, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("BossBoom", "images/BossBoom.bmp", 442, 6750, 1, 15, true, RGB(255, 0, 255));
}

cMainGame::~cMainGame()
{
	g_pTimerManager->DeleteTimerAll();
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
		m_cBoss.Update();
		m_cMap.Update();
		break;
	case GAME_COUNT:
		break;
	case GAME_PLAYING:
		m_cMap.Update();
		PlayerController();
		if (m_nBossShotDelay < 0)
		{
			m_nBossShotDelay = 20;
			ShotBossBullet();
		}
		g_pTimerManager->AddSimpleTimer("Left1");
		if (g_pTimerManager->TickSimpleTimer("Left1") > 4)
		{
			g_pTimerManager->ResetSimpleTimer("Left1");
			TurretLeft1MakeBullet();
			TurretRight2MakeBullet();
			TurretLeft2MakeBullet();
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
		GameClear();
		TurretLeft1MoveBullet();
		TurretRight2MoveBullet();
		TurretLeft2MoveBullet();
		TurretLeft1ActiveFlase();
		TurretLeft1Erase();
		break;
	case GAME_OVER:
		SystemEnter();
		BossBulletAllErase();
		break;
	case GAME_CLEAR:
		SystemEnter();
		BossBulletAllErase();
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
		TurretLeft1Render();
		TurretRight2Render();
		TurretLeft2Render();
		break;
	case GAME_COUNT:
		break;
	case GAME_PLAYING:
		AllRender();
		TurretLeft1Render();
		TurretRight2Render();
		TurretLeft2Render();
		break;
	case GAME_OVER:
		GameOverRender();
		break;
	case GAME_CLEAR:
		GameClearRender();
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

	m_cMap.Setup();
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
			m_GameState = GAME_PLAYING;
			break;
		case GAME_COUNT:
			break;
		case GAME_PLAYING:
			break;
		case GAME_OVER:
			m_GameState = GAME_READY;
			break;
		case GAME_CLEAR:
			m_GameState = GAME_READY;
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
	m_cMap.Render();
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

	sprintf_s(str, "왼쪽1 체력 : %f    왼쪽2 체력 : %f", m_cBoss.GetTurret()->GetHpLeft1(), m_cBoss.GetTurret()->GetHpLeft2());
	TextOut(g_hDC, 10, 30, str, strlen(str));
	
	sprintf_s(str, "오른쪽1 체력 : %f    오른쪽2 체력 : %f", m_cBoss.GetTurret()->GetHpRight1(), m_cBoss.GetTurret()->GetHpRight2());
	TextOut(g_hDC, 10, 50, str, strlen(str));
	
	sprintf_s(str, "머리 체력 : %f    게임오버스택 : %d", m_cBoss.GetHitPointHp(),m_cBoss.GetGameOverStack());
	TextOut(g_hDC, 10, 70, str, strlen(str));
	
	sprintf_s(str, "전체 체력 : %f   비율 : %f",m_cBoss.GetNowBossHp(),m_cBoss.GetNowBossHp() / m_cBoss.GetAllBossHp());
	TextOut(g_hDC, 10, 90, str, strlen(str));

	sprintf_s(str, "왼쪽1 총알 : %d   왼쪽2 총알 : %d",m_veccTbulletLeft1.size(), m_veccTbulletLeft2.size());
	TextOut(g_hDC, 10, 110, str, strlen(str));

	sprintf_s(str, "오른쪽1 총알 : %d   오른쪽2 총알 : %d", m_veccTbulletRight1.size(), m_veccTbulletRight2.size());
	TextOut(g_hDC, 10, 130, str, strlen(str));
}

void cMainGame::ShotBossBullet()
{
	cBbullet BossBullet;
	BossBullet.SetPlayer(&m_cPlayer);
	BossBullet.SetBoss(&m_cBoss);

	BossBullet.Setup();
	float m_fangle = GetAngle(m_cPlayer.GetPosX(), m_cPlayer.GetPosY(), BossBullet.GetPosX(), BossBullet.GetPosY());
	float m_fSpeedX = -cosf(m_fangle / 180 * PI) * 5.0f;
	float m_fSpeedY = -sinf(m_fangle / 180 * PI) * 5.0f;

	BossBullet.SetSpeedX(m_fSpeedX);
	BossBullet.SetSpeedY(m_fSpeedY);
	m_veccbBullet.push_back(BossBullet);

	//float m_dangle = m_fangle + 10.0f;
	//m_fSpeedX = -cosf(m_dangle / 180 * PI) * 5.0f;
	//m_fSpeedY = -sinf(m_dangle / 180 * PI) * 5.0f;
	//
	//BossBullet.SetSpeedX(m_fSpeedX);
	//BossBullet.SetSpeedY(m_fSpeedY);
	//m_veccbBullet.push_back(BossBullet);


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
		if (IntersectRect(&HITTURRET, &m_cBoss.GetTurret()->GetBodyLeft1(), &iter->GetBody()))
		{
			//m_cTurret.SetHpLeft1(m_cTurret.GetHpLeft1() - iter->GetBulletDmg());
			m_cBoss.GetTurret()->SetHpLeft1(m_cBoss.GetTurret()->GetHpLeft1() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cBoss.GetTurret()->GetBodyLeft2(), &iter->GetBody()))
		{
			//m_cTurret.SetHpLeft2(m_cTurret.GetHpLeft2() - iter->GetBulletDmg());
			m_cBoss.GetTurret()->SetHpLeft2(m_cBoss.GetTurret()->GetHpLeft2() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cBoss.GetTurret()->GetBodyRight1(), &iter->GetBody()))
		{
			//m_cTurret.SetHpRight1(m_cTurret.GetHpRight1() - iter->GetBulletDmg());
			m_cBoss.GetTurret()->SetHpRight1(m_cBoss.GetTurret()->GetHpRight1() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else if (IntersectRect(&HITTURRET, &m_cBoss.GetTurret()->GetBodyRight2(), &iter->GetBody()))
		{
			//m_cTurret.SetHpRight2(m_cTurret.GetHpRight2() - iter->GetBulletDmg());
			m_cBoss.GetTurret()->SetHpRight2(m_cBoss.GetTurret()->GetHpRight2() - iter->GetBulletDmg());
			iter = m_veccpBullet.erase(iter);
		}
		else
		{
			iter++;
		}		
	}
}

void cMainGame::GameClear()
{
	if (m_cBoss.GetGameOverStack() > 5)
	{
		m_GameState = GAME_CLEAR;
	}
}

void cMainGame::GameClearRender()
{
	char str[128];
	sprintf_s(str, "게임 클리어!", "게임 클리어!");
	TextOut(g_hDC, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
}


//아직미완============================================================================
void cMainGame::TurretLeft1MakeBullet()
{
	//cBbullet BossBullet;
	//BossBullet.SetPlayer(&m_cPlayer);
	//BossBullet.SetBoss(&m_cBoss);
	//
	//BossBullet.Setup();
	//float m_fangle = GetAngle(m_cPlayer.GetPosX(), m_cPlayer.GetPosY(), BossBullet.GetPosX(), BossBullet.GetPosY());
	//float m_fSpeedX = -cosf(m_fangle / 180 * PI) * 5.0f;
	//float m_fSpeedY = -sinf(m_fangle / 180 * PI) * 5.0f;
	//
	//BossBullet.SetSpeedX(m_fSpeedX);
	//BossBullet.SetSpeedY(m_fSpeedY);
	//m_veccbBullet.push_back(BossBullet);
	cTbulletLeft1 Left1;
	Left1.SetPosX(m_cBoss.GetTurret()->GetPosXLeft1());
	Left1.SetPosY(m_cBoss.GetTurret()->GetPosYLeft1());

	Left1.Setup();
	m_veccTbulletLeft1.push_back(Left1);

	Left1.SetDestX(Left1.GetDestX() + 200);


	m_veccTbulletLeft1.push_back(Left1);

	Left1.SetDestX(Left1.GetDestX() + 200);

	m_veccTbulletLeft1.push_back(Left1);
}

void cMainGame::TurretLeft1MoveBullet()
{
	for (auto iter = m_veccTbulletLeft1.begin(); iter != m_veccTbulletLeft1.end(); iter++)
	{
		float X = iter->GetPosX();
		float Y = iter->GetPosY();
		iter->Update();
		LinearInterpolation(X, Y, iter->GetStartX(), iter->GetStartY(), iter->GetDestX(), iter->GetDestY(), iter->GetT());

		iter->SetPosX(X);
		iter->SetPosY(Y);
		iter->SetT(iter->GetT() + 0.01);
	}
}

void cMainGame::TurretLeft1Render()
{
	for (auto iter = m_veccTbulletLeft1.begin(); iter != m_veccTbulletLeft1.end(); iter++)
	{
		iter->Render();
	}

}

void cMainGame::TurretLeft1ActiveFlase()
{
	for (auto iter = m_veccTbulletLeft1.begin(); iter != m_veccTbulletLeft1.end(); iter++)
	{
		if (iter->GetPosX() < 0 || iter->GetPosX() > WINSIZEX || iter->GetPosY() < 0 || iter->GetPosY() > WINSIZEY)
		{
			iter->SetIsActive(false);
		}
	}
}

void cMainGame::TurretLeft1Erase()
{
	for (auto iter = m_veccTbulletLeft1.begin(); iter != m_veccTbulletLeft1.end();)
	{
		if (!iter->GetIsActive())
		{
			iter = m_veccTbulletLeft1.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
//====================================================================================

//왼쪽2===============================================================================
void cMainGame::TurretLeft2MakeBullet()
{
	cTbulletLeft2 Left2;

	Left2.SetPosX(m_cBoss.GetTurret()->GetPosXLeft2());
	Left2.SetPosY(m_cBoss.GetTurret()->GetPosYLeft2());

	Left2.Setup();

	m_veccTbulletLeft2.push_back(Left2);
}

void cMainGame::TurretLeft2MoveBullet()
{
	for (auto iter = m_veccTbulletLeft2.begin(); iter != m_veccTbulletLeft2.end(); iter++)
	{
		float X = iter->GetPosX();
		float Y = iter->GetPosY();
		iter->Update();
		BezierInterpolation(X, Y, iter->GetStartX(), iter->GetStartY(), iter->GetViaX(), iter->GetViaY(), iter->GetDestX(), iter->GetDestY(), iter->GetT());

		iter->SetPosX(X);
		iter->SetPosY(Y);
		iter->SetT(iter->GetT() + 0.01);
	}
}

void cMainGame::TurretLeft2ActiveFlase()
{

}

void cMainGame::TurretLeft2Erase()
{

}

void cMainGame::TurretLeft2Render()
{
	for (auto iter = m_veccTbulletLeft2.begin(); iter != m_veccTbulletLeft2.end(); iter++)
	{
		iter->Render();
	}
}
//=====================================================================================

//오른쪽2===============================================================================

void cMainGame::TurretRight2MakeBullet()
{
	cTbulletRight2 Right2;

	Right2.SetPosX(m_cBoss.GetTurret()->GetPosXRight2());
	Right2.SetPosY(m_cBoss.GetTurret()->GetPosYRight2());
	Right2.SetDestX(Right2.GetPosX());
	Right2.Setup();

	m_veccTbulletRight2.push_back(Right2);
}

void cMainGame::TurretRight2MoveBullet()
{
	for (auto iter = m_veccTbulletRight2.begin(); iter != m_veccTbulletRight2.end(); iter++)
	{
		//sinf(iter->GetT());
		iter->SetT(iter->GetT() + 0.1f);

		iter->SetPosX(iter->GetDestX() + sinf(iter->GetT()) * 250);
		iter->SetPosY(iter->GetPosY() + 5.0f);

		iter->Update();
	}
}

void cMainGame::TurretRight2ActiveFlase()
{

}

void cMainGame::TurretRight2Erase()
{

}

void cMainGame::TurretRight2Render()
{
	for (auto iter = m_veccTbulletRight2.begin(); iter != m_veccTbulletRight2.end(); iter++)
	{
		iter->Render();
	}
}
//====================================================================================
