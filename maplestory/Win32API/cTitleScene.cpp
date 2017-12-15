#include "stdafx.h"
#include "cTitleScene.h"

void cTitleScene::Setup()
{
	m_ImgTitleBG = g_pImageManager->FindImage("Start");
	m_rtChangeScene = RectMake(454, 280, 50, 50);
	m_rtExit = RectMake(435, 353, 65, 33);
	m_cCursor.Setup();
}

void cTitleScene::Update()
{
	m_cCursor.Update();

	if (g_pKeyManager->isOnceKeyUp(VK_LBUTTON))
	{
		ChangeScene();
		Exit();
	}
}

void cTitleScene::Render()
{
	m_ImgTitleBG->Render(g_hDC, 0, 0);
	//RectangleMake(g_hDC, m_rtChangeScene);
	//RectangleMake(g_hDC, m_rtExit);
	m_cCursor.Render();
}

void cTitleScene::Release()
{

}

void cTitleScene::ChangeScene()
{
	if (PtInRect(&m_rtChangeScene, g_ptMouse))
	{
		g_pSceneManager->SetNextScene(SLIST_PANTHEONTOWN);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
}

void cTitleScene::Exit()
{
	if (PtInRect(&m_rtExit, g_ptMouse))
	{
		PostQuitMessage(0);
	}
}
