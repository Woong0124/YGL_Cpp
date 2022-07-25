#include "Slime.h"
#include <iostream>

Slime::Slime()
{
	name = "Slime";
	std::cout << "Slime Constructor" << std::endl;
}

Slime::~Slime()
{
	std::cout << "Slime Destructor" << std::endl;
}