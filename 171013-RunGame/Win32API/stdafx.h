	// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

//==================================================================
//		## �����ι� - ��ũ�� ## (������â �ʱ�ȭ)
//==================================================================
#define WINNAME (LPCWSTR)(TEXT("�ڵ� ������ ���Ű� ȯ�� �մϴ�."))
#define WINSTARTX		200
#define WINSTARTY		100
#define WINSIZEX		800
#define WINSIZEY		600
#define WINSTYLE		WS_CAPTION | WS_SYSMENU
#define PURE			= 0
#define PI				3.141592654f

#include "MacroUtility.h"

//==================================================================
//		## �Ŵ��� �߰� ##
//==================================================================
#include "cKeyManager.h"

#define g_pKeyManager cKeyManager::GetInstance()

//==================================================================
//		## �������� ##
//==================================================================
extern HINSTANCE	g_hInst;
extern HWND			g_hWnd;
extern POINT		g_ptMouse;
extern HDC			g_hDC;