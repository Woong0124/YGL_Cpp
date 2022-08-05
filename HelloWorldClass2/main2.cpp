#include <iostream>
#include <vector>

using namespace std;

class Parent
{
public:
	Parent() { }
	virtual ~Parent() { }

	virtual void Do()
	{
		cout << "Parent Do" << endl;
		A = 1;
	}

private:
	int A;

protected:
	int C;

};

class Child : public  Parent
{
public:
	Child() { }
	virtual ~Child() { }

	virtual void Do() override
	{
		cout << "Child Do" << endl;

		C = 1;
	}

	void ChildDo()
	{
		cout << "Only Child Do" << endl;
	}
};

template<typename T, typename Y>
T Add(T A, Y B)
{
	return A + B;
}




int main()
{
	cout << Add<int>(3, 4) << endl;
	cout << Add<float>(3.1f, 4.4f) << endl;
	cout << Add<char>(65, 1) << endl;

	Parent* P = new Child();
	Child* CastC = dynamic_cast<Child*>(P); 
	if (CastC)
	{
		CastC->ChildDo();
	}

	vector<Parent*> Data;
	srand((unsigned int)(time(nullptr)));
	for (int i = 0; i < 30; ++i)
	{
		int Type = rand() % 2;
		if (Type == 1)
		{
			Data.push_back(new Parent());
		}
		else
		{
			Data.push_back(new Child());
		}
	}

	//for (int i = 0; i < Data.size(); ++i)
	//{
	//	Child* CastC = dynamic_cast<Child*>(Data[i]);
	//	if (CastC)
	//	{
	//		CastC->ChildDo();
	//	}
	//	else
	//	{
	//		Data[i]->Do();
	//	}
	//}


	return 0;
}