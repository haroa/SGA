#pragma once
#include "cGameobject.h"
#include "cImage.h"

class cPlayer;
class cTarget;

class cArrow:public cGameobject
{
private:
	cImage*			m_pArrowImage;
	cPlayer*		m_pcPlayer;
	cTarget*		m_pcTarget;
	int				m_nArrowNum;
	int				m_nArrowStack;
	float			m_fWindSpeed;


public:
	
	int GetArrowNUM() { return m_nArrowNum; }
	int GetArrowStack() { return m_nArrowStack; }


	void SetArrowNum(int ArrowNum) { m_nArrowNum = ArrowNum; }
	void SetPlayer(cPlayer* Player) { m_pcPlayer = Player; }
	void SetTarget(cTarget* Target) { m_pcTarget = Target; }
	void SetArrowStack(int ArrowStack) { m_nArrowStack = ArrowStack; }
	void SetWindSpeed(float WindSpeed) { m_fWindSpeed = WindSpeed; }
	

	cArrow();
	~cArrow();

	void Setup();
	void Update();
	void Render();

	void Move();
};

