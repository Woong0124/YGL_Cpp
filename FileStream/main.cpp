#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string name = "";
	int age = 0;
	float score = 0.f;

	void PrintInfo()
	{
		cout << name << " " << age << " " << score << endl;
	}
};

void SetStudentInfo(const string& source, Student& ss);

int main()
{
	//ofstream : 파일 쓰기
	//ifstream : 파일 읽기
	//fstream  : 파일 읽고 쓰기

	vector<Student> vecStd;
	string line;
	ifstream file("writeFile.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			Student ss;
			line.erase(remove(line.begin(), line.end(), ' '), line.end());
			SetStudentInfo(line, ss);
			vecStd.push_back(ss);
		}
		file.close();
	}
	else
	{
		cout << "파일 읽기를 실패했습니다." << endl;
	}

	sort(vecStd.begin(), vecStd.end(), [](Student a, Student b) { return a.age > b.age; });

	for (Student s : vecStd)
	{
		s.PrintInfo();
	}
}

void SetStudentInfo(const string& source, Student& ss)
{
	int key = 0;
	int temp = source.find("=", key);
	int tempSpace = source.find(",", key);
	ss.name = source.substr(temp + 1, tempSpace - temp - 1);

	key = tempSpace + 1;
	temp = source.find("=", key);
	tempSpace = source.find(",", key);
	ss.age = stoi(source.substr(temp + 1, tempSpace - temp - 1));

	key = tempSpace + 1;
	temp = source.find("=", key);
	tempSpace = source.find(",", key);
	ss.score = stof(source.substr(temp + 1, tempSpace - temp - 1));
}