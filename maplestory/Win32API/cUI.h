#pragma once
#include "cGameobject.h"

class cUI : public cGameobject
{
private:
	cImage*	m_pHpback;
	cImage*	m_pMpback;
	cImage*	m_pExpback;

	cImage*	m_pHpfront;
	cImage*	m_pMpfront;
	cImage*	m_pExpfront;
private:
	float		m_fHpmin;
	float		m_fHpmax;
	
	float		m_fMpmin;
	float		m_fMpmax;
	
	float		m_fExpmin;
	float		m_fExpmax;

	int			m_nLevel;

	int			m_nExp;
	float		m_fExp;
	int			m_nreckoning;
	int			m_nreckoning2;
	int			m_nreckoning3;

	RECT		m_rtLevel;
	RECT		m_rtHp;
	RECT		m_rtMp;
	RECT		m_rtExp;
public:
	cUI() {};
	~cUI() {};

	void Setup();
	void Update();
	void Render(HDC hdc);
#pragma region Set
	void SetHpmin(float min) { m_fHpmin = min; }
	void SetHpmax(float max) { m_fHpmax = max; }
	void SetMpmin(float min) { m_fMpmin = min; }
	void SetMpmax(float max) { m_fMpmax = max; }
	void SetExpmin(float min) { m_fExpmin = min; }
	void SetExpmax(float max) { m_fExpmax = max; }
	void SetLevel(int level) { m_nLevel = level; }
#pragma endregion

};

