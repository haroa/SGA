#pragma once
#include "cGameobject.h"
class StartScene:public cGameobject
{
private:

public:
	StartScene();
	~StartScene();

	void Setup();
	void Update();
	void Render();
};

