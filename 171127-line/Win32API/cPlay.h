#pragma once
#include "cGameobject.h"
#include "cBall.h"

class cPlay:public cGameobject
{
private:
	float		  m_ft;
	float		  m_fromX;
	float	      m_fromY;
	float         m_ftoX;
	float		  m_ftoY;
	vector<cBall> m_vcBall;
public:
	cPlay() {};
	~cPlay() {};

	void Setup();
	void Update();
	void Render();

	void MakeBall();
	void SetToX(float X) { m_ftoX = X; }
	void SetToY(float Y) { m_ftoY = Y; }
};

