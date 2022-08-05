#include <iostream>
#include <vector>

using namespace std;

//Class
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

	//override
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



//overloading
template<typename T>
T Add(T A, T B)
{
	return A + B;
}



int main()
{
	//overloading
	cout << Add<int>(3, 4) << endl;
	cout << Add<float>(3.14, 1) << endl;



	//Class
	Parent* P = new Child();
	Child* CastC = dynamic_cast<Child*> (P);
	if (CastC)
	{
		CastC->ChildDo();
	}
	 
	Parent* P1 = new Child();
	Parent* P2 = new Parent();
	 
	P1->Do();
	P2->Do(); 
	 
	delete P1;
	delete P2;
	 
	return 0;
}