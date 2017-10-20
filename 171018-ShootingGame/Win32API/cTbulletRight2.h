#pragma once
#include "cGameobject.h"


class cTbulletRight2:public cGameobject
{
private:
	float m_ft;
	float m_fDestX;

public:
	float GetT() { return m_ft; }
	void SetT(float T) { m_ft = T; }

	float GetDestX() { return m_fDestX; }
	void SetDestX(float DestX) { m_fDestX = DestX; }

	cTbulletRight2();
	~cTbulletRight2();

	void Setup();
	void Update();
	void Render();
};

