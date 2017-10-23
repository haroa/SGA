#pragma once
#include "SceneObject.h"

class GameScene : public SceneObject
{
private:

public:
    GameScene(E_GAME_STATE* State);
    ~GameScene();

    virtual void Update() override;
    virtual void Render() override;

    // SceneObject��(��) ���� ��ӵ�
    virtual void Setup() override;
    virtual void LoadImageResources() override;
    virtual void DeleteScene() override;
};

