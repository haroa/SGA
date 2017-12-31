#pragma once

#define QUEUE_SIZE 5

class cCircularQueue
{
private:
	int m_aData[QUEUE_SIZE];
	int m_nFront;
	int m_nRear;

public:
	cCircularQueue();
	~cCircularQueue();

	void	Enqueue(int n);
	int*	Dequeue();
	void	Print();
	bool	IsFull();
	bool	IsEmpty();
};

