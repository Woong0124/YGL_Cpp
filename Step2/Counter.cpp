#include "Counter.h"

Counter::Counter() : value{ 0 } {}

void Counter::Reset()
{
	value = 0;
}

void Counter::Count()
{
	++value;
}

int Counter::GetValue() const
{
	return value;
}