#pragma once
#include "cGameobject.h"
class cPlayer:public cGameobject
{
private:
	cImage* m_pBuffer;
	cImage* m_pMap;

	RECT	m_Hitrt;
public:

	RECT GetHitrt() { return m_Hitrt; }
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();
};

