#pragma once
#include "cGameNode.h"
class cDungeon2 : public cGameNode
{
public:
	cDungeon2() {};
	virtual ~cDungeon2() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

