#pragma once
#include "cGameobject.h"
#include "cFire.h"

class cMap:public cGameobject
{
private:
	cFire	m_cFire;
	//vector<cFire>	m_veccfire;

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

	cImage* m_clearObject;
	RECT	m_rtclearObject;
	float	m_clearObjectX;
	float	m_clearObjectY;

	cImage*	m_boom;
	float	m_boomX;
	float	m_boomY;

	cImage*	m_item;
	float	m_itemX;
	float	m_itemY;
	RECT	m_rtitem;


	bool	m_bMoveRight;
	bool	m_bMoveRight2;
	bool    m_bMoveRight3;
	bool	m_goombaActive;
	bool	m_kupaActive;
	bool	m_clear;
	bool	m_itemActive;
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
	float GetKupaX() { return m_kupaX; }
	float GetkupaY() { return m_kupaY; }
	float GetclearObjectX() { return m_clearObjectX; }
	float GetclearObjectY() { return m_clearObjectY; }
	float GetitemX() { return m_itemX; }
	float GetitemY() { return m_itemY; }
	bool GetMoveRight1() { return m_bMoveRight; }
	bool GetMoveRight2() { return m_bMoveRight2; }
	bool GetMoveRight3() { return m_bMoveRight3; }
	bool GetgoombaActive() { return m_goombaActive; }
	bool GetkupaActive() { return m_kupaActive; }
	bool GetitemActive() { return m_itemActive; }
	RECT GetOB1() { return m_rtOb1; }
	RECT GetOB2() { return m_rtOb2; }
	RECT Getgoomba() { return m_goombart; }
	RECT GetKupaBody() { return m_kupart; }
	RECT GetclearObject() { return m_rtclearObject; }
	RECT Getitem() { return m_rtitem; }
#pragma endregion
	
    cImage* GetMapBuffer() { return m_cBuffer; }
	void SetgoombaActive(bool Active) { m_goombaActive = Active; }

	void SetkupaAcitve(bool active) { m_kupaActive = active; }

	void Setclear(bool clear) { m_clear = clear; }
	void SetitemActive(bool active) { m_itemActive = active; }

	cMap();
	~cMap();

	void Setup();
	void Update();
	void Render();
	void MoveObject();
	void MoveEnemy();
	//void MakeFire();
	//void RenderFire();
	//void MoveFire();
};

