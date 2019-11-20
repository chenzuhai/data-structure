#include<iostream>
#include<malloc.h>
typedef int Element;
using namespace std;
typedef struct LNode
{
	Element data;
	struct LNode *next;
}LNode,*LPNode;
/**LHeader һ�������ͷ�ڵ�
* ���ܣ�����ָ���������ĵ�һ��ָ���������ĳ���
*/
typedef struct Header
{
	int length;        //���泤��
	struct LNode* head;//ָ�������һ���ڵ��ָ��
}*LHeader;
/*int InitList(LHeader *LH)
* ���ܣ���ʼ��һ������
* ���룺��������ͷ�ڵ�
* ���أ�-1���������ڴ�ʧ�� 0��������
*/
int InitList(LHeader LH)
{
	LH = (LHeader)malloc(sizeof(Header));//����һ��Header��С���ڴ������ڵ�
	if (!LH)
	{
		cout << "ͷ�ڵ������ڴ�ʧ��" << endl;
		return -1;
	}
	LH->length =0;
	LH->head = NULL;
	return 0;
}
/*LHeader tail(int data[])
* ���ܣ�ͨ��һ������ʹ��β�巨�����½�һ������
* ���룺���� �������ʼ�±����ֹ�±�
*/
LHeader tail(int data[],int first,int last)
{
	LHeader L = (LHeader)malloc(sizeof(Header));
	if (!L)
	{
		cout << "ͷ�ڵ������ڴ�ʧ��" << endl;
		return NULL;
	}
	L->head = NULL;
	L->length = 0;

	for (int i = first ; i <= last ; i++)
	{
		LPNode s = (LPNode)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		if (L->length == 0) { L->head = s;  L->length++; continue;}
		LPNode p = L->head;
		while (p->next)p = p->next;//�ƶ�����β
		p->next = s;
		s->next = NULL;
		L->length++;
	}
	return L;

}
/*int List(LHeader L)
* ���ܣ����������������������ֵ
* ���룺��������ͷ�ڵ��ָ��
* ���أ� 0������
*/
int List(LHeader L)
{
	LPNode p = L->head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}
/*int dele(LHeader &L, Element data)
* ���ܣ�ɾ��������ָ��Ԫ��
* ���룺�����ͷ�ڵ�ָ�� �� Ҫɾ����ֵ
*/
int dele(LHeader &L, Element data)
{
	LPNode p = L->head;
	LPNode pre = L->head;
	int idx = 0;
	while (p != NULL)
	{
		
		if (p->data == data)
		{
			if (idx == 0)
			{
				LPNode tmp = p;
				L->head = tmp->next;
				L->length--;
				free(tmp);
				cout << "��ɾ����λ��Ϊ" << idx << endl;
				break;
			}
			else
			{
				LPNode temp = p;
				pre->next = temp->next;
				L->length--;
				free(temp);
				cout << "��ɾ����λ��Ϊ" << idx << endl;
				break;
			}
		}
		idx++;
		pre = p;
		p = p->next;
	}
	return 0;
}
int main()
{
	LHeader L;
	int a[] = { 1,2,3,4,5,6,7 };
	L=tail(a, 0, 6);
	dele(L, 4);
	List(L);
	cout << L->length;
	return 0;
}