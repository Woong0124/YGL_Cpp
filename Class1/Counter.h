#pragma once

// 캡슐화 - 객체의 구현부와 사용자부분을 분리

// 숫자를 1씩 증가
// 0으로 초기화 가능
// 현재 카운팅한 값 보기
class Counter
{
private :
	int count;

public :
	// 생성자
	Counter()
	{
		count = 0;
	}

	// count >> 1씩 증가
	void counting()
	{
		++count;
	}

	// count >> 0으로 초기화
	void reset()
	{
		count = 0;
	}

	// count >> 값 알려주기
	int getCount() const
	{
		return count;
	}
};