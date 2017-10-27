#pragma once
#include "cGameobject.h"
class cPlayer:public cGameobject
{
private:
	cImage* m_pBuffer;
public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	void MiniRender();
};

