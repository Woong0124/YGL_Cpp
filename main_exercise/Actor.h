#pragma once

enum class MoveType
{
	Right,
	Up,
	Left,
	Down
};

class Actor
{
private:
	MoveType mType;
	int x;
	int z;
	int startPoint;
	int endPoint;

public:
	Actor();
	void Tick();
	void PrintLocation();
};

