#include<iostream>
#include<malloc.h>
using namespace std;
/*   class
*   ����:����һ���ڵ㣬�ڵ�������������
*/
typedef struct LNode
{
	int  coefficient;//ϵ��
	int power_number;//����
	struct LNode * next;//ָ����һ����ָ��
}LNode, *LPNode;//ȡ��������
				/*
				*����  int InitList(LPNode &L)
				* ����  int��
				* ����  ��ʼ��һ������
				* ����
				* return 1����ɹ�
				* return -1����ʧ��
				*/
int InitList(LPNode &L)
{
	L = (LPNode)malloc(sizeof(LNode));
	if (!L)return -1; //�����ڴ�ʧ��
	L->coefficient = 0;
	L->power_number = 0;
	L->next = NULL;
}
/*
* ����  LPNode head(int coef[],int power[])
* ����  LPNode��
* ����  ����ֱ������β�巨�Ͳ�����һ�����鴴��һ��
* ����   ����int ���͵����� һ������ϵ����һ���������
* ע�� ������鳤������Ҫ�ȿ��ٵ����鳤��С1
* return 0
*/
LPNode head(int power[], int coef[])
{
	LPNode L, current, p;
	L = (LPNode)malloc(sizeof(LNode));//Ϊͷ�ڵ㿪���ڴ�ռ�
	current = L;
	L->next = NULL;
	int i = 0;
	while (coef[i] != '\0'&&power[i] != '\0')
	{
		p = (LPNode)malloc(sizeof(LNode));//�¿��ٵ�һ���ڵ�
		p->coefficient = coef[i];
		p->power_number = power[i];
		current->next = p;//��ǰ�ڵ�ָ���ΪP
		current = p;//Ȼ��ǰ��Ϊp����������������������һ���ڵ�
		i++;
	}
	current->next = NULL;
	return L;
}

/*
* ����  LPNode add_Poly(LPNode L1, LPNode L2)
* ����  LPNode��
* ����  ����ʽ��� ͨ��ƥ����ͬ������Ȼ��ϵ�����
* ����  ����LPNode�͵�ͷ�ڵ�
* return L3  ��������Ӻ�Ľ�����أ�ΪLPNode��
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
