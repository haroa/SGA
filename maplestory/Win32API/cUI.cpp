#include "stdafx.h"
#include "cUI.h"


void cUI::Setup()
{
	m_pImage = g_pImageManager->FindImage("UI");
	m_pHpback = g_pImageManager->FindImage("progressback");
	m_pMpback = g_pImageManager->FindImage("progressback");
	m_pExpback = g_pImageManager->FindImage("progressback");
	
	m_pHpfront = g_pImageManager->FindImage("Hpbar");
	m_pMpfront = g_pImageManager->FindImage("Mpbar");
	m_pExpfront = g_pImageManager->FindImage("Expbar");

	m_rtLevel = RectMake(38, 572, 30, 20);
	m_rtHp = RectMake(237, 568, 90, 10);
	m_rtMp = RectMake(349, 568, 90, 10);
	m_rtExp = RectMake(465, 568, 95, 10);

	
}

void cUI::Update()
{
	m_fExp = (m_fExpmin / m_fExpmax);
	m_nExp = m_fExp * 10000;
	m_nreckoning = m_nExp / 100;
	m_nreckoning2 = m_nExp % 100;
	//m_nreckoning3 = m_nreckoning / 1000;
}

void cUI::Render(HDC hdc)
{
	m_pHpback->Render(hdc, 219, 581, 106, 15);
	m_pHpfront->ProgressRender(hdc, 220, 582, 0, 0, m_fHpmin / m_fHpmax * m_pHpfront->GetWidth());
	//cout << "현재값 : " << m_nHpmin << "맥스값" << m_nHpmax << "현재 길이 : " << m_pHpfront->GetWidth() << endl;
	
	m_pMpback->Render(hdc, 327, 581, 106, 15);
	m_pMpfront->ProgressRender(hdc, 328, 582, 0, 0, m_fMpmin / m_fMpmax * m_pMpfront->GetWidth());
	
	m_pExpback->Render(hdc, 439, 581, 117, 15);
	m_pExpfront->ProgressRender(hdc, 441, 582, 0, 0, m_fExpmin / m_fExpmax * m_pExpfront->GetWidth());
	
	m_pImage->Render(hdc, 0, 532);
	DrawTextBox(hdc, m_rtLevel, 15, to_string(m_nLevel));
	//RectangleMake(hdc, m_rtExp);

	DrawTextBoxWhite(hdc, m_rtHp, 10, "[ " + to_string((int)m_fHpmin) + " / " + to_string((int)m_fHpmax) + " ] ");
	DrawTextBoxWhite(hdc, m_rtMp, 10, "[ " + to_string((int)m_fMpmin) + " / " + to_string((int)m_fMpmax) + " ] ");
	DrawTextBoxWhite(hdc, m_rtExp, 10, " " + to_string((int)m_fExpmin) + " [" + to_string(m_nreckoning) + "." + to_string(m_nreckoning2) + " %] ");
}
