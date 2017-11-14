#include "stdafx.h"
#include "cPlayScene.h"

cPlayScene::cPlayScene()
{
}


cPlayScene::~cPlayScene()
{
}

void cPlayScene::Setup()
{
	OMOKEGG = BLACK;
	choice = 0;
	LoadImageFromFile();
	m_pImgBackground = g_pImageManager->FindImage("omokbg");
	m_pOmok = g_pImageManager->FindImage("omok");
	m_nalpha = 125;
	//���� 15
	//���� 15
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			/*game.pos.x = 21 + 54 * x;
			game.pos.y = 21 + 54 * y;
			game.rtBody = RectMake(game.pos.x - 20, game.pos.y - 20, 40, 40);
			game.isActive = false;
			game.isColor = false;
			game.isShow = false;
	
			m_vecomok.push_back(game);*/

			switch (OMOKEGG)
			{
			case WHITE:
				game.pos.x = 21 + 54 * x;
				game.pos.y = 21 + 54 * y;
				game.rtBody = RectMake(game.pos.x - 20, game.pos.y - 20, 40, 40);
				game.isActive = false;
				game.isColor = true;
				game.isShow = false;

				m_vecomok.push_back(game);
				break;
			case BLACK:
				game.pos.x = 21 + 54 * x;
				game.pos.y = 21 + 54 * y;
				game.rtBody = RectMake(game.pos.x - 20, game.pos.y - 20, 40, 40);
				game.isActive = false;
				game.isColor = false;
				game.isShow = false;

				m_vecomok.push_back(game);
				break;
			}
			
		}
	}
	
}

void cPlayScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->ChangeScene("Title");
	}
	PlayerControll();
}

void cPlayScene::Render()
{
	m_pImgBackground->Render(g_hDC, 0, 0);

	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		//RectangleMakeCenter(g_hDC, iter->pos.x, iter->pos.y, 30, 30);
		//if (iter->isActive)
		//{
		//	if (iter->isColor)
		//	{
		//		m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, m_nalpha);
		//	}
		//	else if (!iter->isColor)
		//	{
		//		m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, m_nalpha);
		//	}
		//}
		if (iter->isActive && iter->isColor)
		{
			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, m_nalpha);
		}
		if (iter->isActive && !iter->isColor)
		{
			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, m_nalpha);
		}
		else
		{
		
		}
		if (iter->isShow)
		{
			if (iter->isColor)
			{
				m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, 255);
			}
			else if (!iter->isColor)
			{
				m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, 255);
			}
		}
	}

	//switch (OMOKEGG)
	//{
	//case WHITE:
	//	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	//	{
	//		//RectangleMakeCenter(g_hDC, iter->pos.x, iter->pos.y, 30, 30);
	//		if (iter->isActive)
	//		{
	//			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, m_nalpha);
	//
	//		}
	//		else
	//		{
	//	
	//		}
	//		if (iter->isShow && iter->isColor)
	//		{
	//			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, 255);
	//		}
	//	}
	//	break;
	//case BLACK:
	//	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	//	{
	//		//RectangleMakeCenter(g_hDC, iter->pos.x, iter->pos.y, 30, 30);
	//		if (iter->isActive)
	//		{
	//			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, m_nalpha);
	//		}
	//		else
	//		{
	//
	//		}
	//		if (iter->isShow && iter->isColor == false)
	//		{
	//			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, 255);
	//		}
	//	}
	//	break;
	//}


	//MiniMapRender();

	//char* str = g_pIniData->LoadDataString("ClassData", "�����", "�ּ�ȣ");
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2 - 50, str, strlen(str));

	//int age = g_pIniData->LoadDataInteger("ClassData", "�����", "�ֵ�ö");
	//char szBuf[128];
	//str = itoa(age, szBuf, 10);
	//TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, str, strlen(str));
}

void cPlayScene::Release()
{

}

void cPlayScene::LoadImageFromFile()
{
	/* ��ü ��� */
	g_pImageManager->AddImage("omokbg", "images/omokbg.bmp", 800,800);

	/* �� */

	/* �̴ϸ�(�� ��Ʈ��) - ���� �� �������� 1/5 ������� �����. */
	

	/* ���α׷����� */
	

	/* �÷��̾� */
	g_pImageManager->AddImage("omok", "images/omok.bmp", 30, 60, 1,2, true, RGB(255, 0, 255));
	
}

void cPlayScene::MiniMapRender()
{
	/* ��� �͵��� �̴ϸ� ������� ����ؼ� �׸���. */

	// ����� ���� �׸���.


	// ���� ������ �׸���.
	

	// �÷��̾� ��ġ

	
}

void cPlayScene::PlayerControll()
{
	switch (OMOKEGG)
	{
	case WHITE:
		for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
		{	
			if (PtInRect(&iter->rtBody, g_ptMouse))
			{
				
				if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON) && !iter->isShow)
				{
					iter->isShow = true;
					OMOKEGG = BLACK;
				}
				else
				{
					iter->isColor = true;
					iter->isActive = true;

				}
			}
			else
			{
				iter->isActive = false;
			}
		}
		break;
	case BLACK:
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (PtInRect(&iter->rtBody, g_ptMouse))
		{
			
			if(g_pKeyManager->isOnceKeyDown(VK_LBUTTON) && !iter->isShow)
			{
				iter->isShow = true;
				OMOKEGG = WHITE;
			}
			else
			{
				iter->isActive = true;
				iter->isColor = false;
			}
		}
		else
		{
			iter->isActive = false;
		}
	}
		break;
	}
}
