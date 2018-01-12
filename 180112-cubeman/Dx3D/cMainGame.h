#pragma once

class cCamera;
class cGrid;
class cCube;

class cMainGame
{
private:
	LPDIRECT3D9				m_pD3D;			// D3D9 인터페이스로의 포인터를 담는다.
	LPDIRECT3DDEVICE9		m_pD3DDevice;	// 장치로 부터 D3D9 인터페이스를 만드는데 사용 된다.

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

