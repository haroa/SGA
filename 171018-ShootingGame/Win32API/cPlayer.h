#pragma once
#include "cGameobject.h"


class cPlayer:public cGameobject
{
private:
	int			m_nHitSizeW;
	int			m_nHitSizeH;
	RECT		m_rtHitPoint;
public:

	RECT GetHitPoint() { return m_rtHitPoint; }
	

	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();
};

