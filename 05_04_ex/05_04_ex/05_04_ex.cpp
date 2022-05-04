// 05_04_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void cbv(int value)		// int value = 5
{
	value++;
	printf("%s : %d\n", __FUNCTION__, value);
}

void cbr(int &ref)	// int &ref = ref
{
	ref++;
	printf("%s : %d\n", __FUNCTION__, ref);
}

void cba(int *address)	// int *address = adress(주소값)
{
	(*address)++;
	printf("%s : %d\n", __FUNCTION__, *address);
}

void callbymain()
{
	int value = 5;			// call by value
	int &ref = value;		// call by reference
	int *address = &value;	// call by address

	printf("%s : %d\n", __FUNCTION__, value);
	cbv(value);
	cbr(ref);
	cba(address);
	printf("%s : %d\n", __FUNCTION__, value);
}



void const_test()
{
	int x = 3;
	int y = 4;
	const int z = 5;
	// 포인터에 const를 조합하면 자료형이 상수화된다.
	const int *p = &x;
	int const *p1 = &x;
	const int const *p2 = &x;
	//z = 7;
	p = &y;
	p1 = &y;
	p2 = &y;
}

void array_test()
{
	int k = 0;
	// 2차원 배열을 포인터로 접근하기
	int t[2][3] = { {11, 12, 13}, {21, 22, 23} };
	int *ptr = (int*)t;
	for (; k < 6; k++)
		printf("T: %d\n", ptr[k]);

	// 배열과 포인터의 결정적인 차이점!
	// 배열은 선언하는 시점에 자동으로 상수가 된다!
	int arr[4] = { 0, };
	int x = 3;
	int *p = arr;
	// 아래와 같은 연산은 불가능!
	// 왜냐하면 배열은 상수이므로 l-value가 될 수 없다!
	//arr = &x;

	// ex 6-5.
	int array[2] = { 1, 2 };
	//int *p = &arr;
	int (*p1)[2] = &array;
	// p2는 int를 요구하나, array는 배열이므로,
	// 자료형이 맞지 않아 오류 발생
	//int **p2 = &array;
	printf("%d %d\n", (*p1)[0], (*p1)[1]);
	int ar[8] = {1, 2};
	
	for (k = 0; k < 7; k++)
	{
		printf("%d\n", ar[k]);
	}
}

int main()
{
	callbymain();
	//array_test();
	//const_test();
	int a = 9;
	// 레퍼런스(참조 타입) 자료형 : 포인터 연산 없이 포인터의 처리를 수행
	int &ra = a;
	// 레퍼런스 변수는 선언 시 반드시 초기화 해야 함!
	//int &rb;
	// 포인터는 초기화하지 않아도 선언 가능!
	int *p;		// 들어 있는 값은 쓰레기 값
	int *p1 = NULL;		// 0으로 초기화. C에서도 사용 가능한 방법
	int *p2 = nullptr;	// 최근 C++에서 포인터를 초기화하는 방법

	// 사용 방법은 일반 변수와 동일 
	// 번역 시점에 자동으로 포인터 형으로 변환
	ra = 3;
	printf("%d\n", a);

    std::cout << "Hello World!\n";
	return 0;
}
