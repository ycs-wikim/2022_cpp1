// 04_13.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 매크로 함수 선언 : 무조건 해당 위치로 복사
#define SWAP(a, b)	{ a ^= b; b ^= a; a ^= b; }

bool checkEvent1();
bool checkEvent2();
bool checkEvent3();
bool checkEvent4();
bool checkEvent5();

int main()
{
	int i, j;

	for (i = 5; i > 0; i--)	{		for (j = 1; j < 6; j++)			if (j >= i)				printf("*");			else				printf(" ");		printf("\n");	}

	return 0;
	/*
	// do ~ while 실예
	// 이벤트 발생 조건 : 필요한 조건 5개
	// 조건 확인 위치
	do
	{
		// 1번 조건 확인
		if (true != checkEvent1())
			break;
		if (true != checkEvent2())
			break;
		if (true != checkEvent3())
			break;
		if (true != checkEvent4())
			break;
		if (true != checkEvent5())
			break;

		// 이벤트를 발생시킨다.

		// 이벤트 발생 참으로 반환
		return true;
	} while (false);

	// 이벤트 발생 조건을 만족하지 못하였다.
	return false;

	}
	*/

	// 매크로 함수의 위험성
	int a = 0;
	int b = 1;

	if (0)
		// 1)
		SWAP(a, b); 

	cout << a << " " << b << endl;
    std::cout << "Hello World!\n" << std::endl;

	return 0;
}
