#pragma once
class cUi
{
private:
	RECT m_rtInfo;
	float m_InfoX;
	float m_InfoY;

	RECT	m_rtinformation;
	float	m_finformationX;
	float	m_finformationY;

	RECT	m_rtPotion1;
	float	m_fPotion1X;
	float	m_fPotion1Y;
	int		m_nCountPotion1;

	RECT	m_rtPotion2;
	float	m_fPotion2X;
	float	m_fPotion2Y;
	int		m_nCountPotion2;

	RECT	m_rtHp;
	float	m_fHpX;
	float	m_fHpY;
	int		m_nHp;

	RECT	m_rtAtk;
	float	m_fAtkX;
	float	m_fAtkY;
	int		m_nAtk;

	RECT	m_rtDef;
	float	m_fDefX;
	float	m_fDefY;
	int		m_nDef;

	RECT	m_rtMoney;
	float	m_fMoneyX;
	float	m_fMoneyY;
	int		m_nMoney;
public:
	cUi();
	~cUi();

	void Setup();
	void Update();
	void Render();

#pragma region Get
	int GetPotion1() { return m_nCountPotion1; }
	int GetPotion2() { return m_nCountPotion2; }
	int GetHp() { return m_nHp; }
	int GetAtk() { return m_nAtk; }
	int GetDef() { return m_nDef; }
	int GetMoney() { return m_nMoney; }

#pragma endregion

#pragma region Set
	void SetPotion1(int potion1) { m_nCountPotion1 = potion1; }
	void SetPotion2(int potion2) { m_nCountPotion2 = potion2; }
	void SetHp(int hp) { m_nHp = hp; }
	void SetAtk(int atk) { m_nAtk = atk; }
	void SetDef(int def) { m_nDef = def; }
	void SetMoney(int money) { m_nMoney = money; }
#pragma endregion



};

