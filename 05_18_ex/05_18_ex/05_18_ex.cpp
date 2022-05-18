// 05_18_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 클래스와 구조체 in C++ : 거의 동일
struct asdf		// 예약어 구조체이름
{
public:
	int kkk;
	void asdffff() { printf("afslkdjl\n"); }
};

/*
. (직접멤버 접근 연산자)	: 객체에서 사용
:: (범위 지정 연산자)		: 클래스에서 사용
*/

// 클래스 선언부 시작
class CName
{
	int x;
public:
	static int value;	// 정적 멤버 선언
	const int cvalue = 15;	// const 멤버 선언과 초기화
	int y;
	// 클래스 멤버 함수의 원형
	void cnMethod();		// 출석부 이름
};
// 클래스 선언부 끝

// 정적 멤버의 초기화
int CName::value = 10;

// 외부에서 클래스 멤버 함수를 구현
// 함수반환값 클래스이름::구현할멤버함수명(인수)
void cnMethod(){}			// 동명 이인
void CName::cnMethod()		// 실제 학생
{
	printf("%s called %p\n", __FUNCTION__, this);
}

int main()
{
	CName cn;
	CName cn1;
	// this는 객체 자신을 가리키는 포인터
	// this는 클래스 내부에서만 사용이 가능!
	//this->	: 허용되지 않음
	cn.cnMethod();
	cn1.cnMethod();

	CName *p = &cn;
	const CName* p1 = &cn;
	int k = 9;
	const int x = k;



	//cn.value = 10;	// 정적 멤버 값 할당
	CName::value = 10;
	//	CName:: ==> 클래스의 범위
	//	cn.		==> 객체에서 접근 가능한 멤버
    std::cout << "Hello World!\n";
}
