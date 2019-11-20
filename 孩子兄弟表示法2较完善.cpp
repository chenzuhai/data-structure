/*网上抄下来的代码
* 看样子好像最多支持两个儿子节点
* 我又重新写了一遍AddNode 函数
*
*/


#include<iostream>
#include<stdlib.h>
typedef char ElemType;
using namespace std;
//------树的 孩子兄弟 表示法------//
struct Node
{
	Node *child;
	ElemType data;
	Node *brother;
}*CSTree;

//先序遍历
int PreOrder(Node *head)
{
	if (head == NULL)return -1;//无根节点
	cout << head->data;
	PreOrder(head->child);//遍历第一个孩子节点
	PreOrder(head->brother);//遍历兄弟节点
	return 0;
}
//中序遍历
int InOrder(Node *head)
{
	if (head == NULL)return -1;//无根节点
	InOrder(head->child);    //遍历孩子
	cout << head->data;        //
	if(head->child)InOrder(head->child->brother);
	return 0;
}
//后序遍历
int  PostOrder(Node *head)
{
	if (head == NULL)return -1;
	PostOrder(head->child);
	cout << head->data;
	PostOrder(head->brother);
	return 0;
}
//添加节点
//int AddNode(Node *parent, Node *child)
//{
//	if (parent->child != NULL)
//	{
//		parent->child->brother = child;
//		return 0;
//	}
//	else
//	{
//		parent->child = child;
//		return 0;
//	}
//}
//添加节点改进版
int AddNode(Node *parent, Node *child)
{
	if (parent->child == NULL)
	{
		parent->child = child;
		return 0;
	}
	else
	{
		Node *S = parent->child;
		while (S->brother != NULL)
		{
			S = S->brother;
		}
		S->brother = child;
		return 0;
	}
}
int main()
{
	int NodeNum = 100;
	CSTree = (Node *)malloc(NodeNum * sizeof(Node));
	char d = 'A';
	for (int i = 0; i < NodeNum; i++)
	{
		CSTree[i].child = NULL;
		CSTree[i].brother = NULL;
		CSTree[i].data = d;
		d++;
	}
	AddNode(&CSTree[0], &CSTree[1]);		// A->B
	AddNode(&CSTree[0], &CSTree[2]);		// A->C
	AddNode(&CSTree[1], &CSTree[3]);		// B->D
	AddNode(&CSTree[1], &CSTree[4]);		// B->E
	AddNode(&CSTree[2], &CSTree[5]);		// C->F
	AddNode(&CSTree[3], &CSTree[6]);		// D->G
	AddNode(&CSTree[6], &CSTree[9]);	
	AddNode(&CSTree[5], &CSTree[7]);		// F->H
	AddNode(&CSTree[5], &CSTree[8]);		// F->I
	
	printf("前序遍历： ");
	PreOrder(&CSTree[0]);
	printf("\n");

	printf("中序遍历： ");
	InOrder(&CSTree[0]);
	printf("\n");

	printf("后序遍历： ");
	PostOrder(&CSTree[0]);
	printf("\n");
	return 0;
}
