#include <iostream>

using namespace std;

int main()
{
	int score = 0;
	cin >> score;

	score /= 10;

	// switch / case 구현
	switch (score)
	{
	case 10:
		__fallthrough;	//의도적 fallthrough 표현
	case 9:
		cout << "A" << endl;
		break;
	case 8:
		cout << "B" << endl;
		break;
	case 7:
		cout << "C" << endl;
		break;
	case 6:
		cout << "D" << endl;
		break;
	case 5:
		cout << "E" << endl;
		break;
	default:
		cout << "F" << endl;
		break;
	}

	// if / else 구현
	if (score >= 90)
	{
		cout << "A" << endl;
	}
	else if (score < 90 && score >= 80)
	{
		cout << "B" << endl;
	}
	else if (score < 80 && score >= 70)
	{
		cout << "C" << endl;
	}
	else if (score < 70 && score >= 60)
	{
		cout << "D" << endl;
	}
	else if (score < 60 && score >= 50)
	{
		cout << "E" << endl;
	}
	else
	{
		cout << "F" << endl;
	}

	//문제 7
	int a, b = 0;
	bool result;

	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;

	result = (a - b > 0) ? true : false;

	switch (result)
	{
	case true:
		cout << boolalpha << result << endl;
		break;
	default:
		cout << boolalpha << result << endl;
		break;
	}

	//문제 8
	int a, b, c = 0;
	bool result;

	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;
	cout << "C is ? ";
	cin >> c;

	result = (a + b > c) ? true : false;

	switch (result)
	{
	case true:
		cout << a + b << endl;
		break;
	default:
		cout << c << endl;
		break;
	}

	//문제 9
	int a = 0;

	cout << "숫자(1 ~ 4) 하나를 입력 ? " << endl;
	cin >> a;

	switch (a)
	{
	case 1:
		cout << "RED" << endl;
		break;
	case 2:
		cout << "BLUE" << endl;
		break;
	case 3:
		cout << "BLACK" << endl;
		break;
	case 4:
		cout << "WHITE" << endl;
		break;
	default:
		cout << "1 ~ 4 의 숫자를 입력해주세요." << endl;
		break;
	}

	//문제 10
	int adress = 0;

	cout << "주민번호 7자리 입력 ? " << endl;
	cin >> adress;

	adress /= 1000000;

	switch (adress)
	{
	case 1:
		cout << "남자" << endl;
		break;
	case 2:
		cout << "여자" << endl;
		break;
	case 3:
		cout << "남자" << endl;
		break;
	case 4:
		cout << "여자" << endl;
		break;
	default:
		cout << "외계인" << endl;
		break;
	}
}