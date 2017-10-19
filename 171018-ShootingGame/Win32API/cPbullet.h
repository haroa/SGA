#pragma once
#include "cGameobject.h"

class cPlayer;

class cPbullet:public cGameobject
{
	cPlayer*		m_pcPlayer;
	float			m_fBulletDmg;


public:

	float GetBulletDmg() { return m_fBulletDmg; }


	void SetPlayer(cPlayer* Player) { m_pcPlayer = Player; }

	cPbullet();
	~cPbullet();
	
	
	void Setup();
	void Update();
	void Render();
};

