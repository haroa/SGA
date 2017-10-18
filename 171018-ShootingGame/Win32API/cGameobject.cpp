#include "stdafx.h"
#include "cGameobject.h"


cGameobject::cGameobject()
{
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = WINSIZEY * 0.5f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, 10, 10);
	m_fSpeedX = 0.0f;
	m_fSpeedY = 0.0f;
	m_nDelay = 0;
	m_nSizeW = 0;
	m_nSizeH = 0;
	m_isActive = true;
}


cGameobject::~cGameobject()
{
}

void cGameobject::Update()
{
}

void cGameobject::Render()
{
}

void cGameobject::Move()
{
}
