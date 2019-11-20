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
	cout << "�����������" << endl;
	cin >> n;
	
	int key;
	cout << "�����������ֵ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	sort(array,array+n);
	for (int i = 0; i < n; i++)
	{
	     cout<<array[i]<<" ";
	}
	cout << "����Ҫ���ҵ�����" << endl;
	cin >> key;
	cout << "�ڵ�" << BinarySearch(array,n,key) + 1 << "��" << endl;
}