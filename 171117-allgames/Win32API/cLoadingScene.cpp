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
		g_pSceneManager->ChangeScene(g_pSceneManager->GetNextScene());
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
	char szBuf[32];
	char* str;

	/* ==== ���ҽ� ���� ===== */
	for (int i = 100; i < 200; ++i)
	{
		str = itoa(i, szBuf, 10);
		g_pImageManager->ReleaseImage(str);
	}
	/* ====================== */

	// ���� ��ü���� �ʿ��� ���ҽ��� Ÿ��Ʋ �� �ε����� ���� �ε��Ѵ�.
	if (g_pSceneManager->GetNextScene() == SLIST_TITLE)
	{
		for (int i = 0; i < 100; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
	}
	else if (g_pSceneManager->GetNextScene() == SLIST_Omok)
	{
		for (int i = 100; i < 200; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		m_pLoading->LoadImageFile("omokbg", "images/omokbg.bmp", 800, 800);
		m_pLoading->LoadFrameImage("omok", "images/omok.bmp", 30, 60, 1, 2, true, RGB(255, 0, 255));
	}
	else if (g_pSceneManager->GetNextScene() == SLIST_RUNGAME)
	{
		for (int i = 200; i < 300; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		m_pLoading->LoadImageFile("omokbg", "images/omokbg.bmp", 800, 800);
		m_pLoading->LoadFrameImage("omok", "images/omok.bmp", 30, 60, 1, 2, true, RGB(255, 0, 255));
	}
	else if (g_pSceneManager->GetNextScene() == SLIST_SUPERMARIO)
	{
		for (int i = 300; i < 400; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		m_pLoading->LoadImageFile("omokbg", "images/omokbg.bmp", 800, 800);
		m_pLoading->LoadFrameImage("omok", "images/omok.bmp", 30, 60, 1, 2, true, RGB(255, 0, 255));
	}
	else if (g_pSceneManager->GetNextScene() == SLIST_SHOOTINGGAME)
	{
		for (int i = 400; i < 500; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		m_pLoading->LoadImageFile("omokbg", "images/omokbg.bmp", 800, 800);
		m_pLoading->LoadFrameImage("omok", "images/omok.bmp", 30, 60, 1, 2, true, RGB(255, 0, 255));
	}
}

void cLoadingScene::LoadingSound()
{
	if (g_pSceneManager->GetNextScene() == SLIST_Omok)
	{
		m_pLoading->LoadSound("Dungeon1_BGM", "sounds/Angel Attack.mp3", true, true);
		m_pLoading->LoadSound("Sword_1", "sounds/Sword_1.mp3",false,false);
	}
}
