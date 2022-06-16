#include <iostream>
#include "circle.h"
#include "coin.h"

using namespace std;

int main()
{
	Circle circle1;
	Coin coin1;
	circle1.mX = 50;
	coin1.mX = 20;
	circle1.printName();
	coin1.printName();
}