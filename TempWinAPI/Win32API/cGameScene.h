#pragma once
#include "cMap.h"
#include "cPlayer.h"
#include "cFire.h"
#include "cGameNode.h"

#define GRAVITY 0.3f

class cGameScene : public cGameNode
{
private:
	cMap		m_cMap;
	cPlayer		m_cPlayer;
	vector<cFire>		m_veccfire;

	cImage*		m_pImage;
	cImage*		m_pbuffer;
	cImage*		m_pminiMap;
	cImage*		m_pObject;
	cImage*		m_pObject2;
	cImage*		m_pGoomba;
	cImage*		m_pKupa;
	cImage*		m_fire;
	cImage*		m_clearobject;
	cImage*		m_item;

	bool		m_isJumpping;
	float		m_fJumpPower;
	float		m_fGravity;
	int			m_nCheck;

	bool		m_bPlayerDie;
	bool		m_clear;
	bool		m_next;
public:
	bool GetPlayerDie() {return m_bPlayerDie;}
	bool Getnext() { return m_next; }

	cGameScene();
	~cGameScene();

	void Setup();
	void Update();
	void Render();

	void SetLanding();
	void PlayerController();
	void MiniMapRender();
	void PlayerMiniRender();
	void PixelCollisionHead();
	void PixelCollisionbottom();
	void ObjectcollPlayer();
	void EnemycollPlayer();
	void ClearcollPlayer();
	void Erasefire();
	void MakeFire();
	void RenderFire();
	void MoveFire();
	void Clear();
	void ItemcollPlayer();
	//void OnemoreMoveFire();
};

