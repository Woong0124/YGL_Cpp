#include "Student.h"

Student::Student(string name, int classNum, int score) : mName(name), mClassNum(classNum), mScore(score) {}

void Student::PrintInfo()
{
	cout << "이름 : " << mName << ", 반 : " << mClassNum << ", 점수 : " << mScore << endl;
}

string Student::GetName()
{
	return mName;
}