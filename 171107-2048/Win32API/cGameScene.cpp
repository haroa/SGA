#include "stdafx.h"
#include "cGameScene.h"


cGameScene::cGameScene()
{
}


cGameScene::~cGameScene()
{
}

void cGameScene::Setup()
{
	m_CreateNum = false;
	m_blankCheck = 0;
	rowCount = -1;
	count = 0;
	countd = -1;
	m_cMap.Setup();
	LoadImages();

	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0)
		{
			rowCount++;
		}


		//tile.uId = i;
		tile.Num = 0;
		tile.isBlank = true;
		tile.isSum = false;
		tile.fPosY = 337 + rowCount * 134;
		tile.fPosX = (i % 4) * 134 + 67;

		m_vectile.push_back(tile);
	}
}

void cGameScene::Update()
{
	srand(time(NULL));

	if (m_CreateNum == false)
	{
		m_idRand = rand() % 100; // 0 ~ 15
		m_numRand = rand() % 2 + 1; // 0 ~ 1
	}


	while (m_blankCheck < m_idRand + 1 && m_CreateNum == false)
	{
		for (auto iter = m_vectile.begin(); iter != m_vectile.end(); iter++)
		{
			if (iter->isBlank)
			{
				m_blankCheck++;
			}
			if (m_blankCheck == m_idRand)
			{
				iter->Num = m_numRand * 2;
				iter->isBlank = false;
				m_CreateNum = true;
				m_blankCheck = 0;
				break;
			}
		}
	}
	PlayerController();
}


void cGameScene::Render()
{
	m_cMap.Render();
	for (auto iter = m_vectile.begin(); iter != m_vectile.end(); iter++)
	{
		if (iter->isBlank == false)
		{
			if (m_number1 != NULL)
			{
				if (iter->Num == 2)
				{
					m_number1->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number2 != NULL)
			{
				if (iter->Num == 4)
				{
					m_number2->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number3 != NULL)
			{
				if (iter->Num == 8)
				{
					m_number3->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number4 != NULL)
			{
				if (iter->Num == 16)
				{
					m_number4->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number5 != NULL)
			{
				if (iter->Num == 32)
				{
					m_number5->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number6 != NULL)
			{
				if (iter->Num == 64)
				{
					m_number6->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number7 != NULL)
			{
				if (iter->Num == 128)
				{
					m_number7->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number8 != NULL)
			{
				if (iter->Num == 256)
				{
					m_number8->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number9 != NULL)
			{
				if (iter->Num == 512)
				{
					m_number9->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number10 != NULL)
			{
				if (iter->Num == 1024)
				{
					m_number10->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
			if (m_number11 != NULL)
			{
				if (iter->Num == 2048)
				{
					m_number11->Render(g_hDC, iter->fPosX, iter->fPosY);
				}
			}
		}
		else
		{

		}

	}
	for (auto iter = m_vectile.begin(); iter != m_vectile.end(); iter++)
	{
		count++;
		if (count % 4 == 0)
		{
			countd++;
		}
		char str[128];
		sprintf(str, "%d", iter->Num);
		TextOut(g_hDC, (count % 4) * 20 + 100, countd * 20 + 200, str, strlen(str));
	}	
}


void cGameScene::PlayerController()
{
	if (g_pKeyManager->isOnceKeyDown(VK_LEFT))
	{
		for (auto iter = m_vectile.begin(); iter != m_vectile.end(); iter++)
		{
			for (int i = 0; i < 3; i++)
			{
				if ((m_vectile.begin() + i)->Num == (m_vectile.begin() + (i + 1))->Num)
				{
					iter->isSum = true;
					(m_vectile.begin() + i)->Num = 2 * (m_vectile.begin() + (i + 1))->Num;
					(m_vectile.begin() + (i + 1))->isBlank = true;
					m_CreateNum = false;
				}
				else if ((m_vectile.begin() + i)->Num != (m_vectile.begin() + (i + 1))->Num)
				{
					iter->isSum = false;
					m_CreateNum = false;
				}
				if ((m_vectile.begin() + i)->isBlank == true && (m_vectile.begin() + (i + 1))->isBlank == false)
				{
					(m_vectile.begin() + i)->isBlank = false;
					(m_vectile.begin() + (i + 1))->isBlank = true;
					(m_vectile.begin() + i)->Num = (m_vectile.begin() + (i + 1))->Num;
				}
			}
		}
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RIGHT))
	{

	}
	else if (g_pKeyManager->isOnceKeyDown(VK_UP))
	{

	}
	else if (g_pKeyManager->isOnceKeyDown(VK_DOWN))
	{

	}
}

void cGameScene::LoadImages()
{
	m_number1 = g_pImageManager->FindImage("2");
	m_number2 = g_pImageManager->FindImage("4");
	m_number3 = g_pImageManager->FindImage("8");
	m_number4 = g_pImageManager->FindImage("16");
	m_number5 = g_pImageManager->FindImage("32");
	m_number6 = g_pImageManager->FindImage("64");
	m_number7 = g_pImageManager->FindImage("128");
	m_number8 = g_pImageManager->FindImage("256");
	m_number9 = g_pImageManager->FindImage("512");
	m_number10 = g_pImageManager->FindImage("1024");
	m_number11 = g_pImageManager->FindImage("2048");
}
