#pragma once
#include "cGameNode.h"
#include "cUi.h"

class cPosionshop :public cGameNode
{
private:
	cUi	m_cUi;

	RECT m_rtPotionui;
	float m_fPotionX;
	float m_fPotionY;

	float m_fPotion1X;
	float m_fPotion1Y;
	RECT m_rtPotion1;

	float m_fPotion2X;
	float m_fPotion2Y;
	RECT m_rtPotion2;

private:
	void Collision();
	void JsonSave();
	void JsonLoad();
public:
	cPosionshop() {};
	virtual ~cPosionshop() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;


};

