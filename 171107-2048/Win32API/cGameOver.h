#pragma once
#include "cGameobject.h"
class cGameOver : public cGameobject
{
public:
	cGameOver();
	~cGameOver();

	void Setup();
	void Update();
	void Render();
};

