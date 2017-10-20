#pragma once
#include "cGameobject.h"

class cTurret;

class cTbulletRight1:public cGameobject
{
private:
	cTurret* m_pcTurret;


public:

	void SetBoss(cTurret* Turret) { m_pcTurret = Turret; }

	cTbulletRight1();
	~cTbulletRight1();

	void Setup();
	void Update();
	void Render();
};

