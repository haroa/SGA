#include "stdafx.h"
#include "cPlayScene.h"




void cPlayScene::Setup()
{
	m_cMap.Setup();
	m_cPlayer.Setup();
	m_cUi.Setup();
	JsonLoad();
}

void cPlayScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
		g_pSceneManager->ChangeScene(SLIST_LOADING);

	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->ChangeScene(SLIST_TITLE);
	}
	m_cPlayer.Update();
	CollisoinRect();
}

void cPlayScene::Render()
{
	//TextOut(g_hDC, 100, 100, "플레이화면", strlen("플레이화면"));
	m_cMap.Render();
	m_cUi.Render();
	m_cPlayer.Render();
}

void cPlayScene::Release()
{
}

void cPlayScene::CollisoinRect()
{
	RECT rt1;
	if (IntersectRect(&rt1, &m_cMap.GetPotion(), &m_cPlayer.GetBody()))
	{
		JsonSave();
		g_pSceneManager->ChangeScene(SLIST_POTIONSHOP);
		m_cPlayer.SetPosX(WINSIZEX * 0.5f);
		m_cPlayer.SetPosY(WINSIZEY * 0.5f);
	}

	RECT rt2;
	if (IntersectRect(&rt2, &m_cMap.GetWeapon(), &m_cPlayer.GetBody()))
	{
		JsonSave();
		g_pSceneManager->ChangeScene(SLIST_WEAPONSHOP);
		m_cPlayer.SetPosX(WINSIZEX * 0.5f);
		m_cPlayer.SetPosY(WINSIZEY * 0.5f);
	}

	RECT rt3;
	if (IntersectRect(&rt3, &m_cMap.GetDungeon1(), &m_cPlayer.GetBody()))
	{
		JsonSave();
		g_pSceneManager->SetNextScene(SLIST_DUNGEON1);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
		m_cPlayer.SetPosX(WINSIZEX * 0.5f);
		m_cPlayer.SetPosY(WINSIZEY * 0.5f);
	}

	RECT rt4;
	if (IntersectRect(&rt4, &m_cMap.GetDungeon2(), &m_cPlayer.GetBody()))
	{
		JsonSave();
		g_pSceneManager->SetNextScene(SLIST_DUNGEON2);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
		m_cPlayer.SetPosX(WINSIZEX * 0.5f);
		m_cPlayer.SetPosY(WINSIZEY * 0.5f);
	}
}

void cPlayScene::JsonSave()
{
	json savedata;
	savedata["Player"]["money"] = m_cUi.GetMoney();
	savedata["Player"]["potion1"] = m_cUi.GetPotion1();
	savedata["Player"]["potion2"] = m_cUi.GetPotion2();
	savedata["Player"]["atk"] = m_cUi.GetAtk();
	savedata["Player"]["def"] = m_cUi.GetDef();
	savedata["Player"]["hp"] = m_cUi.GetHp();
	g_pFileManager->JsonSave(JSON_PATH, savedata.dump());
}

void cPlayScene::JsonLoad()
{
	json loaddata;
	g_pFileManager->JsonLoad("savedata", JSON_PATH);
	loaddata = g_pFileManager->JsonFind("savedata");
	m_cUi.SetMoney(loaddata["Player"]["money"]);
	m_cUi.SetPotion1(loaddata["Player"]["potion1"]);
	m_cUi.SetPotion2(loaddata["Player"]["potion2"]);
	m_cUi.SetAtk(loaddata["Player"]["atk"]);
	m_cUi.SetDef(loaddata["Player"]["def"]);
	m_cUi.SetHp(loaddata["Player"]["hp"]);
	g_pFileManager->JsonRelease("savedata");
}