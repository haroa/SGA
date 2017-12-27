#pragma once
#include "cGameObject.h"

class cBall:public cGameobject
{
public:
	cBall() {};
	~cBall() {};

	void Setup();
	void Update();
	void Render();
};

