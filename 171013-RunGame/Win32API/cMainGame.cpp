#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame()
	: m_isPlaying(false)
	, m_fJumpPower(-10.0f)
	, m_fCurrGravity(0.0f)
	, m_isJumppinig(false)
	, m_fbgPosX(0.0f)
	, m_nScore(0)
	, m_fbgSpeed(5.0f)
	, m_bgdelay(ACTIVE_TIME)
	, m_isAtive(false)
	, m_nLevel(1)
	, m_nTimer(TIMER)
	, m_stopwatch(10)
	, m_LevelSpeed(LEVEL_SPEED)
	, m_LevelBulletSpeed(BULLET_SPEED)
	, m_Blinkimage(0.0f)
	, m_BlinkSpeed(3.5f)
	, m_nJumpStack(2)
	, m_isSlide(false)
	, m_nGravity(GRAVITY)
	, m_nNumberDelay(NUMBER_DELAY)
	, m_ObjectSpeed(5.0f)
	, m_BulletObjectSpeed(8.0f)
	, m_fOutDelay(0.0f)
{

	srand(time(NULL));
	BulletPosYrand = rand() % 291 + 200;

	m_pStartImage = new cImage;
	m_pStartImage->Setup("images/startimage.bmp", 800, 600);
	m_pEnterStart = new cImage;
	m_pEnterStart->Setup("images/enterImage.bmp", 446, 33, true, RGB(255, 0, 255));
	m_pNumber = new cImage;
	m_pNumber->Setup("images/Number1.bmp", 347, 77, 6, 1, WINSIZEX / 2, WINSIZEY / 2, true, RGB(255, 0, 255));

	m_pFrameImage = new cImage;
	m_pFrameImage->Setup("images/metalslug.bmp", 409,81, 6, 1, WINSIZEX / 2 - 200, WINSIZEY / 2 + 210, true, RGB(255, 0, 255));
	m_pbgFrameImage = new cImage;
	m_pbgFrameImage->Setup("images/background1.bmp", 800, 600);
	m_pbgImage2 = new cImage;
	m_pbgImage2->Setup("images/background2.bmp", 800, 600);
	m_pbgImage3 = new cImage;
	m_pbgImage3->Setup("images/background3.bmp", 800, 600);
	m_pbgImage4 = new cImage;
	m_pbgImage4->Setup("images/background4.bmp", 800, 600);
	m_pGameover = new cImage;
	m_pGameover->Setup("images/gameover.bmp", 800, 600);
	m_pClear = new cImage;
	m_pClear->Setup("images/gameclear.bmp", 800, 600);

	m_pSlideImage = new cImage;
	m_pSlideImage->Setup("images/metalslugdown.bmp", 205, 59, 4,1,WINSIZEX / 2 - 200, WINSIZEY / 2 + 210, true, RGB(255, 0, 255));
	m_pRestart = new cImage;
	m_pRestart->Setup("images/restart.bmp", 600, 60, true, RGB(255, 0, 255));

	m_pFrameBullet = new cImage;
	m_pFrameBullet->Setup("images/bullet.bmp", 150,60, 4, 1,WINSIZEX, BulletPosYrand, true, RGB(255, 0, 255));
	
	m_pFrameItem = new cImage;
	m_pFrameItem->Setup("images/item1(score).bmp", 76, 80, true, RGB(255, 0, 255));
	m_pFrameItem2 = new cImage;
	m_pFrameItem2->Setup("images/item2(slow).bmp", 47, 51, true, RGB(255, 0, 255));
	m_pSpikeImage = new cImage;
	m_pSpikeImage->Setup("images/spike.bmp", 40, 60, true, RGB(255, 0, 255));
	m_nMovedelay = MOVE_DELAY;
	m_moveitem = ITEM_DELAY;
	m_GameState = GAME_READY;
}


cMainGame::~cMainGame()
{

}

void cMainGame::Update()
{
	cGameNode::Update();

	switch (m_GameState)
	{
	case GAME_READY:
		Ready();
		break;
	case GAME_COUNT:
	{
		NextNumber();
		if (m_pNumber->GetFrameX() == 7)
		{
			m_GameState = GAME_PLAYING;
		}
		break;
	}
	case GAME_PLAYING:
		Play();
		if (m_nLevel == 14)
		{
			m_GameState = GAME_CLEAR;
		}
		break;
	case GAME_OVER:
	//	Ready();
		break;
	case GAME_CLEAR:

		break;
	default:
		break;
	}
	SystemControl();
}


void cMainGame::Render()
{
	// ������� �̹����� ĥ�Ѵ�.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	switch (m_GameState)
	{
	case GAME_READY:
		ReadyRender();
		break;
	case GAME_COUNT:
		PlayingRender();
		NumberRender();
		break;
	case GAME_PLAYING:
		PlayingRender();
		break;
	case GAME_OVER:
		GameOverRender();
		break;
	case GAME_CLEAR:
		GameClear();
		break;
	}
}

void cMainGame::CreateSpike()
{
	cSpike tempSpike;
	int spikerand = rand() % 101;

	if (spikerand > SPIKE_ATIVE)
	{
		tempSpike.m_pspikeImage = m_pSpikeImage;
		tempSpike.m_PosX = WINSIZEX;
		tempSpike.m_PosY = WINSIZEY / 2 + 180;
		tempSpike.SpikeBody = RectMakeCenter(tempSpike.m_PosX, tempSpike.m_PosY, tempSpike.m_pspikeImage->GetWidth(), tempSpike.m_pspikeImage->GetHeight());

		m_vcSpike.push_back(tempSpike);
	}
	else
	{

	}
	
}

void cMainGame::MoveSpike()
{

		for (auto iter2 = m_vcSpike.begin(); iter2 != m_vcSpike.end(); iter2++)
		{
			iter2->m_PosX -= m_ObjectSpeed + m_LevelBulletSpeed;
			iter2->SpikeBody = RectMakeCenter(iter2->m_PosX, iter2->m_PosY, iter2->m_pspikeImage->GetWidth(), iter2->m_pspikeImage->GetHeight());
		}

	
}

void cMainGame::CreateItem()
{
	cItem tempItem;
	int itemrand = rand() % 101;
	if (itemrand > SLOW_CHANCE)
	{
		tempItem.m_pItemImage = m_pFrameItem2;
		tempItem.m_fmoveSpeed = 0.5f;
	}
	else
	{
		tempItem.m_fmoveSpeed = 1.0f;
		tempItem.m_pItemImage = m_pFrameItem;
	}
		tempItem.m_PosX = WINSIZEX;
		tempItem.m_PosY = WINSIZEY / 2 + 130;
		tempItem.ItemBody = RectMakeCenter(tempItem.m_PosX, tempItem.m_PosY, tempItem.m_pItemImage->GetWidth(), tempItem.m_pItemImage->GetHeight());
	m_vcItem.push_back(tempItem);

	
}

void cMainGame::MoveItem()
{

		for (auto iter = m_vcItem.begin(); iter != m_vcItem.end(); iter++)
		{
			iter->m_PosX -= m_ObjectSpeed + m_LevelBulletSpeed;
			iter->ItemBody = RectMakeCenter(iter->m_PosX, iter->m_PosY, iter->m_pItemImage->GetWidth(), iter->m_pItemImage->GetHeight());
		}

	
}

void cMainGame::NextNumber()
{
	m_nNumberDelay--;

	if (m_nNumberDelay < 0)
	{
		m_nNumberDelay = NUMBER_DELAY;
		m_pNumber->SetFrameY(0);
		m_pNumber->SetFrameX(m_pNumber->GetFrameX() + 1);

		if (m_pNumber->GetFrameX() > m_pNumber->GetMaxFrameX())
			m_pNumber->SetFrameX(7);
	}
}

void cMainGame::NumberRender()
{
	m_pNumber->FrameRender(g_hDC, m_pNumber->GetPosX(), m_pNumber->GetPosY());
}

void cMainGame::Play()
{
	m_nMovedelay--;
	m_moveitem--;
	m_nTimer--;


	//Ÿ�̸Ӱ� 0�� �Ǿ����� �ð��� 1�� ��´�.
	if (m_nTimer < 0)
	{
		m_stopwatch--;
		m_nTimer = TIMER;
	}

	//�ð�10�� 0�� �Ǿ����� ����,��潺�ǵ�,�Ѿ˼ӵ��� ������ �ð��� �ٽ� �ʱ�ȭ
	if (m_stopwatch < 0)
	{
		m_nLevel++;
		m_LevelSpeed += 1.0f;
		m_LevelBulletSpeed += 0.5f;
		m_fOutDelay += 0.5f;
		m_stopwatch = 10;

	}

	//�÷��̾ �����̴� �����̰� 0�� �Ǿ�����
	if (m_nMovedelay < 0)
	{
		m_nMovedelay = MOVE_DELAY;
		m_pFrameImage->SetFrameY(0);
		m_pFrameImage->SetFrameX(m_pFrameImage->GetFrameX() + 1);
		m_pSlideImage->SetFrameY(0);
		m_pSlideImage->SetFrameX(m_pSlideImage->GetFrameX() + 1);

		if (m_pFrameImage->GetFrameX() > m_pFrameImage->GetMaxFrameX())
			m_pFrameImage->SetFrameX(0);

		if (m_pSlideImage->GetFrameX() > m_pSlideImage->GetMaxFrameX())
			m_pSlideImage->SetFrameX(0);
	}
	//���ڰ� �����δ�!!



	// �̻����� ���ǵ�� ��Ʈ
	m_pFrameBullet->SetPosX(m_pFrameBullet->GetPosX() - m_BulletObjectSpeed - m_LevelBulletSpeed);
	rt2 = RectMakeCenter(m_pFrameBullet->GetPosX() + 5, BulletPosYrand, m_pFrameBullet->GetFrameWidth(), m_pFrameBullet->GetFrameHeight() - 20);


	//�����ϱ�
	if (g_pKeyManager->isOnceKeyDown(VK_SPACE) && m_nJumpStack > 0)
	{
		m_nGravity = 0.3f;
		m_isSlide = false;
		m_fJumpPower = -9.0f;
		m_nJumpStack--;
		m_isJumppinig = true;
	}

	if (m_isJumppinig)
	{
		m_fJumpPower += m_nGravity;
		m_pFrameImage->SetPosY(m_pFrameImage->GetPosY() + m_fJumpPower);
		//m_fCurrGravity += GRAVITY;
	}
	//�����̵�
	if (g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		m_isSlide = true;
	}
	if (g_pKeyManager->isOnceKeyUp(VK_DOWN))
	{
		m_isSlide = false;
	}
	if (m_isSlide)
	{
		m_nGravity = 9.0f;

	}
	if (m_pFrameImage->GetPosY() > WINSIZEY / 2 + 180)
	{
		m_pFrameImage->SetCenterY(WINSIZEY / 2 + 210);

		m_nJumpStack = 2;
		m_isJumppinig = false;
	}
	//�˶���� ��Ʈ(����ٰ� ���� ������ �����ٰ� ������ ������ Y���� ����� ���ϱ⶧���� ������ ���ı��� ����ϱ����� �����ڵ��Ʒ����ٰ� ������)
	rt1 = RectMakeCenter(m_pFrameImage->GetPosX(), m_pFrameImage->GetPosY(), m_pFrameImage->GetFrameWidth(), m_pFrameImage->GetFrameHeight());
	rtSlide = RectMakeCenter(m_pSlideImage->GetPosX(), m_pSlideImage->GetPosY(), m_pSlideImage->GetFrameWidth(), m_pSlideImage->GetFrameHeight());


	//�������̱�(������ �ö󰡸� �ö󰥼��� �������� �������)
	m_fbgPosX -= m_fbgSpeed + m_LevelSpeed;

	if (m_fbgPosX <= -800)
	{
		m_fbgPosX = 0;
	}

	//���������۰� ���������ϴ� ������
	if (m_moveitem < 0)
	{
		m_moveitem = ITEM_DELAY - m_fOutDelay;
		CreateSpike();
		CreateItem();
	}
	MoveItem();
	MoveSpike();

	////�÷��̾�� �Ѿ��� �浹�������� �浹ó��

	RECT rttempSlide;
	if (m_isSlide)
	{
		if (IntersectRect(&rttempSlide, &rtSlide, &rt2))
		{
			//Ǯ��
			//Sleep(2000);
			//PostQuitMessage(0);
			m_GameState = GAME_OVER;
		}
	}
	else
	{
		RECT rt3;
		if (IntersectRect(&rt3, &rt1, &rt2))
		{
			//Ǯ��
			//Sleep(2000);
			//PostQuitMessage(0);
			m_GameState = GAME_OVER;
		}
	}

	//�÷��̾�� �����浹
	for (auto iter = m_vcSpike.begin(); iter != m_vcSpike.end(); iter++)
	{
		RECT tempSpike;
		RECT tempSpike1;
		RECT rtSpike = iter->SpikeBody;

		if (IntersectRect(&tempSpike, &rt1, &rtSpike))
		{
			//Ǯ��
			//Sleep(2000);
			//PostQuitMessage(0);
			m_GameState = GAME_OVER;
		}
	}

	//���ÿ� ������ �浹�� �������� ���ΰ��� ������
	for (auto iter = m_vcSpike.begin(); iter != m_vcSpike.end(); iter++)
	{
		for (auto iter2 = m_vcItem.begin(); iter2 != m_vcItem.end(); iter2++)
		{
			RECT rthit;
			if (IntersectRect(&rthit, &iter->SpikeBody, &iter2->ItemBody))
			{
				iter2->m_PosY -= WINSIZEY - iter->m_PosY;
			}
		}
	}

	//�÷��̾�� �������� �浹�������� �浹ó��
	for (auto iter = m_vcItem.begin(); iter != m_vcItem.end();)
	{
		RECT rt4;
		RECT rtbody = iter->ItemBody; // �������� ��Ʈ�� ��������� ����

									  //�÷��̾�� �������� �浹�ϰų� �������� ��Ʈ�������� 0�̵Ǿ����� ����
		if (IntersectRect(&rt4, &rt1, &rtbody) || rtbody.right < 0)
		{
			//�������� �Ծ������� �ӵ��� ���Ͽ� ��������
			//�̰��� �������� �Ծ ���ǵ尡 �״�� �����Ǿ����� ������ �ö�
			if (iter->m_fmoveSpeed == 1.0f)
			{
				m_nScore++;
			}
			//�̰��� �������� �Ծ����� ���ǵ尡 ���������� ����� �ӵ��� iter�� ���ִ� ���ǵ带 ��
			//�׸����� �������� �������� Ȱ��ȭ�� �Ȱ��� ǥ������
			else
			{
				m_fbgSpeed -= iter->m_fmoveSpeed;
				m_isAtive = true;
			}
			//��ó�� ������ �ȸ����� �������ϱ⶧���� �ۿ��ٰ� ��
			iter = m_vcItem.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	//�������� �������� �Ծ����� �����̰� ����Ǵ°���
	if (m_isAtive)
	{
		m_bgdelay--;
	}
	//�����̰� 0�� �Ǿ����� ��δ� �ʱ�ȭ ���ִ°ž�
	if (m_bgdelay < 0)
	{
		m_bgdelay = ACTIVE_TIME;
		m_fbgSpeed = BG_SPEED;
		m_isAtive = false;
	}
}

void cMainGame::PlayingRender()
{
	if (m_nLevel <= 3)
	{
		m_pbgFrameImage->FrameRender(g_hDC, m_fbgPosX);
		m_pbgFrameImage->FrameRender(g_hDC, m_fbgPosX + 800);
	}
	//������ 4~6������
	if (m_nLevel >= 4 && m_nLevel <= 6)
	{
		m_pbgImage2->FrameRender(g_hDC, m_fbgPosX);
		m_pbgImage2->FrameRender(g_hDC, m_fbgPosX + 800);
	}
	//������ 7~9������
	if (m_nLevel >= 7 && m_nLevel <= 9)
	{
		m_pbgImage3->FrameRender(g_hDC, m_fbgPosX);
		m_pbgImage3->FrameRender(g_hDC, m_fbgPosX + 800);
	}
	if (m_nLevel >= 10 && m_nLevel <= 13)
	{
		m_pbgImage4->FrameRender(g_hDC, m_fbgPosX);
		m_pbgImage4->FrameRender(g_hDC, m_fbgPosX + 800);
	}

	for (auto iter = m_vcItem.begin(); iter != m_vcItem.end(); iter++)
	{
		//Rectangle(g_hDC, iter->ItemBody.left, iter->ItemBody.top, iter->ItemBody.right, iter->ItemBody.bottom);
		iter->Render();
	}

	for (auto iter2 = m_vcSpike.begin(); iter2 != m_vcSpike.end(); iter2++)
	{
		//Rectangle(g_hDC, iter2->SpikeBody.left, iter2->SpikeBody.top, iter2->SpikeBody.right, iter2->SpikeBody.bottom);
		iter2->Render();
	}


	if (m_pFrameBullet->GetPosX() <= -50)
	{
		BulletPosYrand = rand() % 291 + 200;
		m_pFrameBullet->SetPosX(WINSIZEX);
	}
	if (m_isSlide)
	{
		//Rectangle(g_hDC, rtSlide.left, rtSlide.top, rtSlide.right, rtSlide.bottom);
		m_pSlideImage->FrameRender(g_hDC, m_pSlideImage->GetPosX(), m_pSlideImage->GetPosY());
	}
	else
	{
		//Rectangle(g_hDC, rt1.left, rt1.top, rt1.right, rt1.bottom);
		m_pFrameImage->FrameRender(g_hDC, m_pFrameImage->GetPosX(), m_pFrameImage->GetPosY());
	}


	//Rectangle(g_hDC, rt2.left, rt2.top, rt2.right, rt2.bottom);
	m_pFrameBullet->FrameRender(g_hDC, m_pFrameBullet->GetPosX(), BulletPosYrand);

	




	char str[128];
	sprintf_s(str, "���� : %d    ���ǵ� : %f    �ð� : %d     ���� : %d", m_nScore, m_fbgSpeed + m_LevelSpeed, m_stopwatch, m_nLevel);
	TextOut(g_hDC, 10, 10, str, strlen(str));


	sprintf_s(str, "�Ѿ� ���ǵ� : %f     ����ġ�°�üũ : %d    ���� : %d", m_pFrameBullet->GetPosX(), m_vcItem.size(), m_nJumpStack);
	TextOut(g_hDC, 10, 30, str, strlen(str));

	sprintf_s(str, "Ÿ�̸� : %d     �ѹ������� : %d", m_nNumberDelay, m_pNumber->GetFrameX());
	TextOut(g_hDC, 10, 50, str, strlen(str));
}

void cMainGame::ReadyRender()
{
	m_pStartImage->Render(g_hDC, 0, 0);
	m_pEnterStart->AlphaRender(g_hDC, WINSIZEX / 2 - (m_pEnterStart->GetWidth() / 2), WINSIZEY / 2 + 80, (int)m_Blinkimage);
}

void cMainGame::GameOverRender()
{
	m_pGameover->Render(g_hDC, 0, 0);
	//m_pRestart->AlphaRender(g_hDC, WINSIZEX / 2 - (m_pRestart->GetWidth() / 2), WINSIZEY / 2 + 80, (int)m_Blinkimage);
}

void cMainGame::Ready()
{
	m_Blinkimage += m_BlinkSpeed;

	if (m_Blinkimage < 0.0f)
	{
		m_Blinkimage = 0.0f;
		m_BlinkSpeed *= -1.0f;
	}
	else if (m_Blinkimage > 255.0f)
	{
		m_Blinkimage = 255.0f;
		m_BlinkSpeed *= -1.0f;
	}
}

void cMainGame::SystemControl()
{
	if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		switch (m_GameState)
		{
		case GAME_READY:
			m_GameState = GAME_COUNT;
			break;
		case GAME_COUNT:
			break;
		case GAME_PLAYING:
			break;
		case GAME_OVER:
			GameStateReset();
			GamePlayReset();
			break;
		case GAME_CLEAR:
			GameStateReset();
			GamePlayReset();
			break;
		default:
			break;
		}
	}
}

void cMainGame::GameStateReset()
{
	m_GameState = GAME_READY;
}

void cMainGame::GameClear()
{
	m_pClear->Render(g_hDC, 0, 0);
}

void cMainGame::GamePlayReset()
{
	m_fJumpPower = -10.0f;
	m_fCurrGravity = 0.0f;
	 m_isJumppinig = false;
	 m_fbgPosX = 0.0f;
	 m_nScore = 0;
	 m_fbgSpeed = 5.0f;
	 m_bgdelay = ACTIVE_TIME;
	 m_isAtive = false;
	 m_nLevel = 1;
	 m_nTimer = TIMER;
	 m_stopwatch = 10;
	 m_LevelSpeed = LEVEL_SPEED;
	 m_LevelBulletSpeed = BULLET_SPEED;
	 m_Blinkimage = 0.0f;
	 m_BlinkSpeed = 3.5f;
	 m_nJumpStack = 2;
	 m_isSlide = false;
	 m_nGravity = GRAVITY;
	 m_nNumberDelay = NUMBER_DELAY;
	 m_ObjectSpeed = 5.0f;
	 m_BulletObjectSpeed = 8.0f;
	 m_fOutDelay = 0.0f;
	 m_pNumber->SetFrameX(0);
	
}


