#pragma once
class cCamera
{
private:
	float		m_fDistance;	// ť�� ���� ī�޶� �Ÿ�
	D3DXVECTOR3	m_vEye;			// ī�޶� ��ġ
	D3DXVECTOR3	m_vLookAt;		// �ٶ󺸴� ��ġ
	D3DXVECTOR3	m_vUp;			// ������ �� ����

	D3DXMATRIXA16		m_matView;
	D3DXMATRIXA16		m_matProj;

	float		m_fRotX;
	float		m_fRotY;
	bool		m_isRButtonDown;
	POINT		m_ptPrevMouse;

public:
	cCamera();
	~cCamera();

	void Setup(LPDIRECT3DDEVICE9& pD3DDevice);
	void Update(LPDIRECT3DDEVICE9& pD3DDevice, D3DXVECTOR3* pTarget = NULL);

	D3DXMATRIXA16 GetViewProjMatrix() { return m_matView * m_matProj; }

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};
