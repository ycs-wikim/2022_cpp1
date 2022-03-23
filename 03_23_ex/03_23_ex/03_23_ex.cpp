// 03_23_ex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// C < C++	: C++에서는 C의 헤더파일을 모두 사용할 수 있음
//			: C에서는 C++의 헤더파일을 모두 사용할 수는 없음

#include <iostream>		// C++에서는 뒤에 .h 를 생략할 수 있음
						// INPUT/OUTPUT STREAM (흐름 담당)
//#include <stdio.h>	// Standard I/O

/*
	* 메인 함수의 특징
	 - 이름이 고정되어 있고, 하나 밖에 존재할 수 없음
	 - 프로그램의 시작 함수. 실행될 때 반드시 최초로 실행되는 함수
	 - 받는 인자 : 2개가 존재 -> 초기화 인수
		* int 변수(argc) : argument count (인수의 개수)
		* char ** 변수(argv) : argument variable (인수의 값)
	 - 함수가 반환(return)을 만나면 프로그램이 종료
*/

// 선언된 이름 공간의 내용을 모두 사용하겠습니다.
using namespace std;

int main(int argc, char **argv)
{
	// 초기화 인수는 항상 값을 받도록 되어 있음
	printf("%d - %s\n", argc, *argv);

	// std::cout ==> std라는 이름 공간(논리적인 그룹)에서 cout 이라는 함수/객체를 사용한다.
	// cout : console output == printf( )
	// cin  : console input == scanf( )
    //std::cout << "Hello World!" << std::endl;		// endl == end of line
	//std::cin  >> 변수
	cout << "Hello World!" << endl;		// endl == end of line

	return 0;
}
