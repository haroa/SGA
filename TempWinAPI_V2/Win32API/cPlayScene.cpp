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

	//char* str = g_pIniData->LoadDataString("ClassData", "�����", "�ּ�ȣ");
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2 - 50, str, strlen(str));

	//int age = g_pIniData->LoadDataInteger("ClassData", "�����", "�ֵ�ö");
	//char szBuf[128];
	//str = itoa(age, szBuf, 10);
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, str, strlen(str));
}

void cPlayScene::Release()
{

}

void cPlayScene::LoadImageFromFile()
{
	/* ��ü ��� */


	/* �� */

	/* �̴ϸ�(�� ��Ʈ��) - ���� �� �������� 1/5 ������� �����. */
	

	/* ���α׷����� */
	

	/* �÷��̾� */
	
}

void cPlayScene::MiniMapRender()
{
	/* ��� �͵��� �̴ϸ� ������� ����ؼ� �׸���. */

	// ����� ���� �׸���.


	// ���� ������ �׸���.
	

	// �÷��̾� ��ġ

	
}