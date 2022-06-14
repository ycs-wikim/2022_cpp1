// 06_14_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

#include <stdint.h>
#include <stack>		// stack 컨테이너

class asdf
{
public:
	int x;
	int y;
};

void testSTL()
{
	stack<asdf> st;
	asdf k;
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		k.x = i + 3;
		k.y = i * 2;

		st.push(k);
	}

	for (i = 0; i < st.size(); i++)
	{
		k = st.top();
		printf("x: %d - y : %d\n", k.x, k.y);
		st.pop();
	}
}


class CTest
{
public:
	int m_value;

	void show()
	{
		printf("THIS: %p\n", this);
	}
};


int main()
{
	CTest *pT = NULL;
	pT->show();

	CTest pp;
	pp.show();
	printf("pp: %p\n", &pp);
	return 0;

	testSTL();
	return 0;

	__int64 i = 0;
	//__int32 i = 0;

	int *ptr = NULL;

	for (int k = 0; ; k++)
		ptr = (int*)malloc(65535);


    std::cout << "Hello World!\n";
}
