#include "stdafx.h"
#include "cMainGame.h"





cMainGame::cMainGame()
{
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
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	
	switch (m_GameState)
	{
	case GAME_READY:
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