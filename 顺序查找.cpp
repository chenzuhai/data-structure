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
	cout << "�����������" << endl;
	cin >> n;

	int key;
	cout << "�����������ֵ" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	
	cout << "����Ҫ���ҵ�����" << endl;
	cin >> key;
	cout <<"�ڵ�"<< Order_Search(array, n, key)+1 <<"��"<< endl;

}