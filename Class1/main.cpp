#include <iostream>
#include "Counter.h"
#include "User.h"
#include "Person.h"

using namespace std;

void g(const Counter& c)
{
	// const class를 참조하려면 class 함수의 형태도 const 여야 한다
	cout << "Counter = " << c.getCount() << endl;
}

int main()
{
	Counter c1;
	c1.counting();
	c1.counting();
	c1.counting();
	cout << "c1 Count = " << c1.getCount() << endl;
	g(c1);

	char a[11] = { "보리" };
	Person* p1 = new Person(a, "서울");
	Person* p2 = new Person("광수", "경기도");
	p2->printAddr();
	p2->changeAddr("센프란시스코");
	p2->printAddr();
	cout << endl;
	p2->changeName("하늘");
	p2->printName();
	delete p1;
	delete p2;



	//int a = 10;
	//int* ptr;	// int* 가리킬 객체 자료형 포인터
	//ptr = &a;	// ptr에 a의 주소값을 넣음	// & : 주소값 계산 연산자
	//*ptr = 20;	// ptr이 가리키는 곳에 20을 넣음	// *ptr : 가리키고 있는 곳에 접근
	//cout << "a = " << a << endl;
	//cout << &ptr << "  " << &a << endl;	// &ptr : 주소값을 저장하는 ptr을 저장한 주소값



	//// 동적할당
	//// 강제로 메모리에 공간 할당
	//int* intPtr;
	//intPtr = new int;	// new : 동적 메모리 할당 연산자
	//*intPtr = 10;		// intPtr이 가리키는 주소에 데이터값 10을 넣음
	//cout << intPtr << endl;
	//delete intPtr;		// delete : 동적 메모리 반환 연산자
	//intPtr = nullptr;	// nullptr : 값이 빔
	//cout << intPtr << endl;

	//int* intArrPtr;
	//intArrPtr = new int[4];	// 배열을 동적 메모리에 할당
	//*intArrPtr = 10;
	//cout << *intArrPtr << "   " << intArrPtr << endl;
	//*(intArrPtr + 1) = 20;	// 아래와 동일한 구문
	//intArrPtr[2] = 30;		// 위와 동일한 구문
	//cout << *intArrPtr << "   " << intArrPtr[1] << "   " << *(intArrPtr + 2) << endl;
	//delete[] intArrPtr;
	//intArrPtr = nullptr;



	//// L-value 참조법
	//int x = 10;
	//int y = 20;
	//int& xRef = x;	// xRef : x의 새로운 별명, 즉 같다
	//xRef = 100;	// xRef는 x의 새로운 별명이기 때문에 x값이 바뀐다
	//cout << x << "   " << y << endl;
	//xRef = y;	// y의 값을 xRef에 넣는다
	//cout << x << "   " << y << endl;
	//xRef = 50;	// 위에서 xRef = y 라고 했지만 y의 값을 xRef가 참조 하고있는 x값에 넣는다 라는 의미
	//cout << x << "   " << y << endl;

	//// 위와 동일하지만 더 불편한 사용법
	//{
	//	int x = 10, y = 20;
	//	int* xRef = &x;
	//	*xRef = 100;
	//	*xRef = y;
	//}
}