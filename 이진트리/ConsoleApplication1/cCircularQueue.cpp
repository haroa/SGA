#include "stdafx.h"
#include "cCircularQueue.h"


cCircularQueue::cCircularQueue()
	: m_nFront(0)
	, m_nRear(0)
{
}


cCircularQueue::~cCircularQueue()
{
}

void cCircularQueue::Enqueue(int n)
{
	if (IsFull()) return;

	m_aData[m_nRear] = n;
	m_nRear = (m_nRear + 1) % QUEUE_SIZE;
}

int* cCircularQueue::Dequeue()
{
	if (IsEmpty()) return NULL;

	int nTemp = m_nFront;
	m_nFront = (m_nFront + 1) % QUEUE_SIZE;

	return &m_aData[nTemp];
}

void cCircularQueue::Print()
{
	int nTemp = m_nFront;

	while (nTemp != m_nRear)
	{
		cout << m_aData[nTemp] << endl;
		nTemp = (nTemp + 1) % QUEUE_SIZE;
	}
}

bool cCircularQueue::IsFull()
{
	return (m_nFront == (m_nRear + 1) % QUEUE_SIZE);
}

bool cCircularQueue::IsEmpty()
{
	return (m_nFront == m_nRear);
}
