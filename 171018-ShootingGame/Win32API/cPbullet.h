#pragma once
#include "cGameobject.h"

class cPlayer;

class cPbullet:public cGameobject
{
	cPlayer*		m_pcPlayer;
	float			m_fBulletDmg;
	float			m_fMoveX;
	float			m_fMoveY;


public:

	float GetBulletDmg() { return m_fBulletDmg; }


	void SetPlayer(cPlayer* Player) { m_pcPlayer = Player; }
	void SetMoveX(float MoveX) { m_fMoveX = MoveX; }
	void SetMoveY(float MoveY) { m_fMoveY = MoveY; }

	cPbullet();
	~cPbullet();
	
	
	void Setup();
	void Update();
	void Render();
};

