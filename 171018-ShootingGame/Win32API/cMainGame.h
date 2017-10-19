#pragma once
#include "cGameNode.h"
#include "cPlayer.h"
#include "cBoss.h"
#include "cBbullet.h"
#include "cPbullet.h"


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
	vector<cBbullet>			m_veccbBullet;
	vector<cPbullet>			m_veccpBullet;

	int							m_nBossShotDelay;
	int							m_nPlayerShotDelay;

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
};