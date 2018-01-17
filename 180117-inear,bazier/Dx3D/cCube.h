#pragma once
class cCube
{
private:
	D3DXMATRIXA16			m_matWorld;
	LPDIRECT3DTEXTURE9		m_pTexture;

	vector<ST_PC_VERTEX>	m_vecPCVertex;
	vector<ST_PT_VERTEX>	m_vecPTVertex;
	vector<cCube*>			m_vecChild;

	D3DXVECTOR3				m_vLocalPos;
	float					m_fRotX;
	float					m_fRotXSpeed;
	float					m_fRotY;
	float					m_fRotYSpeed;

	bool					m_isMoving;
	D3DXVECTOR3				m_vCenter;		// 월드 공간에서의 포지션 정보
	float					m_fRadius;		// 충돌 구의 반지름

	void SetPCVertex(vector<D3DXVECTOR3>& vecV, vector<int>& vecI);
	void SetPTVertex(vector<D3DXVECTOR3>& vecV, vector<int>& vecI,
		vector<D3DXVECTOR2>* vecT);

public:
	cCube();
	~cCube();

	void Setup(vector<D3DXVECTOR2>* vecT, string key, D3DXMATRIXA16* pMat = NULL);
	void Update(D3DXMATRIXA16* pParent = NULL);
	void Render();
	void AddChild(cCube* pCube);
	void Release();

	void SetLocalPos(D3DXVECTOR3 v) { m_vLocalPos = v; }
	void SetRotSpeedX(float speed) { m_fRotXSpeed = speed; }
	void SetRotSpeedY(float speed) { m_fRotYSpeed = speed; }

	// 움직임에 대한 정보는 자식들도 똑같이 공유하므로 재귀 적으로 만든다.
	void SetIsMoving(bool move);

	// 충돌 처리
	void Collision(D3DXVECTOR3& center, float radius);
};

