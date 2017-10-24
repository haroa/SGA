#pragma once
#include "GameNode.h"
#include "SpritesObject.h"
#include "GameScene.h"

class MainGame : public GameNode
{
//=======================================================
//  VARIABLES
private:
	GameScene*		m_scnGame;
	E_GAME_STATE	m_gameState;
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

#pragma region RESOURCES
    void LoadAllResources();
    void LoadImageResources();
    void LoadSoundResources();
#pragma endregion
#pragma region CONTROLLER
    void    SystemController();
    void    MouseLock();
    void    MouseUnlock();
#pragma endregion
};