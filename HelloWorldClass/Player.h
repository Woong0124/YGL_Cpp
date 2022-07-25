#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player();
	~Player();

	//Accessor
	int GetGold();
	void SetGold(int newGold);

	void Move() override;
};