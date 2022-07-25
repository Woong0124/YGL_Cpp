#include <iostream>

using namespace std;


class Apple
{
public:
	int Color;
	int Shape;
	bool Fruit;
	
	void Delicous()
	{

	}
};


int main()
{
	Apple* MyApple = new Apple();

	MyApple = nullptr;
	delete MyApple;
}