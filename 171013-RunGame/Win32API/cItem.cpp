#include "stdafx.h"
#include "cItem.h"


cItem::cItem()
{
}


cItem::~cItem()
{
}

void cItem::Render()
{
	m_pItemImage->Render(g_hDC, m_PosX, m_PosY);
	
}
