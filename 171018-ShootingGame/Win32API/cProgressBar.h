#pragma once
#include "cGameobject.h"



class cProgressBar:public cGameobject
{
private:
	cImage*		m_pHpBar;
	cImage*		m_pFrameBar;

	float		m_fBossMaxHp;
	float		m_fBossNowHp;


public:
	cImage* GetHpBar() { return m_pHpBar; }
	void SetHpBar(cImage* HpBar) { m_pHpBar = HpBar; }

	void SetBossMaxHp(float MaxHp) { m_fBossMaxHp = MaxHp; }
	void SetBossNowHp(float NowHp) { m_fBossNowHp = NowHp; }


	cProgressBar();
	~cProgressBar();

	void Setup();
	void Update();
	void Render();
};

