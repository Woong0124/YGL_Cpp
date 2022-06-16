#include <iostream>

using namespace std;

struct Point	//구조체 연습
{
	int x;
	int y;
}P1, P2;	//Point 구조체 P1, P2 변수 선언

enum Color	//열거형 연습
{
	Red, Blue, Write, Black
};

int main()
{
	//구조체 연습
	P1 = { 11, 22 };	//Point 구조체 P1 값 넣기
	P2 = { 21, 12 };
	P1.x = 20;			//Point 구조체 P1의 x 값 넣기
	P1 = { };			//Point 구조체 P1의 값 초기화

	cout << endl;

	cin >> P1.x;		//P1의 x, y값 입력받기
	cin >> P1.y;
	cout << P1.x << " " << P1.y << endl;

	// if / else 연습
	int a, b, c = 0;

	cout << "점수를 차례로 입력해주세요. = " << endl;
	cin >> a >> b >> c;
	
	int result = (a + b + c) / 3;

	if (result >= 60)
	{
		cout << "합격" << endl;
	}
	else
	{
		cout << "불합격" << endl;
	}

	// if / else 연습 2
	int buy = 0;
	
	cout << "총 구매액을 입력해주세요 : " << endl;
	cin >> buy;

	if (buy >= 10000 && buy < 50000)
	{
		buy *= 0.95;
		cout << "최종 결제액은 " << buy << " 입니다." << endl;
	}
	else if (buy >= 50000 && buy < 100000)
	{
		buy *= 0.90;
		cout << "최종 결제액은 " << buy << " 입니다." << endl;
	}
	else if (buy >= 100000)
	{
		buy *= 0.80;
		cout << "최종 결제액은 " << buy << " 입니다." << endl;
	}
	else
	{
		cout << "최종 결제액은 " << buy << " 입니다." << endl;
	}
}