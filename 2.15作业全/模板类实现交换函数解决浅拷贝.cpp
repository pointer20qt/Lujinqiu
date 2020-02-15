#include<iostream>
using namespace std;
class A
{
public:
	int val;
	char *p;
	A(int val)
	{
		cout << "普通函数"<<endl;
		this->val = val;
		p = new char[50];
	}
	A(const A& other)
	{
		p = new char[50];
		this->val = other.val;
		cout << "拷贝构造函数"<<endl;
		
	}
	A* operator=(A& other)
	{
		delete [] p;
		p = new char[50];
		this->val = other.val;
		return this;
	}
	~A()
	{
		delete []p;
		cout << "析构函数"<<endl;
	}
};
ostream& operator<<(std::ostream &a,A&b)
{
	cout << b.val;
	return a;
}
template<class T> void Lswap( T &a, T &b)
{
	T tmp = a;
	a = b; 
	b = tmp;
}
int main()
{
	/*int a = 10, b = 20;
	double c = 1.2, e = 2.5;
	Lswap(a,b);
	Lswap(c,e);
	cout << a <<"交换"<<b<< endl;
	cout << c << "交换" << e << endl;*/
	A a(10);
	A b(20);
	Lswap(a,b);
	cout << a << "交换" << b << endl;
	return 0;
}