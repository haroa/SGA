#pragma once
#include "cGameobject.h"
#include "cProgressBar.h"
#include "cTurret.h"

class cBoss:public cGameobject
{
private:
	RECT m_rtHitPoint;
	float m_fHitPointX;
	float m_fHitPointY;
	float m_fHitPointHp;
	cProgressBar	m_cProgressBar;
	cTurret			m_cTurret;
	float m_fAllBossHp;
	float m_fNowBossHp;
	cImage* m_pHitPoint;
	cImage* m_pBossBoom;
	int		m_GameOverStack;
	float	m_fRate;
public:

	RECT GetHitPoint() { return m_rtHitPoint; }
	float GetHitPointHp() { return m_fHitPointHp; }
	float GetAllBossHp() { return m_fAllBossHp; }
	float GetNowBossHp() { return m_fNowBossHp; }
	int GetGameOverStack() { return m_GameOverStack; }
	float GetBossHpRate() { return m_fRate; }

	cTurret* GetTurret() { return &m_cTurret; }


	void SetHitPointHp(float Hp) { m_fHitPointHp = Hp; }

	cBoss();
	~cBoss();

	void Setup();
	void Update();
	void Render();
};

