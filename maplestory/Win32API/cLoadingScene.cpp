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
	for (int i = 0; i < 40; ++i)
	{
		str = itoa(i, szBuf, 10);
		g_pImageManager->ReleaseImage(str);
	}

	// ���� ��ü���� �ʿ��� ���ҽ��� Ÿ��Ʋ �� �ε����� ���� �ε��Ѵ�.
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:
		for (int i = 0; i < 20; ++i)
		{
			str = itoa(i, szBuf, 10);

			m_pLoading->LoadEmpty(str, WINSIZEX, WINSIZEY);
		}
		//Ÿ��Ʋ������ �ʿ��� �̹��� �ε� �ϴ� ��
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
		//Ÿ��Ʋ������ �ʿ��� �̹��� �ε� �ϴ� ��
		//==========================================================================================================
		//��
		m_pLoading->LoadImageFile("MapleTownBG", "images/MapleStory_field.bmp", 2000, 1500, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("MapleCollTown", "images/MapleStory_field(magenta).bmp", 2000, 1500);
		m_pLoading->LoadEmpty("MappBuffer", 2000, 1500);
		//==========================================================================================================
		//����UI
		m_pLoading->LoadImageFile("UI", "images/UI.bmp", 800, 68, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("progressback", "images/progressBarBack1.bmp", 118, 16, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Hpbar", "images/hpBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Mpbar", "images/mpBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadImageFile("Expbar", "images/expBarFront.bmp", 105, 14, true, RGB(255, 0, 255));
		m_pLoading->LoadFrameImage("Player", "images/Player.bmp", 500, 1200, 5, 12, true, RGB(255, 0, 255));
		//==========================================================================================================
		//����
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
	// ���� ��ü���� �ʿ��� ���ҽ��� Ÿ��Ʋ �� �ε����� ���� �ε��Ѵ�.
	switch (g_pSceneManager->GetNextScene())
	{
	case SLIST_TITLE:
		//�������� �ʿ��� ���� �ε� �ϴ� �� (��������� ���� ó�� �ε�!!!!!!!!!) - �ȱ׷��� ����
		
		//Ÿ��Ʋ������ �ʿ��� ���� �ε� �ϴ� ��
	

		//====================================
		break;
	default:
		break;
	}
}
