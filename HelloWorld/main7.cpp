#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	//巩力 1
	cout << "* * * * * * * * * *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "*                 *" << endl;
	cout << "* * * * * * * * * *" << endl;
	
	//巩力 2
	int a, b, c = 0;

	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;

	c = a + b;
	
	cout << "A + B = " << hex << c << endl;

	//巩力 3
	int a, b = 0;
	bool result;

	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;

	if (a - b > 0)
	{
		result = true;
		cout << boolalpha << result << endl;
	}
	else
	{
		result = false;
		cout << boolalpha << result << endl;
	}

	//巩力 4
	int a, b, c = 0;
	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;
	cout << "C is ? ";
	cin >> c;

	if (a + b > c)
	{
		cout << a + b << endl;
	}
	else
	{
		cout << c << endl;
	}

	//巩力 5
	int a = 0b10101010;
	int b = 0111;
	int c = 0xff;

	int result = a + b - c;
	//cout << dec << a << '\n' << b << '\n' << c << endl;
	cout << result << endl;

	//巩力 6
	int a, b, c = 0;
	bool result;

	cout << "A is ? ";
	cin >> a;
	cout << "B is ? ";
	cin >> b;
	cout << "C is ? ";
	cin >> c;

	//result = (a > b && a < c) ? true : false;
	//cout << boolalpha << result << endl;

	if (a > b && a < c)
	{
		result = true;
		cout << boolalpha << result << endl;
	}
	else
	{
		result = false;
		cout << boolalpha << result << endl;
	}
}