#include "stdafx.h"
#include "cLoadingScene.h"


void cLoadingScene::Setup()
{
	m_pLoading = new cLoading;
	m_pLoading->Setup();

	LoadingImage();
	LoadingSound();
}

void cLoadingScene::Update()
{
	// m_pLoading->LoadingDone() : ���� ���� ���ҽ� �ε��� ���α׷����� ������Ʈ
	if (m_pLoading->LoadingDone())
	{
		g_pSceneManager->ChangeScene(SLIST_PLAY);

		//if (g_pSceneManager->GetCurrScene() == SLIST_TITLE)
		//	g_pSceneManager->ChangeScene(SLIST_PLAY);
		//else if (g_pSceneManager->GetCurrScene() == SLIST_PLAY)
		//	g_pSceneManager->ChangeScene(SLIST_DUNGEON);
		//else if (g_pSceneManager->GetCurrScene() == SLIST_DUNGEON)
		//	g_pSceneManager->ChangeScene(SLIST_PLAY);
	}
}

void cLoadingScene::Render()
{
	m_pLoading->Render();
}

void cLoadingScene::Release()
{
	SAFE_DELETE(m_pLoading);
}

void cLoadingScene::LoadingImage()
{
	m_pLoading->LoadFrameImage("numbers", "images/numbers.bmp", 1100, 100, 11, 1, true, RGB(255, 0, 255));

	char szBuf[32];
	char* str;

	for (int i = 0; i < 300; ++i)
	{
		str = itoa(i, szBuf, 10);

		m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
	}
}

void cLoadingScene::LoadingSound()
{
}
