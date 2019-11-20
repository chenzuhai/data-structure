#include<iostream>
#include<malloc.h>
#include "�������С��.h"
using namespace std;
#define LENGTH(a) ( (sizeof(a)) )/ ( sizeof(a[0] ) )

static int m_heap[30];
static int m_capacity = 30;  //������
static int m_size = 0;       //ʵ�ʴ���

/*
 *����data�ڶ�����е�����
 *
 *����ֵ��
 *		����--��������
 *		������-- -1
 *
 */
int get_index(int data)
{
	int i = 0;
	for (i = 0; i < m_size; i++)
	{
		if (m_heap[i] == data)
			return i;
	}
	return -1;
}
/*
 *��С�ѵ����µ�����
 *
 *����˵����
 *  start--�������Ľڵ����ʵλ��
 *  end  --������Χ(һ�����������һ��Ԫ�ص�����)
 */
static void minheap_filterdown(int start, int end)
{
	int current = start;          //��ǰ�ڵ��λ��
	int left = 2 * current + 1;   //����λ��
	int tmp = m_heap[current];          //��ǰ�ڵ���ֵ

	while (left <= end)
	{
		if (left<end && m_heap[left]>m_heap[left + 1])//�������ӽڵ���ѡ���С���Ǹ�
		{
			left++;
		}
		if (tmp <= m_heap[left])
			break;
		else
		{
			m_heap[current] = m_heap[left];
			current = left;
			left = 2 * left + left;
		}
	}
	m_heap[current] = tmp;

}
/*
* ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*
* ����˵����
*     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
*/
static void filter_up(int start)
{
	int c = start;            // ��ǰ�ڵ�(current)��λ��
	int p = (c - 1) / 2;        // ��(parent)����λ�� 
	int tmp = m_heap[c];        // ��ǰ�ڵ�(current)�Ĵ�С

	while (c > 0)
	{
		if (m_heap[p] <= tmp)
			break;
		else
		{
			m_heap[c] = m_heap[p];
			c = p;
			p = (p - 1) / 2;
		}
	}
	m_heap[c] = tmp;
}
/*
 *ɾ����С���е�data
 *
 *����ֵ��
 *		0���ɹ�
 *		-1,ʧ��
 */
int minheap_remove(int data)
{
	int index;
	//�����Ϊ��,����-1
	if (m_size == 0)
		return -1;

	//��ȡdata�������е�����
	index = get_index(data);
	if (index == -1)
		return -1;  //û���ҵ�

	m_heap[index] = m_heap[--m_size];//���λ�������һ��Ԫ���油
	minheap_filterdown(index, m_size - 1);
}
/*
 *��data���뵽�������
 *
 *0���ɹ�
 *-1,ʧ��
 */
int minheap_insert(int data)
{
	if (m_size == m_capacity)//���������
		return -1;
	m_heap[m_size] = data;//��������ڱ�β
	filter_up(m_size);//���ϵ�����
	m_size++;

	return 0;
}
/*
 *��ӡ�����
 *0�ɹ�
 *1ʧ��
*/
void minheap_print()
{
	int i;
	for (i = 0; i < m_size; i++)
		cout << m_heap[i] << " ";
}
void main()
{
	int a[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
	int i, len = LENGTH(a);

	printf("== �������: ");
	for (i = 0; i<len; i++)
	{
		printf("%d ", a[i]);
		minheap_insert(a[i]);
	}

	printf("\n== �� С ��: ");
	minheap_print();

	i = 15;
	minheap_insert(i);
	printf("\n== ���Ԫ��: %d", i);
	printf("\n== �� С ��: ");
	minheap_print();

	i = 10;
	minheap_remove(i);
	printf("\n== ɾ��Ԫ��: %d", i);
	printf("\n== �� С ��: ");
	minheap_print();
	printf("\n");
}