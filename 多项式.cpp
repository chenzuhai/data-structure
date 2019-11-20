#include<iostream>
#include<malloc.h>
using namespace std;
/*   class
*   功能:储存一个节点，节点里有三个参数
*/
typedef struct LNode
{
	int  coefficient;//系数
	int power_number;//次数
	struct LNode * next;//指向下一个的指针
}LNode, *LPNode;//取两个别名
				/*
				*函数  int InitList(LPNode &L)
				* 类型  int型
				* 功能  初始化一个链表
				* 输入
				* return 1代表成功
				* return -1代表失败
				*/
int InitList(LPNode &L)
{
	L = (LPNode)malloc(sizeof(LNode));
	if (!L)return -1; //分配内存失败
	L->coefficient = 0;
	L->power_number = 0;
	L->next = NULL;
}
/*
* 函数  LPNode head(int coef[],int power[])
* 类型  LPNode型
* 功能  可以直接利用尾插法和并利用一个数组创建一个
* 输入   两个int 类型的数组 一个代表系数，一个代表次数
* 注意 这个数组长度至少要比开辟的数组长度小1
* return 0
*/
LPNode head(int power[], int coef[])
{
	LPNode L, current, p;
	L = (LPNode)malloc(sizeof(LNode));//为头节点开辟内存空间
	current = L;
	L->next = NULL;
	int i = 0;
	while (coef[i] != '\0'&&power[i] != '\0')
	{
		p = (LPNode)malloc(sizeof(LNode));//新开辟的一个节点
		p->coefficient = coef[i];
		p->power_number = power[i];
		current->next = p;//当前节点指向改为P
		current = p;//然后当前改为p，这样就在链表最后插入了一个节点
		i++;
	}
	current->next = NULL;
	return L;
}

/*
* 函数  LPNode add_Poly(LPNode L1, LPNode L2)
* 类型  LPNode型
* 功能  多项式相加 通过匹配相同次数，然后将系数相加
* 输入  两个LPNode型的头节点
* return L3  将两个相加后的结果返回，为LPNode型
*/
LPNode add_Poly(LPNode L1, LPNode L2)
{
	LPNode p = L1->next;
	LPNode q = L2->next;
	LPNode L3;
	InitList(L3);
	LPNode tail_pointer = L3;
	while (p != NULL && q != NULL)
	{

		if (p->power_number == q->power_number)
		{
			LPNode s = (LPNode)malloc(sizeof(LNode));
			s->power_number = p->power_number;
			s->coefficient = p->coefficient + q->coefficient;

			tail_pointer->next = s;
			s->next = NULL;
			tail_pointer = s;

			p = p->next;
			q = q->next;
		}
		else if (p->power_number > q->power_number)
		{
			tail_pointer->next = q;
			tail_pointer = q;			
			q = q->next;
		}
		else if (p->power_number < q->power_number)
		{
			tail_pointer->next = p;
			tail_pointer = p;
			p = p->next;
		}
	}
	if (p == NULL)
	{
		tail_pointer->next = q;
	}
	else if (q == NULL)
	{
		tail_pointer->next = p;
	}
	return L3;
}
int main()
{
	int power1[10] = { 1,2,3};
	int coef1[10] = { 10,10,10 };
	int power2[10] = { 3,4,5 };
	int coef2[10] = { 10,10,10 };
	LPNode L1 = head(power1, coef1);
	LPNode L2 = head(power2, coef2);
	LPNode L3 = add_Poly(L1, L2);
	LPNode p;
	p = L3->next;
	while (p != NULL)
	{
		cout << p->coefficient << "*x^" << p->power_number << "+";
		p = p->next;

	}
}
