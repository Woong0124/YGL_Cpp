#include <iostream>

int main()
{
	
	//Hello, World 출력
	std::cout << "Hello, World" << std::endl;

	//cin 입력 대기
	int value;
	std::cin >> value;

	//value 에 입력한 값이 출력
	std::cout << "There are " << value << " ways I love you." << std::endl;

	//똑같이 출력
	std::cout << "There are " << 219 << "\n" << " ways I love you." << std::endl;
	std::cout << "There are " << 219 << "\n ways I love you." << std::endl;

	//예제
	std::cout << "A \nBC \nDEF \nGH" << std::endl;

	//모두 똑같이 0 의 값을 가짐
	int a = 0;
	int a1(0);
	int a2{ 0 };
	int a3 = { 0 };

	//
	a = 0b1010101;	// 2진법
	a1 = 0x11;		// 16진법
	std::cout << a << std::endl;
	std::cout << a1 << std::endl;

	//
	char c = 'A';
	char c1 = '\101';	//10진수 유니코드 A
	std::cout << c << std::endl;
	std::cout << c1 << std::endl;

}