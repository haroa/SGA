#include "stdafx.h"
#include "cMainGame.h"

// �� ������ϵ� �߰�
#include "cTitleScene.h"
#include "cOmok.h"
#include "cRungame.h"
#include "cShootinggame.h"
#include "cSupermario.h"
#include "cLoadingScene.h"

cMainGame::cMainGame()
{
}

cMainGame::~cMainGame()
{
}

void cMainGame::Setup()
{
	// �� �߰�
	g_pSceneManager->AddScene(SLIST_TITLE, new cTitleScene);
	g_pSceneManager->AddScene(SLIST_LOADING, new cLoadingScene);
	g_pSceneManager->AddScene(SLIST_Omok, new cOmok);
	//SLIST_RUNGAME,
	//SLIST_SHOOTINGGAME,
	//SLIST_SUPERMARIO,
	g_pSceneManager->AddScene(SLIST_RUNGAME, new cRungame);
	g_pSceneManager->AddScene(SLIST_SHOOTINGGAME, new cShootinggame);
	g_pSceneManager->AddScene(SLIST_SUPERMARIO, new cSupermario);

	// ó�� ���� �� ����
	g_pSceneManager->ChangeScene(SLIST_LOADING);
}

void cMainGame::Update()
{
	cGameNode::Update();

	g_pSceneManager->Update();
}

void cMainGame::Render()
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(g_hWnd, &ps);

	// ������� �̹����� ĥ�Ѵ�.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	g_pSceneManager->Render();
	g_pTimeManager->Render();
	m_pImgBackBuffer->Render(hdc);

	EndPaint(g_hWnd, &ps);
}

void cMainGame::Release()
{
	g_pKeyManager->ReleaseInstance();
	g_pFileData->ReleaseInstance();
	g_pPixelManager->ReleaseInstance();
	g_pTimeManager->ReleaseInstance();
	g_pIniData->ReleaseInstance();
	g_pImageManager->ReleaseInstance();
	g_pSceneManager->ReleaseInstance();
	g_pSoundManager->ReleaseInstance();
}
