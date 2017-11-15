#include "stdafx.h"
#include "cMap.h"


cMap::cMap()
{
}


cMap::~cMap()
{
}

void cMap::Setup()
{
	m_PotionX = 100;
	m_PotionY = 100;
	m_rtPotion = RectMake(m_PotionX, m_PotionY, 100, 100);
	m_WeaponX = 100;
	m_WeaponY = 400;
	m_rtWeapon = RectMake(m_WeaponX, m_WeaponY, 100, 100);
	m_Dungeon1X = 600;
	m_Dungeon1Y = 100;
	m_rtDungeon1 = RectMake(m_Dungeon1X, m_Dungeon1Y, 100, 100);
	m_Dungeon2X = 600;
	m_Dungeon2Y = 400;
	m_rtDungeon2 = RectMake(m_Dungeon2X, m_Dungeon2Y, 100, 100);
}

void cMap::Update()
{
}

void cMap::Render()
{
	Rectangle(g_hDC, m_rtPotion.left, m_rtPotion.top, m_rtPotion.right, m_rtPotion.bottom);
	Rectangle(g_hDC, m_rtWeapon.left, m_rtWeapon.top, m_rtWeapon.right, m_rtWeapon.bottom);
	Rectangle(g_hDC, m_rtDungeon1.left, m_rtDungeon1.top, m_rtDungeon1.right, m_rtDungeon1.bottom);
	Rectangle(g_hDC, m_rtDungeon2.left, m_rtDungeon2.top, m_rtDungeon2.right, m_rtDungeon2.bottom);
	TextOut(g_hDC, 120, 150, "물약상점", strlen("물약상점"));
	TextOut(g_hDC, 120, 450, "장비상점", strlen("장비상점"));
	TextOut(g_hDC, 630, 150, "던전1", strlen("던전1"));
	TextOut(g_hDC, 630, 450, "던전2", strlen("던전2"));
}
