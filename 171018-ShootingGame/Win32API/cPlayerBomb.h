#pragma once
#include "cGameobject.h"


class cPlayerBomb:public cGameobject
{
private:


public:
	cPlayerBomb();
	~cPlayerBomb();

	void Setup();
	void Update();
	void Render();
};

