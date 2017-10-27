#include "stdafx.h"
#include "cMainGame.h"





cMainGame::cMainGame()
{
	g_pImageManager->AddImage("Map", "images/background.bmp", 3564, 224);
	g_pImageManager->AddImage("Player", "images/Player.bmp", 60,120, 3, 6, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Buffer", 5500, 600)->SetTransColor(true, RGB(255, 0, 255));
	g_pImageManager->AddImage("MiniMap", 550, 60)->SetTransColor(true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Object", "images/Object.bmp", 48, 9, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Object2", "images/Object.bmp", 48, 9, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("goomba", "images/goomba.bmp", 16,16, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("kupa", "images/kupa.bmp", 128, 32,4,1, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("fire", "images/fire.bmp", 24, 16, true, RGB(255, 0, 255));
	Reset();
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
		break;
	case GAME_PLAYING:
		m_cGameScene.Update();
		break;
	case GAME_OVER:
		break;
	case GAME_CLEAR:
		break;
	}

}

void cMainGame::Render()
{
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	switch (m_GameState)
	{
	case GAME_READY:
		m_cGameScene.Render();
		break;
	case GAME_COUNT:
		break;
	case GAME_PLAYING:
		m_cGameScene.Render();
		break;
	case GAME_OVER:
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
	m_cGameScene.Setup();
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
			break;
		case GAME_CLEAR:
			break;
		}
	}
}

void cMainGame::RepeatGame()
{

}

void cMainGame::AllRender()
{

}