#pragma once
#include "cGameobject.h"

class cFire:public cGameobject
{
private:
	cImage*		m_Buffer;
	float		m_MapPosX;
public:
	cFire();
	~cFire();

	void Setup();
	void Update();
	void Render();

	void SetMapPosX(float X) { m_MapPosX = X; }
};

