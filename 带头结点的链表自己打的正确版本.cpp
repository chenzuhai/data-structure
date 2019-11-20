#include<iostream>
#include<malloc.h>
typedef int Element;
using namespace std;
typedef struct LNode
{
	Element data;
	struct LNode *next;
}LNode,*LPNode;
/**LHeader 一个链表的头节点
* 功能：储存指向这个链表的第一个指针这个链表的长度
*/
typedef struct Header
{
	int length;        //储存长度
	struct LNode* head;//指向链表第一个节点的指针
}*LHeader;
/*int InitList(LHeader *LH)
* 功能：初始化一个链表
* 输入：这个链表的头节点
* 返回：-1代表申请内存失败 0代表正常
*/
int InitList(LHeader LH)
{
	LH = (LHeader)malloc(sizeof(Header));//划分一个Header大小的内存给这个节点
	if (!LH)
	{
		cout << "头节点申请内存失败" << endl;
		return -1;
	}
	LH->length =0;
	LH->head = NULL;
	return 0;
}
/*LHeader tail(int data[])
* 功能：通过一个数组使用尾插法快速新建一个链表
* 输入：数组 数组的起始下标和终止下标
*/
LHeader tail(int data[],int first,int last)
{
	LHeader L = (LHeader)malloc(sizeof(Header));
	if (!L)
	{
		cout << "头节点申请内存失败" << endl;
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
		while (p->next)p = p->next;//移动到表尾
		p->next = s;
		s->next = NULL;
		L->length++;
	}
	return L;

}
/*int List(LHeader L)
* 功能：遍历并输出这个链表的所有值
* 输入：这个链表的头节点的指针
* 返回： 0无意义
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
* 功能：删除链表内指定元素
* 输入：链表的头节点指针 和 要删除的值
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
				cout << "被删除的位置为" << idx << endl;
				break;
			}
			else
			{
				LPNode temp = p;
				pre->next = temp->next;
				L->length--;
				free(temp);
				cout << "被删除的位置为" << idx << endl;
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