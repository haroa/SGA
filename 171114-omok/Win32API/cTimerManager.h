#pragma once
#include "cSingletonBase.h"

#define g_pTimerManager cTimerManager::GetInstance()

class cTimerManager : public cSingletonBase<cTimerManager>
{
	//  VARS
private:
	map<string, int>                        m_mapSimpleTimer;
	map<string, int>::iterator              m_mapSimpleIter;
public:

	//  FUNCS
private:
public:
#pragma region CRUD
	//  CREATE
	bool    AddSimpleTimer(string Key);
	//  READ
	int     FindTick(string Key);
	//  UPDATE
	bool    SetTick(string Key, int Tick);
	int     TickSimpleTimer(string Key);
	bool    ResetSimpleTimer(string Key);
	//  DELETE
	bool    DeleteTimerByKey(string Key);
	void    DeleteTimerAll();
#pragma endregion
};
