#pragma once

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

	float				m_fmoveZ;
	float				m_fmoveX;
public:
	cCube();
	~cCube();

	void Setup();
	void Update();
	void Render(HDC hdc, cMatrix& matViewProj, cMatrix& matViewPort);

	cVector3 GetPosition() { return m_vPosition; }
};

