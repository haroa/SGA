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
	if (m_pNext) // ���� ��尡 ������ ��尡 �ƴ� ���
	{
		m_pNext->Insert(n);
	}
	else // ���� ��尡 ������ ����� �� ��带 ���� ���� ����
	{
		m_pNext = new cNode(n);
	}
}

void cNode::Delete(int n, LPNODE* prevNext)
{
	if (m_nValue == n) // ������� ��尡 ���� ����� ���
	{
		*prevNext = m_pNext; // ���� ����� ������ ���� ����� �������� ����
		delete this; // ���� ���� ����
	}
	else if (m_pNext) // ������� ��尡 ���� ��尡 �ƴϰ� ���� ��尡 ���� �ϴ� ���
	{
		m_pNext->Delete(n, &m_pNext); // ���� ��忡�� ������ ��û
	}
}

void cNode::Print()
{
	cout << m_nValue << endl; // ���� ����� ��� ���

	if (m_pNext)
	{
		m_pNext->Print(); // ���� ��忡�� ��� ��û
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
