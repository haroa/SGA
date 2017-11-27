#pragma once
#include "cGameobject.h"

//class cPlay;

class cBall:public cGameobject
{
private:
	//cPlay* m_cPlay;
public:
	cBall();
	~cBall();

	void Setup();
	void Update();
	void Render();
};

