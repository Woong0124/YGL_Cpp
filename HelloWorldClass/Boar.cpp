#include "Boar.h"
#include <iostream>

Boar::Boar()
{
	name = "Boar";
	std::cout << "Boar Constructor" << std::endl;
}

Boar::~Boar()
{
	std::cout << "Boar Destructor" << std::endl;
}