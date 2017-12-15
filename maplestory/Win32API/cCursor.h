#pragma once
#include "cGameobject.h"

class cCursor : public cGameobject
{
private:
	int		m_CursorX;
public:
	cCursor() {};
	~cCursor() {};
	
	void Setup();
	void Update();
	void Render();
};

