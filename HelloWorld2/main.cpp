#include <iostream>
#include <conio.h>

using namespace std;

int map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	int playerX = 1;
	int playerY = 1;
	char key = 0;

	for (; ; )
	{
		// input
		key = _getch();

		// process
		if (key == 'w')
		{
			--playerY;
		}
		else if (key == 's')
		{
			++playerY;
		}
		else if (key == 'a')
		{
			--playerX;
		}
		else if (key == 'd')
		{
			++playerX;
		}

		// render
		system("cls");
		for (int y = 0; y < 10; ++y)
		{
			for (int x = 0; x < 10; ++x)
			{
				if (x == playerX && y == playerY)
				{
					cout << 'P';
				}
				else if (map[y][x] == 0)
				{
					cout << ' ';
				}
				else if (map[y][x] == 1)
				{
					cout << '*';
				}
				cout << ' ';
			}
			cout << endl;
		}
	}
}