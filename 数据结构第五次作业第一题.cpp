#include<iostream>
#include<malloc.h>
typedef int Element;
using namespace std;
typedef struct LNode
{
	Element data;
	struct LNode *next;
}LNode, *LPNode;
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
	LH->length = 0;
	LH->head = NULL;
	return 0;
}
/*LHeader tail(int data[])
* 功能：通过一个数组使用尾插法快速新建一个链表
* 输入：数组 数组的起始下标和终止下标
*/
LHeader tail(int data[], int first, int last)
{
	LHeader L = (LHeader)malloc(sizeof(Header));
	if (!L)
	{
		cout << "头节点申请内存失败" << endl;
		return NULL;
	}
	L->head = NULL;
	L->length = 0;

	for (int i = first; i <= last; i++)
	{
		LPNode s = (LPNode)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		if (L->length == 0) { L->head = s;  L->length++; continue; }
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
/*int InsertQueue(Squeue *q, Element data)
* 功能	：入队列
* 输入	：Squeue *q为指向队列的指针 Element data为要入队列的值
* 返回值：-1代表这个队列已经满了 0代表正常
* 这个函数是使用链表来实现的
*/
int InsertQueue(LHeader L, Element data)
{
	LPNode p = L->head;
	LPNode s = (LPNode)malloc(sizeof(LNode));
	s->data = data;
	s->next = NULL;
	while (p->next)p = p->next;	
	p->next = s;
	return 0;
} 
int DelQueue(LHeader L,Element &data)
{
	LPNode tmp = L->head;
	data = L->head->data;
	L->head = tmp->next;
	free(tmp);
	return 0;
}
/*int QueueEmpty(Squeue *q)
* 功能  ：判断这个队列是否为空
* 输入值：指向这个队列的指针
* 返回值：1代表为空  0代表 不为空
*/
int QueueEmpty(LHeader L)
{
	if (L->length == 0)
		return 1;
	return 0;
}
/*int GetHead(Squeue *q, Element &data)
* 功能  ：取得队列的首个元素
* 输入  ：Squeue *q为指向队列的指针  Element &data这个为取出值后所保存的值
* 返回值：-1代表这个队列为空 0代表正常
*/
int GetHead(LHeader L, Element &data)
{
	if (QueueEmpty(L))//判断是否为空队列
	{
		cout << "这个队列为空" << endl;
		return -1;
	}
	else
	{
		data = L->head->data;
		return 0;
	}
}
int main()
{
	LHeader L;
	int a[] = { 1,2,3,4,5,6,7 };
	L = tail(a, 0, 6);
	//dele(L, 4);
	InsertQueue(L, 1);
	int e;
	//DelQueue(L,e);

	List(L);
	GetHead(L, e);
	cout << e;
	return 0;
}