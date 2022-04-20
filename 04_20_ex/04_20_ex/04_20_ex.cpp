// 04_20_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 포인터 정리
// 연산자 : *, &
//	*	- 선언 : 뒤의 변수는 포인터 변수 ==> int *p;
//	*	- 사용 : 뒤의 변수의 값을 반환 ==> 가지고 있는 값
//	&	- 사용 : 뒤의 변수의 주소 값을 반환 ==> 변수의 주소 값

// 배열과 포인터 문법 확인
void test()
{
	int a[4] = { 1, 2, 3, 4 };
	int *p = a;
	// |0|0|0|1|0|0|0|2|0|0|0|3|0|0|0|4|
	printf("A: %d %d %d %d\n", a[0], a[1], a[2], a[3]);
	printf("P: %d %d %d %d\n", p[0], p[1], p[2], p[3]);
	printf("P~:%d %d %d %d\n", *(p+0), *(p+1), *(p+2), *(p+3));
	printf("A~:%d %d %d %d\n", *(a+0), *(a + 1), *(a + 2), *(a + 3));
}

int main()
{
	test();
	return 0;

	char k = 65;
	//int *p = &k;	// 자료형이 다른 주소는 받을 수 없다!
	int *lp = (int*)&k;
	char *pk = &k;
	int *pi;
	printf("1 - %d\n", *lp);
	printf("%d %d\n", sizeof(pk), sizeof(pi));

	// 변수 선언은 반드시 한줄에 하나씩만 합니다!
	//int a, b, c;	// XXXXXX
	int o = 0;		// O
	int b = 0;		// O
	int c = 0;		// O

	int a = 3;	// *a ==> 문법적으로 허용하지 않는 표현(Error)
	//printf("A: %d %d %p\n", *a, a, &a);
	printf("A: %d %p\n", a, &a);

	// 포인터 변수 : 값으로 주소 값만 받을 수 있는 변수
	//int *p = 3;		// 상수로 정의된 정수 값은 받을 수 없다!
	int *p = &a;		// 포인터 변수는 주소 값으로 초기화해야 한다.
	printf("P: %d %p %p\n", *p, p, &p);

	// *p == a
	*p = 9;
	printf("A~: %d\n", a);
	a = 22;
	printf("P~: %d\n", *p);

	int **p1 = &p;
	int ***p2 = &p1;
	int ****p3 = &p2;
	printf("A: %d %p\n", a, &a);
	printf("P: %d %p %p\n", *p, p, &p);
	printf("P1: %d %p %p %p\n", **p1, *p1, p1, &p1);
	printf("P2: %d %p %p %p %p\n", ***p2, **p2, *p2, p2, &p2);


    std::cout << "Hello World!\n";
	return 0;
}
