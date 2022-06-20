#include <iostream>

using namespace std;

void Time(int num);	// 초를 입력받아 시간 출력
float StandardWeight(int height, int weight);	// 표준 몸무게
float FattyLevel(int height, int weight);	// 비만도
void FattyLevelPrint(float fattyLevel);

int main()
{
	float result = 0;
	result = FattyLevel(180, 100);
	FattyLevelPrint(result);
}

void Time(int num)
{
	int h, m, s = { 0 };
	h = num / 3600;
	m = (num % 3600) / 60;
	s = (num % 3600) % 60;
	cout << h << "시간 " << m << "분 " << s << "초 " << endl;
}


float StandardWeight(int height, int weight)
{
	float result = 0;
	result = (height - 100) * 0.9;
	return result;
}

float FattyLevel(int height, int weight)
{
	float result = 0;
	float standardWeight = StandardWeight(height, weight);
	result = (weight - standardWeight) * 100 / standardWeight;
	return result;
}

void FattyLevelPrint(float fattyLevel)
{
	if (fattyLevel <= 10)
	{
		cout << fattyLevel << "  정상입니다... " << endl;
	}
	else if (fattyLevel > 10 && fattyLevel <= 20)
	{
		cout << fattyLevel << "  과체중입니다... " << endl;
	}
	else if (fattyLevel > 20)
	{
		cout << fattyLevel << "  비만입니다... " << endl;
	}
}