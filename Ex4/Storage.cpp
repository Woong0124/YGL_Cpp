#include "Storage.h"

int SelectStorage()
{
	while (true)
	{
		int targetStorage = 0;
		cout << "창고를 선택해주세요... " << endl;
		cout << "1. 1번 창고 " << endl;
		cout << "2. 2번 창고 " << endl;
		cin >> targetStorage;

		if (targetStorage == 1 || targetStorage == 2)
		{
			return targetStorage;
		}
		else
		{
			cout << "다시 입력해 주세요... " << endl;
		}
	}
}