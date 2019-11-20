#include<iostream>
#include<malloc.h>
#include "二叉堆最小堆.h"
using namespace std;
#define LENGTH(a) ( (sizeof(a)) )/ ( sizeof(a[0] ) )

static int m_heap[30];
static int m_capacity = 30;  //总容量
static int m_size = 0;       //实际储存

/*
 *返回data在二叉堆中的索引
 *
 *返回值：
 *		存在--返回索引
 *		不存在-- -1
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
 *最小堆的向下调整法
 *
 *参数说明：
 *  start--被调整的节点的其实位置
 *  end  --截至范围(一般是数组最后一个元素的索引)
 */
static void minheap_filterdown(int start, int end)
{
	int current = start;          //当前节点的位置
	int left = 2 * current + 1;   //左孩子位置
	int tmp = m_heap[current];          //当前节点数值

	while (left <= end)
	{
		if (left<end && m_heap[left]>m_heap[left + 1])//在两个子节点中选择较小的那个
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
* 最小堆的向上调整算法(从start开始向上直到0，调整堆)
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
*
* 参数说明：
*     start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
*/
static void filter_up(int start)
{
	int c = start;            // 当前节点(current)的位置
	int p = (c - 1) / 2;        // 父(parent)结点的位置 
	int tmp = m_heap[c];        // 当前节点(current)的大小

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
 *删除最小堆中的data
 *
 *返回值：
 *		0，成功
 *		-1,失败
 */
int minheap_remove(int data)
{
	int index;
	//如果堆为空,返回-1
	if (m_size == 0)
		return -1;

	//获取data在数组中的索引
	index = get_index(data);
	if (index == -1)
		return -1;  //没有找到

	m_heap[index] = m_heap[--m_size];//这个位置用最后一个元素替补
	minheap_filterdown(index, m_size - 1);
}
/*
 *将data插入到二叉堆中
 *
 *0，成功
 *-1,失败
 */
int minheap_insert(int data)
{
	if (m_size == m_capacity)//二叉堆已满
		return -1;
	m_heap[m_size] = data;//将数组插在表尾
	filter_up(m_size);//向上调整堆
	m_size++;

	return 0;
}
/*
 *打印二叉堆
 *0成功
 *1失败
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

	printf("== 依次添加: ");
	for (i = 0; i<len; i++)
	{
		printf("%d ", a[i]);
		minheap_insert(a[i]);
	}

	printf("\n== 最 小 堆: ");
	minheap_print();

	i = 15;
	minheap_insert(i);
	printf("\n== 添加元素: %d", i);
	printf("\n== 最 小 堆: ");
	minheap_print();

	i = 10;
	minheap_remove(i);
	printf("\n== 删除元素: %d", i);
	printf("\n== 最 小 堆: ");
	minheap_print();
	printf("\n");
}