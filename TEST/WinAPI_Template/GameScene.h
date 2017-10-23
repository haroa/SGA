#pragma once
#include "SceneObject.h"

class SpritesObject;
class GameScene : public SceneObject
{
private:
	SpritesObject* m_spritestest;
public:
    GameScene(E_GAME_STATE* State);
    ~GameScene();

    virtual void Update() override;
    virtual void Render() override;

    // SceneObject을(를) 통해 상속됨
    virtual void Setup() override;
    virtual void LoadImageResources() override;
    virtual void DeleteScene() override;
};

