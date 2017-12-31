#include "stdafx.h"
#include "cBST.h"
#include "cBSTNode.h"


cBST::cBST()
{
	m_pRoot = NULL;
}


cBST::~cBST()
{
}

void cBST::Insert(int key, int data)
{
	if (m_pRoot) // !�� ������ ���̰� ������ ���� �ƴϴ�
		m_pRoot->Insert(key, data);
	else
		m_pRoot = new cBSTNode(key,data);
}

cBSTNode * cBST::Find(int key)
{
	if (m_pRoot)
		 return m_pRoot->Find(key);
	else
		return NULL;
}

void cBST::Delete(int key)
{
	if (m_pRoot)
	{
		m_pRoot->Delete(key,&m_pRoot);
	}
}

void cBST::Print()
{
	if (m_pRoot)
		m_pRoot->Print();
}
