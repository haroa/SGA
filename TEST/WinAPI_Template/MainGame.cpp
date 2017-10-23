#include "stdafx.h"
#include "MainGame.h"

MainGame::MainGame()
{
    LoadAllResources();
    Start();
}


MainGame::~MainGame()
{
}

void MainGame::Start()
{



}

void MainGame::Update()
{
    GameNode::Update();
	switch (m_Gamestate)
	{
	case GAME_READY:
		m_LobbyScene = new LobbyScene(NULL);
		g_pScnManager->AddGameObjToScn("lobby", m_LobbyScene);
		SystemControl();
		break;
	case GAME_PLAYING:
		m_GameScene = new GameScene(NULL);
		g_pScnManager->AddGameObjToScn("Game", m_GameScene);
		break;
	case GAME_PAUSE:
		break;
	case GAME_CLEAR:
		break;
	case GAME_OVER:
		break;
	}
}

void MainGame::Render()
{
    PatBlt(g_hDC, 0, 0, W_WIDTH, W_HEIGHT, BLACKNESS);
	switch (m_Gamestate)
	{
	case GAME_READY:
		g_pScnManager->Render("lobby");
		break;
	case GAME_PLAYING:
		g_pScnManager->Render("Game");
		break;
	case GAME_PAUSE:
		break;
	case GAME_CLEAR:
		break;
	case GAME_OVER:
		break;
	}
}

void MainGame::Reset()
{
}

void MainGame::LoadAllResources()
{
    LoadImageResources();
    LoadSoundResources();
}

void MainGame::LoadImageResources()
{
}

void MainGame::LoadSoundResources()
{
}

void MainGame::SystemControl()
{
	if (g_pKeyManager->isStayKeyDown(VK_RETURN))
	{
		switch (m_Gamestate)
		{
		case GAME_READY:
			m_Gamestate = GAME_PLAYING;
			break;
		case GAME_PLAYING:
			break;
		case GAME_PAUSE:
			break;
		case GAME_CLEAR:
			break;
		case GAME_OVER:
			break;
		}
	}
}
