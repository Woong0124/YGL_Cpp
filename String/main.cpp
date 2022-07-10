#include <iostream>
#include <string>

using namespace std;

char* copyString(const char* str);
char* appendString(const char* str1, const char* str2, const char* str3);
string_view extractExtension(string_view fileName);

int main()
{
	//char* a = copyString("Hi ");
	//char* b = copyString("Hello ");
	//char* c = copyString("Bye ");
	//char* d = appendString(a, b, c);
	//cout << d << endl;
	//cout << endl;
	//
	//size_t s1 = sizeof(b);	// b의 바이트 수 (포인터니까 4 or 8)
	//size_t s2 = strlen(b);	// b의 문자열 길이
	//cout << s1 << " " << s2 << endl;
	//cout << endl;
	//
	//const char* str = "Hello \"World\" !";
	//cout << str << endl;
	//cout << endl;


	string A("12");
	string B("34");
	string C(A + B);
	cout << A << " " << B << " " << C << " " << endl;
	cout << endl;

	string myString = "Hello";
	myString += ", there";
	string myOtherString = myString;
	if (myString == myOtherString)
	{
		myOtherString[0] = 'h';
	}
	cout << myString << endl;
	cout << myOtherString << endl;
	cout << endl;

	auto string1 = "Hello World";
	auto string2 = "Hello World"s;

	long double d = 3.14L;
	string string3 = to_string(d);
	const string toParse = " 123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);
	cout << "Parsed value : " << value << endl;
	cout << "First non-parsed character : '" << toParse[index] << "'" << endl;
	cout << endl;

	string str = "Hello";
	string_view sv = " world";
	auto result = str + sv.data();

	string fileName = R"(C:\temp\my file.ext)";
	cout << "C++ string : " << extractExtension(fileName) << endl;
	const char* cString = R"(C:\temp\my file.ext)";
	cout << "C string : " << extractExtension(cString) << endl;
	cout << "Literal : " << extractExtension(R"(C:\temp\my file.ext)") << endl;
}

char* copyString(const char* str)
{
	char* result = new char[strlen(str) + 1];
	strcpy_s(result, strlen(str) + 1, str);
	return result;
}

char* appendString(const char* str1, const char* str2, const char* str3)
{
	int size = strlen(str1) + strlen(str2) + strlen(str3) + 1;
	char* result = new char[size];
	strcpy_s(result, size, str1);	// strcpy_s = 문자열 복사
	strcat_s(result, size, str2);	// strcat_s = 문자열 붙히기
	strcat_s(result, size, str3);
	return result;
}

string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));	// substr = 문자열 부분 삭제, rfind = 오른쪽 문자열 찾기
}