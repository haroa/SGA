#include "stdafx.h"
#include "cBSTNode.h"

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

void cBSTNode::Delete(int key, LPBSTNODE* ppThis)
{
	//삭제하려는 노드의 자식 노드가 두개인 경우
	//1.삭제하려는 노드의 키값 위치를 찾는다.
	cBSTNode* nodes;
	nodes->Find(key);
	//2.삭제하려는 노드의 오른쪽서브트리를 찾는다.
	//3.오른쪽서브트리에서 제일 작은 숫자를 찾는다.
}

cBSTNode * cBSTNode::GetMinNode()
{

	return nullptr; 
}

void cBSTNode::Swap(cBSTNode* target)
{

}

void cBSTNode::Print()
{

}
