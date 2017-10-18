#include "stdafx.h"
#include "cWind.h"


cWind::cWind()
{
}


cWind::~cWind()
{
}

void cWind::Setup()
{
	// -3.0 ~ +3.0
	m_fSpeedY = (rand() % 101 - 50) * 0.01f;
}

void cWind::Update()
{
	
}

void cWind::Render()
{

}
