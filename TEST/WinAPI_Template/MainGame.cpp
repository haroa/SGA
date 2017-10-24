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

	SetupScene();

}

void MainGame::Update()
{
    GameNode::Update();
	switch (m_gamestate)
	{
	case GAME_READY:	
		SystemControl();
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

void MainGame::Render()
{
    PatBlt(g_hDC, 0, 0, W_WIDTH, W_HEIGHT, WHITENESS);
	switch (m_gamestate)
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

void MainGame::SetupScene()
{
	m_lobbyScene = new LobbyScene(&m_gamestate);
	g_pScnManager->AddGameObjToScn("lobby", m_lobbyScene);

	m_gameScene = new GameScene(&m_gamestate);
	g_pScnManager->AddGameObjToScn("Game", m_gameScene);
}

void MainGame::SystemControl()
{
	if (g_pKeyManager->isStayKeyDown(VK_RETURN))
	{
		switch (m_gamestate)
		{
		case GAME_READY:
			m_gamestate = GAME_PLAYING;
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
