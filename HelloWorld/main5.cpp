#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	{
		int a = 10;
		int b = 0;
		
		//증감 연산자
		b = a++;
		cout << "a = " << a << "b = " << b << endl;
	}

	{
		int a = 10;
		int b = -5;
		bool result = false;
		result = (a > b) ? true : false;
		result = (a == b) ? true : false;
		result = (a > 0 && b > 0) ? true : false;	//논리곱, 둘다 참이면 참
		result = (a > 0 || b > 0) ? true : false;	//논리합, 하나라도 참이면 참
		result = (a > 0 && --b > 0) ? true : false;		//앞이 거짓이면 굳이 뒤 연산까지 하지 않음
		result = !(a > 0) ? true : false;
		cout << "result = " << boolalpha << result << " b = " << b << endl;
														//boolalpha 사용하면 참/거짓으로 값이 나옴
	}
	
	{ 
		int num = 10;
		cout << bitset<32>(num) << endl;	//2진법 출력
		cout << oct << num << endl;			//8진법 출력
		cout << dec << num << endl;			//10진법 출력
		cout << hex << num << endl;			//16진법 출력

		//0 = false, 0이 아닌 수 = true < ex)1 > 
		//비트단위 연산 진행
		int x = 0x35;
		int y = 0xf0;
		cout << "x = " << bitset<8>(x) << endl;
		cout << "y = " << bitset<8>(y) << endl;
		cout << "x & y = " << bitset<8>(x & y) << endl;
		cout << "x | y = " << bitset<8>(x | y) << endl;
		cout << "x ^ y = " << bitset<8>(x ^ y) << endl;
		cout << "~x = " << bitset<8>(~x) << endl;
		
		cout << '\n' << endl;
		
		//비트 단위 시프트
		int x1 = x << 2;
		cout << "x  = " << bitset<8>(x) << endl;
		cout << "x1 = " << bitset<8>(x1) << endl;

		char cX = 0b00010100;
		cout << "cX = " << bitset<8>(cX) << endl;	//시프트 전
		cX = cX >> 2;
		cout << "cX = " << bitset<8>(cX) << endl;	//시프트 후
	}
	
	{
		//형 변환
		int intVar = 7;
		double doubleVar = 1.5;
		float floatVar = 3.7f;

		intVar = doubleVar;
		floatVar = intVar;

		//자료형 변환 우선순위, 사이즈가 크고 실수인 형태가 우선
		//char > int > long > float > double > longdouble
		intVar = doubleVar + intVar * floatVar;		//float > double > int 의 형 변환을 거침

	}
	
	{
		//static cast = 실행중에 형 검사를 하지 않으며, 컴파일 할때 수식에 지정된 그대로 변환함
		//dynamic_cast =  기초 클래스와 파생 클래스 간의 포인터 또는 참조 형 변환이 프로그램 실행 중에 일어나도록 지시힘
		//reinterpret_cast = 포인터를 다른 자료형의 포언터나 정수 자료형으로, 또는 그역으로 변환함
		//const_cast = const 지정을 일시 해제함

		double d = 10.5;
		int a = static_cast<int>(d);
	}
}