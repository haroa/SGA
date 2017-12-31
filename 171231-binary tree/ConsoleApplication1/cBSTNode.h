#pragma once

class cBSTNode;
typedef cBSTNode* LPBSTNODE;

class cBSTNode
{
public:
	//SYNTHESIZE(int, m_nKey, Key);
	int			m_nKey;
	int			m_nData;
	cBSTNode*	m_pLeftChild;
	cBSTNode*	m_pRightChild;

public:
	cBSTNode(int key, int data) :m_nKey(key), m_nData(data), m_pLeftChild(NULL), m_pRightChild(NULL) {}
	~cBSTNode();

	void Insert(int key, int data);
	cBSTNode* Find(int key);
	void Delete(int key, LPBSTNODE* ppthis);
	cBSTNode* GetMinNode();
	void Swap(cBSTNode* target);

	void Print(); // 오름차순 출력
};