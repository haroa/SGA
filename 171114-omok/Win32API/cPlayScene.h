#pragma once
#include "cGameNode.h"

enum OMOK
{
	WHITE = 0,
	BLACK
};


struct omok
{
	int		nPosX;		//X의 점좌표
	int		nPosY;		//Y의 점좌표
	RECT	rtBody;		//바둑알 놓을위치의 렉트
	bool	isActive;	//알파랜더된 바둑알보여주기
	bool	isColor;	//255짜리 흑인지 백인지
	bool	iswhite;	//125짜리 흑인지 백인지
	bool	isShow;		//완벽한 바둑알보여주기
	bool	isCheck;	//내가 둔곳을 확인한다
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
	int				checkcountwidth;
	int				checkcountHeight;
	int				checkcountdialeft;
	int				checkcountdiaright;


	cImage*			m_pImgBackground;		// 화면 전체 배경
	cImage*			m_pOmok;
	cImage*			m_pImgMiniMap;			// 미니맵용 이미지 버퍼
	cImage*			m_pImgMapBuffer;		// 지형 지물이 그려진 맵 버퍼


	void LoadImageFromFile();
	void MiniMapRender();
	void PlayerControll();
	void Win(int X,int Y, bool isColor);

public:
	cPlayScene();
	virtual ~cPlayScene();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

