#pragma once
class cNode
{
private:
	int			m_nValue;
	cNode*		m_pNext;

	// ��� ���� �߰� X

public:
	cNode();
	~cNode();

	int GetValue() { return m_nValue; }
	void SetValue(int n) { m_nValue = n; }
	cNode* GetNext() { return m_pNext; }
	void SetNext(cNode* next) { m_pNext = next; }
};

