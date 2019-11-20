/*���ϳ������Ĵ���
* �����Ӻ������֧���������ӽڵ�
* ��������д��һ��AddNode ����
*
*/


#include<iostream>
#include<stdlib.h>
typedef char ElemType;
using namespace std;
//------���� �����ֵ� ��ʾ��------//
struct Node
{
	Node *child;
	ElemType data;
	Node *brother;
}*CSTree;

//�������
int PreOrder(Node *head)
{
	if (head == NULL)return -1;//�޸��ڵ�
	cout << head->data;
	PreOrder(head->child);//������һ�����ӽڵ�
	PreOrder(head->brother);//�����ֵܽڵ�
	return 0;
}
//�������
int InOrder(Node *head)
{
	if (head == NULL)return -1;//�޸��ڵ�
	InOrder(head->child);    //��������
	cout << head->data;        //
	if(head->child)InOrder(head->child->brother);
	return 0;
}
//�������
int  PostOrder(Node *head)
{
	if (head == NULL)return -1;
	PostOrder(head->child);
	cout << head->data;
	PostOrder(head->brother);
	return 0;
}
//��ӽڵ�
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
//��ӽڵ�Ľ���
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
	
	printf("ǰ������� ");
	PreOrder(&CSTree[0]);
	printf("\n");

	printf("��������� ");
	InOrder(&CSTree[0]);
	printf("\n");

	printf("��������� ");
	PostOrder(&CSTree[0]);
	printf("\n");
	return 0;
}
