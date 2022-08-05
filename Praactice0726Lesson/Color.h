#pragma once

class Color
{
public:
	Color() : R(0), G(0), B(0), A(0) {}
	Color(int NewR, int NewG, int NewB, int NewA)
	{
		R = NewR;
		G = NewG;
		B = NewB;
		A = NewA;
	}
	virtual ~Color() {}

	int R;
	int G;
	int B;
	int A;
};