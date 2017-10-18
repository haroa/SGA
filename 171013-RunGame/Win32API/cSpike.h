#pragma once
#include "cImage.h"
class cSpike
{
public:

	cImage* m_pspikeImage;
	int m_PosX;
	int m_PosY;
	RECT SpikeBody;
	void Render();

	cSpike();
	~cSpike();
};

