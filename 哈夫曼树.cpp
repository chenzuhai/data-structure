#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct
{
	int weight;//节点权重
	int parent, left, right;//父节点、左孩子、右孩子
}HTNode, *HuffmanTree;

//HT为地址传递的存储哈夫曼树的数组，w为储存节点权重的数组，n为节点个数
void  CreateHuffmanTree(HuffmanTree *HT, int *w, int n)
{
	if (n <= 1)return; //如果只有一个编码就相当于0
	int m = 2 * n - 1; //哈夫曼总结点数，n就是叶子节点
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0号位置不用
	HuffmanTree p = *HT;
	//初始化哈夫曼树中的所有节点
	for (int i = 1; i <= n; i++)
	{
		(p + i)->weight = *(w + i - 1);
		(p + i)->parent = 0;
		(p + i)->left	= 0;
		(p + i)->right	= 0;
	}
	//从数组的下标n+1开始初始化哈夫曼树中除叶子节点外的节点
	for (int i = n + 1; i <= n; i++)
	{
		(p + i)->weight = 0;
		(p + i)->parent = 0;
		(p + i)->left	= 0;
		(p + i)->right	= 0;
	}
	//构建哈夫曼树
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;
		Select()
	}
}