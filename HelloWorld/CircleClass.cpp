#include <iostream>
#include "CircleClass.h"

using namespace std;

CircleClass::CircleClass() : circle({ 0 })
{

}

CircleClass::CircleClass(double x, double y, double radius)
{
	initialize(x, y, radius);
}

CircleClass::~CircleClass()
{

}

void CircleClass::initialize(double x, double y, double radius)
{
	circle.center.x = x;
	circle.center.y = y;
	circle.radius = radius;
}

// 원의 넓이 구하기
double CircleClass::circleArea()
{
	return circle.radius * circle.radius * PI;
}

// 피타고라스 정리
double CircleClass::getDistance(CircleType target)
{
	double dx = circle.center.x - target.center.x;
	double dy = circle.center.y - target.center.y;
	double dCntr = sqrt(dx * dx + dy * dy);		// sqrt = 제곱근
	return dCntr;
}

// 두 원이 겹쳐있는지 확인
bool CircleClass::IsOverlapped(CircleType target)
{
	double distance = getDistance(target);
	return (distance < circle.radius + circle.radius);
}
