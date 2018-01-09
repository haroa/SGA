#pragma once

class cCube;

class cMainGame
{
private:
	HDC			m_hMemDC;
	HBITMAP		m_hOldBitmap, m_hBitmap;

	cCube*		m_pCube;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render(HDC hdc);
};

