#include "stdafx.h"
#include "cLinkedList.h"
#include "cNode.h"


cLinkedList::cLinkedList()
	: m_pHead(NULL)
{
}


cLinkedList::~cLinkedList()
{
	cNode* currNode = m_pHead;
	cNode* deleteNode;

	while (currNode)
	{
		deleteNode = currNode;
		currNode = currNode->GetNext();
		delete deleteNode;
	}
}

void cLinkedList::Insert(int n)
{
	//if (isEmpty()) // ���� ����Ʈ�� ��� �ִ� ���
	//{
	//	m_pHead = new cNode(n); // �� ��带 �����ϰ� ��尡 �� ��带 ����Ű�� �Ѵ�.
	//}
	//else
	//{
	//	// 1. ������ ��带 ã�´�.
	//	cNode* pTail = m_pHead;
	//	while (pTail->GetNext())
	//	{
	//		pTail = pTail->GetNext();
	//	}
	//	// 2. �� ��带 �����ؼ� ������ ��� ������ �� ��带 �����Ѵ�.
	//	pTail->SetNext(new cNode(n));
	//}

	if (m_pHead == NULL)
	{
		m_pHead = new cNode(n);
	}
	else
	{
		m_pHead->Insert(n);
	}
}

void cLinkedList::Delete(int n)
{
	//cNode* prevNode = NULL;
	//cNode* currNode = m_pHead;

	//while (currNode)
	//{
	//	if (currNode->GetValue() == n) // ������� ������� Ȯ��
	//	{
	//		if (prevNode == NULL) // ������� ����� ����� ���
	//		{
	//			m_pHead = m_pHead->GetNext();
	//		}
	//		else // ��尡 �ƴ� ���
	//		{
	//			// ���� ����� ���� ��带 ���� ����� ���� ���� �����ϰ�
	//			prevNode->SetNext(currNode->GetNext());
	//			// ���� ��� ����
	//			delete currNode;
	//		}
	//		break;
	//	}
	//	else
	//	{
	//		prevNode = currNode;			// ���� ��带 ���� ���� ����
	//		currNode = currNode->GetNext();	// ���� ��带 ���� ���� ����
	//	}
	//}

	if (m_pHead == NULL) return;

	m_pHead->Delete(n, &m_pHead);
}

void cLinkedList::Print()
{
	//cNode* currNode = m_pHead;

	//while (currNode)	// ���� ��尡 ���� �Ѵٸ�
	//{
	//	cout << currNode->GetValue() << endl;	// ���
	//	currNode = currNode->GetNext();			// ���� ���� �Ѿ��.
	//}

	if (m_pHead == NULL) return;

	m_pHead->Print();
}

void cLinkedList::Reverse()
{
	//cNode* prevNode = NULL;
	//cNode* currNode = m_pHead;
	//cNode* nextNode;

	//while (currNode)
	//{
	//	// 1. ���� ����� �ؽ�Ʈ�� �ӽ÷� ������ �д�.
	//	nextNode = currNode->GetNext();
	//	// 2. ���� ����� �ؽ�Ʈ�� ���� ���� ���� �Ѵ�.
	//	currNode->SetNext(prevNode);
	//	// - ���� ��� �۾� �غ�
	//	// 3. ���� ���� ���� ����� ���� ����̴�.
	//	prevNode = currNode;
	//	// 4. ���� �۾� ���� �������� ����Ʈ������ ���� ����� �ؽ�Ʈ ����̴�.
	//	currNode = nextNode;
	//}
	//m_pHead = prevNode;

	if (m_pHead == NULL) return;

	cNode* tail = m_pHead->GetTail();
	m_pHead->Reverse(NULL);
	m_pHead = tail;
}

bool cLinkedList::isEmpty()
{
	return (m_pHead == NULL);
}