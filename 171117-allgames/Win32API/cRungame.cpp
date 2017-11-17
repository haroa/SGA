#include "stdafx.h"
#include "cRungame.h"

void cRungame::Setup()
{

}

void cRungame::Update()
{

}

void cRungame::Render()
{
	TextOut(g_hDC, WINSIZEX / 2 - 300, WINSIZEY / 2, "2.런게임", strlen("2.런게임"));
}

void cRungame::Release()
{

}
