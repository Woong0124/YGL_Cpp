#include "Goblin.h"
#include <iostream>

Goblin::Goblin()
{
	name = "Goblin";
	std::cout << "Goblin Contructor" << std::endl;
}

Goblin::~Goblin()
{
	std::cout << "Goblin Destructor" << std::endl;
}

void Goblin::Move()
{
	std::cout << name << " Crawl" << std::endl;
}