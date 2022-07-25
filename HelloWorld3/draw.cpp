#include "draw.h"
#include <iostream>
#include "player.h"
#include "map.h"

using namespace std;

void Draw()
{
	system("cls");

	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			if (x == myPlayer->x && y == myPlayer->y)
			{
				cout << 'P' << ' ';
			}
			else
			{
				cout << map[y][x] << ' ';
			}
		}
		cout << endl;
	}
}