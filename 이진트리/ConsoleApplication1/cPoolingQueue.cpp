#include "stdafx.h"
#include "cPoolingQueue.h"
#include "cQueue.h"
#include "cNode.h"


cPoolingQueue::cPoolingQueue()
{
	m_pQueue = new cQueue;
	m_pMemoryPool = new cQueue;
}


cPoolingQueue::~cPoolingQueue()
{
	delete m_pQueue;
	delete m_pMemoryPool;
}

void cPoolingQueue::Enqueue(int n)
{
	// 1. 풀링큐에 할당 된 공간이 있는지 확인하고 있으면 가져온다.

	cNode* pNode = m_pMemoryPool->Dequeue();

	if (pNode) // 풀에서 가져온 공간이 있다.
	{
		m_pQueue->Enqueue(n, pNode); // 메모리풀에서 받은 공간에 값을 설정하고 연결하는 함수
	}
	else // 없다.
	{
		m_pQueue->Enqueue(n); // 메모리 공간을 새로 할당받아 인큐하는 함수
	}
}

cNode* cPoolingQueue::Dequeue()
{
	return m_pQueue->Dequeue();
}

void cPoolingQueue::Delete(cNode* node)
{
	m_pMemoryPool->Enqueue(0, node);
}

void cPoolingQueue::Print()
{
	m_pQueue->Print();
}

bool cPoolingQueue::IsEmpty()
{
	return m_pQueue->IsEmpty();
}