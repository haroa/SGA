#pragma once
#include "cGameobject.h"


class cBoss;
class cPlayer;

class cBbullet:public cGameobject
{
private:
	cBoss*		m_pcBoss;
	cPlayer*	m_pcPlayer;
	float		m_fSpeed;
	float		m_fangle;
	float		m_fradius;

	float		m_fBossNowHp;
public:
	cBbullet();
	~cBbullet();

	void SetBoss(cBoss* Boss) { m_pcBoss = Boss; }
	void SetPlayer(cPlayer* Player) { m_pcPlayer = Player; }
	void SetBossNowHp(float BossNowHp) { m_fBossNowHp = BossNowHp; }

	void Setup();
	void Update();
	void Render();
};

