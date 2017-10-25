#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_playerState = 0;
	Setup();
	g_pTimerManager->AddSimpleTimer("player-idle");
	g_pTimerManager->AddSimpleTimer("player-attack");
}


Player::~Player()
{
}

void Player::Update()
{
	switch (m_playerState)
	{
	case 0:
	{
		SetFrameY(0);
		if (g_pTimerManager->TickSimpleTimer("player-idle") > 5)
		{
			g_pTimerManager->ResetSimpleTimer("player-idle");
			NextFrameX();
		}
		break;
	}
	case 1:
	{
		SetFrameY(1);
		if (g_pTimerManager->TickSimpleTimer("player-attack") > 10)
		{
			g_pTimerManager->ResetSimpleTimer("player-attack");
			NextFrameX();
			if (GetFrameX() > 1)
			{
				SetFrameX(0);
			}
		}
		else
		{
			if (GetFrameX() > 1)
			{
				SetFrameX(0);
			}
		}
		break;
	}
	}
	m_gameObj.Update();
	SpritesObject::Update();
	PlayerController();
}  

void Player::Render()
{
	SpritesObject::Render();
#ifdef _DEBUG
	char infoMsg[128];
	sprintf_s(infoMsg, "posx : %f / posy : %f", m_dPos.x, m_dPos.y);
	TextOut(g_hDC, 0, 10, infoMsg, (int)strlen(infoMsg));
#endif // _DEBUG

}

void Player::PlayerController()
{
	m_playerState = 0;
	UnitSpeed speed = { 0.0f, 0.0f };
	if (g_pKeyManager->isStayKeyDown(VK_UP))
	{
		speed.y = -5.0f;
	}
	else if (g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		speed.y = 5.0f;
	}
	if (g_pKeyManager->isStayKeyDown(VK_LEFT))
	{
		speed.x = -5.0f;
	}
	else if (g_pKeyManager->isStayKeyDown(VK_RIGHT))
	{
		speed.x = 5.0f;
	}
	SetBodySpeed(speed);
	if (g_pKeyManager->isStayKeyDown(VK_SPACE))
	{
		m_playerState = 1;
	}
}
