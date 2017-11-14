#include "stdafx.h"
#include "cMainGame.h"





cMainGame::cMainGame()
{
	g_pImageManager->AddImage("background", "images/2048bg.bmp", 640, 920);
	g_pImageManager->AddImage("2", "images/2.bmp", 100, 100);
	g_pImageManager->AddImage("4", "images/4.bmp", 100, 100);
	g_pImageManager->AddImage("8", "images/8.bmp", 100, 100);
	g_pImageManager->AddImage("16", "images/16.bmp", 100, 100);
	g_pImageManager->AddImage("32", "images/32.bmp", 100, 100);
	g_pImageManager->AddImage("64", "images/64.bmp", 100, 100);
	g_pImageManager->AddImage("128", "images/128.bmp", 100, 100);
	g_pImageManager->AddImage("256", "images/256.bmp", 100, 100);
	g_pImageManager->AddImage("512", "images/512.bmp", 100, 100);
	g_pImageManager->AddImage("1024", "images/1024.bmp", 100, 100);
	g_pImageManager->AddImage("2048", "images/2048.bmp", 100, 100);
	g_pImageManager->AddImage("score", "images/score.bmp", 500, 50, true, RGB(255, 0, 255));
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
		SystemEnter();
		m_cGameScene.Update();
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

void cMainGame::Render()
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(g_hWnd, &ps);
	
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	
	switch (m_GameState)
	{
	case GAME_READY:
		m_cGameScene.Render();
		break;
	case GAME_COUNT:
		break;
	case GAME_PLAYING:
		break;
	case GAME_OVER:
		break;
	case GAME_CLEAR:
		break;
	default:
		break;
	}

	g_pTimeManager->Render();
	m_pImgBackBuffer->Render(hdc);

	EndPaint(g_hWnd, &ps);
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

void cMainGame::RepeatGame()
{

}

void cMainGame::AllRender()
{

}