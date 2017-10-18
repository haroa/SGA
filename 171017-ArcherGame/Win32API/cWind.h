#pragma once
#include "cGameobject.h"

class cWind:public cGameobject
{
public:


	cWind();
	~cWind();

	void Setup();
	void Update();
	void Render();
};

