#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	Hp = 100;
	X = 10;
	Y = 10;
	Gold = 0;
	name = "Player";
	cout << "Player Constructor" << endl;
}

Player::~Player()
{
	cout << "Player Destructor" << endl;
}

//Accessor
int Player::GetGold()
{
	return Gold;
}
void Player::SetGold(int newGold)
{
	if (newGold < 0)
		return;

	Gold = newGold;
}

void Player::Move()
{
	std::cout << name << " Run" << endl;
}