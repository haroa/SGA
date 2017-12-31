#include "stdafx.h"
#include "cNode.h"


cNode::cNode(int n, cNode* next/*= NULL*/)
	: m_nValue(n)
	, m_pNext(next)
{
}


cNode::~cNode()
{
}

void cNode::Insert(int n)
{
	if (m_pNext) // 현재 노드가 마지막 노드가 아닌 경우
	{
		m_pNext->Insert(n);
	}
	else // 현재 노드가 마지막 노드라면 새 노드를 다음 노드로 설정
	{
		m_pNext = new cNode(n);
	}
}

void cNode::Delete(int n, LPNODE* prevNext)
{
	if (m_nValue == n) // 지우려는 노드가 현재 노드인 경우
	{
		*prevNext = m_pNext; // 이전 노드의 다음을 현재 노드의 다음으로 연결
		delete this; // 현재 노드는 삭제
	}
	else if (m_pNext) // 지우려는 노드가 현재 노드가 아니고 다음 노드가 존재 하는 경우
	{
		m_pNext->Delete(n, &m_pNext); // 다음 노드에게 지우라고 요청
	}
}

void cNode::Print()
{
	cout << m_nValue << endl; // 현재 노드의 밸류 출력

	if (m_pNext)
	{
		m_pNext->Print(); // 다음 노드에게 출력 요청
	}
}

void cNode::Reverse(cNode* prev)
{
	if (m_pNext)
	{
		m_pNext->Reverse(this);
	}
	m_pNext = prev;
}

cNode* cNode::GetTail()
{
	cNode* tail = this;

	while (tail->GetNext())
	{
		tail = tail->GetNext();
	}

	return tail;
}
