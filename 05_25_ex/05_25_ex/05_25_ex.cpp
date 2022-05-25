// 05_25_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/*
생성자와 소멸자
1. 생성자
	* 인스턴스가 만들어질때 자동으로 호출
	* 함수이름은 클래스이름과 동일
	* 함수는 반환 값이 존재하지 않는다!
	* 다수개의 생성자를 선언할 수 있다!
	* 반드시 public 권한으로 설정되어야 함!
2. 소멸자
	* 인스턴스가 파괴될 때 자동으로 호출
	* 함수이름은 클래스이름과 동일
	* 클래스이름 앞에 ~를 붙인다.
	* 소멸자는 반환 값이 존재하지 않는다!
	* 단 한개만 선언이 가능!
*/
class cpp
{
public:
	cpp(){ printf("%s called\n", __FUNCTION__); }
	~cpp() { printf("%s called\n", __FUNCTION__); }
};

class cpp1 : cpp
{
	int x;
public:
	// 생성자 : 반환 값이 없다, 클래스이름과 동일
	cpp1() { printf("%s 1 called\n", __FUNCTION__); }
	cpp1(int x) { printf("%s 2 called\n", __FUNCTION__); }
	cpp1(int x, int y) { printf("%s 3 called\n", __FUNCTION__); }
	cpp1(char x) { printf("%s 4 called\n", __FUNCTION__); }
	// 복사 생성자는 원형이 고정되어 있다!
	cpp1(const cpp1 &obj){ printf("%s copy 생성자 called\n", __FUNCTION__); }
	// 소멸자 : 반환 값이 없다, 클래스이름과 동일
	~cpp1(){ printf("%s called\n", __FUNCTION__); }
};

int main()
{
	int x = 8;
	int k(8);		// C++에서만 가능!

	printf("%d %d\n", x, k);
	cpp1 cp;	// 인수 없는 생성자 호출
	// int 1개를 이용한 생성자 호출
	cpp1 cp1(66);
	// int 2개를 이용한 생성자 호출
	cpp1 cp2(33, 44);
	// char 1개를 이용한 생성자 호출
	cpp1 cp3('K');
	// 복사 생성자를 이용한 생성자 호출
	cpp1 cp4(cp1);
}

/*		// 클래스
// 구조체의 메모리 구조
struct asdf			// 5 byte ==> 패딩 설정에 따라 변경
{
	int x;			// 4 byte
	char c;			// 1 byte
};

// 클래스의 메모리 구조
class bbc			// 5 byte ==> 패딩 설정에 따라 변경
{
public:
	int b1;			// 4 byte
private:
	int b2;			// 1 byte
protected:
	int b3;			// 4 byte
public:
	bbc()
	{
		b1 = 3;
		b2 = 6;
		b3 = 99;
	}
	void class1() {}	// 몸체가 없는 멤버 함수
	void class3(int x) {}
	// 몸체가 있는 멤버 함수
	int class2(int x)
	{
		int i = 0;
		printf("I : %d\n", i);
		return i + x;
	}
};

class bbq{};

// 상속 시에도 권한이 동작
class kfc : bbc, bbq
{
public:		// 4 + 4 = 8
	int k1;
	int k2;
	kfc()
	{
		this->b1 = 77;
		//this->b2 = 99;	// 부모클래스의 private 멤버
		this->b3 = 1000;
		k1 = 99;
		k2 = 199;
	}
};



int main()
{
	bbc bc;
	kfc k;
	int *p = (int*)&k;
	printf("kfc size : %d\n", sizeof(class kfc));
	printf("%d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4]);
	printf("%p %p %p %p %p\n", p, p + 1, p+2, p+3, p+4);


	printf("B: %d\n", bc.class2(56));
	printf("struct size: %d\n", sizeof(struct asdf));
	printf("bbc class size: %d\n", sizeof(class bbc));
	printf("kfc class size: %d\n", sizeof(class kfc));
    std::cout << "Hello World!\n";
}
*/