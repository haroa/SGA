#include "stdafx.h"
#include "cPlayScene.h"

cPlayScene::cPlayScene()
{
}


cPlayScene::~cPlayScene()
{
}

void cPlayScene::Setup()
{
	LoadImageFromFile();

}

void cPlayScene::Update()
{

	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->ChangeScene("Title");
	}
}

void cPlayScene::Render()
{
	



	MiniMapRender();

	//char* str = g_pIniData->LoadDataString("ClassData", "국기반", "최수호");
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2 - 50, str, strlen(str));

	//int age = g_pIniData->LoadDataInteger("ClassData", "국기반", "최동철");
	//char szBuf[128];
	//str = itoa(age, szBuf, 10);
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, str, strlen(str));
}

void cPlayScene::Release()
{

}

void cPlayScene::LoadImageFromFile()
{
	/* 전체 배경 */


	/* 맵 */

	/* 미니맵(빈 비트맵) - 원본 맵 사이즈의 1/5 사이즈로 만든다. */
	

	/* 프로그레스바 */
	

	/* 플레이어 */
	
}

void cPlayScene::MiniMapRender()
{
	/* 모든 것들을 미니맵 사이즈로 축소해서 그린다. */

	// 배경을 먼저 그린다.


	// 지형 지물을 그린다.
	

	// 플레이어 위치

	
}