#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Player.h"
#include "Goblin.h"
#include "Slime.h"
#include "Boar.h"
#include <vector>

using namespace std;

int main()
{
	//bool bIsRunning = true;
	//Player* MyPlayer = new Player();
	//Goblin* YourGoblin = new Goblin();
	//Slime* YourSlime = new Slime();
	//Boar* YourBoar = new Boar();
	//
	//while (bIsRunning)
	//{
	//	//input
	//	int KeyCode = _getch();
	//
	//	//process
	//	if (KeyCode == 27)
	//	{
	//		bIsRunning = false;
	//	}
	//	MyPlayer->Move();
	//	YourGoblin->Move();
	//	YourSlime->Move();
	//	YourBoar->Move();
	//
	//	//render
	//}
	//
	//delete YourBoar;
	//delete YourSlime;
	//delete YourGoblin;
	//delete MyPlayer;


	//srand(time(nullptr));	// ���� ����
	//bool bIsRunning = true;
	//
	//vector<Character*> MyCharacters;	// ĳ���͵� ���� ���� �迭
	//
	//MyCharacters.push_back(new Player);	// ĳ���� ����
	//for (int i = 0; i < 5; ++i)
	//{
	//	int type = (rand() % 3) + 1;	// Ÿ�Ժ��� ���� ����
	//	if (type == 1)
	//	{
	//		MyCharacters.push_back(new Goblin());
	//	}
	//	else if (type == 2)
	//	{
	//		MyCharacters.push_back(new Slime());
	//	}
	//	else if (type == 3)
	//	{
	//		MyCharacters.push_back(new Boar());
	//	}
	//}
	//
	////[1]
	////Player* MyPlayer = new Player();
	////Goblin* YourGoblin = new Goblin[GoblinCount];
	//
	//while (bIsRunning)
	//{
	//	//input
	//	int Keycode = _getch();
	//	
	//	//process
	//	if (Keycode == 27)
	//	{
	//		bIsRunning = false;
	//	}
	//
	//	for (int i = 0; i < MyCharacters.size(); ++i)
	//	{
	//		MyCharacters[i]->Move();
	//	}
	//
	//	//[1]
	//	//for (int i = 0; i < GoblinCount; ++i)
	//	//{
	//	//	YourGoblin[i].Move();
	//	//}
	//}
	//
	//for (int i = 0; i < MyCharacters.size(); ++i)
	//{
	//	delete MyCharacters[i];
	//}


	Character* MyCharacter = new Character();
	Player* MyPlayer = new Player();

	MyCharacter->Move();
	MyPlayer->Move();

	delete MyPlayer;
}