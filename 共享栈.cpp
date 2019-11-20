#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int Element;
typedef struct SharedStack
{
	Element data[MAXSIZE];
	int top1;
	int top2;
};

int InitStack(SharedStack *S)
{

	S->top1 = 0;
	S->top2 = MAXSIZE;
	return 0;
}

int Push1(SharedStack *S, Element data)
{
	if (S->top1 == S->top2)
	{
		return -1;
	}
	S->data[S->top1] = data;
	S->top1++;
	
	return 0;
}
int Push2(SharedStack *S, Element data)
{
	if (S->top1 == S->top2)
	{
		return -1;
	}
	
	S->data[S->top2] = data;
	S->top2--;
}
int Pop1(SharedStack *S, Element&data)
{

	if (S->top1 == 0)
	{
		return -1;
	}
	
	S->top1--;
	data = S->data[S->top1];
		

}
int Pop2(SharedStack *S, Element&data)
{
	if (S == NULL)
	{
		return -1;
	}
	if (S->top1 == 0)
	{
		S->top2++;
		data = S->data[S->top2];
		
	}
}
int main()
{
	SharedStack S;
	InitStack(&S);
	for (int i = 0; i < 5; i++)
	{
		Push1(&S, i);
	}
	for (int i = 0; i < 5; i++)
	{
		int e;
		Pop1(&S, e);
		cout << e;
	}
	for (int i = 0; i < 5; i++)
	{
		Push2(&S, i);
	}
	for (int i = 0; i < 5; i++)
	{
		int e;
		Pop2(&S, e);
		cout << e;
	}

}