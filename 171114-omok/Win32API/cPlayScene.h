#pragma once
#include "cGameNode.h"

enum OMOK
{
	WHITE = 0,
	BLACK
};


struct omok
{
	float	fPosX;		//�ٵϾ� ������ġX
	float	fPosY;		//�ٵϾ� ������ġY
	RECT	rtBody;		//�ٵϾ� ������ġ�� ��Ʈ
	bool	isActive;	//���ķ����� �ٵϾ˺����ֱ�
	bool	isColor;	//������ ������
	bool	isShow;		//�Ϻ��� �ٵϾ˺����ֱ�
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


	cImage*			m_pImgBackground;		// ȭ�� ��ü ���
	cImage*			m_pOmok;
	cImage*			m_pImgMiniMap;			// �̴ϸʿ� �̹��� ����
	cImage*			m_pImgMapBuffer;		// ���� ������ �׷��� �� ����


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

