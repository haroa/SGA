#pragma once
#include "cGameobject.h"

class Ranking:public cGameobject
{
public:
	Ranking();
	~Ranking();

	void Setup();
	void Update();
	void Render();
};

