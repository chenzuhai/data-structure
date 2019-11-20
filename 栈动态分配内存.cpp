#include<iostream>
#include<malloc.h>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACK_INREMENT 10

typedef int Element;
typedef struct
{
	int StackSize;
	Element *bottom;
	Element *top;
}SqLStack;

int InitStack(SqLStack* S)
{
	S->bottom = (Element*)malloc(STACK_INIT_SIZE*sizeof(Element));
	if (!S->bottom)
	{
		cout << "·ÖÅäÄÚ´æÊ§°Ü" << endl;
		exit(0);
	}
	S->top = S->bottom;


	S->StackSize = STACK_INIT_SIZE;

	return 0;
}

int StackEmpty(SqLStack* S)
{
	if (S->bottom == S->top)return 1;

	return 0;
	
}
int Push(SqLStack *S, Element e)
{
	if (S->StackSize == (S->top - S->bottom))
	{
		S->bottom = (Element *)realloc(S->bottom, (S->StackSize + STACK_INREMENT )* sizeof(Element));
	
		if (!S->bottom)
		{
			cout << "·ÖÅäÄÚ´æÊ§°Ü" << endl;
			return 0;
		}
		S->StackSize += STACK_INREMENT;
		S->top = S->bottom + S->StackSize;
	}
		
	*(S->top) = e;
	S->top++;
	return 0;
}
int Pop(SqLStack* S, Element &e)
{
	if (S->bottom == S->top)
	{
		cout << "Õ»Îª¿Õ" << endl;
		return -1;
	}
	S->top--;
	e = *(S->top);
	
	return 0;
}
/*oid DestroyStack(SqLStack *S)
{
	if (S->bottom)
		free(S->bottom);
}*/
void DestroyStack(SqLStack *S)
{
	int len = S->StackSize;
	for (int i = 0; i < len; i++)
	{
		free(S->bottom);
		S->bottom++;
	}
	S->bottom = S->top = NULL;
	S->StackSize = 0;
}
SqLStack creatStack(int arr[],int len)
{
	SqLStack S;
	InitStack(&S);

	for (int i = 0; i < len; i++)
	{
		Push(&S, arr[i]);
	}
	return S;
}
int main()
{

	SqLStack S;
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	S=creatStack(a,15);
	int e;
	for (int i = 0; i < 15; i++)
	{
		Pop(&S, e);
		cout << e << " ";
	}
	return 0;
}