#pragma once
#include "SpritesObject.h"

#define GRAVITY 0.3f

class Player : public SpritesObject
{
    //  vars
private:
    GameObject  m_gameObj;
    int         m_playerState;
	float		m_fjumppower;
	float		m_fGravity;
	bool		m_isJumpping;
public:
    Player();
    ~Player();

    virtual void Update() override;
    virtual void Render() override;
    
    void PlayerController();
};