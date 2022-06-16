#pragma once
#include "circle.h"

class Coin : public Circle
{
public :

	Coin();
	~Coin();

	// 오버라이드
	virtual void printName() override
	{
		__super::printName();	// 부모 함수 구문 실행
		cout << "price = " << price << " color = " << color << endl;
	}

	int price;
	int color;
};