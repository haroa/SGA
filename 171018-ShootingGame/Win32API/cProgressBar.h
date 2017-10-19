#pragma once
#include "cGameobject.h"
#include "cBoss.h"

class cProgressBar:public cGameobject
{
private:
	cImage*		m_pHpBar;
	cImage*		m_pFrameBar;

	cBoss		m_cBoss;


public:
	cImage* GetHpBar() { return m_pHpBar; }
	void SetHpBar(cImage* HpBar) { m_pHpBar = HpBar; }


	cProgressBar();
	~cProgressBar();

	void Setup();
	void Update();
	void Render();
};

