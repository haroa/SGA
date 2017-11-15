#pragma once
#include "cGameNode.h"
#include "cMap.h"
#include "cPlayer.h"
#include "cUi.h"

class cPlayScene : public cGameNode
{
private:
	cMap m_cMap;
	cPlayer m_cPlayer;
	cUi m_cUi;
private:
	void CollisoinRect();

	void JsonSave();

	void JsonLoad();

public:
	cPlayScene() {};
	virtual ~cPlayScene() {};

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

