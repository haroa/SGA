#pragma once
#include "cGameNode.h"
class cDungeonScene : public cGameNode
{
public:
	cDungeonScene() {};
	virtual ~cDungeonScene() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

