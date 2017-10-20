#pragma once
#include "cGameNode.h"
#include "cPlayer.h"
#include "cBoss.h"
#include "cBbullet.h"
#include "cPbullet.h"
#include "cTurret.h"
#include "cProgressBar.h"
#include "cMap.h"
#include "cTbulletLeft1.h"
#include "cTbulletLeft2.h"
#include "cTbulletRight1.h"
#include "cTbulletRight2.h"


enum E_GAME
{
	GAME_READY = 0, GAME_COUNT, GAME_PLAYING, GAME_OVER, GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME						m_GameState;
	cPlayer						m_cPlayer;
	cBoss						m_cBoss;
	cTurret						m_cTurret;
	cProgressBar				m_cProgressBar;
	cMap						m_cMap;
	vector<cTbulletLeft1>				m_veccTbulletLeft1;
	vector<cTbulletLeft2>				m_veccTbulletLeft2;
	vector<cTbulletRight1>				m_veccTbulletRight1;
	vector<cTbulletRight2>				m_veccTbulletRight2;
	vector<cBbullet>			m_veccbBullet;
	vector<cPbullet>			m_veccpBullet;

	int							m_nBossShotDelay;
	int							m_nPlayerShotDelay;
	float						m_fNowBossHp;
	float						m_fSaveBossHp;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;


	void Reset();
	void GameStartRender();
	void SystemEnter();
	void PlayerController();
	void RepeatGame();
	void AllRender();
	void ShotBossBullet();
	void BossBulletMove();
	void BossBulletActiveFalse();
	void BossBulletErase();
	void HitBossBulletPlayer();
	void GameOverRender();
	void BossBulletAllErase();
	void PlayerMakeBullet();
	void PlayerMoveBullet();
	void PlayerShotBullet();
	void PlayerBulletActiveFalse();
	void PlayerBulletErase();
	void HitPlayerBulletBoss();
	void HitPlayerBulletTurret();
	void GameClear();
	void GameClearRender();
	void TurretLeft1MakeBullet();
	void TurretLeft1MoveBullet();
	void TurretLeft1Render();
	void TurretLeft1ActiveFlase();
	void TurretLeft1Erase();
	void TurretLeft2MakeBullet();
	void TurretLeft2MoveBullet();
	void TurretLeft2ActiveFlase();
	void TurretLeft2Erase();
	void TurretLeft2Render();
	void TurretRight1MakeBullet();
	void TurretRight1MoveBullet();
	void TurretRight1ActiveFlase();
	void TurretRight1Erase();
	void TurretRight1Render();
	void TurretRight2MakeBullet();
	void TurretRight2MoveBullet();
	void TurretRight2ActiveFlase();
	void TurretRight2Erase();
	void TurretRight2Render();
};