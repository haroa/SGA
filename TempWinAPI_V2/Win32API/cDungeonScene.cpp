#include "stdafx.h"
#include "cDungeonScene.h"


void cDungeonScene::Setup()
{
}

void cDungeonScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
		g_pSceneManager->ChangeScene(SLIST_LOADING);
}

void cDungeonScene::Render()
{
}

void cDungeonScene::Release()
{
}
