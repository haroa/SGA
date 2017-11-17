#pragma once
#include "cGameNode.h"
class cShootinggame : public cGameNode
{
public:
	cShootinggame() {};
	virtual ~cShootinggame() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

