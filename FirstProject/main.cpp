#include <iostream>

using namespace std;

//void func(int a);
//void func(float a);
//
//func(10);			void func(int a);		// 함수 호출
//func(10.f);		void func(float a);		// 함수 호출
//func(10.0);								// 에러 발생

// 구조체 선언은 항상 맨 처음에 !!
struct salesRec
{
	char pID[10];
	int dYear;
	int dMonth;
	int dData;
	char deliverAddr[40];
};

struct timeRec
{
	int hours;
	int minutes;
	int seconds;
};

// 함수 선언
double getArraySum(double arr[], int n);	// 배열의 값을 모두 더해주는 함수
void printSum(double sum);					// 프린트 함수	// void는 반환값이 없음
double variance(double arr[], int n);		// 분산 구하기 함수
void swapValues(int& x, int& y);			// 두 값을 서로 바꾸는 함수
void prSalesRec(salesRec srec);

// 같은 타입, 같은 변수명, 다른 매개변수	 가능
// 다른 타입, 같은 변수명, 같은 매개변수	불가능
void addTime(timeRec& t1, const timeRec& t2);	// 시간 t1에 t2를 더한다
void addTime(timeRec& t1, int minutes);			// 시간 t1에 minutes 분을 더한다

int main()
{
	////함수를 썼을 때 코딩
	//double a[50], b[100];
	//double sum = 0;
	//sum = getArraySum(a, 50);
	//printSum(sum);
	//sum = getArraySum(b, 100);
	//printSum(sum);

	//위와 동일		//함수를 쓰지 않았을 때의 코딩
	//for (int i = 0; i < 50; ++i)
	//{
	//	a[i] = i;
	//	sum += a[i];
	//}
	//cout << "sum = " << sum << endl;
	//for (int i = 0; i < 100; ++i)
	//{
	//	b[i] = i;
	//	sum += b[i];
	//}
	//cout << "sum = " << sum << endl;

	////
	//int a, b = { 0 };
	//cout << "두개의 수를 입력해 주세요. \n";
	//cin >> a >> b;
	//swapValues(a, b);
	//cout << "a = " << a << " b = " << b << endl;

	////
	//salesRec stRec;
	//strcpy_s(stRec.pID, "123456789");
	//stRec.dYear = 2022;
	//stRec.dMonth = 6;
	//stRec.dData = 8;
	//strcpy_s(stRec.deliverAddr, "경기도");
	//prSalesRec(stRec);

	//
	timeRec time1 = { 2, 20, 30 };
	timeRec time2 = { 1, 55, 11 };

	cout << time1.hours << "시간 " << time1.minutes << "분 " << time1.seconds << "초 + ";
	cout << time2.hours << "시간 " << time2.minutes << "분 " << time2.seconds << "초 = ";
	addTime(time1, time2);
	cout << time1.hours << "시간 " << time1.minutes << "분 " << time1.seconds << "초";

	//cout << time1.hours << "시간 " << time1.minutes << "분 + ";
	//cout << time2.hours << "시간 " << time2.minutes << "분 = ";
	//addTime(time1, 210);
	//cout << time1.hours << "시간 " << time1.minutes << "분";
}

// 배열의 값을 모두 더해주는 함수
double getArraySum(double arr[], int n)		// 자료형 함수명 (매게변수)
{
	double sum = 0;

	for (int i = 0; i < n; ++i)
	{
		arr[i] = i;
		sum += arr[i];
	}

	return sum;
}

// 프린트 함수	// void는 반환값이 없음
void printSum(double sum)
{
	cout << "sum = " << sum << endl;
}

// 분산 구하기 함수
double variance(double arr[], int n)
{
	double sum = 0, sqSum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		sqSum += arr[i] * arr[i];
	}
	double result = sqSum / n - sum / (n * n);
	return result;
}

// 두 값을 서로 바꾸는 함수
void swapValues(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

//
void prSalesRec(salesRec srec)
{
	cout << "품목코드 : " << srec.pID << endl;
	cout << "배달일자 : " << srec.dYear << "년 " << srec.dMonth << "월 " << srec.dData << "일 " << endl;
	cout << "배달주소 : " << srec.deliverAddr << endl;
}

// 시간 t1에 t2를 더한다
void addTime(timeRec& t1, const timeRec& t2)
{
	t1.seconds += t2.seconds;
	t1.minutes += t2.minutes + (t1.seconds / 60);
	t1.seconds %= 60;
	t1.hours += t2.hours + (t1.minutes / 60);
	t1.minutes %= 60;
}

// 시간 t1에 minutes 분을 더한다
void addTime(timeRec& t1, int minutes)
{
	t1.minutes += minutes;
	t1.hours += (t1.minutes / 60);
	t1.minutes %= 60;
}