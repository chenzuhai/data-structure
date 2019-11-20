#include <stdio.h>

long int
horner(int coefficient[], int n, int x) //coefficient[]为待求多项式的系数数组，n为数组大小，x为多项式中未知数x的具体值
{                                       //注意：coefficient[0]存放系数a0，coefficient[1]存放系数a1，以此类推…
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