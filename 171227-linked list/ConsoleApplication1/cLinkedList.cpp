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
		//����)for(auto iter = dldldl.begin(); iter != dldldl.end(); iter++)
		cNode* iter = new cNode;
		iter = m_pHead; // ������ �������ش� = iter = dldldl.begin();

		//iter��next�� null�� �ƴҶ� ������ ã�´�
		//iter != dldldl.end();
		while (iter->GetNext() != NULL)
		{
			//iter�ȿ� ���� ��� �־��ش�.
			//iter++;
			iter = iter->GetNext();
			
		}
		//iter�� next�� null�̸� ��� ���� �־��ش�
		iter->SetNext(node);
	}
}

void cLinkedList::Reverse()
{
	cNode* iter = NULL;	   //�������
	cNode* temp = NULL;	   //����

	while (m_pHead->GetNext() != NULL)
	{
		//ó�� ������,1
		iter = m_pHead;
		//��带 �����ڸ��� �Ű��ִ¿���
		m_pHead = iter->GetNext();
		//���� ����ڸ����ִ� �ؽ�Ʈ�� null���� �ֱ�
		iter->SetNext(temp);
		//�������� �Ѿ��?
		temp = iter;
	}
	m_pHead->SetNext(temp);
}

void cLinkedList::Delete(int n)
{
	cNode* iter = m_pHead; //���� ���
	cNode* preNode = NULL; //���� ���

	int count = 0; //����带 ��������ؼ� ���� ī��Ʈ

	while (iter->GetValue() != n) //iter�� value�� ������ �����
	{
		if (iter->GetNext() == NULL) // �˻��ϴ� ���� �������
		{
			return; //�Լ� ������
		}
		else
		{
			preNode = iter; // ��������� ���� ��尡 ���� ����� ������ ������
			iter = iter->GetNext(); //���� ���� ���� iter++
		}	
		count++; //while���� ���� ����
	}

	if (count == 0) //while���� �ѹ��� �����ʾҴٸ� �ʱ�ȭ�Ѵ�� 0�̵Ǵϱ� �������
	{
		m_pHead = iter->GetNext(); // �� ���� ������
	}
	else
	{
		if (iter->GetNext() == NULL) // ���̸�
			preNode->SetNext(NULL); // ���� ��带 NULL�� ����
		else
			preNode->SetNext(iter->GetNext()); //���� �ƴϸ� ���� ������� ����� ���� ��带 ���� ���� ����
	}

	delete iter; //���� ��带 �����.
}

void cLinkedList::Print()
{
	cout << "==========================================����======================================" << endl;
	cNode* iter = m_pHead;

	while (iter->GetNext() != NULL)
	{
		cout << iter->GetValue() << endl;
		iter = iter->GetNext();
	}
	cout << iter->GetValue() << endl;
	cout << "==========================================��========================================" << endl;
}

void cLinkedList::LoadData()
{
}
