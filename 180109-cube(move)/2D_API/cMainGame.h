#pragma once

class cCube;
class cGrid;
class cCamera;

class cMainGame
{
private:
	HDC			m_hMemDC;
	HBITMAP		m_hOldBitmap, m_hBitmap;

	cCube*		m_pCube;
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render(HDC hdc);
};

