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
	m_f->Render();

}

void GameScene::Setup()
{
	m_f = new SpritesObject;
	m_f->SetBodyImg(g_pImgManager->FindImage("Game"));
	m_f->SetupForSprites(1, 1);
	m_f->SetBodyPos({ W_WIDTH * 0.5f,W_HEIGHT * 0.5f });
	m_f->SetBodySize({ 100,100 });
	m_f->SetBodyRect(g_pDrawHelper->MakeRect(m_f->GetPos(), m_f->GetSize()));
}

void GameScene::LoadImageResources()
{
	g_pImgManager->AddImage("Game", "images/Game.bmp", 100, 100);
}

void GameScene::DeleteScene()
{
}