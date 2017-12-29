#pragma once

class cNode;
typedef cNode* LPNODE;

class cNode
{
private:
	int			m_nValue;
	cNode*		m_pNext;
	int			m_nDummy[4096];

	// 멤버 변수 추가 X

public:
	cNode(int n, cNode* next = NULL);
	~cNode();

	int GetValue() { return m_nValue; }
	void SetValue(int n) { m_nValue = n; }
	cNode* GetNext() { return m_pNext; }
	void SetNext(cNode* next) { m_pNext = next; }

	void Insert(int n);
	void Delete(int n, LPNODE* prevNext);
	void Print();
	void Reverse(cNode* prev);
	cNode* GetTail();
};

