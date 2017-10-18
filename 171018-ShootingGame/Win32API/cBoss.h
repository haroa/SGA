#pragma once
#include "cGameobject.h"

class cBoss:public cGameobject
{
public:
	cBoss();
	~cBoss();

	void Setup();
	void Update();
	void Render();
};

