#pragma once
#include "cGameobject.h"

class cProgressBar:public cGameobject
{
private:
	cImage*		m_pHpBar;
	cImage*		m_pFrameBar;


public:
	cProgressBar();
	~cProgressBar();

	void Setup();
	void Update();
	void Render();
};

