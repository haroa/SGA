#pragma once
#include "cVector3.h"
#include "cMatrix.h"
class cGrid
{
private:
	vector<cVector3>	m_vecVertex;
	cVector3			m_vAxisX;
	cVector3			m_vAxisY;

public:
	cGrid();
	~cGrid();

	void Setup();
	void Render(HDC hdc, cMatrix& matViewProjViewport);
};

