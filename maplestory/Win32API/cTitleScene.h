#pragma once
#include "cGameNode.h"
#include "cCursor.h"

class cTitleScene :	public cGameNode
{
private:
	cImage*				m_ImgTitleBG;
	RECT				m_rtChangeScene;
	RECT				m_rtExit;
	cCursor				m_cCursor;
private:
	void ChangeScene();
	void Exit();
public:
	cTitleScene() {};
	virtual ~cTitleScene() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

