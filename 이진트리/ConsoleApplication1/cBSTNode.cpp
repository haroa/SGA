#include "stdafx.h"
#include "cBSTNode.h"

void cBSTNode::Insert(int key, int data)
{
	//key == ����� �̸�
	//data == ���ȿ� ����ִ� ��
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
	//�����Ϸ��� ����� �ڽ� ��尡 �ΰ��� ���
	//1.�����Ϸ��� ����� Ű�� ��ġ�� ã�´�.
	cBSTNode* nodes;
	nodes->Find(key);
	//2.�����Ϸ��� ����� �����ʼ���Ʈ���� ã�´�.
	//3.�����ʼ���Ʈ������ ���� ���� ���ڸ� ã�´�.
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
