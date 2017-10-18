#pragma once
#include "cImage.h"
class cItem
{
public:

	cImage* m_pItemImage;
	int m_PosX;
	int m_PosY;
	RECT ItemBody;

	float m_fmoveSpeed;

	cItem();
	~cItem();

	void Render();
};

