#include "stdafx.h"
#include "cSupermario.h"

void cSupermario::Setup()
{
}

void cSupermario::Update()
{
}

void cSupermario::Render()
{
	TextOut(g_hDC, WINSIZEX / 2 - 300, WINSIZEY / 2, "3.½´ÆÛ¸¶¸®¿À", strlen("3.½´ÆÛ¸¶¸®¿À"));
}

void cSupermario::Release()
{
}
