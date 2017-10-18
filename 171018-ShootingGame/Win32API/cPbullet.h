#pragma once
#include "cGameobject.h"

class cPbullet:public cGameobject
{
public:
	cPbullet();
	~cPbullet();
	
	
	void Setup();
	void Update();
	void Render();
};

