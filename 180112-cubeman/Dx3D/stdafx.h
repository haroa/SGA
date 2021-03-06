// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <vector>
#include <time.h>


#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
using namespace std;

extern HWND g_hWnd;

#define SAFE_DELETE(p) { if (p) delete (p); (p) = NULL; }
#define SAFE_RELEASE(p) { if (p) (p)->Release(); }

/* 버텍스 FVF 정보 셋팅 옵션 */

// Flexible Vertex Format(유연한 버텍스 포맷) - 사용 할 정점의 다양한 정보를 사용자가 직접 필요한 부분만 골라서 정의하여 쓸 수 있는 방법
//	1. Position 정점의 좌표 x,y,z(float)				: D3DFVF_XYZ - 정점 포맷이 변환되지 않은 정점의 위치 좌표
// 	2. RHW (float)                                  : D3DFVF_XYZRHW - 정점 포맷이 변환 된 정점의 위치 좌표 (D3DFVF_XYZ 또는 D3DFVF_NORMAL과 같이 사용불가)
// 	3. Blending Weight Data 결합 가중치 (float)		: D3DFVF_XYZB1 ~ D3DFVF_XYZB5
// 	4. Vertex Normal 정점의 법선 벡터 x,y,z(float)	: D3DFVF_NORMAL
// 	5. Vertex Point Size 정점의 점 크기 (float)		: D3DFVF_PSIZE
// 	6. Diffuse Color (DWORD)						: D3DFVF_DIFFUSE			// 확산광		// Ambient 환경 반사광
// 	7. Specular Color (DWORD)						: D3DFVF_SPECULAR			// 정반사광
// 	8. Texture Coordinate Set 1 (float)             : D3DFVF_TEX0 - D3DFVF_TEX8

/* 정점에 대한 정보를 구조체로 만들어서 관리 */
struct ST_PC_VERTEX
{
	D3DXVECTOR3		p;
	D3DCOLOR		c;

	static const int FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

	ST_PC_VERTEX() {}
	ST_PC_VERTEX(D3DXVECTOR3 _p, D3DCOLOR _c) : p(_p), c(_c) {}
};