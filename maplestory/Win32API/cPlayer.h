#pragma once
#include "cGameobject.h"
#include "cPantheonMap.h"
#include "cUI.h"

class cPlayer :public cGameobject
{
private:
	cImage*			m_pImgColl;			//�÷��̾ �ȼ��浹�� �̹���
private:
	RECT			m_rtAtkLeft;		//������ �����Ҷ� ���� ��Ʈ
	RECT			m_rtAtkRight;		//�������� �����Ҷ� ���� ��Ʈ
private:
	float	m_fJumpPower;				//�÷��̾��� �⺻�����Ŀ�			
	float	m_fHitMonsterJumpPower;		//�÷��̾ ���Ͷ� �浹������ �ڷιз��� �����Ŀ�
	float	m_fGravity;					//�߷�
	int		m_nLevel;					//�÷��̾��� ����
	int		m_nAtk;						//�÷��̾��� ���ݷ�
	int		m_nHp;						//�÷��̾��� ���� ü��
	int		m_nMp;						//�÷��̾��� ���� ����
	int		m_nExp;						//�÷��̾��� ���� ����ġ
	int		m_nMaxHp;					//�÷��̾��� �ִ� ü��
	int		m_nMaxMp;					//�÷��̾���	�ִ� ü��
	int		m_nMaxExp;					//�÷��̾��� �ִ� ����ġ
private:
	bool	m_isJumpping;				//�÷��̾ ������ ���� ������
	bool	m_isLeft;					//�÷��̾ ������ �����ִ��� �Ⱥ����ִ���
	bool	m_isDown;					//�÷��̾ �Ʒ�Ű�� �������� �ȴ�������
	bool	m_isAtk;					//�÷��̾ ������ �ߴ��� ���ߴ���
	bool	m_isdrop;					//�÷��̾ ���������ִ��� �ȶ��������ִ���
	bool	m_isHitMonster;				//�÷��̾ ���Ϳ��� �¾Ҵ��� �ȸ¾Ҵ���
	bool	m_isHitMonsterJumpping;		//�÷��̾ ���Ϳ��� �°� ������ �ߴ��� ���ߴ���
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

