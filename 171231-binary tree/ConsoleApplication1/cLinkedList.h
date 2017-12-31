#pragma once

class cNode;

class cLinkedList
{
private:
	cNode*		m_pHead;

	// 멤버 변수 추가 X

public:
	cLinkedList();
	~cLinkedList();

	void Insert(int n);
	void Delete(int n);
	void Print();
	void Reverse();
	bool isEmpty();
};

