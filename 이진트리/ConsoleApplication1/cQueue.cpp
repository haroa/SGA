#include "stdafx.h"
#include "cQueue.h"
#include "cNode.h"


cQueue::cQueue()
	: m_pFront(NULL)
	, m_pRear(NULL)
{
}


cQueue::~cQueue()
{
}

void cQueue::Enqueue(int n)
{
	if (IsEmpty())
	{
		m_pFront = m_pRear = new cNode(n);
	}
	else
	{
		m_pRear->SetNext(new cNode(n));
		m_pRear = m_pRear->GetNext();
	}
}

void cQueue::Enqueue(int n, cNode* pNode)
{
	pNode->SetValue(n);
	pNode->SetNext(NULL);

	if (IsEmpty())
	{
		m_pFront = m_pRear = pNode;
	}
	else
	{
		m_pRear->SetNext(pNode);
		m_pRear = m_pRear->GetNext();
	}
}

cNode* cQueue::Dequeue()
{
	cNode* pTemp = m_pFront;

	if (m_pFront)
		m_pFront = m_pFront->GetNext();

	if (IsEmpty())
		m_pRear = NULL;

	return pTemp;
}

void cQueue::Print()
{
	if (m_pFront)
		m_pFront->Print();
}

bool cQueue::IsEmpty()
{
	return (m_pFront == NULL);
}
