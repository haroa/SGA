#pragma once
#include "cGameNode.h"


class cPlayScene : public cGameNode
{
private:
	cImage*			m_pImgBackground;		// ȭ�� ��ü ���
	cImage*			m_pImgMiniMap;			// �̴ϸʿ� �̹��� ����
	cImage*			m_pImgMapBuffer;		// ���� ������ �׷��� �� ����


	void LoadImageFromFile();
	void MiniMapRender();

public:
	cPlayScene();
	virtual ~cPlayScene();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

