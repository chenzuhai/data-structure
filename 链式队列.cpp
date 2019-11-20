#include<iostream>
#include<malloc.h>
using namespace std;
typedef int ElemType;
typedef struct QNode
{
	ElemType data;     //存储节点数据
	struct QNode *next;//指向下一个节点的指针
}LNode;
typedef struct 
{
	LNode *front;//指向头节点的指针
	LNode *rear; //指向尾节点的指针
	int count;   //储存队列中元素的个数
}LQueue;
/*int InitLQueue(LQueue *q)
* 功能：初始化一个链式队列
* 输入：一个队列的头节点
* 返回：-1代表申请内存失败 0代表正常
*/
int InitLQueue(LQueue *q)
{
	q->front = (LNode*)malloc(sizeof(LNode));//申请一个新的节点
	if (!q->front)
	{
		cout << "申请空间失败" << endl;
		return -1;
	}
	q->front->next = NULL;//将这个节点的指向下一个节点的指针置空
	q->rear = q->front;//头指针和尾指针指向同一地方
	q->count = 0;        //列表元素个数为0
	return 0;
}
/*int QueueEmpty(LQueue *q)
* 功能：判断这个队列是否为空
* 输入：一个队列的头节点
* 返回：1代表为空 0代表不为空
*/
int QueueEmpty(LQueue *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
/*int GetHead(LQueue *q,ElemType &data)
* 功能：获取队列第一个元素值
* 输入：一个队列的头节点 和 一个变量
* 返回：-1代表队列为空 0代表正常
*/
int GetHead(LQueue *q,ElemType &data)
{
	if (q->front == q->rear)
	{
		cout << "这个队列为空" << endl;
		return -1;
	}
	else
	{
		data = q->front->data; 
		return 0;
	}
}
/*int InsertQueue(LQueue *q, ElemType &data)
* 功能：添加元素到队列中
* 输入：一个队列的头节点 和 一个变量
* 返回：-1代表分配内存失败 0代表正常
*/
int InsertQueue(LQueue *q, ElemType data)
{
	q->rear->next = (LNode *)malloc(sizeof(LNode));//分配空间
	if (!q->rear->next)
	{
		cout << "分配空间失败" << endl;
		return -1;
	}
	q->rear->next->data = data;//将这个数据赋给他；
	q->rear = q->rear->next;   //将这个节点设置为新的尾节点
	q->rear->next = NULL;      //将尾节点的后继节点置空
	q->count++;
	return 0;
}
/*int DelQueue(LQueue *q, ElemType &data)
* 功能：出队列
* 输入：一个队列的头节点 和 一个变量
* 返回： -1代表分配内存失败或者列表为空 0代表正常
*/
int DelQueue(LQueue *q, ElemType &data)
{
	
	LNode *s;
	if (q->front == q->rear)//判断队列是否为空
	{
		cout << "这个列表为空，不能出队列" << endl;
		return -1;
	}

	else
	{
		s = q->front->next;    //s指向队列的首节点
		data = q->front->next->data; //讲数据带出
		q->front->next = s->next;    //将头节点向后移动一位
		q->count--;            //节点个数-1
		free(s);               //释放原来的第一个节点
		return 0;
	}

}
void DeQueue(LQueue  *q, ElemType &data) {
	if (q->front->next == NULL) {
		printf("队列为空");
		return;
	}
	QNode * p = q->front->next;
	data = p->data;
	q->front->next = p->next;
	if (q->rear == p) {
		q->rear = q->front;
	}
	free(p);
}
int getCount(LQueue  *q)
{
	return q->count;
}
int main()
{
	LQueue L; int data;
	InitLQueue(&L);
	for (int i = 0; i < 10; i++)
	{
		InsertQueue(&L, i);
	}
	for (int i = 0; i < 10; i++)
	{
		DelQueue(&L, data); 
		cout << data;
	}

	return 0;
}