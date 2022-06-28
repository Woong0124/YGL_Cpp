#pragma once
#include <iostream>

using namespace std;

// 창고 선택
int SelectStorage();

struct Storage
{
	int potato;
	int onion;
	int carrot;

	// 감자, 양파, 당근 증가
	void AddVege(int a, int b, int c)
	{
		potato += a;
		onion += b;
		carrot += c;
	}

	// 감자, 양파, 당근 감소
	void MinusVege(int a, int b, int c)
	{
		potato -= a;
		onion -= b;
		carrot -= c;
		if (potato <= 0)
		{
			potato = 0;
		}
		if (onion <= 0)
		{
			onion = 0;
		}
		if (carrot <= 0)
		{
			carrot = 0;
		}
	}

	// 스토리지의 값을 받아오고 넘겨준 스토리지는 초기화
	void MoveStorage(Storage& target)
	{
		potato += target.potato;
		onion += target.onion;
		carrot += target.carrot;
		target = { 0 };
	}

	// 창고에서 취할 행동 선택
	bool SelectInStorage(int target)
	{
		switch (target)
		{
		case 1:
			cout << "1번 창고입니다. 행동을 선택해주세요..." << endl;
			break;
		case 2:
			cout << "2번 창고입니다. 행동을 선택해주세요..." << endl;
			break;
		}

		while (true)
		{
			int order = 0;
			cout << "0. 창고 선택으로 돌아갑니다..." << endl;
			cout << "1. 창고에 채소를 넣습니다..." << endl;
			cout << "2. 창고에 채소를 꺼냅니다..." << endl;
			cin >> order;

			switch (order)
			{
			case 0:
				target = SelectStorage();
				break;
			case 1:
				return true;
			case 2:
				return false;
			default:
				cout << "다시 선택해주세요..." << endl;
				break;
			}
		}
	}

	// 행동 실행
	void DoItStorage(bool targetIn)
	{
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;
		if (targetIn == true)
		{
			cout << "감자, 양파, 당근 순서로 넣을 수량을 입력해주세요..." << endl;
			cin >> num1 >> num2 >> num3;
			AddVege(num1, num2, num3);
		}
		else if (targetIn == false)
		{
			cout << "감자, 양파, 당근 순서로 뺄 수량을 입력해주세요..." << endl;
			cin >> num1 >> num2 >> num3;
			MinusVege(num1, num2, num3);
		}
	}
};