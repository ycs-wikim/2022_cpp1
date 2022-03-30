// 03_30_example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>		// #include는 include한 파일 전체를 가져와서 include한 위치에 넣어준다.
#include <stdint.h>		// 크기 표준 자료형 선언 헤더 파일

using namespace std;

// 매크로 상수/함수 정의 방법 : #define A B
//	의미 : A는 앞으로 B로 사용하겠다고 컴파일러에게 알려주는 것.
//	특징 : A는 상수가 됩니다.
#define PI 3.141592		// 매크로 상수
#define ADD(X,Y) X + Y	// 매크로 함수
//      A        B
#define ADDEX(x,y) x + y; printf("addex called\n");
// 매크로 함수에서 문장을 2개 이상 사용할 경우 반드시 {, }로 묶어서 사용
// 매크로 함수는 프로그램 작성 시, 최대한 사용하지 않도록 합니다.
//#define ADDEX(x,y) x + y; printf("addex called\n");
#define ADDEX(x,y) { x + y; printf("addex called\n"); }

// RAIN을 단순 선언
#define RAIN

bool predeftest()
{
	if (3 > 5)
	{
		cout << __FILE__ << "\t" << __FUNCTION__ << "\t" << __LINE__ << endl;
		return false;
	}

	return true;
}

int main()
{
	// ex 2-6.
	char str[8];			// 8byte의 메모리 공간 선언
							// 문자열 : 항상 마지막에는 NULL이 들어가야 한다
	// memset = memory setting
	// memset( address, value, length) : str 변수의 내용을 모두 A로 초기화
	memset(str, 'A', 8);		// str[ AAAAAAAA ]

	str[0] = 'C';		// str[ CAAAAAAA ]
	str[1] = '+';		// str[ C+AAAAAA ]
	str[2] = '+';		// str[ C++AAAAA ]
	//str[7] = NULL;
	str[4] = NULL;
	printf("STR: %s\n", str);	// 문자열 출력의 특징 : NULL을 만날때까지 무조건 추력
	cout << str << endl;
	return 0;


	// ex 2-5.
	// 단일 문자는 컴파일러에서 숫자로 자동 변환
	char c1 = 'A';		// 문자로 보이지만 컴파일러는 65로 처리
	char c2 = 65;
	char c3 = 'A' + 1;	// 65 + 1
	char c4 = 66;

	cout << c1 << c2 << c3 << c4 << endl;



#ifdef _M_X64
	__int64 x;
	cout << 3.141592 << endl;
	cout << PI << endl;
#else
	__int32 x;
	printf("This is sparta~\n");

	// 미리 정의되어 있는 매크로
	cout << __FILE__ << "\t" << __FUNCTION__ << "\t" << __LINE__ << endl;
	predeftest();
	double d = PI;
	cout << d << endl;
	printf("printf - %f / %f / %f\n", 3.141592, PI, d);
#endif
	//3 = 7;
	//PI = 15;
    cout << "Hello World! " << ADD(3, 6) << " " << 9 << endl;
	//cout << "ADD Ex function :" << ADDEX(4, 9) << endl;	// 오류 문장
	// cout과 endl의 특징 때문에 발생
	// endl은 반드시 사용되는 문장에 cout이 존재해야만 정상 동작
	//endl; // 단독 사용할 수 없음
	cout << endl;
	cout << "ADD Ex function :" << 4 + 9; printf("addex called\n"); cout << endl;
	//std::cout << "Hello World! " << 3 + 6 << " " << 9 << std::endl;
}
