#pragma once
#include "cGameobject.h"
#include "cBall.h"

#define SIZE 30

class cPlay:public cGameobject
{
private:
	cBall			m_cBall;
	vector<cBall>	m_vecBall;
	int				m_nIndex;

	float m_fLineX;
	float m_fLineY;
public:
	cPlay() {};
	~cPlay() {};

	void Setup();
	void Update();
	void Render();

	void MakeBall();
};

