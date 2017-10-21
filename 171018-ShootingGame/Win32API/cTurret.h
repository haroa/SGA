#pragma once
#include "cImage.h"

class cTurret
{
private:
#pragma region Member
	float m_BossPosX;
	float m_BossPosY;
	int m_BossWidth;
	int m_BossHeight;
	float m_BossRate;

#pragma endregion


#pragma region Left1
	cImage* m_pLeft1;
	RECT m_rtLeft1;
	float m_fPosXLeft1;
	float m_fPosYLeft1;
	float m_fHpLeft1;
	float m_fDealyLeft1;
#pragma endregion

#pragma region Left2
	cImage* m_pLeft2;
	RECT m_rtLeft2;
	float m_fPosXLeft2;
	float m_fPosYLeft2;
	float m_fHpLeft2;
	float m_fDealyLeft2;
#pragma endregion

#pragma region Right1
	cImage* m_pRight1;
	RECT m_rtRight1;
	float m_fPosXRight1;
	float m_fPosYRight1;
	float m_fHpRight1;
	float m_fDealyRight1;
#pragma endregion

#pragma region Right2
	cImage* m_pRight2;
	RECT m_rtRight2;
	float m_fPosXRight2;
	float m_fPosYRight2;
	float m_fHpRight2;
	float m_fDealyRight2;
#pragma endregion



	
	
public:
#pragma region Get
	float GetBossRate() { return m_BossRate; }

	RECT GetBodyLeft1() { return m_rtLeft1; }
	float GetPosXLeft1() { return m_fPosXLeft1; }
	float GetPosYLeft1() { return m_fPosYLeft1; }
	float GetHpLeft1() { return m_fHpLeft1; }

	RECT GetBodyLeft2() { return m_rtLeft2; }
	float GetPosXLeft2() { return m_fPosXLeft2; }
	float GetPosYLeft2() { return m_fPosYLeft2; }
	float GetHpLeft2() { return m_fHpLeft2; }

	RECT GetBodyRight1() { return m_rtRight1; }
	float GetPosXRight1() { return m_fPosXRight1; }
	float GetPosYRight1() { return m_fPosYRight1; }
	float GetHpRight1() { return m_fHpRight1; }

	RECT GetBodyRight2() { return m_rtRight2; }
	float GetPosXRight2() { return m_fPosXRight2; }
	float GetPosYRight2() { return m_fPosYRight2; }
	float GetHpRight2() { return m_fHpRight2; }
#pragma endregion

#pragma region Set
	void SetBossPosX(float PosX) { m_BossPosX = PosX; }
	void SetBossPosY(float PosY) { m_BossPosY = PosY; }
	void SetBossWidth(int Width) { m_BossWidth = Width; }
	void SetBossHeight(int Height) { m_BossHeight = Height; }
	void SetBossRate(float Rate) { m_BossRate = Rate; }

	void SetBodyLeft1(RECT Left1) { m_rtLeft1 = Left1; }
	void SetPosXLeft1(float Left1) { m_fPosXLeft1 = Left1; }
	void SetPosYLeft1(float Left1) { m_fPosYLeft1 = Left1; }
	void SetHpLeft1(float Left1) { m_fHpLeft1 = Left1; }

	void SetBodyLeft2(RECT Left2) { m_rtLeft2 = Left2; }
	void SetPosXLeft2(float Left2) { m_fPosXLeft2 = Left2; }
	void SetPosYLeft2(float Left2) { m_fPosYLeft2 = Left2; }
	void SetHpLeft2(float Left2) { m_fHpLeft2 = Left2; }


	void SetBodyRight1(RECT Right1) { m_rtRight1 = Right1; }
	void SetPosXRight1(float Right1) { m_fPosXRight1 = Right1; }
	void SetPosYRight1(float Right1) { m_fPosYLeft1 = Right1; }
	void SetHpRight1(float Right1) { m_fHpRight1 = Right1; }


	void SetBodyRight2(RECT Right2) { m_rtRight2 = Right2; }
	void SetPosXRight2(float Right2) { m_fPosXRight2 = Right2; }
	void SetPosYRight2(float Right2) { m_fPosYRight2 = Right2; }
	void SetHpRight2(float Right2) { m_fHpRight2 = Right2; }


#pragma endregion



	cTurret();
	~cTurret();

	void Setup();
	void Update();
	void Render();
};

