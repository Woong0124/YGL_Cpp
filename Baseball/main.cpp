#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//int password[3] = { 1,2,3 };
	//int number[3] = { 0 };
	//
	//while (1)
	//{
	//	int sCount = 0;
	//	int bCount = 0;
	//	cin >> number[0] >> number[1] >> number[2];
	//	for (int i : number)
	//	{
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//
	//	for (int i = 0; i < size(number); ++i)
	//	{
	//		if (number[i] == password[i])	// ÀÚ¸´¼ö³¢¸® °°À¸¸é S
	//		{
	//			++sCount;
	//		}
	//		for (int j = 0; j < 3; ++j)
	//		{
	//			if (i == j)
	//				continue;
	//			if (number[i] == password[j])
	//			{
	//				++bCount;
	//			}
	//		}
	//	}
	//	cout << "S : " << sCount << ", B : " << bCount << endl;
	//
	//	if (sCount == 3)
	//	{
	//		break;
	//	}
	//}

	vector<int> random = { 0 };
	sort(random.begin(), random.end());

	for (int i = 0; i < random.size(); ++i)
	{
		for (int j = i + 1; j < random.size(); ++j)
		{
			if (random[i] >= random[j])
			{
				swap(random[i], random[j]);
			}
		}
	}

	for (int i = 0; i < random.size(); ++i)
	{
		cout << random[i] << " ";
	}
}