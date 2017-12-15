	// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <time.h>
#include <string.h>
#include <map>
#include <assert.h>
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

//==================================================================
//		## 디파인문 - 메크로 ## (윈도우창 초기화)
//==================================================================
#define WINNAME (LPCWSTR)(TEXT("뭬이풀쑤또뤼"))
#define WINSTARTX		0
#define WINSTARTY		0
#define WINSIZEX		800
#define WINSIZEY		600
#define WINSTYLE		WS_CAPTION | WS_SYSMENU
#define PURE			= 0
#define PI				3.141592654f
#define GRAVITY			0.3f
#define JSON_PATH		"monsters/Monster.json"

#include "MacroUtility.h"

//==================================================================
//		## 메크로함수 ## (클래스 동적할당된 부분 해제)
//==================================================================
#define SAFE_DELETE(p)		{ if(p) { delete(p); (p) = NULL; } }
#define SAFE_DELETE_ARRAY	{ if(p) { delete[] (p); (p) = NULL; } }

//==================================================================
//		## 매니져 추가 ##
//==================================================================
#include "cKeyManager.h"
#include "cImage.h"
#include "cImageManager.h"
#include "cFileData.h"
#include "cPixelCollision.h"
#include "cTimeManager.h"
#include "cIniData.h"
#include "cSceneManager.h"
#include "cSoundManager.h"
#include "cTimerManager.h"
#include "FileDataManager.h"
//==================================================================
//		## 전역변수 ##
//==================================================================
extern HINSTANCE	g_hInst;
extern HWND			g_hWnd;
extern POINT		g_ptMouse;
extern HDC			g_hDC;