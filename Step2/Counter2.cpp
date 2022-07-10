#include "Counter2.h"

Counter2::Counter2(int num) : value{ num } {}

Counter2::Counter2(const Counter2& c) : value{ c.value } {}

void Counter2::Reset()
{
	value = 0;
}

void Counter2::Count()
{
	++value;
}

int Counter2::GetValue() const
{
	return value;
}