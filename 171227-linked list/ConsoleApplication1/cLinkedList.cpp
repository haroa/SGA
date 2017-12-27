#include "stdafx.h"
#include "cLinkedList.h"
#include "cNode.h"

cLinkedList::cLinkedList()
{
}


cLinkedList::~cLinkedList()
{
}

void cLinkedList::Insert(int n)
{
	//m_pHead->SetValue(n);
	//m_pHead->SetNext(NULL);
	cNode* node = new cNode;
	node->SetValue(n);
	node->SetNext(NULL);

	if (m_pHead == NULL)
	{
		m_pHead = node;
	}
	else
	{
		//예제)for(auto iter = dldldl.begin(); iter != dldldl.end(); iter++)
		cNode* iter = new cNode;
		iter = m_pHead; // 시작을 가르쳐준다 = iter = dldldl.begin();

		//iter의next가 null이 아닐때 까지를 찾는다
		//iter != dldldl.end();
		while (iter->GetNext() != NULL)
		{
			//iter안에 값을 계속 넣어준다.
			//iter++;
			iter = iter->GetNext();
			
		}
		//iter의 next가 null이면 계속 값을 넣어준다
		iter->SetNext(node);
	}
}

void cLinkedList::Reverse()
{
	cNode* iter = NULL;	   //이전노드
	cNode* temp = NULL;	   //빈노드

	while (m_pHead->GetNext() != NULL)
	{
		//처음 시작점,1
		iter = m_pHead;
		//헤드를 다음자리로 옮겨주는역할
		m_pHead = iter->GetNext();
		//원래 헤드자리에있던 넥스트에 null값을 넣기
		iter->SetNext(temp);
		//다음으로 넘어가기?
		temp = iter;
	}
	m_pHead->SetNext(temp);
}

void cLinkedList::Delete(int n)
{
	cNode* iter = m_pHead; //시작 노드
	cNode* preNode = NULL; //이전 노드

	int count = 0; //헤드노드를 지우기위해서 만든 카운트

	while (iter->GetValue() != n) //iter가 value와 같으면 멈춘다
	{
		if (iter->GetNext() == NULL) // 검색하는 값이 없을경우
		{
			return; //함수 끝낸다
		}
		else
		{
			preNode = iter; // 지우기전에 이전 노드가 현재 노드의 정보를 가진다
			iter = iter->GetNext(); //다음 노드로 연결 iter++
		}	
		count++; //while문이 돌때 증가
	}

	if (count == 0) //while문이 한번도 돌지않았다면 초기화한대로 0이되니까 여기들어와
	{
		m_pHead = iter->GetNext(); // 맨 앞을 지울경우
	}
	else
	{
		if (iter->GetNext() == NULL) // 끝이면
			preNode->SetNext(NULL); // 이전 노드를 NULL로 연결
		else
			preNode->SetNext(iter->GetNext()); //끝이 아니면 원래 지우려는 노드의 다음 노드를 이전 노드와 연결
	}

	delete iter; //현재 노드를 지운다.
}

void cLinkedList::Print()
{
	cout << "==========================================시작======================================" << endl;
	cNode* iter = m_pHead;

	while (iter->GetNext() != NULL)
	{
		cout << iter->GetValue() << endl;
		iter = iter->GetNext();
	}
	cout << iter->GetValue() << endl;
	cout << "==========================================끝========================================" << endl;
}

void cLinkedList::LoadData()
{
}
