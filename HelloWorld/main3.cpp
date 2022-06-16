#include <iostream>

using namespace std;

int main()
{
	
	//형변환 예시
	int someInteger = 256;
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;	//257
	someInteger *= 2;	//514
	someShort = short(someInteger);	//514
	someLong = someShort * 10000;	//5140000
	someFloat = someLong + 0.785f;	//5140000.785
	someDouble = double(someFloat) / 100000;	//51.40000785
	cout << someDouble << endl;

	//두 변수 연산 예제
	int firstNum = 0;
	cout << "첫번째 숫자 : ";
	cin >> firstNum;
	int secondNum = 0;
	cout << "두번째 숫자 : ";
	cin >> secondNum;
	cout << "결과는 " << firstNum + secondNum << " 입니다." << endl;

	//const  //변경불가 상수
	const int i = 1;

	//자료형 크기 예제
	int x = 2999999999;
	unsigned int y = 2999999999;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

}