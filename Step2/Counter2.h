#pragma once

class Counter2
{
private:
	int value;

public:
	Counter2(int num);	// 디폴트 생성자 - 매개변수 있음
	Counter2(const Counter2& c);	// 복사 생성자 - 같은 객체를 복사해서 생성
	void Reset();
	void Count();
	int GetValue() const;
};