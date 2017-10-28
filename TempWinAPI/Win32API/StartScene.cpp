#include "stdafx.h"
#include "StartScene.h"


StartScene::StartScene()
{
	m_pImage = g_pImageManager->FindImage("start");
}


StartScene::~StartScene()
{

}

void StartScene::Setup()
{
	m_pImage = g_pImageManager->FindImage("start");
}

void StartScene::Update()
{

}

void StartScene::Render()
{
	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC,0,0,800,600);
	}
}
