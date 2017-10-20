#pragma once
#include "cGameobject.h"

class cMap:public cGameobject
{
private:
	float	m_fDelay;
public:
	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();
};

