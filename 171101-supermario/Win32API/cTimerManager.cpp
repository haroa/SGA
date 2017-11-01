#include "stdafx.h"
#include "cTimerManager.h"

bool cTimerManager::AddSimpleTimer(string Key)
{
	m_mapSimpleIter = m_mapSimpleTimer.find(Key);
	if (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		return false;
	}
	else
	{
		m_mapSimpleTimer.insert(make_pair(Key, 0));
		return true;
	}
}

int cTimerManager::FindTick(string Key)
{
	m_mapSimpleIter = m_mapSimpleTimer.find(Key);
	if (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		return m_mapSimpleIter->second;
	}
	else
	{
		return -1;  //   -1 find fail
	}
}

bool cTimerManager::SetTick(string Key, int Tick)
{
	m_mapSimpleIter = m_mapSimpleTimer.find(Key);
	if (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		m_mapSimpleIter->second = Tick;
		return true;
	}
	else
	{
		return false;
	}
}

int cTimerManager::TickSimpleTimer(string Key)
{
	if (SetTick(Key, FindTick(Key) + 1))
	{
		return FindTick(Key);
	}
	else
	{
		return -1;
	}
}

bool cTimerManager::ResetSimpleTimer(string Key)
{
	m_mapSimpleIter = m_mapSimpleTimer.find(Key);
	if (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		m_mapSimpleIter->second = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool cTimerManager::DeleteTimerByKey(string Key)
{
	m_mapSimpleIter = m_mapSimpleTimer.find(Key);
	if (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		m_mapSimpleTimer.erase(m_mapSimpleIter);
		return true;
	}
	else
	{
		return false;
	}
}

void cTimerManager::DeleteTimerAll()
{
	m_mapSimpleIter = m_mapSimpleTimer.begin();
	while (m_mapSimpleIter != m_mapSimpleTimer.end())
	{
		m_mapSimpleIter = m_mapSimpleTimer.erase(m_mapSimpleIter);
	}
}