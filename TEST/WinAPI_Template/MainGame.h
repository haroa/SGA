#pragma once
#include "GameNode.h"
#include "LobbyScene.h"
#include "GameScene.h"

class MainGame : public GameNode
{
//=======================================================
//  VARIABLES
private:
	LobbyScene*		m_lobbyScene;
	GameScene*		m_gameScene;
	E_GAME_STATE	m_gamestate;
//=======================================================
//  FUNCTIONS
private:
public:
    MainGame();
    ~MainGame();

    virtual void Start() override;
    virtual void Update() override;
    virtual void Render() override;
    void Reset();

    void LoadAllResources();
    void LoadImageResources();
    void LoadSoundResources();
	void SetupScene();
	void SystemControl();
};