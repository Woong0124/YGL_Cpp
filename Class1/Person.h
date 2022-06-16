#pragma once

class Person
{
private:
	char* name;
	char* addr;

public:
	Person(const char* name, const char* addr);
	~Person();

	void changeAddr(const char* newAddr);
	void printAddr();
	void changeName(const char* newName);
	void printName();
};

