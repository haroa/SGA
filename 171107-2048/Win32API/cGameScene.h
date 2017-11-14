#pragma once
#include "cGameNode.h"
#include "cMap.h"

#define PUZZLE_SIZE	100

struct Tile
{
	cImage* image;
	float	fPosX;			//X의 위치
	float	fPosY;			//Y의 위치
	float	fCheckPosX;		//X의 테스트위치
	float	fCheckPosY;		//Y의 테스트위치
	int		Num;			//타일의 숫자
	bool	isBlank;		//타일이 비어있는가?
	bool	isSum;			//합쳐졌는가?
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

