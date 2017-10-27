#pragma once
#include "cGameobject.h"
#include "cFire.h"

class cMap:public cGameobject
{
private:
	cFire	m_cFire;
	vector<cFire>	m_veccfire;

	cImage* m_cminiMap;
	cImage*	m_cBuffer;
	cImage*	m_cObject;
	cImage* m_Object2;
	cImage* m_goomba;
	cImage* m_kupa;
	float	m_fObjectX;
	float	m_fObjectY;
	float	m_fObjectX2;
	float	m_fObjectY2;
	RECT	m_rtOb1;
	RECT	m_rtOb2;
	float	m_ob1Speedplus;
	float	m_os1Speedminus;
	float	m_ob2Speedplus;
	float	m_os2Speedminus;
	float	m_goombaX;
	float	m_goombaY;
	RECT    m_goombart;
	float	m_kupaX;
	float   m_kupaY;
	RECT    m_kupart;

	bool	m_bMoveRight;
	bool	m_bMoveRight2;
	bool    m_bMoveRight3;
public:
#pragma region Get
	float GetObjectX() { return m_fObjectX; }
	float GetObjectY() { return m_fObjectY; }
	float GetObjectX2() { return m_fObjectX2; }
	float GetObjectY2() { return m_fObjectY2; }
	float GetOb1Speedplus() { return m_ob1Speedplus; }
	float GetOb1Speedminus() { return m_os1Speedminus; }
	float GetOb2Speedplus() { return m_ob2Speedplus; }
	float GetOb2Speedminus() { return m_os2Speedminus; }
	float GetGoombaX() { return m_goombaX; }
	float GetGoombaY() { return m_goombaY; }
	bool GetMoveRight1() { return m_bMoveRight; }
	bool GetMoveRight2() { return m_bMoveRight2; }
	bool GetMoveRight3() { return m_bMoveRight3; }
	RECT GetOB1() { return m_rtOb1; }
	RECT GetOB2() { return m_rtOb2; }
	RECT Getgoomba() { return m_goombart; }

#pragma endregion
	float GetKupaX() { return m_kupaX; }
	float GetkupaY() { return m_kupaY; }
	RECT GetKupaBody() { return m_kupart; }


	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();
	void MoveObject();
	void MoveEnemy();
	void MakeFire();
	void RenderFire();
	void MoveFire();
};

