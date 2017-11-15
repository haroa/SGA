#include "stdafx.h"
#include "cDungeon2.h"


void cDungeon2::Setup()
{
	m_cUi.Setup();
}

void cDungeon2::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->ChangeScene(SLIST_PLAY);
	}
}

void cDungeon2::Render()
{
	TextOut(g_hDC, 100, 100, "던전2", strlen("던전2"));
	m_cUi.Render();
}

void cDungeon2::Release()
{
}
