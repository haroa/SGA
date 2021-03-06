#pragma once
#include "cGameNode.h"



enum E_GAME
{
	GAME_READY = 0, GAME_COUNT, GAME_PLAYING, GAME_OVER, GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME				m_GameState;


public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void Reset();
	void GameStartRender();
	void SystemEnter();
	void RepeatGame();
	void AllRender();
};