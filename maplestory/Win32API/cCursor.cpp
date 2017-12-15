#include "stdafx.h"
#include "cCursor.h"

void cCursor::Setup()
{
	m_pImage = g_pImageManager->FindImage("Cursor");
	m_CursorX = 0;
}

void cCursor::Update()
{
	m_CursorX = 0;
	if (g_pKeyManager->isStayKeyDown(VK_LBUTTON))
	{
		m_CursorX = 3;
	}
}

void cCursor::Render()
{
	m_pImage->FrameRender(g_hDC, g_ptMouse.x, g_ptMouse.y, m_CursorX, 0);
}
