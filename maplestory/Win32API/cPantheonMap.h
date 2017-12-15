#pragma once
#include "cGameobject.h"

class cPantheonMap : public cGameobject
{
private:
	cImage*	m_pImgBG;
	cImage*	m_pImgUI;

public:
	cPantheonMap() {};
	~cPantheonMap() {};

	void Setup();
	void Update();
	void Render(HDC hdc);
};

