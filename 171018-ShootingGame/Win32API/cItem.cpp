#include "stdafx.h"
#include "cItem.h"


cItem::cItem()
{

}


cItem::~cItem()
{

}

void cItem::Setup()
{
	RandX = rand() % 500 + 100;
	m_fPosX = RandX;
	m_fPosY = 0;
	m_nSizeW = 32;
	m_nSizeH = 32;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cItem::Update()
{
	m_fPosY += 5.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cItem::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}
