#pragma once
#include "cGameNode.h"

enum OMOK
{
	WHITE = 0,
	BLACK
};


struct omok
{
	float	fPosX;		//바둑알 놓을위치X
	float	fPosY;		//바둑알 놓을위치Y
	RECT	rtBody;		//바둑알 놓을위치의 렉트
	bool	isActive;	//알파랜더된 바둑알보여주기
	bool	isColor;	//흑인지 백인지
	bool	isShow;		//완벽한 바둑알보여주기
	POINT	pos;
};


class cPlayScene : public cGameNode
{
private:
	omok			game;
	vector<omok>	m_vecomok;
	int				m_nalpha;
	OMOK			OMOKEGG;
	int				choice;


	cImage*			m_pImgBackground;		// 화면 전체 배경
	cImage*			m_pOmok;
	cImage*			m_pImgMiniMap;			// 미니맵용 이미지 버퍼
	cImage*			m_pImgMapBuffer;		// 지형 지물이 그려진 맵 버퍼


	void LoadImageFromFile();
	void MiniMapRender();
	void PlayerControll();
	void Win();

public:
	cPlayScene();
	virtual ~cPlayScene();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

