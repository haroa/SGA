#pragma once
#include "SceneObject.h"
#include "SpritesObject.h"

class SplashScene : public SceneObject
{
private:

public:
    SplashScene(E_GAME_STATE* State);
    ~SplashScene();

    virtual void Update() override;
    virtual void Render() override;

    // SceneObject��(��) ���� ��ӵ�
    virtual void Setup() override;
    virtual void LoadImageResources() override;
    virtual void DeleteScene() override;
};