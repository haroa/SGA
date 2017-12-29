#pragma once

class cNode;

class cQueue
{
private:
	cNode* m_pFront;
	cNode* m_pRear;

public:
	cQueue();
	~cQueue();

	void Enqueue(int n);
	void Enqueue(int n, cNode* pNode);
	cNode* Dequeue();
	void Print();
	bool IsEmpty();
};

