#include<iostream>
#include<vector>
#include<Initializer_List>
#define NDEBUG
#include<assert.h>
using namespace std;
class A
{
	int *cur;
public:
	A(const initializer_list<int>& item)
	{
		cout << "调用了默认构造函数" << endl;
		cur = new int[item.size()];
		int j = 0;
		for (auto i=item.begin();i<item.end();i++)
		{
			*(cur+j) = *i;
			j++;
		}
	}
	int operator[](int index)
	{
		return cur[index];
	}
	~A()
	{
		cout << "析构函数"<<endl;
		delete[]cur;
	}
};

int main()
{
	int a;
	unsigned char *p = (unsigned char*)&a;

	a = 147;
	assert(a<100);
	printf("%d %d %d %d\n",p[0],p[1],p[2],p[3]);
	a = 256;
	printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
	return 0;
}


