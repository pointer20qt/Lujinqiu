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
		cout << "ѧУ�Ĺ��캯��"<<endl;
	}
	virtual void Print()
	{
		cout << "ѧУ�� "<<this->sname << endl;
	}
	virtual ~school()
	{
		cout << "ѧУ����������"<<endl;
	}
};
class university:public school
{
public:
	university() :school("����ʯ�ʹ�ѧ")
	{
		cout << "��ѧ�Ĺ��캯��"<<endl;
	}
	void Print()
	{
		cout << "��ѧ��Print����"<<endl;
	}
	~university()
	{
		cout << "��ѧ����������"<<endl;
	}
};
int main()
{
	school *a = new university();
	a->Print();
	delete a;
	return 0;
}