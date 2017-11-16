#include "stdafx.h"
#include "cUi.h"


cUi::cUi()
{
}


cUi::~cUi()
{
}

void cUi::Setup()
{
	m_InfoX = 800;
	m_InfoY = 0;
	m_rtInfo = RectMake(m_InfoX, m_InfoY, 200, 600);
#pragma region Information
	m_finformationX = 800;
	m_finformationY = 0;
	m_rtinformation = RectMake(m_finformationX, m_finformationY, 200, 50);

	m_fPotion1X = 800;
	m_fPotion1Y = 50;
	m_rtPotion1 = RectMake(m_fPotion1X, m_fPotion1Y, 200, 50);
	m_nCountPotion1 = 10;

	m_fPotion2X = 800;
	m_fPotion2Y = 100;
	m_rtPotion2 = RectMake(m_fPotion2X, m_fPotion2Y, 200, 50);
	m_nCountPotion2 = 10;

	m_fHpX = 800;
	m_fHpY = 150;
	m_rtHp = RectMake(m_fHpX, m_fHpY, 200, 50);
	m_nHp = 100;

	m_fAtkX = 800;
	m_fAtkY = 200;
	m_rtAtk = RectMake(m_fAtkX, m_fAtkY, 200, 50);
	m_nAtk = 30;

	m_fDefX = 800;
	m_fDefY = 250;
	m_rtDef = RectMake(m_fDefX, m_fDefY, 200, 50);
	m_nDef = 20;

	m_fMoneyX = 800;
	m_fMoneyY = 300;
	m_rtMoney = RectMake(m_fMoneyX, m_fMoneyY, 200, 50);
	m_nMoney = 500000;
#pragma endregion

}

void cUi::Update()
{
}

void cUi::Render()
{
	Rectangle(g_hDC, m_rtInfo.left, m_rtInfo.top, m_rtInfo.right, m_rtInfo.bottom);
	//TextOut(g_hDC, m_finformationX, m_finformationY, "==========정보===========", strlen("==========정보==========="));

	string szinfo = "==========정보===========";
	DrawTextBox(g_hDC, m_rtinformation, 15, szinfo);
	
	string szpotion1 = "포션1 : ";
	szpotion1.append(to_string(m_nCountPotion1));
	DrawTextBox(g_hDC, m_rtPotion1, 15, szpotion1);

	string szpotion2 = "포션2 : ";
	szpotion2.append(to_string(m_nCountPotion2));
	DrawTextBox(g_hDC, m_rtPotion2, 15, szpotion2);

	string szhp = "HP : ";
	szhp.append(to_string(m_nHp));
	DrawTextBox(g_hDC, m_rtHp, 15, szhp);

	string szatk = "공격력 : ";
	szatk.append(to_string(m_nAtk));
	DrawTextBox(g_hDC, m_rtAtk, 15, szatk);

	string szdef = "방어력 : ";
	szdef.append(to_string(m_nDef));
	DrawTextBox(g_hDC, m_rtDef, 15, szdef);

	string szmoney = "돈 : ";
	szmoney.append(to_string(m_nMoney));
	DrawTextBox(g_hDC, m_rtMoney, 15, szmoney);
}
