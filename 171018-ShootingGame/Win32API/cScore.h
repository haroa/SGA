#pragma once
#include "cGameobject.h"

class cScore:public cGameobject
{
public:
	cScore();
	~cScore();
	
	void Setup();
	void Update();
	void Render();
};

