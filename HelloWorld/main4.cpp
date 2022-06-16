#include <iostream>
#include "Employeestruct.h"

using namespace std;

int main()
{
	//직원 레코드 생성 및 값 채우기
	Employee anEmployee;
	anEmployee.firstInitial = 'M';
	anEmployee.lastInitial = '6';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	//직원 레코드에 저장된 값 출력하기
	cout << "Employee: " << anEmployee.firstInitial << anEmployee.lastInitial << endl;
	cout << "Number: " << anEmployee.employeeNumber << endl;
	cout << "Salary: " << anEmployee.salary << endl;
	return 0;
}