#include<iostream>
using namespace std;
class p
{
public:
	p()
	{
		cout << "p con" << endl;
	}
	~p()
	{
		cout << "p des" << endl;
	}
};
class c:public p
{
public:
	c()
	{
		cout << "c con" << endl;
	}
	~c()
	{
		cout << "c des" << endl;
	}
};
int main()
{
	c c1;
	c c2;
}