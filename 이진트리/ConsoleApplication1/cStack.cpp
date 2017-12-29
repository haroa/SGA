#include "stdafx.h"
#include "cStack.h"
#include "cNode.h"

cStack::cStack()
	: m_pTop(NULL)
{
}


cStack::~cStack()
{
}

void cStack::Push(int n)
{
	m_pTop = new cNode(n, m_pTop);
}

cNode * cStack::Pop()
{
	cNode* pPop = m_pTop;

	if (m_pTop)
		m_pTop = m_pTop->GetNext();

	return pPop;
}

void cStack::Print()
{
	if (m_pTop)
		m_pTop->Print();
}
