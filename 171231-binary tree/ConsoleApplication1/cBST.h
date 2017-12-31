#pragma once

class cBSTNode;

class cBST
{
private:
	cBSTNode* m_pRoot;

public:
	cBST();
	~cBST();

	void		Insert(int key, int data);
	cBSTNode*	Find(int key);
	void		Delete(int key);
	void		Print();			// 오름 차순 정렬
};

