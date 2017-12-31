#include "stdafx.h"
#include "cBSTNode.h"

cBSTNode::~cBSTNode()
{
	//SAFE_DELETE(m_pLeftChild);
	//SAFE_DELETE(m_pRightChild);
}

void cBSTNode::Insert(int key, int data)
{
	//key == 노드의 이름
	//data == 노드안에 들어있는 값
	if (m_nKey != key)
	{
		if (m_nKey > key)
		{
			if (m_pLeftChild == NULL)
				m_pLeftChild = new cBSTNode(key, data);
			else
				m_pLeftChild->Insert(key, data);
		}
		else
		{ 
			if(m_pRightChild == NULL)
				m_pRightChild = new cBSTNode(key, data);
			else
			m_pRightChild->Insert(key, data);
		}
	}
}

cBSTNode * cBSTNode::Find(int key)
{
	//if (m_nKey != key)
	//{
	//	if (m_pLeftChild != NULL)
	//		m_pLeftChild->Find(key);
	//	if (m_pRightChild != NULL)
	//		m_pRightChild->Find(key);
	//	else
	//		return NULL;
	//}
	//else
	//	return (this);
	if (m_nKey > key)
	{
		if (m_pLeftChild != NULL)
		{
			return m_pLeftChild->Find(key);
		}
		else
			return NULL;
	}
	else if (m_nKey < key)
	{
		if (m_pRightChild != NULL)
		{
			return m_pRightChild->Find(key);
		}
		else
			return NULL;
	}
	else if (m_nKey == key)
	{
		return this;
	}
}

void cBSTNode::Delete(int key, LPBSTNODE* ppthis)
{
	//키값이 같을때
	if (m_nKey == key)
	{
		cBSTNode* deletenode = NULL;

		//■ 삭제할 노드가 단말 노드인 경우
		//1.오른쪽 노드와 왼쪽노드가 모두 null인 조건문
		if (!m_pRightChild && !m_pLeftChild)
		{
			//2.deletenode에다가 지울this를 넣어줌?
			deletenode = this;
			//3.SAFE_DELETE(deletenode)를 써서 deletenode안에 있는 값을 지워줌
			//4.*ppthis = NULL 을 넣어서 null이라는 걸 알려줌?
			SAFE_DELETE(deletenode);
			*ppthis = deletenode;
		}

		//■ 삭제할 노드의 자식 노드가 하나인 경우

		//왼쪽이 null일때
		//1.왼쪽이 널이고 오른쪽에 값이 있을때의 조건문
		else if (m_pRightChild && !m_pLeftChild)
		{
			//2.deletenode에다가 this를 넣어줌
			deletenode = this;
			//3.위의 3번과 같음
			//4.*ppthis = 오른쪽자식을 넣어준다
			*ppthis = m_pRightChild;
			SAFE_DELETE(deletenode);
		}

		//오른쪽이 null일때
		//1.오른쪽이 널이고 왼쪽에 값이 있을때의 조건문
		else if (!m_pRightChild && m_pLeftChild)
		{
			//2.deletenode에다가 this를 넣어줌
			deletenode = this;
			//3.위의 3번과 같음
			//4.*ppthis = 왼쪽의 자식을 넣어준다
			*ppthis = m_pLeftChild;
			SAFE_DELETE(deletenode);
		}

		//■ 삭제할 노드의 자식 노드가 두 개인 경우
		else
		{
			//1.getminnode함수를 사용해서 저장할 공간에다가 넣는다
			cBSTNode* minnode = GetMinNode();
			//2.swap을 사용해서 getminnode의 함수와 바꿀 노드의 값을 바꿔준다
			Swap(minnode);
			//3.바뀐 오른쪽노드의 값을 지우기위해 오른쪽자식한테 delete하라고 한다.
			m_pRightChild->Delete(key, &m_pRightChild);
		}
	}
	//내가 적은 키값이 작을때
	//1.왼쪽으로 가는 조건문if(m_nKey > key)
	else if (m_nKey > key)
	{
		//2.왼쪽자식의 삭제 딜리트 함수를 호출?
		if(m_pLeftChild)
			m_pLeftChild->Delete(key, &m_pLeftChild);
	}
	//내가 적은 키값이 클때
	//1.오른쪽으로 가는 조건문if(m_nKey < key)
	else
	{
		//2.오른쪽자식의 삭제 딜리트 함수를 호출?
		if(m_pRightChild)
			m_pRightChild->Delete(key, &m_pRightChild);
	}
}

cBSTNode* cBSTNode::GetMinNode()
{
	if (!m_pLeftChild)
	{
		return this;
	}
	else
		return m_pLeftChild->GetMinNode();
}

void cBSTNode::Swap(cBSTNode* target)
{
	int tempkey = m_nKey;
	int	tempdata= m_nData;

	m_nKey = target->m_nKey;
	m_nData = target->m_nData;

	target->m_nKey = tempkey;
	target->m_nData = tempdata;

	
}

void cBSTNode::Print()
{
	//cout << "키 : " << m_nKey << " || 데이터 : " << m_nData;
	//if (m_pLeftChild)
	//	cout << "   left키 : " << m_pLeftChild->m_nKey << " || left데이터 : " << m_pLeftChild->m_nData;
	//else
	//	cout << "left키 : x , left데이터 : x";
	//if (m_pRightChild)
	//	cout << " right키 : " << m_pRightChild->m_nKey << " || right데이터 : " << m_pRightChild->m_nData << endl;
	//else
	//	cout << " right키 : x || right데이터 : x" << endl;
	if (m_pLeftChild)
	{	
		m_pLeftChild->Print();
	}

	cout << m_nKey << endl;

	if (m_pRightChild)
	{
		m_pRightChild->Print();
	}
}
