#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int Element;
typedef struct
{
	Element data[MAXSIZE];
	int front;
	int rear;
}Squeue;
/*void InitQueue(Squeue *q)
* 功能  ：初始化这个队列
* 输入值：指向这个队列的指针
* 返回值：无
*/
void InitQueue(Squeue *q)
{
	q->front = 0;
	q->rear = 0;
}
/*int QueueEmpty(Squeue *q)
* 功能  ：判断这个队列是否为空
* 输入值：指向这个队列的指针
* 返回值：1代表为空  0代表 不为空
*/
int QueueEmpty(Squeue *q)
{
	if (q->front == q->rear)//如果头和尾都在一个位置表明这个队列为空
		return 1;
	else
		return 0;
}
/*int GetHead(Squeue *q, Element &data)
* 功能  ：取得队列的首个元素
* 输入  ：Squeue *q为指向队列的指针  Element &data这个为取出值后所保存的值
* 返回值：-1代表这个队列为空 0代表正常
*/
int GetHead(Squeue *q, Element &data)
{
	if (QueueEmpty(q))//判断是否为空队列
	{
		cout << "这个队列为空" << endl;
		return -1;
	}
	else
	{
		data = q->data[(q->front + 1) % MAXSIZE];//将队列第一个元素赋给data
		return 0;
	}
}
/*int InsertQueue(Squeue *q, Element data)
* 功能	：入队列
* 输入	：Squeue *q为指向队列的指针 Element data为要入队列的值
* 返回值：-1代表这个队列已经满了 0代表正常
*/
int InsertQueue(Squeue *q, Element data)
{
	if (q->front == (q->rear + 1) % MAXSIZE)//表示尾指针后面那个就是头指针
	{
		cout << "队列满了" << endl;
		return -1;
	}
	else
	{
		
		q->rear = (q->rear + 1) % MAXSIZE;//尾指针向后移动一位
		q->data[q->rear] = data;
	}
	return 0;
}
int Insert_front(Squeue *q, Element data)
{
	if (q->front == (q->rear + 1)*MAXSIZE)
	{
		cout << "队列满了" << endl;
		return -1;
	}
	else
	{
		q->data[q->front] = data;
		if (q->front > 0)
		{
			q->front = q->front - 1;
		}
		else if (q->front ==0)
		{
			q->front = MAXSIZE - 1;
		}
		else
		{
			q->front = q->front - 1;
		}	
		return 0;
	}

}
/*int DelQueue(Squeue *q, Element &data)
* 功能	：删除队列第一个元素
* 输入	：Squeue *q是指向队列的指针 Element &data出队列的元素值
* 返回值：-1表示队列为空 0表示正常
*/
int DelQueue(Squeue *q, Element &data)
{
	if (QueueEmpty(q))
	{
		cout << "队列为空" << endl;
		return -1;
	}
	else
	{
		
		q->front = (q->front + 1) % MAXSIZE;
		data = q->data[q->front];
		return 0;
	}
}
int Del_last(Squeue *q, Element &data)
{
	if (QueueEmpty(q))
	{
		cout << "队列为空" << endl;
		return -1;
	}
	else
	{
		data = q->data[q->rear];
		if (q->rear == 0)
		{
			q->rear = MAXSIZE - 1;
		}
		else
		{
			q->rear = (q->rear - 1);
		}
		return 0;
	}
}
int main()
{
	Squeue *q = (Squeue*)malloc(sizeof(Squeue));
	InitQueue(q);
	
		for (int i = 0; i < 10; i++)
		{
			Insert_front(q, i);
		}
		for (int i = 0; i < 10; i++)
		{
			int e;
			Del_last(q, e);
			cout << e << " ";
		}

	

}