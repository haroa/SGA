#pragma once
#include "SpritesObject.h"


class cScore:public SpritesObject
{
public:
	cScore();
	~cScore();
	
	void Setup();
	void Update();
	void Render();
};

