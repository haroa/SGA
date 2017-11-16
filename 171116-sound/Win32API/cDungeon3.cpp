#include "stdafx.h"
#include "cDungeon3.h"


void cDungeon3::Setup()
{
}

void cDungeon3::Update()
{
	if (g_pKeyManager->isOnceKeyDown('1'))
	{
		g_pSceneManager->SetNextScene(SLIST_DUNGEON1);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown('2'))
	{
		g_pSceneManager->SetNextScene(SLIST_DUNGEON2);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown('3'))
	{
		g_pSceneManager->SetNextScene(SLIST_TITLE);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
		PostQuitMessage(0);
}

void cDungeon3::Render()
{
	TextOut(g_hDC, 100, 100, "3¹ø¾À", strlen("3¹ø¾À"));
}

void cDungeon3::Release()
{
}
