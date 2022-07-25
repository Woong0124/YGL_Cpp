#include <iostream>
#include "Character.h"

Character::Character()
{
	Hp = 100;
	X = 10;
	Y = 10;
	Gold = 0;
	name = "Character";
	std::cout << "Character Contructor" << std::endl;
}

Character::~Character()
{
	std::cout << "Character Destructor" << std::endl;
}

void Character::Move()
{
	std::cout << name << " Move" << std::endl;
}

void Character::Attack()
{
	std::cout << name << " Attack" << std::endl;
}