#include "stdafx.h"
#include "cPlayer.h"

void cPlayer::Setup()
{
	m_pImage = g_pImageManager->FindImage("Player");
	m_fPosX = 700.0f;
	m_fPosY = 1100.0f;													//플레이어의 기본적인 변수 초기화
	m_nSizeW = 100;
	m_nSizeH = 100;
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_nLevel = 1;
	m_nAtk = 50;
	m_nHp = 50;
	m_nMp = 100;
	m_nExp = 1356;
	m_nMaxHp = 100;
	m_nMaxMp = 100;
	m_nMaxExp = 9872;
	//================================================================
	m_pImgColl = g_pImageManager->FindImage("MapleCollTown");
	m_isJumpping = false;
	m_isHitMonster = false;
	m_isHitMonsterJumpping = false;
	m_isLeft = true;
	m_isDown = false;													//플레이어가 이동할때 필요한 bool값과 변수초기화
	m_fJumpPower = 8.0f;
	m_fHitMonsterJumpPower = 3.0f;
	m_fGravity = 0.0f;
	m_isdrop = false;
	//===================================================================
	m_rtAtkLeft = RectMake(m_fPosX, m_fPosY, 20, m_nSizeH);
	m_rtAtkRight = RectMake(m_fPosX + m_pImage->GetFrameWidth(), m_fPosY, 20, m_nSizeH);	//플레이어가 공격할때 쓰일 렉트
	//===================================================================
	g_pTimerManager->AddSimpleTimer("Player_jump");
	g_pTimerManager->AddSimpleTimer("Player_Idel_LEFT");
	g_pTimerManager->AddSimpleTimer("Player_Idel_RIGHT");
	g_pTimerManager->AddSimpleTimer("Player_Left");
	g_pTimerManager->AddSimpleTimer("Player_Right");					//플레이어의 이미지프레임이 돌아가는 딜레이 초기화
	g_pTimerManager->AddSimpleTimer("Player_Attack_Left");
	g_pTimerManager->AddSimpleTimer("Player_Attack_Right");
	g_pTimerManager->AddSimpleTimer("Player_downAttack_Left");
	g_pTimerManager->AddSimpleTimer("Player_downAttack_Right");
	//===================================================================
}

void cPlayer::Update()
{
	m_rtBody = RectMake(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
	m_rtAtkLeft = RectMake(m_fPosX, m_fPosY, 20, m_nSizeH);
	m_rtAtkRight = RectMake(m_fPosX + m_pImage->GetFrameWidth(), m_fPosY, 20, m_nSizeH);
	if (!m_isHitMonster)
	{
		Move();
	}
	if (m_isHitMonster)
	{
		HitMonster();
	}
}

void cPlayer::Render(HDC hdc)
{
	m_pImage->FrameRender(hdc, m_fPosX, m_fPosY, m_nSizeW, m_nSizeH, m_pImage->GetFrameX(), m_pImage->GetFrameY());
	if (m_pImage->GetFrameY() == 4 && m_pImage->GetFrameX() == 2 && m_isLeft)
	{
		RectangleMake(hdc, m_rtAtkLeft);
	}
	else if (m_pImage->GetFrameY() == 10 && m_pImage->GetFrameX() == 2 && !m_isLeft)
	{
		RectangleMake(hdc, m_rtAtkRight);
	}
}

void cPlayer::Move()
{
	//=========================================================================================
	//바닥픽셀충돌할때와 점프할때
	float probeX = m_fPosX + m_nSizeW / 2;
	float probeY = m_fPosY + m_nSizeH;
	
	if (!g_pPixelManager->CheckPixel(m_pImgColl, probeX, probeY))
	{
		if (m_fGravity >= m_fJumpPower)
		{
			int deepY = 0;
			while (!g_pPixelManager->CheckPixel(m_pImgColl, probeX, probeY - deepY - 1))
			{
				++deepY;
			}
			m_fPosY = m_fPosY - deepY;
			m_fGravity = 0.0f;
			m_isJumpping = false;
		}
	}
	else
	{
		m_isdrop = true;
		m_fPosY = m_fPosY + m_fGravity;
		m_fGravity += GRAVITY;
	}
	//=========================================================================================
	//왼쪽을 눌렀을때 이동,픽셀충돌,이미지프레임이동
	if (g_pKeyManager->isStayKeyDown(VK_LEFT))
	{

		if (0 <= m_fPosX + 20)
			m_fPosX -= 3;

		m_pImage->SetFrameY(1);
		if (g_pTimerManager->TickSimpleTimer("Player_Left") > 10)
		{
			g_pTimerManager->ResetSimpleTimer("Player_Left");
			m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
		}
		if (m_pImage->GetFrameX() > 3)
		{
			m_pImage->SetFrameX(0);
		}
		m_isLeft = true;
	}
	//=========================================================================================
	//오른쪽을 눌렀을때 이동,픽셀충돌,이미지프레임이동
	else if (g_pKeyManager->isStayKeyDown(VK_RIGHT))
	{
		if(2000 >= m_fPosX + m_nSizeW - 20)
			m_fPosX += 3;

		m_pImage->SetFrameY(7);
		if (g_pTimerManager->TickSimpleTimer("Player_Right") > 10)
		{
			g_pTimerManager->ResetSimpleTimer("Player_Right");
			m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
		}
		if (m_pImage->GetFrameX() > 3)
		{
			m_pImage->SetFrameX(0);
		}
		m_isLeft = false;
	}
	//=========================================================================================
	//아래 눌렀을때 이미지프레임이동
	else if (g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		if (m_isLeft && !m_isDown)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(2);
		}
		if (!m_isLeft && !m_isDown)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(8);
		}
	}
	//=========================================================================================
	//공격을 눌렀을때 이미지프레임이동
	else if (g_pKeyManager->isStayKeyDown('X'))
	{
		if (m_isLeft)
		{
			m_pImage->SetFrameY(4);
			if (g_pTimerManager->TickSimpleTimer("Player_Attack_Left") > 10)
			{
				g_pTimerManager->ResetSimpleTimer("Player_Attack_Left");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 4)
			{
				m_pImage->SetFrameX(0);
			}
		}
		if (!m_isLeft)
		{
			m_pImage->SetFrameY(10);
			if (g_pTimerManager->TickSimpleTimer("Player_Attack_Right") > 10)
			{
				g_pTimerManager->ResetSimpleTimer("Player_Attack_Right");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 4)
			{
				m_pImage->SetFrameX(0);
			}
		}
	}
	//=========================================================================================
	//아무것도 안눌렀을때 이미지프레임이동
	else
	{
		if (m_isLeft)
		{
			m_pImage->SetFrameY(0);
			if (g_pTimerManager->TickSimpleTimer("Player_Idel_LEFT") > 20)
			{
				g_pTimerManager->ResetSimpleTimer("Player_Idel_LEFT");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 1)
			{
				m_pImage->SetFrameX(0);
			}
		}
		if (!m_isLeft)
		{
			m_pImage->SetFrameY(6);
			if (g_pTimerManager->TickSimpleTimer("Player_Idel_RIGHT") > 20)
			{
				g_pTimerManager->ResetSimpleTimer("Player_Idel_RIGHT");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 1)
			{
				m_pImage->SetFrameX(0);
			}
		}
	}
	//=========================================================================================
	//점프를 눌렀을때 이미지프레임이동과 점프에 관한것들
	if (!m_isJumpping && g_pKeyManager->isStayKeyDown('Z'))
	{
		m_isJumpping = true;
		m_fGravity = 0.0f;
	}
	if (m_isJumpping)
	{
		if (m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(3);
		}
		else if (!m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(9);
		}
		m_fPosY = m_fPosY - m_fJumpPower;
	}
	//=========================================================================================
	//아래와 공격키를 눌렀을때 하단공격이 되는 이미지프레임이동
	if (g_pKeyManager->isStayKeyDown(VK_DOWN) && g_pKeyManager->isStayKeyDown('X'))
	{
		m_isDown = true;
		if (m_isLeft)
		{
			m_pImage->SetFrameY(2);
			if (g_pTimerManager->TickSimpleTimer("Player_downAttack_Left") > 20)
			{
				g_pTimerManager->ResetSimpleTimer("Player_downAttack_Left");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 1)
			{
				m_pImage->SetFrameX(0);
			}
		}
		if (!m_isLeft)
		{
			m_pImage->SetFrameY(8);
			if (g_pTimerManager->TickSimpleTimer("Player_downAttack_Right") > 20)
			{
				g_pTimerManager->ResetSimpleTimer("Player_downAttack_Right");
				m_pImage->SetFrameX(m_pImage->GetFrameX() + 1);
			}
			if (m_pImage->GetFrameX() > 1)
			{
				m_pImage->SetFrameX(0);
			}
		}
	}
	//=========================================================================================
	//아래와 점프를 동시에 누르면 밑으로 점프
	else if (g_pKeyManager->isStayKeyDown(VK_DOWN) && g_pKeyManager->isStayKeyDown('Z'))
	{
		
	}
	//=========================================================================================
	//아래를 때는순간 bool값 초기화
	else if (g_pKeyManager->isOnceKeyUp(VK_DOWN))
	{
		m_isDown = false;
	}
	//=========================================================================================
	//점프를 안누르고 떨어질때 이미지 프레임 이동
	if (m_isdrop)
	{
		if (m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(3);
		}
		else if (!m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(9);
		}
	}
	if (m_fPosY >= 500)
	{
		m_isdrop = false;
	}
	//=========================================================================================
}

void cPlayer::HitMonster()
{
	float probeX = m_fPosX + m_nSizeW / 2;
	float probeY = m_fPosY + m_nSizeH;

	if (!g_pPixelManager->CheckPixel(m_pImgColl, probeX, probeY))
	{
		if (m_fGravity >= m_fHitMonsterJumpPower)
		{
			int deepY = 0;
			while (!g_pPixelManager->CheckPixel(m_pImgColl, probeX, probeY - deepY - 1))
			{
				++deepY;
			}
			m_fPosY = m_fPosY - deepY;
			m_fGravity = 0.0f;
			m_isHitMonsterJumpping = false;
		}
	}
	else
	{
		m_isdrop = true;
		m_fPosY = m_fPosY + m_fGravity;
		m_fGravity += GRAVITY;
	}

	if (m_isHitMonsterJumpping)
	{
		if (m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(3);
		}
		else if (!m_isLeft)
		{
			m_pImage->SetFrameX(0);
			m_pImage->SetFrameY(9);
		}
		m_fPosY = m_fPosY - m_fJumpPower;
	}
}

