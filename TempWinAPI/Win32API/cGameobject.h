#pragma once
#include "cImage.h"

class cGameobject
{
protected:
	cImage*		m_pImage;	//자기이미지
	float		m_fPosX;	//현재 X위치
	float		m_fPosY;	//현재 Y위치
	RECT		m_rtBody;	//렉트 박스
	float		m_fSpeedX;	//X의 위치스피드
	float		m_fSpeedY;	//Y의 위치스피드
	int			m_nDelay;	//딜레이
	int			m_nSizeW;	//가로크기
	int			m_nSizeH;	//세로크기
	



	bool	m_isActive;	//활성화 체크
public:
	
#pragma region GET
	float GetPosX() { return m_fPosX; }
	float GetPosY() { return m_fPosY; }
	float GetSpeedX() { return m_fSpeedX; }
	float GetSpeedY() { return m_fSpeedY; }
	RECT GetBody() { return m_rtBody; }
	int GetDelay() { return m_nDelay; }
	int GetSizeW() { return m_nSizeW; }
	int GetsizeH() { return m_nSizeH; }
	bool GetIsActive() { return m_isActive; }
#pragma endregion


#pragma region Set
	void SetPosX(float X) { m_fPosX = X; }
	void SetPosY(float Y) { m_fPosY = Y; }
	void SetSpeedX(float X) { m_fSpeedX = X; }
	void SetSpeedY(float Y) { m_fSpeedY = Y; }
	void SetBody(RECT rtBody) { m_rtBody = rtBody; }
	void SetDelay(int Delay) { m_nDelay = Delay; }
	void SetSizeW(int Width) { m_nSizeW = Width; }
	void SetSizeH(int Height) { m_nSizeH = Height; }
	void SetIsActive(bool isActive) { m_isActive = isActive; }
#pragma endregion


	
	cGameobject();
	~cGameobject();

	void Update();
	void Render();
	void Move();
};

