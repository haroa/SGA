// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cLinkedList.h"
#include "cNode.h"
#include "cStack.h"
#include "cCircularQueue.h"
#include "cQueue.h"
#include "cPoolingQueue.h"


void LinkedListTest();

void main()
{
	//LinkedListTest();

	// 스택 테스트
	//cStack* pStack = new cStack;

	//pStack->Push(3);
	//pStack->Push(2);
	//pStack->Push(1);

	//cNode* pTemp = pStack->Pop();
	//cout << pTemp->GetValue() << endl;
	//delete pTemp;

	// 서큘라큐 테스트
	//cCircularQueue* pCQueue = new cCircularQueue;
	//pCQueue->Enqueue(3);
	//pCQueue->Enqueue(2);
	//pCQueue->Enqueue(1);

	//int* pTemp = pCQueue->Dequeue();
	//cout << *pTemp << endl;

	// 링크드리스크 큐 테스트
	//cQueue* pQueue = new cQueue;
	//pQueue->Enqueue(3);
	//pQueue->Enqueue(2);
	//pQueue->Enqueue(1);

	//cNode* pTemp = pQueue->Dequeue();
	//if (pTemp) cout << pTemp->GetValue() << endl;
	//SAFE_DELETE(pTemp);
	//pTemp = pQueue->Dequeue();
	//if (pTemp) cout << pTemp->GetValue() << endl;
	//SAFE_DELETE(pTemp);
	//pTemp = pQueue->Dequeue();
	//if (pTemp) cout << pTemp->GetValue() << endl;
	//SAFE_DELETE(pTemp);

	cQueue*	pQueue = new cQueue;
	cPoolingQueue* pPoolQueue = new cPoolingQueue;

	DWORD dwStart, dwEnd, dwQueue, dwPQueue;

	dwStart = GetTickCount();

	/*
	큐 알고리즘 작성
	*/
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 1000; ++j)
			pQueue->Enqueue(i);
		for (int j = 0; j < 1000; ++j)
		{
			cNode* pNode = pQueue->Dequeue();
			SAFE_DELETE(pNode);
		}
	}

	dwEnd = GetTickCount();

	dwQueue = dwEnd - dwStart;

	dwStart = GetTickCount();

	cout << "=====================================" << endl;
	/*
	풀링큐 알고리즘 작성
	*/
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 1000; ++j)
			pPoolQueue->Enqueue(i);
		for (int j = 0; j < 1000; ++j)
		{
			cNode* pNode = pPoolQueue->Dequeue();
			pPoolQueue->Delete(pNode);
		}
	}

	dwEnd = GetTickCount();

	dwPQueue = dwEnd - dwStart;

	cout << "=====================================" << endl;

	cout << dwQueue / (float)dwPQueue << "배" << endl;

	/*
	링크드 리스크 큐와 메모리풀링(링크드 리스트) 큐 속도 차이 배율로 출력
	*/

	system("pause");
}

void LinkedListTest()
{
	cLinkedList* pList = new cLinkedList;

	//pList->Insert(3);
	//pList->Insert(2);
	//pList->Insert(1);
	//pList->Insert(3);

	//pList->Delete(3);
	//pList->Reverse();

	//pList->Print();

	FILE* fp = NULL;
	fopen_s(&fp, "data.txt", "r");

	while (true)
	{
		if (feof(fp)) break;		// 파일 커서가 마지막 도달하면 종료

		char szBuf[1024];
		fgets(szBuf, 1024, fp);		// 한줄씩 읽는다. fgetc : 한자씩 읽는다.

		if (szBuf[0] == 'i')
		{
			pList->Insert(atoi(&szBuf[2]));
		}
		else if (szBuf[0] == 'd')
		{
			pList->Delete(atoi(&szBuf[2]));
		}
		else if (szBuf[0] == 'p')
		{
			pList->Print();
		}
		else if (szBuf[0] == 'r')
		{
			pList->Reverse();
		}
	}

	fclose(fp);

	delete pList;
}