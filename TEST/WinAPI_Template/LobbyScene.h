#pragma once
#include "SceneObject.h"

class SpritesObject;
class LobbyScene : public SceneObject
{
private:
	SpritesObject* m_t;
public:
    LobbyScene(E_GAME_STATE* State);
    ~LobbyScene();

    virtual void Update() override;
    virtual void Render() override;

    // SceneObject을(를) 통해 상속됨
    virtual void Setup() override;
    virtual void LoadImageResources() override;
    virtual void DeleteScene() override;
};

