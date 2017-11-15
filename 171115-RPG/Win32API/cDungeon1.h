#pragma once
#include "cGameNode.h"
#include "cUi.h"
#include "cPlayer.h"
class cDungeon1 : public cGameNode
{
private:
	cUi	m_cUi;
	cPlayer	m_cPlayer;

	float	 m_fMonster1X;
	float	 m_fMonster1Y;
	RECT	 m_rtMonster1;

	float	 m_fMonster2X;
	float	 m_fMonster2Y;
	RECT	 m_rtMonster2;

	float	 m_fMonster3X;
	float	 m_fMonster3Y;
	RECT	 m_rtMonster3;

private:
	void Collision();
	void JsonSave();
	void JsonLoad();
public:
	cDungeon1() {};
	virtual ~cDungeon1() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

