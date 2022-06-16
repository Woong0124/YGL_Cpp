#pragma once
#include "Counter.h"

class User
{
public :
	void KillMonster()
	{
		m_Counter.counting();
	}

	Counter m_Counter;
};