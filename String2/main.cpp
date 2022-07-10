#include <iostream>
#include <vector>
#include <string>

using namespace std;



struct student
{
	string name = "";
	float score = 0;
	int age = 0;

	void printInfo()
	{
		cout << "name = " << name << " / score = " << score << " / age = " << age << endl;
	}
};



// source를 key로 기준하여 왼쪽 = leftStr, 오른쪽 = rightStr 에 값을 저장
void StringCutHalfwithKey(const string& source, char key, string& leftStr, string& rightStr);

// source를 key로 기준하여 나눈 값을 벡터에 담아 리턴
vector<string> StringCutbyKey(const string& source, char key);



int main()
{
	//string str = "123+4+5+6";
	//int point = str.find("+");
	//cout << point << endl;
	//string leftStr = str.substr(1, point+1);
	//cout << leftStr << endl;
	//string rightStr = str.substr(point , 50);
	//cout << rightStr << endl;
	//int leftNum = stoi(leftStr);
	//cout << leftNum << endl;

	//cout << "Num1 + Num2 입력..." << endl;
	//string str = "";
	//cin >> str;
	//int plus = str.find("+");
	//string leftStr = str.substr(0, plus);
	//string rightStr = str.substr(plus + 1, str.length());
	//int leftNum = stoi(leftStr);
	//int rightNum = stoi(rightStr);
	//cout << leftNum + rightNum;

	//vector<string> vecStr;
	//string str = "AAA BBB CCC DDD EEE F GGG HHH III JJJ KK LL M";
	//
	//int i = 0;
	//while (true)
	//{
	//	int temp = str.find(" ");	// 공백 찾기 (찾지 못하면 -1 반환)
	//	vecStr.push_back(str.substr(0, temp));	// #substr(인덱스번호, 갯수(-1 이라면 인덱스 번호부터 전부 표시))  #공백찾아서 푸시백
	//	str = str.substr(temp + 1);	// 푸시백부분 제외 스트링 재정의
	//	cout << vecStr[i] << endl;	// 출력
	//	++i;
	//	if (temp == string::npos)	// temp가 공백을 찾지 못했을때 탈출
	//	{
	//		break;
	//	}
	//}
	//// +a) int index = find(vecStr.begin(), vecStr.end(), "AAA") - vecStr.begin();	// 백터에서 찾는 값의 인덱스

	//vector<string> vecStr;
	//vector<int> vecInt;
	//string str = "AAA=111 BBB=222 CCC=333 DDD=444";
	//int findKey = 0;
	//
	//while (true)
	//{
	//	int temp = str.find(" ", findKey);
	//	if (temp == string::npos)
	//	{
	//		break;
	//	}
	//
	//	string subStr;
	//	string strNum;
	//	StringCutHalfwithKey(str.substr(findKey, temp - findKey), '=', subStr, strNum);
	//	vecStr.push_back(subStr);
	//	vecInt.push_back(stoi(strNum));
	//	findKey = temp + 1;
	//}
	//
	//for (int i = 0; i < vecStr.size(); ++i)
	//{
	//	cout << vecStr[i] << " " << vecInt[i] << endl;
	//}

	//string str = "1 2 33 44 555 6 777";
	//vector<string> vecStr;
	//vecStr = StringCutbyKey(str, ' ');
	//
	//for (int i = 0; i < vecStr.size(); ++i)
	//{
	//	cout << vecStr[i] << endl;
	//}

	student st1;
	string strData = "name=jonh score=3.6 age=20";

	//int key = 0;
	//int temp = strData.find("=", key);
	//int space = strData.find(" ", temp) - temp;
	//st1.name = strData.substr(temp + 1, space - 1);
	//
	//key = temp + 1;
	//temp = strData.find("=", key);
	//space = strData.find(" ", temp) - temp;
	//st1.score = stof(strData.substr(temp + 1, space - 1));
	//
	//key = temp + 1;
	//temp = strData.find("=", key);
	//space = strData.find(" ", temp) - temp;
	//st1.age = stoi(strData.substr(temp + 1, space - 1));

	vector<string> vecStr;
	vecStr = StringCutbyKey(strData, ' ');
	for (string s : vecStr)
	{
		cout << s << endl;
	}
	cout << endl;
	for (string s : vecStr)
	{
		string leftStr = "";
		string rightStr = "";
		StringCutHalfwithKey(s, '=', leftStr, rightStr);
		if (leftStr == "name")
		{
			st1.name = rightStr;
		}
		else if (leftStr == "score")
		{
			st1.score = stoi(rightStr);
		}
		else if (leftStr == "age")
		{
			st1.age = stoi(rightStr);
		}
	}

	st1.printInfo();
}



void StringCutHalfwithKey(const string& source, char key, string& leftStr, string& rightStr)
{
	int temp = source.find(key);
	leftStr = source.substr(0, temp);
	rightStr = source.substr(temp + 1, source.length());
}
	
vector<string> StringCutbyKey(const string& source, char key)
{
	vector<string> vec;
	int findKey = 0;
	while (true)
	{
		int temp = source.find(key, findKey);	// findKey번째부터 key를 찾아라
		vec.push_back(source.substr(findKey, temp - findKey));	// findKey번째부터 temp - findKey번 까지 찾아라
		if (temp == string::npos)	// temp에 값이 없으면 브레이크
		{
			break;
		}
		findKey = temp + 1; 
	}
	return vec;
}