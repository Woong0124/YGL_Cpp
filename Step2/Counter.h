#pragma once

class Counter
{
private:
	int value;

public:
	Counter();	// 디폴트 생성자 - 매개변수 없음
	void Reset();
	void Count();
	int GetValue() const;
};