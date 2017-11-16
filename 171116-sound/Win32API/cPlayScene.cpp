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
	m_pImgBackground = g_pImageManager->FindImage("omokbg");
	m_pOmok = g_pImageManager->FindImage("omok");
	m_nalpha = 125;
	checkcountwidth = 0;
	checkcountHeight = 0;
	checkcountdialeft = 0;
	checkcountdiaright = 0;
	//가로 15
	//세로 15
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
				game.nPosX = x;
				game.nPosY = y;
				game.pos.x = 21 + 54 * x;
				game.pos.y = 21 + 54 * y;
				game.rtBody = RectMake(game.pos.x - 20, game.pos.y - 20, 40, 40);
				game.isActive = false;
				game.isColor = true;
				game.iswhite = true;
				game.isShow = false;
				game.isCheck = false;

				m_vecomok.push_back(game);
				break;
			case BLACK:
				game.nPosX = x;
				game.nPosY = y;
				game.pos.x = 21 + 54 * x;
				game.pos.y = 21 + 54 * y;
				game.rtBody = RectMake(game.pos.x - 20, game.pos.y - 20, 40, 40);
				game.isActive = false;
				game.isColor = false;
				game.iswhite = false;
				game.isShow = false;
				game.isCheck = false;

				m_vecomok.push_back(game);
				break;
			}
			
		}
	}
	g_pSoundManager->Play("Dungeon1_BGM");
}

void cPlayScene::Update()
{
	if (g_pKeyManager->isOnceKeyDown(VK_ESCAPE))
	{
		g_pSceneManager->ChangeScene(SLIST_TITLE);
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
		if (iter->isActive == true && iter->iswhite)
		{
			m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, m_nalpha);
		}
		else
		{

		}
		if (iter->isActive == true && !iter->iswhite)
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
				m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 1, 255);
			}
			else if (!iter->isColor)
			{
				m_pOmok->AlphaFrameRender(g_hDC, iter->pos.x - 15, iter->pos.y - 15, 30, 30, 0, 0, 255);
			}
		}
	}
	char str[128];
	sprintf(str, "%d", checkcountwidth);
	TextOut(g_hDC, 100,300, str, strlen(str));
}

void cPlayScene::Release()
{

}

void cPlayScene::LoadImageFromFile()
{
	/* 전체 배경 */
	

	/* 맵 */

	/* 미니맵(빈 비트맵) - 원본 맵 사이즈의 1/5 사이즈로 만든다. */
	

	/* 프로그레스바 */
	

	/* 플레이어 */
	
}

void cPlayScene::MiniMapRender()
{
	/* 모든 것들을 미니맵 사이즈로 축소해서 그린다. */

	// 배경을 먼저 그린다.


	// 지형 지물을 그린다.
	

	// 플레이어 위치

	
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
					g_pSoundManager->Play("Sword_1");
					iter->isShow = true;
					OMOKEGG = BLACK;
					iter->isColor = true;
					iter->isCheck = true;
				}
				else
				{
					iter->isActive = true;
					iter->iswhite = true;
				}
				//================오목체크=========================
				if (iter->isCheck)
				{
					Win(iter->nPosX, iter->nPosY, iter->isColor);
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

				if (g_pKeyManager->isOnceKeyDown(VK_LBUTTON) && !iter->isShow)
				{
					g_pSoundManager->Play("Sword_1");
					iter->isShow = true;
					OMOKEGG = WHITE;
					iter->isColor = false;
					iter->isCheck = true;
				}
				else
				{
					iter->isActive = true;
					iter->iswhite = false;
				}
				if (iter->isCheck)
				{
					Win(iter->nPosX, iter->nPosY, !iter->isColor);
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

void cPlayScene::Win(int X, int Y, bool isColor)
{
	checkcountwidth = 0;
	//===============================가로======================================
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
			iter->isCheck = false;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 1 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 2 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 3 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 4 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	//-----------------------------------------------------------------------------
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 1 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 2 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 3 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 4 && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountwidth++;
		}
	}
	//=====================================세로==========================================
	checkcountHeight = 0;
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
			iter->isCheck = false;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X  && iter->nPosY == Y - 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y - 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y - 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y - 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	//-----------------------------------------------------------------------------
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y + 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y + 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y + 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y + 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountHeight++;
		}
	}
	//==========================================왼쪽대각선======================================
	checkcountdialeft = 0;
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
			iter->isCheck = false;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 1  && iter->nPosY == Y - 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 2 && iter->nPosY == Y - 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 3 && iter->nPosY == Y - 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 4 && iter->nPosY == Y - 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	//-----------------------------------------------------------------------------
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 1 && iter->nPosY == Y + 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 2 && iter->nPosY == Y + 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 3 && iter->nPosY == Y + 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 4 && iter->nPosY == Y + 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdialeft++;
		}
	}
	//================================오른쪽대각선======================================
	checkcountdiaright = 0;
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X && iter->nPosY == Y && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
			iter->isCheck = false;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 1 && iter->nPosY == Y + 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 2 && iter->nPosY == Y + 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 3 && iter->nPosY == Y + 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X + 4 && iter->nPosY == Y + 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	//-----------------------------------------------------------------------------
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 1 && iter->nPosY == Y - 1 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 2 && iter->nPosY == Y - 2 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 3 && iter->nPosY == Y - 3 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}
	for (auto iter = m_vecomok.begin(); iter != m_vecomok.end(); iter++)
	{
		if (iter->nPosX == X - 4 && iter->nPosY == Y - 4 && iter->isColor == isColor && iter->isShow)
		{
			checkcountdiaright++;
		}
	}


	if (checkcountwidth == 5)
	{
		Sleep(2000);
		PostQuitMessage(0);
	}
	if (checkcountHeight == 5)
	{
		Sleep(2000);
		PostQuitMessage(0);
	}
	if (checkcountdialeft == 5)
	{
		Sleep(2000);
		PostQuitMessage(0);
	}
	if (checkcountdiaright == 5)
	{
		Sleep(2000);
		PostQuitMessage(0);
	}

}
