#include "stdafx.h"
#include "cTarget.h"


cTarget::cTarget()
{
	m_pTargetImage = NULL;
	m_pAnotherTargetImage = NULL;
	m_pHitSpot = NULL;
}


cTarget::~cTarget()
{
}

void cTarget::Setup()
{
	m_fHitPointX = 0.0f;
	m_fHitPointY = 0.0f;
	m_fAnotherPosX = 200.0f;
	m_fAnotherPosY = WINSIZEY * 0.5f + 100;
	m_nAnotherSizeW = 150;
	m_nAnotherSizeH = 150;
	m_AnotherrtBody = RectMakeCenter(m_fAnotherPosX, m_fAnotherPosY, m_nAnotherSizeW, m_nAnotherSizeH);
	m_nSizeW = 20;
	m_nSizeH = 120;
	m_fPosX = WINSIZEX - 200.0f;
	m_fPosY = 60.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_pTargetImage = g_pImageManager->FindImage("Target");
	m_pAnotherTargetImage = g_pImageManager->FindImage("AnotherTarget");
	m_pHitSpot = g_pImageManager->FindImage("Spot");
#ifdef _DEBUG
	m_fSpeedY = 2.0f;
#else
m_fSpeedY = 2.0f;
#endif

}

void cTarget::Update()
{
	Move();
	m_fArrPosX = m_fAnotherPosX - m_fHitPointX;
	m_rtHitPoint = RectMakeCenter(m_fArrPosX, m_fAnotherPosY, 10, 10);
}

void cTarget::Render()
{
#ifdef _DEBUG
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
	Rectangle(g_hDC, m_AnotherrtBody.left, m_AnotherrtBody.top, m_AnotherrtBody.right, m_AnotherrtBody.bottom);
	Rectangle(g_hDC, m_rtHitPoint.left, m_rtHitPoint.top, m_rtHitPoint.right, m_rtHitPoint.bottom);
#endif // _DEBUG

	if (m_pTargetImage != NULL)
	{
		m_pTargetImage->Render(g_hDC, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
		m_pAnotherTargetImage->Render(g_hDC, m_fAnotherPosX, m_fAnotherPosY, m_nAnotherSizeW, m_nAnotherSizeH);

		if (m_fHitPointX == 0.0f)
		{

		}
		else
		{
			m_pHitSpot->Render(g_hDC, m_fArrPosX, m_fAnotherPosY, 10, 10);
		}
	}

}

void cTarget::Move()
{
	m_fPosY += m_fSpeedY;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cTarget::PosReset()
{
	m_nSizeW = 20;
	m_nSizeH = 120;
	m_fPosX = WINSIZEX - 200.0f;
	m_fPosY = 60.0f;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_fSpeedY = 5.0f;
}
