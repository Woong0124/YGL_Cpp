#pragma once
#include <iostream>

using namespace std;

class VecF
{
private:
	int n;	// 벡터의 크기
	float* arr;	// 벡터의 float값의 정보 포인터

public:
	VecF(int d, float* a = nullptr);
	VecF(const VecF& fv);
	~VecF();

	VecF add(const VecF& fv) const;
	void Print() const;
};