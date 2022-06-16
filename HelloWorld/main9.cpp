#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{

	// 배열 선언, 변수명[인덱스 갯수]
	int myArray[5] = { 0 };
	// 인덱스 갯수를 정하지 않았을때에는 직접 값을 입력 해줘야한다.
	int myArray[] = { 1,2,3,4 };
	// 일부 값을 지정해주지 않으면 0으로 초기화
	int myArray[5] = { 1,2,3 };	// 4, 5번 인덱스는 0 으로 초기화
	
	// 2차원 배열
	//	1	2	3	4
	//	5	6	7	8		<== 이렇게 표기됨
	int myArray1[2][4] = { {1,2,3,4},{5,6,7,8} };
	
	// 같은 표기법
	int myArray2[3] = { 0 };
	array<int, 3> myArray2 = { 5,2,3 };	// 선호 표기법
	auto [a1, a2, a3] = myArray2;	// auto (형태에 맞게 자동 변환)	// 
	
	// 백터
	vector<int> myVector = { 11, 22 };
	myVector.push_back(33);	// 인덱스를 33개 까지 늘림



	// for 구문
	// myVector에 모든 값을 더해보자.

	vector<int> myVector = { 11, 22, 33 };
	int sum = 0;
	
	for (int i = 0; i < myVector.size(); ++i)
	{
		sum += myVector[i];
	}
	cout << sum << endl;

	//위와 동일
	for (auto i = myVector.begin(); i < myVector.end(); ++i)	// 포인터
	{
		sum += *i;	// 현재 포인터의 주소값을 읽을때에는 * 을 붙힘
	}
	cout << sum << endl;

	// 위와 동일
	for (int i : myVector)	// for(변수 : 범위)	// myVector의 값을 i 변수에 하나씩 대입해서	범위가 끝날때 까지 반복
	{
		sum += i;
	}
	cout << sum << endl;

	// & 붙혀주면 참조되어 본 값에도 영향을 준다
	// 붙히면 12,23,34	// 안붙히면 11,22,33
	for (int& i : myVector)
	{
		++i;
	}

	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << "myVector[ " << i << " ] = " << myVector[i] << endl;
	}

	//myVector(11,22,33) -> (12,23,34)로 바꿔보자
	for (int i = 0; i < myVector.size(); ++i)
	{
		++myVector[i];
	}

	for (int i = 0; i < myVector.size(); ++i)
	{
		cout << "myVector[ " << i << " ] = " << myVector[i] << endl;
	}



	// while 구문			// 선 조건체크, 후 실행
	vector<int> myVector = { 11, 22, 33 };

	int vectorSize = myVector.size();
	cout << "VectorSize = " << vectorSize << endl;

	int sum = 0;
	int i = 0;

	while (i < 3)
	{
		sum += myVector[i];
		++i;
	}

	// do / while 구문		// 선 실행, 후 조건체크
	int sum2 = 0;
	int j = 0;
	do {
		sum2 += myVector[j];
		++j;
	} while (j > 3);



	//
	int selection = 0;

	do {
		system("cls");	// 창에 보여진 모든걸 없에버림
		cout << "What do you like? : \n";
		cout << "1) Red\n";
		cout << "2) Blue\n";
		cout << "3) Black\n";
		cout << "4) White\n";
		cin >> selection;
	} while (4 < selection || selection < 1);

	cout << "You like " << selection << endl;

	
	do {
		system("cls");

		int a, b = { 0 };
		cout << "put number [A B] : \n";
		cin >> a >> b;

		cout << "A + B = " << a + b << endl;
		cout << "Quit ? ( Y / N ) : ";

		char q = ' ';
		cin >> q;

		if (q == 'Y')
		{
			break;
		}
	} while (1);
}