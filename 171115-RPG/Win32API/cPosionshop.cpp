#include "stdafx.h"
#include "cPosionshop.h"


void cPosionshop::Setup()
{
	m_cUi.Setup();

	m_fPotionX = 80;
	m_fPotionY = 80;
	m_rtPotionui = RectMake(m_fPotionX, m_fPotionY, 600, 400);

	m_fPotion1X = 100;
	m_fPotion1Y = 100;
	m_rtPotion1 = RectMake(m_fPotion1X, m_fPotion1Y, 500, 50);

	m_fPotion2X = 100;
	m_fPotion2Y = 300;
	m_rtPotion2 = RectMake(m_fPotion2X, m_fPotion2Y, 500, 50);

	JsonLoad();
}

void cPosionshop::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		JsonSave();
		g_pSceneManager->ChangeScene(SLIST_PLAY);
	}
	Collision();
}

void cPosionshop::Render()
{
	//TextOut(g_hDC, 100, 100, "포션", strlen("포션"));
	m_cUi.Render();
	Rectangle(g_hDC, m_rtPotionui.left, m_rtPotionui.top, m_rtPotionui.right, m_rtPotionui.bottom);
	Rectangle(g_hDC, m_rtPotion1.left, m_rtPotion1.top, m_rtPotion1.right, m_rtPotion1.bottom);
	Rectangle(g_hDC, m_rtPotion2.left, m_rtPotion2.top, m_rtPotion2.right, m_rtPotion2.bottom);
	TextOut(g_hDC, 125, 125, "포션1 - 갯수 : 무한대 - 가격 : 500원", strlen("포션1 - 갯수 : 무한대 - 가격 : 500원"));
	TextOut(g_hDC, 125, 325, "포션2 - 갯수 : 무한대 - 가격 : 1000원", strlen("포션2 - 갯수 : 무한대 - 가격 : 1000원"));
}

void cPosionshop::Release()
{
}

void cPosionshop::Collision()
{
	if (PtInRect(&m_rtPotion1, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 500);
			m_cUi.SetPotion1(m_cUi.GetPotion1() + 1);
		}
	}
	if (PtInRect(&m_rtPotion2, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 1000);
			m_cUi.SetPotion2(m_cUi.GetPotion2() + 1);
		}
	}
}

void cPosionshop::JsonSave()
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

void cPosionshop::JsonLoad()
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
