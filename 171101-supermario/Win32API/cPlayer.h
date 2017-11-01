#pragma once
#include "cGameobject.h"
class cPlayer:public cGameobject
{
private:
	cImage* m_pBuffer;
	cImage* m_pMap;

	RECT	m_Hitrt;
	int		m_alpha;

	bool m_eatitem;
public:

	RECT GetHitrt() { return m_Hitrt; }
	void Seteatitem(bool eat) { m_eatitem = eat; }
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();
};

