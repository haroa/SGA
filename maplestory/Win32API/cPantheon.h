#pragma once
#include "cGameNode.h"
#include "cCursor.h"
#include "cPantheonMap.h"
#include "cPlayer.h"
#include "cMonster.h"
#include "cUI.h"

class cPantheon : public cGameNode
{
private:
	cImage*				m_pBuffer;
	RECT				m_rtChangeScene;
	RECT				m_viewport;
	float				m_PosX;
	float				m_PosY;
	float				m_fFromX;
	float				m_fFromY;
	float				m_fToX;
	float				m_fToY;
	float				m_fT;
	bool				m_isHit;
	bool				m_isMonsterLeft;
private:
	cCursor				m_cCursor;
	cPantheonMap		m_cPantheonMap;
	cPlayer				m_cPlayer;
	cMonster			m_cMonster;
	vector<cMonster>	m_vecMonsters;
	cUI					m_cUI;
private:
	void HitMonster();
	void MonsterHitPlayer();
	void MonsterSpawn();
	void MonsterUpdate();
	void JsonLoad();
public:
	cPantheon() {};
	virtual ~cPantheon() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};