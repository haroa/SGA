#pragma once
#include "cGameobject.h"

class cMap : public cGameobject
{
private:
	RECT m_rtPotion;
	RECT m_rtWeapon;
	RECT m_rtDungeon1;
	RECT m_rtDungeon2;

	float m_PotionX;
	float m_PotionY;
	float m_WeaponX;
	float m_WeaponY;
	float m_Dungeon1X;
	float m_Dungeon1Y;
	float m_Dungeon2X;
	float m_Dungeon2Y;


public:
	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();

	RECT GetPotion() { return m_rtPotion; }
	RECT GetWeapon() { return m_rtWeapon; }
	RECT GetDungeon1() { return m_rtDungeon1; }
	RECT GetDungeon2() { return m_rtDungeon2; }
};

