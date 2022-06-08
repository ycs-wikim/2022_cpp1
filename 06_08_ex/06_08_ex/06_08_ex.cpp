// 06_08_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 연산자 중복 정의의 제약
// 1. 피 연산자의 개수 변경 불가
//		클래스 내부에 선언한 경우 : 객체 + X
//		객체는 고정, X는 다양한 형태를 지원할 수 있음
//		다양한 형태 전체에 대해 정의를 해야 함!
//		연산자는 기본적으로 피 연산자의 개수가 정의
// 2. 기본 정의 우선순위와 결합 순서 변경 불가!
//		재정의로 +, *를 함!
//		a + b * c + z	==>		b * c
// 3. 실무에서 이런 형식으로 프로그램 작성하면 혼남!
//		연산자가 의도 없이 사용되었을 때
//		버그 확인이 거의 불가능에 가까움


class faker { public:int x; };
class CNumber
{
public:
	int m_value;
	//int (operator+)(int x)
	// 연산자의 중복 정의 가능한 연산자들
	CNumber operator * (int x) {}
	CNumber operator - (int x) {}
	CNumber operator / (int x) {}
	CNumber operator % (int x) {}
	CNumber operator | (int x) {}
	CNumber operator & (int x) {}
	CNumber operator > (int x) {}
	CNumber operator >> (int x) {}
	CNumber operator <= (int x) {}
	CNumber operator << (int x) {}
	/*
	CNumber operator + (int x)
	{
		CNumber cn;
		cn.m_value = cn.m_value + x;
		return cn;
	}
	
	CNumber operator + (const CNumber &obj)
	{
		CNumber cn;
		cn.m_value = cn.m_value + obj.m_value;
		return cn;
	}
	CNumber operator + (const faker &obj)
	{
		CNumber cn;
		cn.m_value = cn.m_value + obj.x;
		return cn;
	}
	*/
};

// 간접멤버 연산자를 이용한 클래스 설계 방법
class parent
{
public:
	int m_x;
	int m_y;
	int m_z;
};

class child
{
public:
	int c_a;
	int c_b;
	int c_c;
	// 간접멤버 연산자 중복 정의
	parent* operator ->()
	{
		return &m_p;
	}
private:
	parent m_p;	// 포함관계. 권한 때문에 외부 접근 불가
};


// 초기화 리스트 클래스
class asdf
{
public:
	int m_x;
	// 일반 생성자 형식
	//asdf(int x)		// int x = 3
	// 초기화 리스트를 이용한 생성자 형식
	// ) 다음에 : 을 입력하고 멤버변수(입력 값)
	
	// 초기화 리스트 : 선언 시 초기화해야 하는 멤버들을
	//		클래스의 생성자 위치에서 초기화 시킬 수 있는 방법
	asdf(int x)
		: m_x(7),	// 초기화 리스트는 먼저 실행
		k(x)
	{
		// 전달 받은 인수로 멤버 변수 초기화 => 마지막 실행
		m_x = x;
	}

	const int k;	// 상수 변수는 반드시 선언 시 초기화
};


// 상수 인수의 위험성
// 함수에 const가 붙은 경우 : 
int kbs(const int *x)
{
	int *p = (int*)x;
	*p = 7;
	return *x + 3;
}


int main()
{
	int i = 9;
	printf("KBS: %d\n", kbs(&i));

	asdf ad(3);
	printf("%d - %d\n", ad.m_x, ad.k);
	return 0;
	child c;

	int x = 0;
	CNumber a, b;
	faker f;
	/*
	a = a + b;
	a = a + f;
	*/
	b.m_value = 3;
	//a = b + 3;
	x = x + 3;

	// C, C++에서 {, }는 스택을 의미
	{
		int y;
	}
	//y = y + 3;	// y를 다른 스택에서 선언하였으므로 인식 X

	a = b;
	//a = b.m_value + 1;	// CNumber = int
	x = b.m_value + 1;	// int = int
	//a = a + b;		// 멤버 중 누구와 연산해야 하는지 결정 X
}

















/*
class CTest
{
public:
	int m_a;
	//const int m_b = 3;
	int &m_c = m_a;
};

int main()
{
	CTest a, b;
	a = b;

    std::cout << "Hello World!\n";
}
*/