#pragma once
#include "SceneObject.h"

class SpritesObject;
class ClearScene : public SceneObject
{
private:

public:
    ClearScene(E_GAME_STATE* State);
    ~ClearScene();

    virtual void Update() override;
    virtual void Render() override;

    // SceneObject��(��) ���� ��ӵ�
    virtual void Setup() override;
    virtual void LoadImageResources() override;
    virtual void DeleteScene() override;
};