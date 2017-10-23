#include "stdafx.h"
#include "LobbyScene.h"
#include "SpritesObject.h"

LobbyScene::LobbyScene(E_GAME_STATE* State)
{
    SyncGameState(State);
    LoadImageResources();
    Setup();
}


LobbyScene::~LobbyScene()
{
}

void LobbyScene::Update()
{
}

void LobbyScene::Render()
{
	m_t->Render();
}

void LobbyScene::Setup()
{
	m_t = new SpritesObject;
	m_t->SetBodyImg(g_pImgManager->FindImage("test"));
	m_t->SetupForSprites(1, 1);
	m_t->SetBodyPos({ 100.0f , 100.0f });
	m_t->SetBodySize({ 100, 100 });
	m_t->SetBodyRect(g_pDrawHelper->MakeRect(m_t->GetPos(), m_t->GetSize()));
}

void LobbyScene::LoadImageResources()
{
	g_pImgManager->AddImage("test", "images/test.bmp", 100, 100);
}

void LobbyScene::DeleteScene()
{
}
