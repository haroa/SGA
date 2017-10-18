#pragma once
#include "cGameNode.h"
#include "cItem.h"
#include "cSpike.h"

#define MOVE_DELAY 7		// �÷��̾��̹����� ���� ������
#define ITEM_DELAY 10.0f		// �����۳����� �ӵ��� ���� ������
#define BG_SPEED 5.0f		// ����� ���ǵ�
#define ACTIVE_TIME 200		// �������� �������� �Ծ����� ����� ������
#define	SLOW_CHANCE 99		// �������� �������� ���� Ȯ��
#define TIMER 50		// Ÿ�̸� �������� �ӵ��� ����� ������
#define LEVEL_SPEED 0.0f	// ������ ���� ���ӵ�
#define BULLET_SPEED 0.0f	// ������ ���� �Ѿ˼ӵ�
#define	SPIKE_ATIVE	95
#define	NUMBER_DELAY 50

#define GRAVITY 0.3f		// �߷°�

enum E_GAME
{
	GAME_READY = 0, GAME_COUNT,GAME_PLAYING,GAME_OVER,GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME			m_GameState;

	cImage*			m_pGameover;
	cImage*			m_pFrameImage;		//�÷��̾� �̹���
	cImage*			m_pbgFrameImage;	//��� �̹���
	cImage*			m_pFrameBullet;		//�Ѿ� �̹���
	int				m_nMovedelay;		//�÷��̾��� �̹��� ������
	float			m_fJumpPower;		//����
	float			m_fCurrGravity;		//�߷�
	bool			m_isJumppinig;		//������ �ߴ��� ���ߴ��� üũ
	RECT			rt1;				//�÷��̾��� ��Ʈ
	RECT			rt2;				//�Ѿ��� ��Ʈ
	RECT			rtSlide;			//�÷��̾� �����̵� ��Ʈ
	float			m_fbgPosX;			//����� X��ġ
	cImage*			m_pFrameItem;		//���� �̹���
	cImage*			m_pFrameItem2;		//���������ϴ� �������� �̹���
	float			m_moveitem;			//������ ������ �ӵ�
	int				m_nScore;			//������ ǥ���ϴ� �������
	float			m_fbgSpeed;			//����� ���ǵ�
	int				m_bgdelay;			//���������ϴ� �������� ������ ���ӽð��� ������
	bool			m_isAtive;			//���������ϴ� �������� Ȱ��ȭ�� �Ǿ����� �ȵǾ����� Ȯ��
	int				m_nLevel;			//������ �������
	int				m_nTimer;			//�ð��� �������� ���� ������
	int				m_stopwatch;		//�ð��� ǥ��
	int				m_LevelSpeed;		//������ ���� ����� �������� ���ǵ�
	float			m_LevelBulletSpeed;	//������ ���� �Ѿ��� �������� ���ǵ�
	cImage*			m_pStartImage;		//��ŸƮ �̹���
	cImage*			m_pEnterStart;		//�����ϸ� ��ŸƮ �̹���
	float			m_Blinkimage;		//���� ����
	float			m_BlinkSpeed;		//�������� �ӵ�
	bool			m_TwoJump;			//2������ �Ұ�
	int				m_nJumpStack;		//������ ������ŭ �ö󰡴� ����
	int				BulletPosYrand;		//�Ѿ��� y���� ��������
	cImage*			m_pSpikeImage;		//������ �̹���
	cImage*			m_pSlideImage;		//�÷��̾� �����̵� �̹���
	bool			m_isSlide;			//�����̵� �Ұ�
	float			m_nGravity;			//�߷¸������
	cImage*			m_pbgImage2;		//�ι�°���
	cImage*			m_pbgImage3;
	cImage*			m_pbgImage4;
	cImage*			m_pNumber;
	int				m_nNumberDelay;
	float			m_ObjectSpeed;
	float			m_BulletObjectSpeed;
	float			m_fOutDelay;
	cImage*			m_pRestart;
	cImage*			m_pClear;

	

	vector <cItem>		m_vcItem;
	vector <cSpike>		m_vcSpike;

public:
	cMainGame();
	~cMainGame();

	virtual void Update() override;
	virtual void Render() override;

	void CreateSpike();
	void MoveSpike();
	void CreateItem();
	void MoveItem();
	void NextNumber();
	void NumberRender();
	void Play();
	void PlayingRender();
	void ReadyRender();
	void GameOverRender();
	void Ready();
	void SystemControl();
	void GameStateReset();
	void GameClear();
	void GamePlayReset();
};