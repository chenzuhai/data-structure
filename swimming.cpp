#include<iostream>
using namespace std;
int main()
{
	unsigned long long n;
	int day;
	while (cin >> day >> n)
	{
		unsigned long long way = 0;
		for (int i = 0; i < n; i++)
		{
			if ((i + day) % 7 == 6 || (i + day) % 7 == 0)continue;
			else
				way += 250;
		}
		cout << way<<endl;
	}
	return 0;
}