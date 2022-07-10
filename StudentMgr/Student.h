#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
	string mName;
	int mClassNum;
	int mScore;

public:
	Student(string name, int classNum, int score);
	
	void PrintInfo();
	string GetName();
};