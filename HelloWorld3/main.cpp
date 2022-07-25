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
	//// ������
	//int gold = 1;
	//int* PGold = &gold;
	// 
	//cout << &gold << endl;	// �ڱ� �ڽ��� �ּҰ� ���
	// 
	//cout << PGold << endl;	// ����ִ� �ּҰ� ���
	//cout << *PGold << endl;	// ����ִ� �ּҰ��� ���� ���
	//cout << &PGold << endl;	// �ڱ� �ڽ��� �ּҰ� ���

	//// ������
	//int a = 10;
	//int b = 20;
	// 
	//cout << a << " , " << b << endl;
	//Swap(&a, &b);
	//cout << a << " , " << b << endl;

	//// �����Ҵ� ( Heap���� �޸𸮿� ���� )
	//int* PGold = new int(10);	// ����
	//cout << *PGold << endl;
	//delete PGold; // ����
	//
	//// �迭 �����Ҵ�
	//int* PArrGold = new int[10];	// ����
	//delete[] PArrGold;	// ����

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