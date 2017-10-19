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

#pragma region Get
	cImage* GetHpBar() { return m_pHpBar; }
#pragma endregion

#pragma region Set
	void SetBossMaxHp(float MaxHp) { m_fBossMaxHp = MaxHp; }
	void SetBossNowHp(float NowHp) { m_fBossNowHp = NowHp; }
#pragma endregion




	cProgressBar();
	~cProgressBar();

	void Setup();
	void Update();
	void Render();
};

