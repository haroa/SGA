#include "stdafx.h"
#include "cMainGame.h"



cMainGame::cMainGame()
{
	srand(time(NULL));
	m_cWind.Setup();
	
	m_nSocre = 0;

	g_pImageManager->AddImage("Player", "images/Player.bmp", 40, 40, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Arrow", "images/Arrow.bmp", 40, 5, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Target", "images/Target.bmp", 20, 120, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("AnotherTarget", "images/AnotherTarget.bmp", 150, 150, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Spot", "images/Spot.bmp", 10, 10, true, RGB(255, 0, 255));

}

cMainGame::~cMainGame()
{
	
}

void cMainGame::Setup()
{
	m_cWind.Setup();
}

void cMainGame::Update()
{
	cGameNode::Update();
	switch (m_GameState)
	{
	case GAME_READY:
		Reset();
		SystemEnter();
		m_cWind.Setup();
		break;
	case GAME_COUNT:
		Reset();
		SystemEnter();
		break;
	case GAME_PLAYING:
		Gameend();
		m_cTarget.Update();
		ShootArrow();
		m_cArrow.Update();
		RepeatGame();
		HitTarget();
		break;
	case GAME_OVER:
		SystemEnter();
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
		WindChoiceRender();
		m_cPlayer.Render();
		m_cTarget.Render();
		m_cArrow.Render();
		break;
	case GAME_COUNT:
		AllRender();
		GameStartRender();
		m_cPlayer.Render();
		m_cTarget.Render();
		m_cArrow.Render();
		break;
	case GAME_PLAYING:
		AllRender();
		m_cPlayer.Render();
		m_cTarget.Render();
		m_cArrow.Render();
		break;
	case GAME_OVER:
		GameoverRender();
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
	m_cTarget.Setup();
	m_cArrow.SetPlayer(&m_cPlayer);
	m_cArrow.Setup();
}

void cMainGame::GameStartRender()
{
	char str[128];
	sprintf_s(str, "Enter to Start","Enter to Start");
	TextOut(g_hDC, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
}

void cMainGame::WindChoiceRender()
{
	char str[128];
	sprintf_s(str, "바람 정하기!", "바람 정하기!");
	TextOut(g_hDC, WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
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
			m_GameState = GAME_PLAYING;
			break;
		case GAME_PLAYING:
			break;
		case GAME_OVER:
			m_GameState = GAME_READY;
#ifdef _DEBUG
			m_cArrow.SetArrowNum(1);
#else
			m_cArrow.SetArrowNum(10);
#endif // _DEBUG

			
			m_nSocre = 0;
			break;
		case GAME_CLEAR:
			break;
		}
	}
}

void cMainGame::ShootArrow()
{
	if (g_pKeyManager->isOnceKeyDown(VK_SPACE)&&m_cArrow.GetArrowStack() > 0)
	{
		m_cArrow.SetSpeedX(5.0f);
		m_cArrow.SetWindSpeed(m_cWind.GetSpeedY());
		m_cArrow.SetArrowNum(m_cArrow.GetArrowNUM() - 1);
		m_cArrow.SetArrowStack(m_cArrow.GetArrowStack() - 1);
	}
}

void cMainGame::RepeatGame()
{
	if (m_cArrow.GetArrowNUM() > 0 && m_cTarget.GetBody().top > WINSIZEY)
	{
		m_GameState = GAME_READY;
	}
}

void cMainGame::AllRender()
{
	char str[128];
	sprintf_s(str, "화살Y변경 값 : %f   점수 : %d", m_cWind.GetSpeedY(),m_nSocre);
	TextOut(g_hDC, 10, 30, str, strlen(str));
}

void cMainGame::HitTarget()
{
	RECT rt;
	if (IntersectRect(&rt, &m_cArrow.GetBody(), &m_cTarget.GetBody()))
	{
		m_fDist = m_cTarget.GetPosY() - m_cArrow.GetPosY();
		float tempfDist = abs(m_cTarget.GetPosY() - m_cArrow.GetPosY());

		if (m_cArrow.GetIsActive())
		{
			if (tempfDist < m_cTarget.GetsizeH() * 0.1f)
			{
				m_nSocre += 100;
			}
			else if (tempfDist < m_cTarget.GetsizeH() * 0.2f)
			{
				m_nSocre += 80;
			}
			else if (tempfDist < m_cTarget.GetsizeH() * 0.3f)
			{
				m_nSocre += 60;
			}
			else if (tempfDist < m_cTarget.GetsizeH() * 0.4f)
			{
				m_nSocre += 40;
			}
			else if (tempfDist < m_cTarget.GetsizeH() * 0.5f)
			{
				m_nSocre += 20;
			}
			else if (tempfDist <= m_cTarget.GetsizeH() * 0.6f)
			{
				m_nSocre += 0;
			}
			m_cTarget.SetHitPointX(m_fDist);
		}
			m_cArrow.SetIsActive(false);
		
	}
}

void cMainGame::Gameend()
{
	if (m_cArrow.GetArrowNUM() == 0 && m_cTarget.GetBody().top > WINSIZEY)
	{
		m_GameState = GAME_OVER;
	}
}

void cMainGame::GameoverRender()
{
	char str[128];
	sprintf_s(str, "최종 점수 : %d",m_nSocre);
	TextOut(g_hDC, WINSIZEX / 2 ,WINSIZEY / 2, str, strlen(str));
}
