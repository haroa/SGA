#pragma once

class cCube;
class cCharacterController;

struct tagXY
{
	float x;
	float y;

	tagXY(float _x, float _y) { x = _x; y = _y; }
};

class cCubeMan
{
private:
	cCube*					m_pRootCube;
	cCharacterController*	m_pController;

	void SetTextureVertex(vector<D3DXVECTOR2>& vecT, tagXY vXY, tagXY sXY);

public:
	cCubeMan();
	~cCubeMan();

	void Setup();
	void Update();
	void Render();

	void SetController(cCharacterController* c) { m_pController = c; }
};

