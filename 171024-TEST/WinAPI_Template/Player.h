#pragma once
#include "SpritesObject.h"

class Player:public SpritesObject
{
private:
	GameObject  m_gameObj;
	int			m_playerState;
public:
	Player();
	~Player();

	virtual void Update() override;
	virtual void Render() override;

	void PlayerController();
};

