#pragma once
#include "cGameobject.h"

class cMap:public cGameobject
{
private:



public:
	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();
};

