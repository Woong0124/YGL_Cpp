#include <iostream>
#include <array>
#include <vector>
#include "CircleClass.h"

using namespace std;

//const double PI = 3.141592;

//// 2D 원 좌표
//struct C2dType
//{
//	double x, y;
//};
//
//struct CircleType
//{
//	C2dType center;
//	double radius;
//};
//
//// 원의 넓이 구하기
//double circleArea(CircleType c)
//{
//	return c.radius * c.radius * PI;
//}
//
//// 피타고라스 정리
//double getDistance(CircleType c1, CircleType c2)
//{
//	double dx = c1.center.x - c2.center.x;
//	double dy = c1.center.y - c2.center.y;
//	double dCntr = sqrt(dx * dx + dy * dy);		// sqrt = 제곱근
//	return dCntr;
//}
//
//// 두 원이 겹쳐있는지 확인
//bool IsOverlapped(CircleType c1, CircleType c2)
//{
//	double distance = getDistance(c1, c2);
//	return (distance < c1.radius + c2.radius);
//}

int main()
{
	//CircleType c1, c2;
	//c1.center.x = 10;
	//c1.center.y = 10;
	//c1.radius = 10;

	//c2.center.x = 30;
	//c2.center.y = 30;
	//c2.radius = 10;

	//bool bIsOverlapped = IsOverlapped(c1, c2);
	//cout << "IsOverlapped = " << boolalpha << bIsOverlapped << noboolalpha << endl;

	CircleClass cc1 = { 10, 10, 10 };
	CircleClass cc2 = { 30, 30, 10 };
	
	bool bIsOverlapped = cc1.IsOverlapped(cc2.circle);
	cout << "IsOverlapped = " << boolalpha << bIsOverlapped << noboolalpha << endl;
}