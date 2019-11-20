#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int n, w = 1, m;
	cin >> n;
	m = n;
	while (n--)
	{
		int u = 0;
		char a[1010], b[1010];
		cin >> a >> b;
		int l1 = strlen(a);
		int l2 = strlen(b);
		int x[1010], y[1010], z[1010];
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		for (int i = l1 - 1, k = 0; i >= 0; i--, k++)
			x[k] = a[i] - '0';
		for (int i = l2 - 1, k = 0; i >= 0; i--, k++)
			y[k] = b[i] - '0';
		int l3 = l1>l2 ? l1 : l2;
		for (int i = 0; i <= l3; i++)
		{
			z[i] = x[i] + y[i] + u;
			u = z[i] / 10;
			z[i] = z[i] % 10;
		}
		for (int i = l3; i >= 0; i--)
			if (z[i] != 0)
			{
				l3 = i;
				break;
			}
		printf("Case %d:\n%s + %s = ", w++, a, b);
		for (int i = l3; i >= 0; i--)
		{
			printf("%d", z[i]);
		}
		printf("\n");
		if (w <= m)
			printf("\n");
	}
	return 0;
}
