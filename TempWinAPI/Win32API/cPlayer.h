#pragma once
#include "cGameobject.h"
class cPlayer:public cGameobject
{
public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void MiniRender();
};

