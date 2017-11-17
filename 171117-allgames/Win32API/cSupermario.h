#pragma once
#include "cGameNode.h"

class cSupermario :public cGameNode
{
public:
	cSupermario() {};
	virtual ~cSupermario() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

