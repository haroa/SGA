#pragma once
#include "cGameobject.h"
#include "cImage.h"


class cTarget:public cGameobject
{
private:
	cImage*	m_pTargetImage;
	cImage* m_pAnotherTargetImage;
	cImage* m_pHitSpot;
	/*
	float	m_fPosX;	//현재 X위치
	float	m_fPosY;	//현재 Y위치
	RECT	m_rtBody;	//렉트 박스
	float	m_fSpeedX;	//X의 위치스
	float	m_fSpeedY;	//Y의 위치스
	int		m_nDelay;	//딜레이
	int		m_nSizeW;	//가로크기
	int		m_nSizeH;	//세로크기
	*/

	float	m_fAnotherPosX;
	float	m_fAnotherPosY;
	RECT	m_AnotherrtBody;
	int		m_nAnotherSizeW;
	int		m_nAnotherSizeH;
	float	m_fHitPointX;
	float	m_fHitPointY;
	RECT	m_rtHitPoint;
	float	m_fArrPosX;
public:

	float GetHitPointX() { return m_fHitPointX; }
	float GetHitPointY() { return m_fHitPointY; }

	void SetHitPointX(float X) { m_fHitPointX = X; }
	void SetHitPointY(float Y) { m_fHitPointY = Y; }

	cTarget();
	~cTarget();

	void Setup();
	void Update();
	void Render();

	void Move();
	void PosReset();
};

