#pragma once
#include "cGameobject.h"



class cTbulletLeft1:public cGameobject
{
private:
	float m_StartX;
	float m_StartY;
	float m_DestX;
	float m_DestY;
	float m_ft;


public:
	float GetStartX() { return m_StartX; }
	float GetStartY() { return m_StartY; }
	float GetDestX() { return m_DestX; }
	float GetDestY() { return m_DestY; }
	float GetT() { return m_ft; }
	void SetT(float t) { m_ft = t; }
	void SetDestX(float DestX) { m_DestX = DestX; }
	void SetDestY(float DestY) { m_DestY = DestY; }


	cTbulletLeft1();
	~cTbulletLeft1();
	
	void Setup();
	void Update();
	void Render();
};

