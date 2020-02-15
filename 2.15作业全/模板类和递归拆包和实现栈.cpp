#include<iostream>
#include<vector>
using namespace std;
template<class T> class L_stack
{
public:
	vector<int> res;
	void push(T&& a)
	{
		res.push_back(a);
	}
	void pop()
	{
		res.pop_back();
	}
	T& top()
	{
		return res.back();
	}
};

void Lprintf()
{
}
template<class T=int, class... args>void Lprintf(T f, args...d)
{
	cout << f << endl;
	Lprintf(d...);
}
int main()
{
	/*L_stack<int> a;
	a.push(3);
	a.push(2);
	a.push(1);
	cout << a.top()<< endl;
	a.pop();
	cout << a.top()<< endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();*/
	Lprintf(1,2,3,4,"asd");
	return 0;
}