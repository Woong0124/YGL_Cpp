//#include <iostream>
//#include <fstream>
//#include "Engine.h"
//#include <vector>
#include "Engine.h"

using namespace std;

//void Sorting(vector<int>& vec)
//{
//	int Temp = 0;
//	for (int i = 0; i < vec.size() - 1; ++i)
//	{
//		for (int j = i + 1; j < vec.size(); ++j)
//		{
//			if (vec[i] > vec[j])
//			{
//				Temp = vec[i];
//				vec[i] = vec[j];
//				vec[j] = Temp;
//			}
//		}
//	}
//}

int SDL_main(int argc, char* argv[])
{
	//// 1, 4, 7, 3, 2, 10
	//vector<int> vec = { 1,4,7,3,2,10,5 };
	//Sorting(vec);
	//for (int v : vec)
	//{
	//	cout << v << endl;
	//}
	//vector<int>::iterator a = vec.begin();
	//cout << *a;


	Engine* MyEngine = GameEngine;
	
	//MyEngine->LoadMap("level1.txt");
	//MyEngine->SaveMap("level2.txt");

	MyEngine->LoadMap("level2.txt");
	MyEngine->Run();
	
	delete MyEngine;


	//SDL_SetRenderDrawColor(MyRenderer, 0, 255, 255, 255);
	//SDL_Rect MyRect = { 100, 100, 100, 100 };
	//SDL_RenderFillRect(MyRenderer, &MyRect);

	return 0;
}