#pragma once
#include "cVector3.h"
#include "cMatrix.h"
class cCube
{
private:
	cMatrix				m_matWorld;

	vector<cVector3>	m_vecVertex;
	vector<int>			m_vecIndex;

	float				m_fRotX;
	float				m_fRotY;
	float				m_fRotZ;
	cVector3			m_vPosition;

public:
	cCube();
	~cCube();

	void Setup();
	void Update();
	void Render(HDC hdc, cMatrix& matViewProj, cMatrix& matViewPort);
};

