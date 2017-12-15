#pragma once

class cMonster
{
private:
	cImage* m_imgbody;
private:
	float	m_fMonsterX;
	float	m_fMonsterY;
	RECT	m_rtMonster;
	int		m_nHp;
	int		m_nAtk;
	int		m_nDef;
	int		m_nSizeW;
	int		m_nSizeH;
	bool	m_isLeft;
private://프레임을 위한 변수들
	//대기상태 프레임
	int		m_nLeftIdleFrameXmin;
	int		m_nLeftIdleFrameXmax;
	int		m_nLeftIdleFrameY;
	int		m_nRightIdleFrameXmin;
	int		m_nRightIdleFrameXmax;
	int		m_nRightIdleFrameY;
	//이동 프레임
	int		m_nLeftMoveFrameXmin;
	int		m_nLeftMoveFrameXmax;
	int		m_nLeftMoveFrameY;
	int		m_nRightMoveFrameXmin;
	int		m_nRIghtMoveFrameXmax;
	int		m_nRightMoveFrameY;
	//히트 프레임
	int		m_nLeftHitFrameXmin;
	int		m_nLeftHitFrameXmax;
	int		m_nLeftHitFrameY;
	int		m_nRightHitFrameXmin;
	int		m_nRightHitFrameXmax;
	int		m_nRightHitFrameY;
	//죽음 프레임
	int		m_nLeftDeadFrameXmin;
	int		m_nLeftDeadFrameXmax;
	int		m_nLeftDeadFraemY;
	int		m_nRightDeadFrameXmin;
	int		m_nRightDeadFrameXmax;
	int		m_nRightDeadFrameY;
	//테스트
	int*		m_nTest;
public:
	cMonster() {};
	~cMonster() {};

	void Setup();
	void Update();
	void Render(HDC hdc);
	//void TimterLeftFrame(int size);
	//void TimerRightFrame(int size);


	int GetHp() { return m_nHp; }
	
#pragma region Get
	RECT GetRectMonster() { return m_rtMonster; }
	float GetPosX() { return m_fMonsterX; }
	float GetPosY() { return m_fMonsterY; }
	int	GetSizeW() { return m_nSizeW; }
	int	GetSizeH() { return m_nSizeH; }
#pragma endregion

#pragma region Set
	void SetPosY(float y) { m_fMonsterY = y; }
	//기본스탯 셋터
	void SetHp(int hp) { m_nHp = hp; }
	void SetAtk(int atk) { m_nAtk = atk; }
	void SetDef(int def) { m_nDef = def; }
	void SetSizeW(int width) { m_nSizeW = width; }
	void SetSizeH(int height) { m_nSizeH = height; }
	//프레임 셋터
	void SetImg(string imgname) { m_imgbody = g_pImageManager->FindImage(imgname); }
	//대기상태 셋터
	void SetLeftIdleFrameXmin(int xmin) { m_nLeftIdleFrameXmin = xmin; }
	void SetLeftIdleFrameXmax(int xmax) { m_nLeftIdleFrameXmax = xmax; }
	void SetLeftIdleFrameY(int y) { m_nLeftIdleFrameY = y; }
	void SetRightIdleFrameXmin(int xmin) { m_nRightIdleFrameXmin = xmin; }
	void SetRightIdleFrameXmax(int xmax) { m_nRightIdleFrameXmax = xmax; }
	void SetRightIdleFrameY(int y) { m_nRightIdleFrameY = y; }
	//움직이는 상태 셋터
	void SetLeftMoveFrameXmin(int xmin) { m_nLeftMoveFrameXmin = xmin; }
	void SetLeftMoveFrameXmax(int xmax) { m_nLeftMoveFrameXmax = xmax; }
	void SetLeftMoveFrameY(int y) { m_nLeftMoveFrameY = y;}
	void SetRightMoveFrameXmin(int xmin) { m_nRightMoveFrameXmin = xmin; }
	void SetRightMoveFrameXmax(int xmax) { m_nRIghtMoveFrameXmax = xmax; }
	void SetRightMoveFrameY(int y) { m_nRightMoveFrameY = y; }
	//맞은상태 셋터
	void SetLeftHitFrameXmin(int xmin) { m_nLeftHitFrameXmin = xmin; }
	void SetLeftHitFrameXmax(int xmax) { m_nLeftHitFrameXmax = xmax; }
	void SetLeftHitFrameY(int y) { m_nLeftHitFrameY = y; }
	void SetRightHitFrameXmin(int xmin) { m_nRightHitFrameXmin = xmin; }
	void SetRightHitFrameXmax(int xmax) { m_nRightHitFrameXmax = xmax; }
	void SetRightHitFrameY(int y) { m_nRightHitFrameY = y; }
	//죽은상태 셋터
	void SetLeftDeadFrameXmin(int xmin) { m_nLeftDeadFrameXmin = xmin; }
	void SetLeftDeadFrameXmax(int xmax) { m_nLeftDeadFrameXmax = xmax; }
	void SetLeftDeadFrameY(int y) { m_nLeftDeadFraemY = y; }
	void SetRightDeadFrameXmin(int xmin) { m_nLeftDeadFrameXmin = xmin; }
	void SetRightDeadFrameXmax(int xmax) { m_nLeftDeadFrameXmax = xmax; }
	void SetRightDeadFrameY(int y) { m_nRightDeadFrameY = y; }
	//테스트
	void SetTest(int* test) { m_nTest = test; }
#pragma endregion

};

