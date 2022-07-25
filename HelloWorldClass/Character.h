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

	virtual void Move();
	void Attack();
};