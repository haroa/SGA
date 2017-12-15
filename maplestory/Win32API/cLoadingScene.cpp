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
	// m_pLoading->LoadingDone() : 실질 적인 리소스 로딩과 프로그레스바 업데이트
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

	/* ==== 리소스 해제 ===== */
	for (int i = 0; i < 40; ++i)
	{
		str = itoa(i, szBuf, 10);
		g_pImageManager->ReleaseImage(str);
	}

	// 게임 전체에서 필요한 리소스는 타이틀 씬 로딩에서 전부 로드한다.
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:
		for (int i = 0; i < 20; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		//타이틀씬에서 필요한 이미지 로드 하는 곳
		m_pLoading->LoadImageFile("Start", "images/MapleStory_Start.bmp", 800, 600, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Cursor", "images/Cursor.bmp", 160, 40, 4, 1, true, RGB(255, 0, 255));
		//====================================
		break;
	case SLIST_PANTHEONTOWN:
		for (int i = 20; i < 40; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		//타이틀씬에서 필요한 이미지 로드 하는 곳
		//==========================================================================================================
		//맵
		m_pLoading->LoadImageFile("MapleTownBG", "images/MapleStory_field.bmp", 2000, 1500, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("MapleCollTown", "images/MapleStory_field(magenta).bmp", 2000, 1500);
		m_pLoading->LoadEmpty("MappBuffer", 2000, 1500);
		//==========================================================================================================
		//게임UI
		m_pLoading->LoadImageFile("UI", "images/UI.bmp", 800, 68, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("progressback", "images/progressBarBack1.bmp", 118, 16, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Hpbar", "images/hpBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Mpbar", "images/mpBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Expbar", "images/expBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Player", "images/Player.bmp", 500, 1200, 5, 12, true, RGB(255, 0, 255));
		//==========================================================================================================
		//몬스터
		m_pLoading->LoadFrameImage("Orangemushroom", "images/orangemushroom.bmp", 210, 560, 3, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Mushroom", "images/mushroom.bmp", 200, 400, 4, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Greensnail", "images/green.bmp", 405, 360, 9, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Curseeye", "images/curseeye.bmp", 600, 1200, 4, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Evileye", "images/evileye.bmp", 600, 1200, 4, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Pig", "images/pig.bmp", 210, 560, 3, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Ribbonpig", "images/ribbonpig.bmp", 210, 560, 3, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Stonegolem", "images/stonegolem.bmp", 1750, 2000, 7, 8, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Mixgolem", "images/mixgolem.bmp", 1750, 2000, 7, 8, true, RGB(255, 0, 255));
		//====================================
		break;
	default:
		break;
	}
}

void cLoadingScene::LoadingSound()
{
	// 게임 전체에서 필요한 리소스는 타이틀 씬 로딩에서 전부 로드한다.
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:
		//모든씬에서 필요한 사운드 로드 하는 곳 (고정사운드는 제일 처음 로드!!!!!!!!!) - 안그러면 터짐
		
		//타이틀씬에서 필요한 사운드 로드 하는 곳
	

		//====================================
		break;
	default:
		break;
	}
}
