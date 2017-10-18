#pragma once
#include "cGameobject.h"
#include "cImage.h"

class cPlayer:public cGameobject
{
private:
	cImage*		m_pPlayerImage;
public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();
};

