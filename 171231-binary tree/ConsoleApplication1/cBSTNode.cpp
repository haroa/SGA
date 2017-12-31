#include "stdafx.h"
#include "cBSTNode.h"

cBSTNode::~cBSTNode()
{
	//SAFE_DELETE(m_pLeftChild);
	//SAFE_DELETE(m_pRightChild);
}

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

void cBSTNode::Delete(int key, LPBSTNODE* ppthis)
{
	//Ű���� ������
	if (m_nKey == key)
	{
		cBSTNode* deletenode = NULL;

		//�� ������ ��尡 �ܸ� ����� ���
		//1.������ ���� ���ʳ�尡 ��� null�� ���ǹ�
		if (!m_pRightChild && !m_pLeftChild)
		{
			//2.deletenode���ٰ� ����this�� �־���?
			deletenode = this;
			//3.SAFE_DELETE(deletenode)�� �Ἥ deletenode�ȿ� �ִ� ���� ������
			//4.*ppthis = NULL �� �־ null�̶�� �� �˷���?
			SAFE_DELETE(deletenode);
			*ppthis = deletenode;
		}

		//�� ������ ����� �ڽ� ��尡 �ϳ��� ���

		//������ null�϶�
		//1.������ ���̰� �����ʿ� ���� �������� ���ǹ�
		else if (m_pRightChild && !m_pLeftChild)
		{
			//2.deletenode���ٰ� this�� �־���
			deletenode = this;
			//3.���� 3���� ����
			//4.*ppthis = �������ڽ��� �־��ش�
			*ppthis = m_pRightChild;
			SAFE_DELETE(deletenode);
		}

		//�������� null�϶�
		//1.�������� ���̰� ���ʿ� ���� �������� ���ǹ�
		else if (!m_pRightChild && m_pLeftChild)
		{
			//2.deletenode���ٰ� this�� �־���
			deletenode = this;
			//3.���� 3���� ����
			//4.*ppthis = ������ �ڽ��� �־��ش�
			*ppthis = m_pLeftChild;
			SAFE_DELETE(deletenode);
		}

		//�� ������ ����� �ڽ� ��尡 �� ���� ���
		else
		{
			//1.getminnode�Լ��� ����ؼ� ������ �������ٰ� �ִ´�
			cBSTNode* minnode = GetMinNode();
			//2.swap�� ����ؼ� getminnode�� �Լ��� �ٲ� ����� ���� �ٲ��ش�
			Swap(minnode);
			//3.�ٲ� �����ʳ���� ���� ��������� �������ڽ����� delete�϶�� �Ѵ�.
			m_pRightChild->Delete(key, &m_pRightChild);
		}
	}
	//���� ���� Ű���� ������
	//1.�������� ���� ���ǹ�if(m_nKey > key)
	else if (m_nKey > key)
	{
		//2.�����ڽ��� ���� ����Ʈ �Լ��� ȣ��?
		if(m_pLeftChild)
			m_pLeftChild->Delete(key, &m_pLeftChild);
	}
	//���� ���� Ű���� Ŭ��
	//1.���������� ���� ���ǹ�if(m_nKey < key)
	else
	{
		//2.�������ڽ��� ���� ����Ʈ �Լ��� ȣ��?
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
	//cout << "Ű : " << m_nKey << " || ������ : " << m_nData;
	//if (m_pLeftChild)
	//	cout << "   leftŰ : " << m_pLeftChild->m_nKey << " || left������ : " << m_pLeftChild->m_nData;
	//else
	//	cout << "leftŰ : x , left������ : x";
	//if (m_pRightChild)
	//	cout << " rightŰ : " << m_pRightChild->m_nKey << " || right������ : " << m_pRightChild->m_nData << endl;
	//else
	//	cout << " rightŰ : x || right������ : x" << endl;
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
