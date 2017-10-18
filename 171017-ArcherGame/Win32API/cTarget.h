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
	float	m_fPosX;	//���� X��ġ
	float	m_fPosY;	//���� Y��ġ
	RECT	m_rtBody;	//��Ʈ �ڽ�
	float	m_fSpeedX;	//X�� ��ġ��
	float	m_fSpeedY;	//Y�� ��ġ��
	int		m_nDelay;	//������
	int		m_nSizeW;	//����ũ��
	int		m_nSizeH;	//����ũ��
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

