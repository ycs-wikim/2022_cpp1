// 04_06_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// #define A B : 앞으로 A는 B로 사용한다.
// typedef A B : 앞으로 A는 B와 같은 자료형으로 사용한다.
// typedef : type + define(definition) = 새로운 자료형을 정의
typedef int X;	// int와 동일한 X 자료형을 선언
typedef int i;	// int와 동일한 i 자료형을 선언
// 자료형과 변수는 사용될 수 있는 위치가 지정
// 컴파일러에서 변수와 자료형은 목록 형태로 구분되어 처리

// 복잡하거나 긴 이름을 가지고 있는 자료형을 쉽게 사용하기 위해
typedef struct calcResultForStrudentScore
{
	int x;
} STUDENT_SCORE, *PSTUDENT_SCORE;

// 변수의 상수화 : const keyword
// 1. keyword 자료형 변수선언 = 초기화;
// 2. 자료형 keyword 변수선언 = 초기화;

// 전역 변수 선언
int gx;

// 지역변수 주소 출력 함수
void asdf()
{
	int tx;
	printf("%s = %p : %p\n", __FUNCTION__, &tx, &gx);
}

/*
void test3_2()
{
	int a = 0;	// a++ = a = a + 1
	++a = 1;	// 정상 :	(a = a + 1) = 1;
				//			a = 1;
	a++ = 1;	// 에러 :	a = a + 1 = 1;
	1 = 1;
	2345 = 2387;
}
*/

void test_3_3()
{
	int a = 0;

	if (1 == a)	// 조건식 : 상수 (관계연산자) 변수
		printf("asdf\n");

				// 조건식 : 변수 (관계연산자) 상수
	if (a = 1)	// a = 1; 먼저 실행 -> a값 확인?
		printf("a == 1\n");
	else
		printf("a != 1\n");
}

int main()
{
	test_3_3();
	return 0;
	int tx;
	printf("%s = %p : %p\n", __FUNCTION__, &tx, &gx );
	asdf();
	return 0;

	struct calcResultForStrudentScore asdf;
	STUDENT_SCORE b;
	PSTUDENT_SCORE ptr = &b;

	// const 예제. 상수화 시점에는 반드시 초기화를 해야 한다!
	const int x = 3;
	//const int a;	// 초기화하지 않아 오류 발생
	//int const a;	// 초기화하지 않아 오류 발생
	int const y = 5;

	i i = 0;
	X a;
	a = 67;
	i = i + 7;	// 해석 : 1) i  2) =  3) i
	printf("%d\n", i);
	std::cout << "Hello World! " << a << std::endl;

	return 0;
}
