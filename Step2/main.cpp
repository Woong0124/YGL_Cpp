#include <iostream>
#include "Counter.h"
#include "Counter2.h"
#include "VecF.h"

using namespace std;

int main()
{
	// 디폴트 생성자 - 매개변수 없음
	Counter cnt1;
	Counter* pCnt = new Counter[10];
	delete[] pCnt;

	// 디폴트 생성자 - 매개변수 있음
	Counter2 cnt2{ 999 };
	Counter2 cnt3[3] = { Counter2(9), Counter2(9), Counter2(9) };

	// 복사 생성자 - 같은 객체를 복사해서 생성
	Counter2 cnt4{ cnt2 };
	Counter2 cnt5 = cnt2;

	// 복사 생성자 - 얕은 복사
	float a[3] = { 1,2,3 };
	VecF v1(3, a);
	VecF v2(v1);

	// 복사 생성자 - 메모리 낭비
	float p1[3] = { 1,2,3 };
	float p2[3] = { 2,4,6 };
	VecF v3(3, p1);
	VecF v4(3, p2);
	VecF v5(v3.add(v4));

	// L-value : 다시 사용가능한 값
	// R-value : 한번만 사용가능한 값
	// & : L-value 참조 기호
	// && : R-value 참조 기호
	int a1 = 10;
	int& aRef = a1;
	const int& bb = 20;
	int&& c = 30;
	
	VecF v6(3);
	VecF v7(3);
	VecF&& vRef1 = v6.add(v7);
}