#pragma once

class cBoss;

class cTurret
{
private:
	cBoss* m_pcBoss;


	RECT m_rtLeft1;
	float m_fPosXLeft1;
	float m_fPosYLeft1;
	
	RECT m_rtLeft2;
	float m_fPosXLeft2;
	float m_fPosYLeft2;
	
	RECT m_rtRight1;
	float m_fPosXRight1;
	float m_fPosYRight1;
	
	RECT m_rtRight2;
	float m_fPosXRight2;
	float m_fPosYRight2;
public:
#pragma region Get
	RECT GetBodyLeft1() { return m_rtLeft1; }
	float GetPosXLeft1() { return m_fPosXLeft1; }
	float GetPosYLeft1() { return m_fPosYLeft1; }

	RECT GetBodyLeft2() { return m_rtLeft2; }
	float GetPosXLeft2() { return m_fPosXLeft2; }
	float GetPosYLeft2() { return m_fPosYLeft2; }

	RECT GetBodyRight1() { return m_rtRight1; }
	float GetPosXRight1() { return m_fPosXRight1; }
	float GetPosYRight1() { return m_fPosYRight1; }

	RECT GetBodyRight2() { return m_rtRight2; }
	float GetPosXRight2() { return m_fPosXRight2; }
	float GetPosYRight2() { return m_fPosYRight2; }
#pragma endregion

#pragma region Set
	void SetBoss(cBoss* Boss) { m_pcBoss = Boss; }


	void SetBodyLeft1(RECT Left1) { m_rtLeft1 = Left1; }
	void SetPosXLeft1(float Left1) { m_fPosXLeft1 = Left1; }
	void SetPosYLeft1(float Left1) { m_fPosYLeft1 = Left1; }

	void SetBodyLeft2(RECT Left2) { m_rtLeft2 = Left2; }
	void SetPosXLeft2(float Left2) { m_fPosXLeft2 = Left2; }
	void SetPosYLeft2(float Left2) { m_fPosYLeft2 = Left2; }


	void SetBodyRight1(RECT Right1) { m_rtRight1 = Right1; }
	void SetPosXRight1(float Right1) { m_fPosXRight1 = Right1; }
	void SetPosYRight1(float Right1) { m_fPosYLeft1 = Right1; }


	void SetBodyRight2(RECT Right2) { m_rtRight2 = Right2; }
	void SetPosXRight2(float Right2) { m_fPosXRight2 = Right2; }
	void SetPosYRight2(float Right2) { m_fPosYRight2 = Right2; }


#pragma endregion



	cTurret();
	~cTurret();

	void Setup();
	void Update();
	void Render();
};

