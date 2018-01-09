#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid()
{
}


cGrid::~cGrid()
{
}

void cGrid::Render(HDC hdc, cMatrix& matViewProjViewport)
{
	int z = 10;
	int x = -10;
	for (int x = 0; x < 21; x++)
	{
		//z에 대한 임시변수
		cVector3 vX0 = cVector3(-10, 0, z);
		cVector3 vX1 = cVector3( 10, 0, z);
		vX0.TransformCoord(&matViewProjViewport);
		vX1.TransformCoord(&matViewProjViewport);

		MoveToEx(hdc, vX0.x, vX0.y, NULL);
		LineTo(hdc, vX1.x, vX1.y);
		z--;
	}

	for (int z = 0; z < 21; z++)
	{
		//z에 대한 임시변수
		cVector3 vZ0 = cVector3(x, 0, 10);
		cVector3 vZ1 = cVector3(x, 0,-10);
		vZ0.TransformCoord(&matViewProjViewport);
		vZ1.TransformCoord(&matViewProjViewport);

		MoveToEx(hdc, vZ0.x, vZ0.y, NULL);
		LineTo(hdc, vZ1.x, vZ1.y);
		x++;
	}
}
