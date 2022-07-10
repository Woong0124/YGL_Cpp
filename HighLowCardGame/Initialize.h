#pragma once
#include "Common.h"

// 만든 카드 변수를 이용하는 기능 헤더

void Initialize();
void Shuffle();
int Betting(int money);	// 배팅
bool CompareCard(const StCard& CardA, const StCard& CardB);	// 카드 비교
void ResultCard(bool& result, char c, int& count);	// 성공 실패 확인
void BettingResult(const bool result, int& betting, int& money);	// 배팅 결산
bool ContinueCard(bool result);	// 계속 할지 여부 확인