#include<iostream>
using namespace std;
class A
{
private:
	
	friend class B;
	char *p;
public:
	int age;
	A()
	{
		cout << "默认构造函数"<<endl;
		p = new char();
	}
	A(const A& a)
	{
		cout << "拷贝构造函数"<<endl;
		this->p = new char();
	}
	A(A&&b) :age(b.age)
	{
		cout << "移动构造函数"<<endl;
		p = b.p;
		b.p = NULL;
	}
	~A()
	{
		cout << "西沟函数"<<endl;
		delete p;
	}
};
class B
{
private:
	int b;
public:
	void add()
	{

	}
};
int main()
{
	A b;
	b.age = 10;
	A a(move(b));
	cout << a.age;
	return 0;
}