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
	// 1. Ǯ��ť�� �Ҵ� �� ������ �ִ��� Ȯ���ϰ� ������ �����´�.

	cNode* pNode = m_pMemoryPool->Dequeue();

	if (pNode) // Ǯ���� ������ ������ �ִ�.
	{
		m_pQueue->Enqueue(n, pNode); // �޸�Ǯ���� ���� ������ ���� �����ϰ� �����ϴ� �Լ�
	}
	else // ����.
	{
		m_pQueue->Enqueue(n); // �޸� ������ ���� �Ҵ�޾� ��ť�ϴ� �Լ�
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