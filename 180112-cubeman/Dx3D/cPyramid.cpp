#include "stdafx.h"
#include "cPyramid.h"


cPyramid::cPyramid()
{
}


cPyramid::~cPyramid()
{
}

void cPyramid::Setup(D3DCOLOR c, D3DXMATRIXA16& matWorld)
{
	m_matWorld = matWorld;

	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(0, 0, 0), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1, 1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1,-1), c));

	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(0, 0, 0), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1, 1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1, 1), c));

	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(0, 0, 0), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1,-1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1, 1), c));

	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(0, 0, 0), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1,-1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1,-1), c));

	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1,-1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1,-1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1, 1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1,-1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1, 1, 1), c));
	m_vecPCVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(1,-1, 1), c));
}

void cPyramid::Render(LPDIRECT3DDEVICE9 & pD3DDevice)
{
	pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecPCVertex.size() / 3,
		&m_vecPCVertex[0], sizeof(ST_PC_VERTEX));
}
