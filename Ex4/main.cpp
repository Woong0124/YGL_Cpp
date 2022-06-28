#include <iostream>
#include "Storage.h"

using namespace std;

int main()
{
	// 두개의 창고에 물건 넣고 빼기
	Storage s1 = { 10,20,30 };
	Storage s2 = { 100,100,100 };

	int targetStorage;	// 창고 선택 변수
	bool targetInStorage = true;	// 해당 창고에서 할 행동 변수

	targetStorage = SelectStorage();	// 창고 선택

	if (targetStorage == 1)	// 선택 창고에 따른 행동 선택
	{
		targetInStorage = s1.SelectInStorage(targetStorage);	// 해당 창고에 취할 행동 선택
		s1.DoItStorage(targetInStorage);	// 행동 실행
	}
	else if (targetStorage == 2)
	{
		targetInStorage = s2.SelectInStorage(targetStorage);	// 해당 창고에 취할 행동 선택
		s2.DoItStorage(targetInStorage);	// 행동 실행
	}

	cout << "potato = " << s1.potato << endl;
	cout << "onion = " << s1.onion << endl;
	cout << "carrot = " << s1.carrot << endl;
	cout << endl;
	
	cout << "potato = " << s2.potato << endl;
	cout << "onion = " << s2.onion << endl;
	cout << "carrot = " << s2.carrot << endl;
}