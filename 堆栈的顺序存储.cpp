#include<iostream>
using namespace std;
typedef int Element;
#define maxsize 100
typedef struct SqStack
{
	Element data[maxsize];
	int top;
}*Stack;
int Initial(Stack S)
{
	//S = (SqStack*)malloc(sizeof(SqStack));
	S->top = -1;
	return 0;
}
int StackEmpty(Stack S)
{
	if (S->top == -1)return 1;

	return 0;
}
int StackFull(Stack S)
{
	if (S->top == maxsize - 1)return 1;

	return 0;
}
int Push(Stack S, Element e)
{
	if (StackFull(S) == 1)return -1;
	else
	{
		S->top++;
		S->data[S->top] = e;
		return 0;
	}
}
int Pop(Stack S, Element &e)
{
	if (StackEmpty(S) == 1)return -1;
	else
	{
		e = S->data[S->top];
		S->top--;
		return 0;
	}
}
int main()
{
	SqStack S;
	Initial(&S);
	Push(&S, 1);
	Push(&S, 2);
	int e;
	Pop(&S, e);
	cout << e << endl;
	Pop(&S, e);
	cout << e << endl;
	return 0;
}