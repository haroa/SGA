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
	D3DXVECTOR3				m_vCenter;		// ���� ���������� ������ ����
	float					m_fRadius;		// �浹 ���� ������

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

	// �����ӿ� ���� ������ �ڽĵ鵵 �Ȱ��� �����ϹǷ� ��� ������ �����.
	void SetIsMoving(bool move);

	// �浹 ó��
	void Collision(D3DXVECTOR3& center, float radius);
};

