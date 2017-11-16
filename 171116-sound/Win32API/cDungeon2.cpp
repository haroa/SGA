#include "stdafx.h"
#include "cDungeon2.h"


void cDungeon2::Setup()
{
	g_pSoundManager->Stop("Dungeon1_BGM");
}

void cDungeon2::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_UP))
	{
		g_pSoundManager->VolumeUp("Dungeon1_BGM");
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_DOWN))
	{
		g_pSoundManager->VolumeDown("Dungeon1_BGM");
	}

	if (g_pKeyManager->isOnceKeyDown('S'))
	{
		if (g_pSoundManager->IsPlaySound("Dungeon1_BGM"))
			g_pSoundManager->Stop("Dungeon1_BGM");
		else
			g_pSoundManager->Play("Dungeon1_BGM");
	}
	else if (g_pKeyManager->isOnceKeyDown('P'))
	{
		if (g_pSoundManager->IsPauseSound("Dungeon1_BGM"))
			g_pSoundManager->Resume("Dungeon1_BGM");
		else
			g_pSoundManager->Pause("Dungeon1_BGM");
	}

	if (g_pKeyManager->isOnceKeyDown('1'))
	{
		g_pSceneManager->SetNextScene(SLIST_DUNGEON1);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown('2'))
	{
		g_pSceneManager->SetNextScene(SLIST_TITLE);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown('3'))
	{
		g_pSceneManager->SetNextScene(SLIST_DUNGEON3);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
		PostQuitMessage(0);
}

void cDungeon2::Render()
{
	TextOut(g_hDC, 100, 100, "2¹ø¾À", strlen("2¹ø¾À"));
}

void cDungeon2::Release()
{
}
