#pragma once
class cCharacterController
{
private:
	vector<D3DXVECTOR3> m_vecHexa;
	D3DXVECTOR3		m_vPosition;
	D3DXVECTOR3		m_vPositionA;
	D3DXVECTOR3		m_vPositionB;

	D3DXVECTOR3		m_vFrom;
	D3DXVECTOR3		m_vTo;
	D3DXVECTOR3		m_vVia;
	float			m_fT;
	
	float			m_fRotY;
	float			m_fMoveSpeed;

	D3DXMATRIXA16	m_matWorld;

	bool			m_isMoving;
	bool			m_isLinear;
	bool			m_isBezier;

public:
	cCharacterController();
	~cCharacterController();

	void Update();
	
	D3DXVECTOR3* GetPosition() { return &m_vPosition; }
	D3DXMATRIXA16* GetWorldTM() { return &m_matWorld; }
	void SetHexa(vector<D3DXVECTOR3> hexa) { m_vecHexa = hexa; }
	bool GetIsMoving() { return m_isMoving; }
	void LinearInterpolation(OUT D3DXVECTOR3 start, IN D3DXVECTOR3 from, IN D3DXVECTOR3 to, IN D3DXVECTOR3 t);
};

