#include "stdafx.h"
#include "cDungeon2.h"


void cDungeon2::Setup()
{
	m_cUi.Setup();
	m_cPlayer.Setup();
	JsonLoad();
	m_fMonster1X = 200;
	m_fMonster1Y = 200;
	m_rtMonster1 = RectMake(m_fMonster1X, m_fMonster1Y, 60, 60);

	m_fMonster2X = 600;
	m_fMonster2Y = 400;
	m_rtMonster2 = RectMake(m_fMonster2X, m_fMonster2Y, 60, 60);

	m_fMonster3X = 500;
	m_fMonster3Y = 500;
	m_rtMonster3 = RectMake(m_fMonster3X, m_fMonster3Y, 60, 60);
}

void cDungeon2::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		JsonSave();
		g_pSceneManager->SetNextScene(SLIST_PLAY);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
		m_cPlayer.SetPosX(WINSIZEX * 0.5f);
		m_cPlayer.SetPosY(WINSIZEY * 0.5f);
	}
	else if (g_pKeyManager->isOnceKeyDown('1'))
	{
		m_cUi.SetPotion1(m_cUi.GetPotion1() - 1);
		m_cUi.SetHp(m_cUi.GetHp() + 10);
	}
	else if (g_pKeyManager->isOnceKeyDown('2'))
	{
		m_cUi.SetPotion2(m_cUi.GetPotion2() - 1);
		m_cUi.SetHp(m_cUi.GetHp() + 20);
	}
	m_cPlayer.Update();
	Collision();
}

void cDungeon2::Render()
{
	//TextOut(g_hDC, 100, 100, "던전1", strlen("던전1"));
	m_cUi.Render();
	m_cPlayer.Render();
	EllipseMake(g_hDC, m_rtMonster1);
	EllipseMake(g_hDC, m_rtMonster2);
	EllipseMake(g_hDC, m_rtMonster3);
}

void cDungeon2::Release()
{
}

void cDungeon2::Collision()
{
	RECT rt1;
	if (IntersectRect(&rt1, &m_cPlayer.GetBody(), &m_rtMonster1))
	{
		m_cUi.SetHp(m_cUi.GetHp() - 10);
		m_cUi.SetMoney(m_cUi.GetMoney() + 500);
		m_rtMonster1 = RectMake(0, 0, 0, 0);
	}
	else if (IntersectRect(&rt1, &m_cPlayer.GetBody(), &m_rtMonster2))
	{
		m_cUi.SetHp(m_cUi.GetHp() - 10);
		m_cUi.SetMoney(m_cUi.GetMoney() + 500);
		m_rtMonster2 = RectMake(0, 0, 0, 0);
	}
	else if (IntersectRect(&rt1, &m_cPlayer.GetBody(), &m_rtMonster3))
	{
		m_cUi.SetHp(m_cUi.GetHp() - 10);
		m_cUi.SetMoney(m_cUi.GetMoney() + 500);
		m_rtMonster3 = RectMake(0, 0, 0, 0);
	}
}

void cDungeon2::JsonSave()
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

void cDungeon2::JsonLoad()
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

