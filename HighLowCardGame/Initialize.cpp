#include <iostream>
#include "Initialize.h"

void Initialize()
{
	// 카드 생성
	for (int i = 0; i < 52; ++i)
	{
		cards[i].number = (i % 13) + 1;
		if (i / 13 == 0)
		{
			cards[i].mark = Clover;
		}
		else if (i / 13 == 1)
		{
			cards[i].mark = Heart;
		}
		else if (i / 13 == 2)
		{
			cards[i].mark = Dia;
		}
		else if (i / 13 == 3)
		{
			cards[i].mark = Spade;
		}
	}
}

void Shuffle()
{
	// 카드 섞기
	srand((unsigned int)time(NULL));	// srand(time) - rand 함수에 사용될 수를 매번 바뀌는 시간으로 초기화
	for (int i = 0; i < 52; ++i)
	{
		int FirstNumber = rand() % 52;	// rand - 랜덤한 수를 반환해줌 (반복해도 결과는 매번 똑같음)
		int SecoundNumber = rand() % 52;

		StCard temp = cards[FirstNumber];
		cards[FirstNumber] = cards[SecoundNumber];
		cards[SecoundNumber] = temp;
	}

}

int Betting(int money)
{
	int betting = 0;
	cout << "얼마를 배팅하시겠습니까? " << endl;
	cout << "현재 금액 : " << money << endl;
	cin >> betting;
	while (betting > money)
	{
		cout << "배팅금액이 현재 머니보다 많습니다. 다시 배팅해주세요... " << endl;
		cout << "현재 금액 : " << money << endl;
		cin >> betting;
	}
	return betting;
}

bool CompareCard(const StCard& CardA, const StCard& CardB)
{
	if (CardA.number > CardB.number)
	{
		cout << "첫번째 카드가 크다 " << endl;
		cout << endl;
		return true;
	}
	else if (CardA.number < CardB.number)
	{
		cout << "두번째 카드가 크다 " << endl;
		cout << endl;
		return false;
	}
	else if (CardA.number == CardB.number)
	{
		if (CardA.mark > CardB.mark)
		{
			cout << "첫번째 카드가 크다 " << endl;
			cout << endl;
			return true;
		}
		else if (CardA.mark < CardB.mark)
		{
			cout << "두번째 카드가 크다 " << endl;
			cout << endl;
			return false;
		}
	}
}

void ResultCard(bool& result, char c, int& count)
{
	if (result == true)
	{
		if (c == 'h')
		{
			cout << "실패" << endl;
			cout << "총 " << count << " 번 성공 " << endl;
			cout << endl;
			result = false;
		}
		if (c == 'l')
		{
			++count;
			cout << count << " 번 성공" << endl;
			cout << endl;
			result = true;
		}
	}
	else if (result == false)
	{
		if (c == 'h')
		{
			++count;
			cout << count << " 번 성공" << endl;
			cout << endl;
			result = true;
		}
		if (c == 'l')
		{
			cout << "실패" << endl;
			cout << "총 " << count << " 번 성공 " << endl;
			cout << endl;
			result = false;
		}
	}
}

void BettingResult(const bool result, int& betting, int& money)
{
	if (result == true)	// 배팅 결산
	{
		money += betting;
		cout << betting << " 원의 배팅 금액을 획득하셨습니다..." << endl;
		cout << "현재 금액 : " << money << endl;
		cout << endl;
	}
	if (result == false)
	{
		money -= betting;
		cout << betting << " 원의 금액을 잃어버렸습니다..." << endl;
		cout << "현재 금액 : " << money << endl;
		cout << endl;
	}
}

bool ContinueCard(bool result)
{
	char c = 0;
	if (result == true)
	{
		cout << "계속 하시겠습니까 ?" << endl;
		while (!(c == 'y' || c == 'n'))
		{
			cout << "y 혹은 n 을 입력해주세요..." << endl;
			cin >> c;
		}
		if (c == 'n')
		{
			return false;
		}
	}
	else if (result == false)
	{
		cout << "다시 하시겠습니까 ?" << endl;
		while (!(c == 'y' || c == 'n'))
		{
			cout << "y 혹은 n 을 입력해주세요..." << endl;
			cin >> c;
		}
		if (c == 'n')
		{
			return false;
		}
	}
}