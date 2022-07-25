#include <iostream>
#include <conio.h>
#include "player.h"
#include "input.h"
#include "process.h"
#include "draw.h"
#include "map.h"

using namespace std;


void Swap(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}


int main()
{
	//// 포인터
	//int gold = 1;
	//int* PGold = &gold;
	// 
	//cout << &gold << endl;	// 자기 자신의 주소값 출력
	// 
	//cout << PGold << endl;	// 담고있는 주소값 출력
	//cout << *PGold << endl;	// 담고있는 주소값의 값을 출력
	//cout << &PGold << endl;	// 자기 자신의 주소값 출력

	//// 포인터
	//int a = 10;
	//int b = 20;
	// 
	//cout << a << " , " << b << endl;
	//Swap(&a, &b);
	//cout << a << " , " << b << endl;

	//// 동적할당 ( Heap영역 메모리에 생성 )
	//int* PGold = new int(10);	// 선언
	//cout << *PGold << endl;
	//delete PGold; // 제거
	//
	//// 배열 동적할당
	//int* PArrGold = new int[10];	// 선언
	//delete[] PArrGold;	// 제거

	// 
	myPlayer = new Player();
	myPlayer->x = 1;
	myPlayer->y = 1;

	while (true)
	{
		int keycode = Input();
		Process(keycode);
		Draw();
		if (keycode == 27)
		{
			break;
		}
	}

	myPlayer = nullptr;
	delete myPlayer;
}