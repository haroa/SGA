#pragma once
#include "SpritesObject.h"

class Player:public SpritesObject
{
public:
	Player();
	~Player();

	virtual void Update() override;
	virtual void Render() override;

	void PlayerController();
};

