#include "stdafx.h"
#include "cBoss.h"


cBoss::cBoss()
{
	m_pImage = NULL;
}


cBoss::~cBoss()
{

}

void cBoss::Setup()
{
	m_pImage = g_pImageManager->FindImage("Boss");
	m_fPosX = WINSIZEX * 0.5f;
	m_fPosY = 200.0f;
	m_nSizeW = 464;
	m_nSizeH = 356;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	
	//=================================================================
	m_fHitPointX = m_fPosX;
	m_fHitPointY = m_fPosY;
	m_rtHitPoint = RectMakeCenter(m_fHitPointX, m_fHitPointY, 60,60);
}

void cBoss::Update()
{

}

void cBoss::Render()
{
#ifdef _DEBUG
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
#endif // _DEBUG

	if (m_pImage != NULL)
	{
		m_pImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	}
	Rectangle(g_hDC, m_rtHitPoint.left, m_rtHitPoint.top, m_rtHitPoint.right, m_rtHitPoint.bottom);
}
