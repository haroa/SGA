#pragma once
#include "cMap.h"
#include "cPlayer.h"
#include "cGameNode.h"

#define GRAVITY 0.3f

class cGameScene : public cGameNode
{
private:
	cMap		m_cMap;
	cPlayer		m_cPlayer;

	cImage*		m_pImage;
	cImage*		m_pbuffer;
	cImage*		m_pminiMap;

	bool		m_isJumpping;
	float		m_fJumpPower;
	float		m_fGravity;
public:
	cGameScene();
	~cGameScene();

	void Setup();
	void Update();
	void Render();

	void SetLanding();
	void PlayerController();
	void MiniMapRender();
};

