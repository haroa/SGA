#pragma once
#include "cGameobject.h"


class cPlayer : public cGameobject
{
private:


public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void Move();
};

