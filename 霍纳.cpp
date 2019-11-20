#include <stdio.h>

long int
horner(int coefficient[], int n, int x) //coefficient[]Ϊ�������ʽ��ϵ�����飬nΪ�����С��xΪ����ʽ��δ֪��x�ľ���ֵ
{                                       //ע�⣺coefficient[0]���ϵ��a0��coefficient[1]���ϵ��a1���Դ����ơ�
	int i;
	long int result;

	result = coefficient[n - 1];
	for (i = 1; i <= n - 1; i++)
	{
		result = result * x + coefficient[n - 1 - i];
	}

	return result;
}

int
main(void)
{
	long int p;
	int a[4] = { 1, 2, 1,1 };
	p = horner(a, 4, 1);
	printf("polynomial 1x^3 + 1x^2 + 1x + 1 = %ld\n", p);
}