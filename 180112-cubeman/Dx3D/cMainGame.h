#pragma once

class cCamera;
class cGrid;
class cCube;

class cMainGame
{
private:
	LPDIRECT3D9				m_pD3D;			// D3D9 �������̽����� �����͸� ��´�.
	LPDIRECT3DDEVICE9		m_pD3DDevice;	// ��ġ�� ���� D3D9 �������̽��� ����µ� ��� �ȴ�.

private:
	cCamera*				m_pCamera;
	cGrid*					m_pGrid;
	cCube*					m_pCube;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

