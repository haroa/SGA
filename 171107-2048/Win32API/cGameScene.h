#pragma once
#include "cGameNode.h"
#include "cMap.h"

#define GRAVITY 0.3f

struct Tile
{
	float	fPosX;			//X�� ��ġ
	float	fPosY;			//Y�� ��ġ
	int		uId;			//Ÿ���� ����
	bool	isBlank;		//Ÿ���� ����ִ°�?
	bool	isSum;			//�������°�?
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

