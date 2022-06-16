#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(const char* name, const char* addr)
{
	this->name = new char[strlen(name) + 1];	// this->변수명 : 구현 클래스 안의 변수를 가리키는 문법
	strcpy_s(this->name, strlen(name) + 1, name);	// strlen(name) + 1 : 마지막 문자는 \n 이 추가 표기됨
													// \n : 문자열의 마지막을 알리는 표기
	this->addr = new char[strlen(addr) + 1];
	strcpy_s(this->addr, strlen(addr) + 1, addr);

	cout << "Person 객체 생성 ( " << name << ", " << addr << " )" << endl;
}

Person::~Person()
{
	cout << "Person 객체 제거 ( " << name << ", " << addr << " )" << endl;
	delete[] name;
	delete[] addr;
	name = nullptr;
	addr = nullptr;
}

void Person::changeAddr(const char* newAddr)
{
	delete[] addr;
	addr = new char[strlen(newAddr) + 1];
	strcpy_s(addr, strlen(newAddr) + 1, newAddr);
}

void Person::printAddr()
{
	cout << "주소는 " << addr << " 입니다." << endl;
}

void Person::changeName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Person::printName()
{
	cout << "이름은 " << name << " 입니다." << endl;
}
