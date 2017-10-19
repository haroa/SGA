#pragma once
#include "cGameobject.h"

class cBoss:public cGameobject
{
private:
	RECT m_rtHitPoint;
	float m_fHitPointX;
	float m_fHitPointY;
public:

	RECT GetHitPoint() { return m_rtHitPoint; }

	cBoss();
	~cBoss();

	void Setup();
	void Update();
	void Render();
};

