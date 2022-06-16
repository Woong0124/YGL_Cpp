#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// if / else 문
	int a, b = 0;
	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;
	if (a > b)
	{
		cout << "A가 크다. " << endl;
	}
	else
	{
		cout << "B가 크다. " << endl;
	}

	if (a < b)	//a 와 b 값을 바꾸는 구문
	{
		int temp = a;
		a = b;
		b = temp;
		cout <<  "a = " << a << endl << "b = " << b << endl;
	}
}