#include "stdafx.h"
#include "cSpike.h"


void cSpike::Render()
{
	m_pspikeImage->Render(g_hDC, m_PosX, m_PosY);
}

cSpike::cSpike()
{
}


cSpike::~cSpike()
{

}
