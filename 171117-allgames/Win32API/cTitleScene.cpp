#include "stdafx.h"
#include "cTitleScene.h"


void cTitleScene::Setup()
{
}

void cTitleScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown('1'))
	{
		g_pSceneManager->SetNextScene(SLIST_Omok);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	if (g_pKeyManager->isOnceKeyDown('2'))
	{
		g_pSceneManager->SetNextScene(SLIST_RUNGAME);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	if (g_pKeyManager->isOnceKeyDown('3'))
	{
		g_pSceneManager->SetNextScene(SLIST_SUPERMARIO);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	if (g_pKeyManager->isOnceKeyDown('4'))
	{
		g_pSceneManager->SetNextScene(SLIST_SHOOTINGGAME);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
		PostQuitMessage(0);
}

void cTitleScene::Render()
{
	TextOut(g_hDC, WINSIZEX / 2 - 300, WINSIZEY / 2, "1.����   2.������   3.���۸�����  4.���ð���", strlen("1.����   2.������   3.���۸�����  4.���ð���"));
}

void cTitleScene::Release()
{
}
