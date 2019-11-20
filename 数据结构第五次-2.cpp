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
* ����  ����ʼ���������
* ����ֵ��ָ��������е�ָ��
* ����ֵ����
*/
void InitQueue(Squeue *q)
{
	q->front = 0;
	q->rear = 0;
}
/*int QueueEmpty(Squeue *q)
* ����  ���ж���������Ƿ�Ϊ��
* ����ֵ��ָ��������е�ָ��
* ����ֵ��1����Ϊ��  0���� ��Ϊ��
*/
int QueueEmpty(Squeue *q)
{
	if (q->front == q->rear)//���ͷ��β����һ��λ�ñ����������Ϊ��
		return 1;
	else
		return 0;
}
/*int GetHead(Squeue *q, Element &data)
* ����  ��ȡ�ö��е��׸�Ԫ��
* ����  ��Squeue *qΪָ����е�ָ��  Element &data���Ϊȡ��ֵ���������ֵ
* ����ֵ��-1�����������Ϊ�� 0��������
*/
int GetHead(Squeue *q, Element &data)
{
	if (QueueEmpty(q))//�ж��Ƿ�Ϊ�ն���
	{
		cout << "�������Ϊ��" << endl;
		return -1;
	}
	else
	{
		data = q->data[(q->front + 1) % MAXSIZE];//�����е�һ��Ԫ�ظ���data
		return 0;
	}
}
/*int InsertQueue(Squeue *q, Element data)
* ����	�������
* ����	��Squeue *qΪָ����е�ָ�� Element dataΪҪ����е�ֵ
* ����ֵ��-1������������Ѿ����� 0��������
*/
int InsertQueue(Squeue *q, Element data)
{
	if (q->front == (q->rear + 1) % MAXSIZE)//��ʾβָ������Ǹ�����ͷָ��
	{
		cout << "��������" << endl;
		return -1;
	}
	else
	{
		
		q->rear = (q->rear + 1) % MAXSIZE;//βָ������ƶ�һλ
		q->data[q->rear] = data;
	}
	return 0;
}
int Insert_front(Squeue *q, Element data)
{
	if (q->front == (q->rear + 1)*MAXSIZE)
	{
		cout << "��������" << endl;
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
* ����	��ɾ�����е�һ��Ԫ��
* ����	��Squeue *q��ָ����е�ָ�� Element &data�����е�Ԫ��ֵ
* ����ֵ��-1��ʾ����Ϊ�� 0��ʾ����
*/
int DelQueue(Squeue *q, Element &data)
{
	if (QueueEmpty(q))
	{
		cout << "����Ϊ��" << endl;
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
		cout << "����Ϊ��" << endl;
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