#include "process.h"
#include "player.h"
#include "map.h"

void Process(int keycode)
{
	if (keycode == 'w' || keycode == 'W')
	{
		if (Predict(myPlayer->x, myPlayer->y - 1))
		{
			--myPlayer->y;
		}
	}
	else if (keycode == 's' || keycode == 'S')
	{
		if (Predict(myPlayer->x, myPlayer->y + 1))
		{
			++myPlayer->y;
		}
	}
	else if (keycode == 'a' || keycode == 'A')
	{
		if (Predict(myPlayer->x - 1, myPlayer->y))
		{
			--myPlayer->x;
		}
	}
	else if (keycode == 'd' || keycode == 'D')
	{
		if (Predict(myPlayer->x + 1, myPlayer->y))
		{
			++myPlayer->x;
		}
	}
}

bool Predict(int x, int y)
{
	return(map[y][x] == ' ');
}
