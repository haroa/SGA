#include "stdafx.h"
#include "cWeaponshop.h"


void cWeaponshop::Setup()
{
	m_cUi.Setup();
	JsonLoad();
	m_fWeaponX = 80;
	m_fWeaponY = 80;
	m_rtWeaponui = RectMake(m_fWeaponX, m_fWeaponY, 600, 400);

	m_fWeapon1X = 100;
	m_fWeapon1Y = 100;
	m_rtWeapon1 = RectMake(m_fWeapon1X, m_fWeapon1Y, 500, 50);

	m_fWeapon2X = 100;
	m_fWeaponY = 200;
	m_rtWeapon2 = RectMake(m_fWeapon2X, m_fWeaponY, 500, 50);

	m_fArmor1X = 100;
	m_fArmor1Y = 300;
	m_rtArmor1 = RectMake(m_fArmor1X, m_fArmor1Y, 500, 50);
	 
	m_fArmor2X = 100;
	m_fArmor2Y = 400;
	m_rtArmor2 = RectMake(m_fArmor2X, m_fArmor2Y, 500, 50);
}

void cWeaponshop::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		JsonSave();
		g_pSceneManager->ChangeScene(SLIST_PLAY);
	}
	Collision();
}

void cWeaponshop::Render()
{
	TextOut(g_hDC, 100, 100, "장비", strlen("장비"));
	Rectangle(g_hDC, m_rtWeaponui.left, m_rtWeaponui.top, m_rtWeaponui.right, m_rtWeaponui.bottom);
	Rectangle(g_hDC, m_rtWeapon1.left, m_rtWeapon1.top, m_rtWeapon1.right, m_rtWeapon1.bottom);
	Rectangle(g_hDC, m_rtWeapon2.left, m_rtWeapon2.top, m_rtWeapon2.right, m_rtWeapon2.bottom);
	Rectangle(g_hDC, m_rtArmor1.left, m_rtArmor1.top, m_rtArmor1.right, m_rtArmor1.bottom);
	Rectangle(g_hDC, m_rtArmor2.left, m_rtArmor2.top, m_rtArmor2.right, m_rtArmor2.bottom);
	TextOut(g_hDC, 125, 125, "찬혁툴의 검 - 공격력 : 4 - 가격 : 500원", strlen("찬혁툴의 검 - 공격력 : 4 - 가격 : 500원"));
	TextOut(g_hDC, 125, 225, "동냐의 쌍검 - 공격력 : 10 - 가격 : 1000원", strlen("동냐의 쌍검 - 공격력 : 10 - 가격 : 1000원"));
	TextOut(g_hDC, 125, 325, "성준의 적응형투구 - 방어력 : 8 - 가격 : 1000원", strlen("성준의 적응형투구 - 방어력 : 8 - 가격 : 1000원"));
	TextOut(g_hDC, 125, 425, "유진의 얼음방패 - 방어력 : 15 - 가격 : 5000원", strlen("유진의 얼음방패 - 방어력 : 15 - 가격 : 5000원"));
	m_cUi.Render();
}

void cWeaponshop::Release()
{
}

void cWeaponshop::Collision()
{
	if (PtInRect(&m_rtWeapon1, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 500);
			m_cUi.SetAtk(m_cUi.GetAtk() + 4);
		}
	}
	if (PtInRect(&m_rtWeapon2, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 1000);
			m_cUi.SetAtk(m_cUi.GetAtk() + 10);
		}
	}
	if (PtInRect(&m_rtArmor1, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 1000);
			m_cUi.SetDef(m_cUi.GetDef() + 8);
		}
	}
	if (PtInRect(&m_rtArmor2, g_ptMouse))
	{
		if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON))
		{
			m_cUi.SetMoney(m_cUi.GetMoney() - 5000);
			m_cUi.SetDef(m_cUi.GetDef() + 15);
		}
	}
}

void cWeaponshop::JsonSave()
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

void cWeaponshop::JsonLoad()
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
