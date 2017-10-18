#pragma once
#include "cGameNode.h"
#include "cItem.h"
#include "cSpike.h"

#define MOVE_DELAY 7		// 플레이어이미지가 가질 딜레이
#define ITEM_DELAY 10.0f		// 아이템나오는 속도가 가질 딜레이
#define BG_SPEED 5.0f		// 배경의 스피드
#define ACTIVE_TIME 200		// 느려지는 아이템을 먹었을때 실행될 딜레이
#define	SLOW_CHANCE 99		// 느려지는 아이템이 나올 확률
#define TIMER 50		// 타이머 내려가는 속도를 계산할 딜레이
#define LEVEL_SPEED 0.0f	// 레벨에 따른 배경속도
#define BULLET_SPEED 0.0f	// 레벨에 따른 총알속도
#define	SPIKE_ATIVE	95
#define	NUMBER_DELAY 50

#define GRAVITY 0.3f		// 중력값

enum E_GAME
{
	GAME_READY = 0, GAME_COUNT,GAME_PLAYING,GAME_OVER,GAME_CLEAR
};

class cMainGame : public cGameNode
{
private:
	E_GAME			m_GameState;

	cImage*			m_pGameover;
	cImage*			m_pFrameImage;		//플레이어 이미지
	cImage*			m_pbgFrameImage;	//배경 이미지
	cImage*			m_pFrameBullet;		//총알 이미지
	int				m_nMovedelay;		//플레이어의 이미지 딜레이
	float			m_fJumpPower;		//점프
	float			m_fCurrGravity;		//중력
	bool			m_isJumppinig;		//점프를 했는지 안했는지 체크
	RECT			rt1;				//플레이어의 렉트
	RECT			rt2;				//총알의 렉트
	RECT			rtSlide;			//플레이어 슬라이드 렉트
	float			m_fbgPosX;			//배경의 X위치
	cImage*			m_pFrameItem;		//점수 이미지
	cImage*			m_pFrameItem2;		//느려지게하는 아이템의 이미지
	float			m_moveitem;			//아이템 나오는 속도
	int				m_nScore;			//점수를 표시하는 멤버변수
	float			m_fbgSpeed;			//배경의 스피드
	int				m_bgdelay;			//느려지게하는 아이템을 먹으면 지속시간의 딜레이
	bool			m_isAtive;			//느려지게하는 아이템이 활성화가 되었는지 안되었는지 확인
	int				m_nLevel;			//레벨의 멤버변수
	int				m_nTimer;			//시간을 내려가게 만들 딜레이
	int				m_stopwatch;		//시간을 표시
	int				m_LevelSpeed;		//레벨에 따라 배경이 빨라지는 스피드
	float			m_LevelBulletSpeed;	//레벨에 따라 총알이 빨라지는 스피드
	cImage*			m_pStartImage;		//스타트 이미지
	cImage*			m_pEnterStart;		//엔터하면 스타트 이미지
	float			m_Blinkimage;		//투명도 조정
	float			m_BlinkSpeed;		//투명해질 속도
	bool			m_TwoJump;			//2단점프 불값
	int				m_nJumpStack;		//점프를 누른만큼 올라가는 변수
	int				BulletPosYrand;		//총알의 y값을 랜덤으로
	cImage*			m_pSpikeImage;		//가시의 이미지
	cImage*			m_pSlideImage;		//플레이어 슬라이드 이미지
	bool			m_isSlide;			//슬라이드 불값
	float			m_nGravity;			//중력멤버변수
	cImage*			m_pbgImage2;		//두번째배경
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