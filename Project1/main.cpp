#include <iostream>
#include <windows.h>

using namespace std;

void PrintToEven()
{
	int number[100] = { 0 };
	for (int i = 0; i < 100; ++i)
	{
		number[i] = i * 2;
		if (number[i] > 100)
		{
			break;
		}
		cout << number[i] << endl;
	}
}

void PrintToOdd()
{
	int number[100] = { 0 };
	for (int i = 0; i< 100; ++i)
	{
		number[i] = (i * 2) + 1;
		if (number[i] > 100)
		{
			break;
		}
		cout << number[i] << endl;
	}
}

void PrintTo3Dra()
{
	int number[100] = { 0 };
	for (int i = 0; i < 100; ++i)
	{
		number[i] = (i * 3);
		if (number[i] > 100)
		{
			break;
		}
		cout << number[i] << endl;
	}
}

void PrintToMulti()
{
	int number[100] = { 0 };
	for (int i = 0; i < 100; ++i)
	{
		number[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			number[i] *= 3;
		}
		cout << number[i] << endl;
		if (number[i] > 100)
		{
			break;
		}
	}
}

void PrintTo99Dan(int n)
{
	for (int i = 1; i < 10; ++i)
	{
		cout << n << " * " << i << " = " << n * i << endl;
	}
}

int PrintFactorial(int n)
{
	int fac = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		fac *= i + 2;
	}
	return fac;
}

int main()
{
	// 0 ~ 100 사이 x값 증감
	int x = 0;
	bool isTrue = true;

	while (1)
	{
		cout << x << endl;

		if (isTrue)
		{
			++x;
			if (x >= 100)
			{
				isTrue = false;
			}
		}
		else if (!isTrue)
		{
			--x;
			if (x <= 0)
			{
				isTrue = true;
			}
		}

		Sleep(10);
		system("cls");
	}



	//int number[1000] = { 0 };

	//// 0 ~ 99
	//for (int i = 0; i < 100; ++i)
	//{
	//	number[i] = i;
	//	cout << number[i] << endl;
	//}

	//// 짝수
	//for (int i = 0; i < 51; ++i)
	//{
	//	number[i] = (i * 2);
	//	cout << number[i] << endl;
	//}

	//// 홀수
	//for (int i = 0; i < 50; ++i)
	//{
	//	number[i] = (i * 2) + 1;
	//	cout << number[i] << endl;
	//}

	//// 3의 배수
	//for (int i = 0; i < 50; ++i)
	//{
	//	number[i] = i * 3;
	//	cout << number[i] << endl;
	//}

	//// 3의 거듭제곱
	//for (int i = 0, result = 1; i < 10; ++i)
	//{
	//	number[i] = result * 3;
	//	result *= 3;
	//	cout << number[i] << endl;
	//}
	//// 위와 동일
	//for (int i = 0; i < 10; ++i)
	//{
	//	number[i] = 1;
	//	for (int j = 0; j < i; ++j)
	//	{
	//		number[i] *= 3;
	//	}
	//	cout << number[i] << endl;
	//}

	//// 구구단 2단
	//for (int i = 1; i < 10; ++i)
	//{
	//	number[i] = i * 2;
	//	cout << "2 * " << i << " = " << number[i] << endl;
	//}

	//// 구구단 2 ~ 9단
	//for (int i = 2; i < 10; ++i)
	//{
	//	for (int j = 1; j < 10; ++j)
	//	{
	//		cout << i << " * " << j << " = " << i * j << endl;
	//	}
	//	cout << endl;
	//}

	//// 입력받은 수 구구단
	//int c = 0;
	//cin >> c;
	//for (int i = 1; i < 10; ++i)
	//{
	//	cout << c << " * " << i << " = " << c * i << endl;
	//}

	////팩토리얼
	//int iValue = 1;
	//int iCount = 0;
	//cin >> iCount;

	//for (int j = 0; j < iCount - 1; ++j)
	//{
	//	iValue *= (j + 2);
	//}
	//cout << iValue << endl;
}