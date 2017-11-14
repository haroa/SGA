#pragma once
#include "cGameNode.h"

enum OMOK
{
	WHITE = 0,
	BLACK
};


struct omok
{
	int		nPosX;		//X�� ����ǥ
	int		nPosY;		//Y�� ����ǥ
	RECT	rtBody;		//�ٵϾ� ������ġ�� ��Ʈ
	bool	isActive;	//���ķ����� �ٵϾ˺����ֱ�
	bool	isColor;	//255¥�� ������ ������
	bool	iswhite;	//125¥�� ������ ������
	bool	isShow;		//�Ϻ��� �ٵϾ˺����ֱ�
	bool	isCheck;	//���� �а��� Ȯ���Ѵ�
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


	cImage*			m_pImgBackground;		// ȭ�� ��ü ���
	cImage*			m_pOmok;
	cImage*			m_pImgMiniMap;			// �̴ϸʿ� �̹��� ����
	cImage*			m_pImgMapBuffer;		// ���� ������ �׷��� �� ����


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

