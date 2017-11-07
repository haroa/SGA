#pragma once
#include "cGameNode.h"
#include "cMap.h"

#define GRAVITY 0.3f

struct Tile
{
	float	fPosX;			//X의 위치
	float	fPosY;			//Y의 위치
	int		uId;			//타일의 숫자
	bool	isBlank;		//타일이 비어있는가?
	bool	isSum;			//합쳐졌는가?
};

class cGameScene : public cGameNode
{
private:
	cMap		m_cMap;



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

