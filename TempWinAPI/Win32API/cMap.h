#pragma once
#include "cGameobject.h"
class cMap:public cGameobject
{
private:
	cImage* m_cminiMap;
	cImage*	m_cBuffer;
public:
	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();
};

