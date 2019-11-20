#include<iostream>
#include<algorithm>
using namespace std;
int BinarySearch(int a[], int n, int key)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (key == a[mid])return mid;
		if (key > a[mid])left = mid + 1;
		else right = mid - 1;
	}
	return -1;
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
	sort(array,array+n);
	for (int i = 0; i < n; i++)
	{
	     cout<<array[i]<<" ";
	}
	cout << "输入要查找的数字" << endl;
	cin >> key;
	cout << "在第" << BinarySearch(array,n,key) + 1 << "个" << endl;
}