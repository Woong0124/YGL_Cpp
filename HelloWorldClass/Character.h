#pragma once
#include <string>

class Character
{
protected:
	int Hp;
	int X;
	int Y;
	int Gold;
	std::string name;

public:
	Character();
	virtual ~Character();

	void Move();
	void Attack();
};