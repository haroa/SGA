#pragma once

class cNode;

class cStack
{
private:
	cNode* m_pTop;

public:
	cStack();
	~cStack();

	void Push(int n);
	cNode* Pop();
	void Print();
};

