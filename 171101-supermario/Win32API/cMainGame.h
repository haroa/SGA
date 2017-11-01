#pragma once
#include "cGameNode.h"
#include "cGameScene.h"
#include "StartScene.h"
#include "cGameOver.h"
#include "cPlayer.h"


enum E_GAME
{
	GAME_READY = 0, GAME_COUNT, GAME_PLAYING, GAME_OVER, GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME				m_GameState;

	cGameScene			m_cGameScene;
	StartScene			m_cStartScene;
	cGameOver			m_cGameOver;
	cPlayer				m_cPlayer;

	cImage*				m_MiniMap;


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