#include "stdafx.h"
#include "cTitleScene.h"


void cTitleScene::Setup()
{
}

void cTitleScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		g_pSceneManager->SetNextScene(SLIST_PLAY);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
		PostQuitMessage(0);
}

void cTitleScene::Render()
{

}

void cTitleScene::Release()
{
}
