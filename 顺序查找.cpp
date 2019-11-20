#include<iostream>
using namespace std;
int Order_Search(int array[], int n, int key)
{
	int i;
	array[n] = key;
	for ( i = 0; key != array[i]; i++);
	return (i < n ? i : -1);
}
int main()
{
	int n;
	int array[10005];
	cout << "输入数组个数" << endl;
	cin >> n;

	int key;
	cout << "输入数组里的值" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	cout << "输入要查找的数字" << endl;
	cin >> key;
	cout <<"在第"<< Order_Search(array, n, key)+1 <<"个"<< endl;

}