#pragma once
#include "cGameobject.h"
class cStart:public cGameobject
{

public:
	cStart();
	~cStart();

	void Setup();
	void Update();
	void Render();
};

