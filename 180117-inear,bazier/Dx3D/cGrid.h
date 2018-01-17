#pragma once

class cPyramid;

class cGrid
{
private:
	vector<ST_PC_VERTEX>	m_vecPCVertex;
	vector<ST_PC_VERTEX>	m_vecLineVertex;
	vector<D3DXVECTOR3>		m_vecPointVertex;
	vector<cPyramid*>		m_vecPyramid;

public:
	cGrid();
	~cGrid();

	void Setup();
	void Render();

	vector<D3DXVECTOR3> GetHexaPoint() { return m_vecPointVertex; }
};

