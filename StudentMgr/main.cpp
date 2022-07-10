#include <iostream>
#include <vector>
#include <map>
#include "Student.h"

using namespace std;

int main()
{
	vector<Student> vecStudent;
	string name = "";
	map<string, Student> mapStudent;
	int classNum = 0;
	int score = 0;
	int mgrType = 0;

	Student aaa = { "학생1", 1, 100 };
	Student bbb = { "학생2", 2, 60 };
	Student ccc = { "학생3", 1, 50 };
	vecStudent.push_back(aaa);
	vecStudent.push_back(bbb);
	vecStudent.push_back(ccc);

	while (true)
	{
		cout << " [Student Manager] " << endl;
		cout << "1. 학생 추가 " << endl;
		cout << "2. 학생 제거 " << endl;
		cout << "3. 모든 학생 정보 보기 " << endl;
		cout << "4. 학생 찾기 " << endl;
		cout << endl;
		cin >> mgrType;
		if (!(mgrType == 1 || mgrType == 2 || mgrType == 3 || mgrType == 4))
		{
			cout << "다시 입력해 주세요... " << endl;
			cin >> mgrType;
		}

		switch (mgrType)
		{
		case 1: {
			cout << "추가할 학생의 정보를 입력합니다..." << endl;
			cout << "이름, 반, 점수를 입력해주세요..." << endl;
			cin >> name;
			cin >> classNum;
			cin >> score;
			cout << endl;
			Student s = { name,classNum,score };
			vecStudent.push_back(s);
		} break;

		case 2: {
			int index = 0;
			cout << "제거할 학생의 Index를 입력해주세요... " << endl;
			cin >> index;
			vecStudent.erase(vecStudent.begin() + index);
			cout << "제거가 완료되었습니다..." << endl;
			cout << endl;
		} break;

		case 3: {
			cout << " - 학생 정보 - " << endl;
			for (Student s : vecStudent)
			{
				s.PrintInfo();
			}
			cout << endl;
		} break;

		case 4: {
			string cName = "";
			cout << "찾을 학생의 이름을 입력해주세요..." << endl;
			cin >> cName;
			for (int i = 0; i < vecStudent.size(); ++i)
			{
				string n = "";
				if (vecStudent[i].GetName() == cName)
				{
					vecStudent[i].PrintInfo();
					cout << "해당 학생의 Index는 " << i << " 입니다..." << endl;
					cout << endl;
				}
			}
		} break;
		}

		char c = NULL;
		cout << "추가 입력 하시겠습니까? " << endl;
		cin >> c;
		if (c == 'n')
		{
			break;
		}
		while (!(c == 'y' || c == 'n'))
		{
			cout << "다시 입력해주세요..." << endl;
			cin >> c;
		}
	}
}