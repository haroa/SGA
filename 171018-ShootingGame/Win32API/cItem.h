#pragma once
#include "cGameobject.h"
class cItem:public cGameobject
{
private:
	int RandX;
public:
	cItem();
	~cItem();

	void Setup();
	void Update();
	void Render();
};

