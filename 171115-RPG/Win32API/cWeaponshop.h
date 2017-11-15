#pragma once
#include "cGameNode.h"
#include "cUi.h"
class cWeaponshop :public cGameNode
{
private:
	cUi m_cUi;

	RECT m_rtWeaponui;
	float m_fWeaponX;
	float m_fWeaponY;

	float m_fWeapon1X;
	float m_fWeapon1Y;
	RECT m_rtWeapon1;

	float m_fWeapon2X;
	float m_fPotion2Y;
	RECT m_rtWeapon2;

	float m_fArmor1X;
	float m_fArmor1Y;
	RECT m_rtArmor1;

	float m_fArmor2X;
	float m_fArmor2Y;
	RECT m_rtArmor2;
private:
	void Collision();
	void JsonSave();
	void JsonLoad();
public:
	cWeaponshop() {};
	virtual ~cWeaponshop() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

