#include<iostream>
using namespace std;
using x = int;
class A
{
private:
	friend class B;
public:
	int age;
	A()
	{
		cout << "默认构造函数"<<endl;
	}
	A(const A& a)
	{
		cout << "拷贝构造函数"<<endl;
	}
	A(A&&b) :age(b.age)
	{
		cout << "移动构造函数"<<endl;

	}
	void getA()
	{
		cout << f;
	}
	~A()
	{
		cout << "西沟函数"<<endl;

	}
};
class B :public A
{

public:
	int b;
	B()
	{
		cout << "子类构造函数"<<endl;
	}

};
int main()
{
	A a;
	A b(move(a));
	return 0;
}