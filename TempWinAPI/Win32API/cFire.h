#pragma once
#include "cGameobject.h"

class cFire:public cGameobject
{
private:
	cImage*		m_Buffer;
public:
	cFire();
	~cFire();

	void Setup();
	void Update();
	void Render();
};

