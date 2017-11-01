#pragma once
#include "cGameNode.h"

#define GRAVITY 0.3f

class cGameScene : public cGameNode
{
private:

	float	m_fJumpPower;
	float	m_fGravity;
	
	bool	m_isJumpping;

public:

	cGameScene();
	~cGameScene();

	void Setup();
	void Update();
	void Render();

	void SetLanding();
	void PlayerController();
	void MiniMapRender();
	void PlayerMiniRender();
};

