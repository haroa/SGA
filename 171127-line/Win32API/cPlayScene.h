#pragma once
#include "cGameNode.h"
#include "cPlay.h"
class cPlayScene : public cGameNode
{
private:
	cPlay m_cPlay;
public:
	cPlayScene() {};
	virtual ~cPlayScene() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};
