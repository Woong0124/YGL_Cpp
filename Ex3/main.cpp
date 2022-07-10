#include <iostream>
#include "FuncSum.h"
#include "FuncAverage.h"
#include "FuncDivid.h"
#include "FuncFmulti.h"
#include "FuncMulti.h"
#include "FuncRemain.h"
#include "FuncSum3.h"
#include "FuncMinus.h"

using namespace std;


int main()
{
	
	int sum = 0;
	int a = 0;
	int b = { 0 };
	char c = 0;
	while (true)
	{
		system("cls");
		cin >> a >> c >> b;
		switch (c)
		{
		case '+':
			sum = a + b;
			break;
		case '-':
			sum = a - b;
			break;
		case '*':
			sum = a * b;
			break;
		case '/':
			sum = a / b;
			break;
		case '%':
			sum = a % b;
			break;
		case '^':
			sum = FuncFmulti(a, b);
			break;
		}
		cout << " Sum = " << sum << endl;
		cout << " 종료는 두 숫자 모두 0 입력 " << endl;
		if (a == 0 && b == 0)
		{
			break;
		}
		//system("pause");
	}
}