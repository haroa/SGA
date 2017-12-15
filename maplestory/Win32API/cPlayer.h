#pragma once
#include "cGameobject.h"
#include "cPantheonMap.h"
#include "cUI.h"

class cPlayer :public cGameobject
{
private:
	cImage*			m_pImgColl;			//플레이어가 픽셀충돌할 이미지
private:
	RECT			m_rtAtkLeft;		//왼쪽을 공격할때 나올 렉트
	RECT			m_rtAtkRight;		//오른쪽을 공격할때 나올 렉트
private:
	float	m_fJumpPower;				//플레이어의 기본점프파워			
	float	m_fHitMonsterJumpPower;		//플레이어가 몬스터랑 충돌했을때 뒤로밀려날 점프파워
	float	m_fGravity;					//중력
	int		m_nLevel;					//플레이어의 레벨
	int		m_nAtk;						//플레이어의 공격력
	int		m_nHp;						//플레이어의 현재 체력
	int		m_nMp;						//플레이어의 현재 마나
	int		m_nExp;						//플레이어의 현재 경험치
	int		m_nMaxHp;					//플레이어의 최대 체력
	int		m_nMaxMp;					//플레이어의	최대 체력
	int		m_nMaxExp;					//플레이어의 최대 경험치
private:
	bool	m_isJumpping;				//플레이어가 점프를 할지 안할지
	bool	m_isLeft;					//플레이어가 왼쪽을 보고있는지 안보고있는지
	bool	m_isDown;					//플레이어가 아래키를 눌렀는지 안눌렀는지
	bool	m_isAtk;					//플레이어가 공격을 했는지 안했는지
	bool	m_isdrop;					//플레이어가 떨어지고있는지 안떨어지고있는지
	bool	m_isHitMonster;				//플레이어가 몬스터에게 맞았는지 안맞았는지
	bool	m_isHitMonsterJumpping;		//플레이어가 몬스터에게 맞고 점프를 했는지 안했는지
public:
	cPlayer() {};
	~cPlayer() {};

	void Setup();
	void Update();
	void Render(HDC hdc);

	void Move();
	void HitMonster();
#pragma region Get
	RECT GetAtkLeft() { return m_rtAtkLeft; }
	RECT GetAtkRight() { return m_rtAtkRight; }
	int GetCurrHp() { return m_nHp; }
	int GetCurrMp() { return m_nMp; }
	int GetCurrExp() { return m_nExp; }
	int GetMaxHp() { return m_nMaxHp; }
	int GetMaxMp() { return m_nMaxMp; }
	int GetMaxExp() { return m_nMaxExp; }
	int	GetLevel() { return m_nLevel; }
	int GetAtk() { return m_nAtk; }
	bool GetHitMonster() { return m_isHitMonster; }
	bool GetHitMonsterJumpping() { return m_isHitMonsterJumpping; }
#pragma endregion
};

