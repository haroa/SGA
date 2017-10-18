#pragma once
#include "cGameNode.h"
#include "cArrow.h"
#include "cPlayer.h"
#include "cTarget.h"
#include "cWind.h"

enum E_GAME
{
	GAME_READY = 0, GAME_COUNT, GAME_PLAYING, GAME_OVER, GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME				m_GameState;

	cArrow			m_cArrow;
	cPlayer			m_cPlayer;
	cTarget			m_cTarget;
	cWind			m_cWind;

	float			m_fDist;
	int				m_nSocre;


public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void Reset();
	void GameStartRender();
	void WindChoiceRender();
	void SystemEnter();
	void ShootArrow();
	void RepeatGame();
	void AllRender();
	void HitTarget();
	void Gameend();
	void GameoverRender();
};