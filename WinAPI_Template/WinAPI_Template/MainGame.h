#pragma once
#include "GameNode.h"

#pragma region SCENE
#include "GameScene.h"
#pragma endregion

class MainGame : public GameNode
{
//=======================================================
//  VARIABLES
private:
    E_GAME_STATE    m_gameState;
    GameScene*      m_scnGame;

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