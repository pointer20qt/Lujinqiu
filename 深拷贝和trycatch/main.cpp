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
		cout << "Ĭ�Ϲ��캯��"<<endl;
		p = new char();
	}
	A(const A& a)
	{
		cout << "�������캯��"<<endl;
		this->p = new char();
	}
	A(A&&b) :age(b.age)
	{
		cout << "�ƶ����캯��"<<endl;
		p = b.p;
		b.p = NULL;
	}
	~A()
	{
		cout << "��������"<<endl;
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