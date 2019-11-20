#include<stdio.h>
#include<malloc.h>
typedef struct LNode
{
	int element;
	struct LNode *next;
}LNode, *LPNode;
LNode *head(int a[])
{
	LPNode L, current, p;
	L = (LPNode)malloc(sizeof(LNode));
	current = L;
	L->next = NULL;
	int i = 0;
	while (a[i] != '\0')
	{
		p = (LPNode)malloc(sizeof(LNode));
		p->element = a[i];
		current->next = p;
		current = p;
		i++;

	}
	current->next = NULL;
	return L;
}
void del1(LPNode &L, int x)
{
	LPNode p = L;//头结点 
	p = p->next;//头结点后的第一个结点
	LPNode pre = L;
	while (p != NULL) {
		if (p->element == x) {
			pre->next = p->next;
			delete(p);
			p = pre->next;
			break;

		}
		else {//数据域不是x，把pre和p都后移一位 
			pre = p;
			p = p->next;
		}
	}
}
int del2(LPNode &L, int e)
{
	LPNode p =L->next;
	LPNode q = L;
	//int idx = 0;
	while (p)
	{
		//idx++;
		if (p->element == e)
		{
				LPNode tmp = p;
				q->next = tmp->next;
				free(tmp);
				break;
		}
		q = p;
		p = p->next;
	}
	return 1;
}
int del3(LPNode &L, int e, int &idx)
{
	LPNode p = L->next;
	LPNode q = L;

	while (p->next)
	{
		idx++;
		if (p->element == e)
		{
			
				LPNode tmp = p;
				q->next = tmp->next;
				free(tmp);
				break;
		}
		q = p;
		p = p->next;
	}
	return 1;
}
void del(LPNode &L, int x)
{
	LPNode p = L;//头结点 
	p = p->next;//头结点后的第一个结点
	LPNode pre = L;
	while (p != NULL) {
		if (p->element == x) {
			pre->next = p->next;
			delete(p);
			p = pre->next;

		}
		else {//数据域不是x，把pre和p都后移一位 
			pre = p;
			p = p->next;

		}
	}
}
int main()
{
	LPNode L, p; int a;
	int x[10] = { 1,2,3,4,5,6};
	L = head(x);
	
	del2(L, 6);
	p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->element);
		p = p->next;
	}
	return 0;
}