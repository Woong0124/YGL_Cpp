#pragma once
#include "Vector2D.h"
#include "Color.h"
#include "Texture.h"

class Actor
{
public:
	Actor() : Shape(' ')
	{
		MyTexture = nullptr;
	};

	Actor(int NewX, int NewY) : Shape(' ')
	{
		Location.X = NewX;
		Location.Y = NewY;

		MyTexture = nullptr;
	}

	virtual ~Actor()
	{
		if (MyTexture)
		{
			delete MyTexture;
		}
	};

	Vector2D Location;
	char Shape;

	//abstract class (�߻� Ŭ����)
	//pure virtual function
	//virtual void Render() = 0;	// ������ �ڽ�Ŭ�������� ������ �ؾߵǰ��ϴ� ���� (= unreal interface)
	virtual void Tick();
	virtual void Render();

	virtual bool CheckCollision(int NewX, int NewY);

	int SortOrder = 0;
	bool bCollision = true;

	Color MyColor;

	int Width = 50;
	int Height = 50;

	Texture* MyTexture;

	Uint64 ElapsedTime;
};