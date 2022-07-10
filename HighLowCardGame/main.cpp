#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "Common.h"
#include "Initialize.h"

using namespace std;

//1. 52개의 카드를 가지고 시작
//2. 게임이 시작되면 카드 하나를 오픈
//3. 플레이어는 다음카드가
// 오픈된 카드보다 높은 카드인지
// 낮은 카드인지에 대하여 배팅을 한다
//4. 선택 맞다면 승리 틀리면 패배
//5. 카드는 1이 가장 낮고 K가 가장 높다
//6. 문양은 스페이트 > 다이아 > 하트 > 클로버
//순으로 높다.

int main()
{
	// 하이로우 카드게임
	Initialize();
	int count = 0;	// 몇번 성공했는지 확인 변수
	int money = 10000;	// 머니 변수
	int betting = 0;	// 배팅 변수
	while (true)
	{
		system("cls");
		Shuffle();

		betting = Betting(money);	// 배팅

		cards[0].printCard();
		char c;
		bool result = true;
		cin >> c;
		while (!(c == 'h' || c == 'l'))
		{
			cout << "h 혹은 l 을 입력해주세요..." << endl;
			cin >> c;
		}
		cards[1].printCard();

		result = CompareCard(cards[0], cards[1]);	// 카드 비교

		ResultCard(result, c, count);	// 성공 실패 확인

		BettingResult(result, betting, money);	// 배팅 결산

		result = ContinueCard(result);	// 계속 할지 여부 확인
		if (result == false)
		{
			break;
		}

		system("pause");
	}
}