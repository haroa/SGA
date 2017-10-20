#pragma once
#include "cGameobject.h"



class cTbulletLeft2:public cGameobject
{
private:
	float m_fStartX;
	float m_fStartY;
	float m_fDestX;
	float m_fDestY;
	float m_fViaX;
	float m_fViaY;
	float m_ft;

public:
	float GetStartX() { return m_fStartX; }
	float GetStartY() { return m_fStartY; }
	float GetDestX() { return m_fDestX; }
	float GetDestY() { return m_fDestY; }
	float GetViaX() { return m_fViaX; }
	float GetViaY() { return m_fViaY; }
	float GetT() { return m_ft; }

	void SetT(float T) { m_ft = T; }

	cTbulletLeft2();
	~cTbulletLeft2();

	void Setup();
	void Update();
	void Render();
};

