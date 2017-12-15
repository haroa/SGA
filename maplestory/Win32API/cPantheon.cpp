#include "stdafx.h"
#include "cPantheon.h"

void cPantheon::Setup()
{
	JsonLoad();
	m_pBuffer = g_pImageManager->FindImage("MappBuffer");
	m_PosX = m_cPlayer.GetPosX();
	m_PosY = m_cPlayer.GetPosY();
	m_fFromX = 0.0f;
	m_fFromY = 0.0f;
	m_fToX = 0.0f;
	m_fToY = 0.0f;
	m_fT = 0.0f;
	m_cPantheonMap.Setup();
	m_cCursor.Setup();
	m_cPlayer.Setup();

	m_cUI.Setup();
	m_isHit = false;
	m_isMonsterLeft = true;
	g_pTimerManager->AddSimpleTimer("Monster_Spawn");

}

void cPantheon::Update()
{
	if (g_pTimerManager->TickSimpleTimer("Monster_Spawn") > 50)
	{
		g_pTimerManager->ResetSimpleTimer("Monster_Spawn");
		MonsterSpawn();
	}
	m_cMonster.SetTest(m_vecMonsters.size());
	cout << "벡터의 사이즈 : " << m_vecMonsters.size() << endl;
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->SetNextScene(SLIST_TITLE);
		g_pSceneManager->ChangeScene(SLIST_LOADING);
	}
	m_fToX = m_cPlayer.GetPosX();
	m_fToY = m_cPlayer.GetPosY();
	
	m_PosX = (1.0f - m_fT) * m_fFromX + m_fT * m_fToX;
	m_PosY = (1.0f - m_fT) * m_fFromY + m_fT * m_fToY;
	
	m_fFromX = m_PosX;
	m_fFromY = m_PosY;

	m_fT += 0.00003;	

	if (m_fT >= 0.9f)
	{
		m_fT = 0.0f;
	}

	m_viewport = ViewPortMake(m_PosX, m_PosY, WINSIZEX, WINSIZEY, 2000, 1500);
	m_cCursor.Update();
	m_cPantheonMap.Update();
	m_cPlayer.Update();
	m_cUI.SetHpmin(m_cPlayer.GetCurrHp());
	m_cUI.SetHpmax(m_cPlayer.GetMaxHp());
	m_cUI.SetMpmin(m_cPlayer.GetCurrMp());
	m_cUI.SetMpmax(m_cPlayer.GetMaxMp());
	m_cUI.SetExpmin(m_cPlayer.GetCurrExp());
	m_cUI.SetExpmax(m_cPlayer.GetMaxExp());
	m_cUI.SetLevel(m_cPlayer.GetLevel());
	//m_cMonster.Update();
	for (auto iter = m_vecMonsters.begin(); iter != m_vecMonsters.end(); iter++)
	{
		iter->Update();
	}
	//MonsterUpdate();
	m_cUI.Update();
}

void cPantheon::Render()
{
	m_cPantheonMap.Render(m_pBuffer->GetMemDC());
	//m_cMonster.Render(m_pBuffer->GetMemDC());
	for (auto iter = m_vecMonsters.begin(); iter != m_vecMonsters.end(); iter++)
	{
		iter->Render(m_pBuffer->GetMemDC());
	}
	m_cPlayer.Render(m_pBuffer->GetMemDC());
	m_pBuffer->ViewPortRender(g_hDC, m_viewport, WINSIZEX, WINSIZEY);
	m_cUI.Render(g_hDC);
	m_cCursor.Render();

	//char str[128];
	//sprintf(str, "몬스터 체력 : %d", m_cMonster.GetHp());
	//TextOut(g_hDC, 10, 320, str, strlen(str));
}

void cPantheon::Release()
{
}

void cPantheon::MonsterSpawn()
{
	m_cMonster.Setup();

	m_vecMonsters.push_back(m_cMonster);
}

void cPantheon::MonsterUpdate()
{
	//if (m_isMonsterLeft)
	//{
	//	m_cMonster.TimterLeftFrame(1, m_isMonsterLeft);
	//}
	//else if (!m_isMonsterLeft)
	//{
	//	m_cMonster.TimerRightFrame(1, m_isMonsterLeft);
	//}
//	cout << "몬스터 사이즈 : " << m_vecMonsters.size() << endl;
}

void cPantheon::JsonLoad()
{
	json loaddata;
	g_pFileManager->JsonLoad("Monsters", JSON_PATH);
	loaddata = g_pFileManager->JsonFind("Monsters");
	int randomjson = rand() % loaddata["monsters"].size();
	cout << "랜덤값 : " << randomjson << endl;
	m_cMonster.SetImg(loaddata["monsters"][randomjson]["name"]);
	m_cMonster.SetHp(loaddata["monsters"][randomjson]["hp"]);
	m_cMonster.SetAtk(loaddata["monsters"][randomjson]["atk"]);
	m_cMonster.SetDef(loaddata["monsters"][randomjson]["def"]);
	m_cMonster.SetSizeW(loaddata["monsters"][randomjson]["sizew"]);
	m_cMonster.SetSizeH(loaddata["monsters"][randomjson]["sizeh"]);
	m_cMonster.SetPosY(loaddata["monsters"][randomjson]["PosY"]);
	m_cMonster.SetLeftIdleFrameXmin(loaddata["monsters"][randomjson]["leftidleframeXmin"]);
	m_cMonster.SetLeftIdleFrameXmax(loaddata["monsters"][randomjson]["leftidleframeXmax"]);
	m_cMonster.SetLeftIdleFrameY(loaddata["monsters"][randomjson]["leftidleframeY"]);
	m_cMonster.SetLeftMoveFrameXmin(loaddata["monsters"][randomjson]["leftwalkframeXmin"]);
	m_cMonster.SetLeftMoveFrameXmax(loaddata["monsters"][randomjson]["leftwalkframeXmax"]);
	m_cMonster.SetLeftMoveFrameY(loaddata["monsters"][randomjson]["leftwalkframeY"]);
	m_cMonster.SetRightMoveFrameXmin(loaddata["monsters"][randomjson]["rightwalkframeXmin"]);
	m_cMonster.SetRightMoveFrameXmax(loaddata["monsters"][randomjson]["rightwalkframeXmax"]);
	m_cMonster.SetRightMoveFrameY(loaddata["monsters"][randomjson]["rightwalkframeY"]);
}
