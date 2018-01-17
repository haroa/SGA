#pragma once

class cCamera;
class cGrid;
class cCube;
class cCharacterController;
class cCubeMan;

class cMainGame
{
private:
	cCamera*				m_pCamera;
	cGrid*					m_pGrid;
	cCharacterController*	m_pController;
	cCubeMan*				m_pCubeMan;
	cCube*					m_pCube;

	LPDIRECT3DTEXTURE9		m_pTexture;		// 텍스쳐 포인터

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

