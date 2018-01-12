#pragma once
#define GRAVITY	0.3f

enum BODY_KIND { HEAD, BODY, LARM, RARM, LLEG, RLEG };

class cCube
{
private:
	D3DXMATRIXA16			m_matWorld;

	vector<ST_PC_VERTEX>	m_vecPCVertex;

	float					m_fRotX;
	float					m_fRotY;
	float					m_fRotZ;
	D3DXVECTOR3				m_vPosition;

	D3DXMATRIXA16			m_matScale;
	D3DXMATRIXA16			m_matRot;
	D3DXMATRIXA16			m_matTrans;
	bool					m_iscontroll;

	vector<cCube*>			m_vecChildCube;

	bool					m_isJumpping;
	float					m_fJumppower;
	float					m_fGravity;

	bool					m_ismove;
	BODY_KIND				m_nBody;
public:
	cCube(D3DXVECTOR3 scale, D3DXVECTOR3 rot, D3DXVECTOR3 trans, BODY_KIND kind, bool controll = false);
	~cCube();

	void Setup();
	void Update(cCube* cube = NULL);
	void Render(LPDIRECT3DDEVICE9& pD3DDevice);

	D3DXVECTOR3* GetPosition() { return &m_vPosition; }

	void Addchild(cCube* child) { m_vecChildCube.push_back(child); }
	D3DXMATRIXA16& GetWorld() { return m_matWorld; }
	bool GetMove() { return m_ismove; }
	bool GetControl() { return m_iscontroll; }
	void SetLanding();
};

