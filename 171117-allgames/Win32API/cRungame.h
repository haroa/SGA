#pragma once
#include "cGameNode.h"

class cRungame : public cGameNode
{
public:
	cRungame() {};
	virtual ~cRungame() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

