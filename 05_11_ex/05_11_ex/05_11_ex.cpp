// 05_11_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdarg.h>
//#define CODE_FUNCTION	0
///
// 함수 호출 방식을 사용하기 위한 구조체를 선언
typedef struct test_for_function_call_method
{
	int x;		// 이것은 배고플때 사용하는 변수입니다.
	int y;		// 이 변수는 영국으로부터~~~
	int z;		// 그냥... 피곤해요.
} TEST_FUNC, *PTEST_FUNC;

// 함수의 원형(프로토타입) : 함수의 기능 구현부분을 제외한 모든 내용을 기록
void printstruct(PTEST_FUNC);


// 1 ~ 5
// 1. 기능 : 구조체에 들어 있는 내용을 수정(+1)하겠다.
// 2. 인수 : 구조체 변수
//		1. TEST_FUNC x;		// 값
//		2. PTEST_FUNC x;	// 포인터
//		3. TEST_FUNC &x;	// 레퍼런스
// 3. 해야할 일(기능) : 전달된 구조체 멤버에 모두 1을 더한다.
//		1. x.x++;
//		2. x->x++;
//		3. x.x++;
// 4. 함수이름 : sadd
// 5. 결과 값 : 없다.(void)

// 1. call by value
//		호출 시점의 변수 값을 복사해서 전달
//		복사된 값을 받는 변수의 값을 아무리 변경해도 원본에는 영향이 없다!
/*
	int x = 3;
	int y = x;	// y = 3
	y = 15;		// y = 15, x = 3
*/
void call_by_value(TEST_FUNC x)		// TEST_FUNC x = a
{
	x.x++;
	x.y++;
	x.z++;
	printstruct(&x);
}

// 2. call by address
//		호출 시점에 전달 변수의 주소(비활성화되는 스택 프레임에 위치)를 전달
//		값을 변경하면 주소 위치의 값이 변경되므로, 원본에 동일한 영향을 준다.
void call_by_address(PTEST_FUNC x)
{
	x->x++;
	x->y++;
	x->z++;
}

// 3. call by reference
//		값을 변경하면 주소 위치의 값이 변경되므로, 원본에 동일한 영향을 준다.
void call_by_ref(TEST_FUNC &x)
{
	x.x++;
	x.y++;
	x.z++;
}

void printstruct(PTEST_FUNC x)
{
	printf("x[ %d ] y[ %d ] z[ %d ]\n", x->x, x->y, x->z);
}


// 디폴트 인자
void testdefault(int x, int y = 7)
{
	printf("%d %d\n", x, y);
}

// 디폴트 인자는 여러개 사용이 가능!
// 디폴트 인자 사용시 주의할 점 : 디폴트 인자는 항상 마지막에 위치해야 함!
void testdefault1(int x, int y = 15, int k = 90)
{}

void VFFunc(int arg1, int arg2, ...)
{
	va_list arg_ptr;
	va_start(arg_ptr, arg2);
	double varg3 = va_arg(arg_ptr, double);
	char varg4 = va_arg(arg_ptr, char);
	char *varg5 = va_arg(arg_ptr, char*);
	va_end(arg_ptr);

	printf("%d %d %f %c %s\n", arg1, arg2, varg3, varg4, varg5);
}

int main()
{
	VFFunc(1, 2, 3.0, '4', "Finve");
	testdefault1(3, 9);
	testdefault(237);

	TEST_FUNC a;
	a.x = 10;
	a.y = 11;
	a.z = 12;

	printstruct(&a);
	call_by_value(a);
	printstruct(&a);
	call_by_address(&a);
	printstruct(&a);
	call_by_ref(a);
	printstruct(&a);
}


#ifdef CODE_FUNCTION
// 함수에 대한 처리 이전 코드들
// 함수 : 어떠한 입력 값(들)에 대한 처리를 수행하고, 그 결과를 반환해주는 기능
/*
// 선언 방법
반환자료형(결과 값의 반환 자료형) 함수이름(예약어는 사용 불가) ( 인수, 인자, 매개변수 )
 인수, 인자, 매개변수 선언 방법 : 일반 변수 선언 형식과 동일
 {	// 함수의 내용 시작

	// 실제로 해당 함수가 실행할 내용들이 있는 구간
	// ==> 함수의 본체

 }	// 함수 내용이 종료
*/

// 1. 숫자 2개를 전달하면 곱해서 그 결과를 알려주는 기능! 이 필요하다!
// 2. 인수 : 숫자 2개를 전달해 주어야 겠다
//		int x
//		int b
// 3. 해야할 일(기능) : 전달된 인수 2개를 곱한다. 곱한 결과를 알려준다.
//		x * b
// 4. 함수이름 : Mul
// 5. 결과 값 : 어떤 자료형으로 받을 것인가? : 반환 자료형은 반드시 1개만 가능!
//		int 형으로 받을게요~

// 호출 시점 : Mul(3, 10)
int Mul(int x, int b)	// int x = 3, int b = 10
{
	int a = 5;
	int d = 6;
	int c = 8;
	return a, d, c;
	return 1, 2, 3, 4;
	return x * b;	// 임시 변수가 생성
	//	임시변수 = x * b; 먼저 실행
	// return 임시변수;
	int result = 0;
	result = x * b;
	// return : 함수의 동작을 멈추고, 호출한 대상으로 PC를 반환
	// 반환 값이 없는 경우(void) : return;
	// 반환 값이 있는 경우 : return 함수의 반환 자료형에 맞는 변수/값;
	return result;
}

void print(const char *fmt){}
void print(const char *fmt, int x) {}
void print(const char *fmt, int x, int x1, int x2, int x3, int x4) {}
void print(const char *fmt, int x, char k) {}

int main()
{
	int a1 = 0, b1 = 0, c1 = 0;
	a1, b1, c1 = Mul(3, 10);
	printf("%d %d %d\n", a1, b1, c1);
	printf("%d\n", Mul(3, 10));
	return 0;
	print("%d %d %d\n");
	print("%d %d %d\n", 10);
	print("%d %d %d\n", 10, 'A');
	print("%d %d %d\n", 10, 20, 30, 40, 50);
	//printf("%d %d %d\n", x, b, t, y, u, i, h, j, k);
	// 졸린 학생들을 위한 임시 방편 소스~~~
	struct asdf
	{
		int x;
		int y;
		int z;
	} as;
	as.x = 10;
	as.y = 20;
	as.z = 99;
	struct asdf *p1 = &as;
	void *p = &as;
	int *k = (int*)p;
	printf("%d %d %d\n", k[0], k[1], *(k + 2));

	// 공용체에 대해 공부하려는 학생은 LARGE_INTERGER 자료형을 검색!


	// typedef A B; // A는 앞으로 B로 사용한다.
	typedef
	// A의 시작
		struct ManyFunctionsAndVariables
	{
		int x;		// 4byte
		char y;		// 1byte	: 구조체 메모리 생성시 4byte로 변경하여 생성
					// padding : 데이터 처리 시, CPU나 기타 H/W의
					// 추가 작업을 제거하여 빠른 정보 교환을 가능하도록 하는 기능
	}
	// A 종료 및 B의 시작
	MEM;

	printf("MEM size: %d\n", sizeof(MEM));
	printf("int size: %d\n", sizeof(int));
	printf("char size: %d\n", sizeof(char));

	MEM a;
	MEM b;
	MEM *ptr = &a;
	//a = b;
	//ptr.x = 10;	// C++에서는 포인터 변수인 경우, . 연산자 사용 불가
	ptr->x = 10;



	/*
	// 구조체를 사용할 때는 반드시 이름을 적어주세요~
	struct a
	{
		char m;
	} s1;

	struct a
	{
		char m;
	} s2;

	// 이름이 없는 경우는 에러입니다.
	s1 = s2;
	*/
    std::cout << "Hello World!\n";
}
#endif