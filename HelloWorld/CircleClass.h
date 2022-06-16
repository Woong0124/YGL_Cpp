#pragma once
#include <iostream>

//public = 모든 곳에서 접근할 수 있음
//private = 다른 곳에서 접근할 수 없음
//protected = 자식까지는 접근할 수 있음

const double PI = 3.141592;

// 2D 원 좌표
struct C2dType
{
	double x, y;
};

struct CircleType
{
	C2dType center;
	double radius;
};

class CircleClass
{
public:
	CircleClass();	// 생성자
	CircleClass(double x, double y, double radius);

	~CircleClass();	// 파괴자

	void initialize(double x, double y , double radius);
	double circleArea();	// 원의 넓이 구하기
	double getDistance(CircleType target);	// 피타고라스 정리				// target과의 거리 구하기
	bool IsOverlapped(CircleType target);	// 두 원이 겹쳐있는지 확인		// target과 오버랩 되어 있는지 체크

	CircleType circle;	// 속성
};