#include<iostream>
#include<malloc.h>
using namespace std;
typedef int ElemType;
typedef struct QNode
{
	ElemType data;     //�洢�ڵ�����
	struct QNode *next;//ָ����һ���ڵ��ָ��
}LNode;
typedef struct 
{
	LNode *front;//ָ��ͷ�ڵ��ָ��
	LNode *rear; //ָ��β�ڵ��ָ��
	int count;   //���������Ԫ�صĸ���
}LQueue;
/*int InitLQueue(LQueue *q)
* ���ܣ���ʼ��һ����ʽ����
* ���룺һ�����е�ͷ�ڵ�
* ���أ�-1���������ڴ�ʧ�� 0��������
*/
int InitLQueue(LQueue *q)
{
	q->front = (LNode*)malloc(sizeof(LNode));//����һ���µĽڵ�
	if (!q->front)
	{
		cout << "����ռ�ʧ��" << endl;
		return -1;
	}
	q->front->next = NULL;//������ڵ��ָ����һ���ڵ��ָ���ÿ�
	q->rear = q->front;//ͷָ���βָ��ָ��ͬһ�ط�
	q->count = 0;        //�б�Ԫ�ظ���Ϊ0
	return 0;
}
/*int QueueEmpty(LQueue *q)
* ���ܣ��ж���������Ƿ�Ϊ��
* ���룺һ�����е�ͷ�ڵ�
* ���أ�1����Ϊ�� 0����Ϊ��
*/
int QueueEmpty(LQueue *q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
/*int GetHead(LQueue *q,ElemType &data)
* ���ܣ���ȡ���е�һ��Ԫ��ֵ
* ���룺һ�����е�ͷ�ڵ� �� һ������
* ���أ�-1�������Ϊ�� 0��������
*/
int GetHead(LQueue *q,ElemType &data)
{
	if (q->front == q->rear)
	{
		cout << "�������Ϊ��" << endl;
		return -1;
	}
	else
	{
		data = q->front->data; 
		return 0;
	}
}
/*int InsertQueue(LQueue *q, ElemType &data)
* ���ܣ����Ԫ�ص�������
* ���룺һ�����е�ͷ�ڵ� �� һ������
* ���أ�-1��������ڴ�ʧ�� 0��������
*/
int InsertQueue(LQueue *q, ElemType data)
{
	q->rear->next = (LNode *)malloc(sizeof(LNode));//����ռ�
	if (!q->rear->next)
	{
		cout << "����ռ�ʧ��" << endl;
		return -1;
	}
	q->rear->next->data = data;//��������ݸ�������
	q->rear = q->rear->next;   //������ڵ�����Ϊ�µ�β�ڵ�
	q->rear->next = NULL;      //��β�ڵ�ĺ�̽ڵ��ÿ�
	q->count++;
	return 0;
}
/*int DelQueue(LQueue *q, ElemType &data)
* ���ܣ�������
* ���룺һ�����е�ͷ�ڵ� �� һ������
* ���أ� -1��������ڴ�ʧ�ܻ����б�Ϊ�� 0��������
*/
int DelQueue(LQueue *q, ElemType &data)
{
	
	LNode *s;
	if (q->front == q->rear)//�ж϶����Ƿ�Ϊ��
	{
		cout << "����б�Ϊ�գ����ܳ�����" << endl;
		return -1;
	}

	else
	{
		s = q->front->next;    //sָ����е��׽ڵ�
		data = q->front->next->data; //�����ݴ���
		q->front->next = s->next;    //��ͷ�ڵ�����ƶ�һλ
		q->count--;            //�ڵ����-1
		free(s);               //�ͷ�ԭ���ĵ�һ���ڵ�
		return 0;
	}

}
void DeQueue(LQueue  *q, ElemType &data) {
	if (q->front->next == NULL) {
		printf("����Ϊ��");
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