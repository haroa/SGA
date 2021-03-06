// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void main()
{
	//link.Insert(2);
	//link.Insert(3);
	//link.Insert(4);
	//link.Print();
	//link.Reverse();
	//link.Print();
	cLinkedList link;
	ifstream data;
	string   szdata;
	data.open("data.txt", ios_base::in);

	//한줄씩 받아오는 와일문
	//
	while (data >> szdata)
	{
		if (szdata.substr(0, 1) == "i")
		{
			int Insertvalue = atoi(szdata.substr(2).c_str());
			link.Insert(Insertvalue);
		}
		else if (szdata.substr(0, 1) == "p")
		{
			link.Print();
		}
		else if (szdata.substr(0, 1) == "d")
		{
			int deletevalue = atoi(szdata.substr(2).c_str());
			link.Delete(deletevalue);
		}
		else if (szdata.substr(0, 1) == "r")
		{
			link.Reverse();
		}
	}
}

/*
data.txt
i:3		Insert(3)
d:2		Delete(2)
p		Print()
r		Reverse()
*/