#include<iostream>
#include<string>
using namespace std;
class school
{
public:
	string sname;
	school(string a)
	{
		this->sname =a;
		cout << "学校的构造函数"<<endl;
	}
	virtual void Print()
	{
		cout << "学校的 "<<this->sname << endl;
	}
	virtual ~school()
	{
		cout << "学校的析构函数"<<endl;
	}
};
class university:public school
{
public:
	university() :school("东北石油大学")
	{
		cout << "大学的构造函数"<<endl;
	}
	void Print()
	{
		cout << "大学的Print函数"<<endl;
	}
	~university()
	{
		cout << "大学的析构函数"<<endl;
	}
};
int main()
{
	school *a = new university();
	a->Print();
	delete a;
	return 0;
}