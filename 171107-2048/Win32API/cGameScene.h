#pragma once
#include "cGameNode.h"
#include "cMap.h"

#define PUZZLE_SIZE	100

struct Tile
{
	cImage* image;
	float	fPosX;			//X�� ��ġ
	float	fPosY;			//Y�� ��ġ
	float	fCheckPosX;		//X�� �׽�Ʈ��ġ
	float	fCheckPosY;		//Y�� �׽�Ʈ��ġ
	int		Num;			//Ÿ���� ����
	bool	isBlank;		//Ÿ���� ����ִ°�?
	bool	isSum;			//�������°�?
};

class cGameScene : public cGameNode
{
private:
	cMap		m_cMap;
	Tile		tile;
	vector<Tile> m_vectile;
	int			rowCount;
	int			m_idRand;
	int			m_numRand;
	bool		m_CreateNum;
	int			m_blankCheck;
	int			count;
	int			m_nScore;
	RECT		rt;


	cImage*		m_number1;
	cImage*		m_number2;
	cImage*		m_number3;
	cImage*		m_number4;
	cImage*		m_number5;
	cImage*		m_number6;
	cImage*		m_number7;
	cImage*		m_number8;
	cImage*		m_number9;
	cImage*		m_number10;
	cImage*		m_number11;

	cImage*		m_nScore1;
	cImage*		m_nScore2;
	cImage*		m_nScore3;
	cImage*		m_nScore4;
	cImage*		m_nScore5;
	cImage*		m_nScore6;
public:

	vector<Tile> Gettile() { return m_vectile; }

	cGameScene();
	~cGameScene();

	void Setup();
	void Update();
	void Render();

	void PlayerController();
	void LoadImages();
	void Sumscore();
};

