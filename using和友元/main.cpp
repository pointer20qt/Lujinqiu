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
		cout << "Ĭ�Ϲ��캯��"<<endl;
	}
	A(const A& a)
	{
		cout << "�������캯��"<<endl;
	}
	A(A&&b) :age(b.age)
	{
		cout << "�ƶ����캯��"<<endl;

	}
	void getA()
	{
		cout << f;
	}
	~A()
	{
		cout << "��������"<<endl;

	}
};
class B :public A
{

public:
	int b;
	B()
	{
		cout << "���๹�캯��"<<endl;
	}

};
int main()
{
	A a;
	A b(move(a));
	return 0;
}