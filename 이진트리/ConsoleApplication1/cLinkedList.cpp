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
	//if (isEmpty()) // 현재 리스트가 비어 있는 경우
	//{
	//	m_pHead = new cNode(n); // 새 노드를 생성하고 헤드가 새 노드를 가르키게 한다.
	//}
	//else
	//{
	//	// 1. 마지막 노드를 찾는다.
	//	cNode* pTail = m_pHead;
	//	while (pTail->GetNext())
	//	{
	//		pTail = pTail->GetNext();
	//	}
	//	// 2. 새 노드를 생성해서 마지막 노드 다음에 새 노드를 연결한다.
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
	//	if (currNode->GetValue() == n) // 지우려는 대상인지 확인
	//	{
	//		if (prevNode == NULL) // 지우려는 대상이 헤드인 경우
	//		{
	//			m_pHead = m_pHead->GetNext();
	//		}
	//		else // 헤드가 아닌 경우
	//		{
	//			// 이전 노드의 다음 노드를 현재 노드의 다음 노드로 셋팅하고
	//			prevNode->SetNext(currNode->GetNext());
	//			// 현재 노드 삭제
	//			delete currNode;
	//		}
	//		break;
	//	}
	//	else
	//	{
	//		prevNode = currNode;			// 이전 노드를 현재 노드로 설정
	//		currNode = currNode->GetNext();	// 현재 노드를 다음 노드로 설정
	//	}
	//}

	if (m_pHead == NULL) return;

	m_pHead->Delete(n, &m_pHead);
}

void cLinkedList::Print()
{
	//cNode* currNode = m_pHead;

	//while (currNode)	// 현재 노드가 존재 한다면
	//{
	//	cout << currNode->GetValue() << endl;	// 출력
	//	currNode = currNode->GetNext();			// 다음 노드로 넘어간다.
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
	//	// 1. 현재 노드의 넥스트를 임시로 저장해 둔다.
	//	nextNode = currNode->GetNext();
	//	// 2. 현재 노드의 넥스트를 이전 노드로 셋팅 한다.
	//	currNode->SetNext(prevNode);
	//	// - 다음 노드 작업 준비
	//	// 3. 현재 노드는 다음 노드의 이전 노드이다.
	//	prevNode = currNode;
	//	// 4. 다음 작업 노드는 오리지널 리스트에서의 현재 노드의 넥스트 노드이다.
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