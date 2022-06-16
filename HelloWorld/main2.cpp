#include <iostream>

using namespace std;

namespace myNS1 { int n = 10; }
namespace myNS2 { int n = 20; }
int n = 30; //전역변수

int main()
{

	int n = 40; //지역변수

	cout << myNS1::n << endl;
	cout << myNS2::n << endl;
	cout << ::n << endl;
	cout << n << endl;

	cout << endl;

	//형변환 방법 //강제 형변환은 데이터가 소실될 수 있다.
	float myFloat = 3.14f;
	int i1 = (int)myFloat;
	int i2 = int(myFloat);
	int i3 = static_cast<int>(myFloat);

	//실수형의 표현 방법
	double d1 = 1200.;
	double d2 = 1200.0;
	double d3 = 12e2;	//e 는 10, 2 는 제곱
	double d4 = 12e+2;	//위 문장과 동일

	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d4 << endl;

}