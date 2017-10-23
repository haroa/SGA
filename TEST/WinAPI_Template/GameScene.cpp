#include "stdafx.h"
#include "GameScene.h"
#include "SpritesObject.h"

GameScene::GameScene(E_GAME_STATE* State)
{
    SyncGameState(State);
    LoadImageResources();
	Setup();
}


GameScene::~GameScene()
{
}

void GameScene::Update()
{
}

void GameScene::Render()
{
#ifdef _DEBUG
   // char infoMsg[128];
   // sprintf_s(infoMsg, "");
   // TextOut(g_hDC, 0, 30, infoMsg, (int)strlen(infoMsg));
#endif // _DEBUG
	m_spritestest->Render();

}

void GameScene::Setup()
{
	m_spritestest = new SpritesObject;
	m_spritestest->SetBodyImg(g_pImgManager->FindImage("Game"));
	m_spritestest->SetupForSprites(1, 1);
	m_spritestest->SetBodyPos({ W_WIDTH * 0.5f,W_HEIGHT * 0.5f });
	m_spritestest->SetBodySize({ 100,100 });
	m_spritestest->SetBodyRect(g_pDrawHelper->MakeRect(m_spritestest->GetPos(), m_spritestest->GetSize()));
}

void GameScene::LoadImageResources()
{
	g_pImgManager->AddImage("Game", "images/Game.bmp", 100, 100);
}

void GameScene::DeleteScene()
{
}