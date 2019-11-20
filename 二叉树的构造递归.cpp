#include<iostream>
#include<stdlib.h>

typedef struct BTNode
{
	int data;
	struct BTNode *Lchild;
	struct BTNode *Rchild;
}BiTNode;

//���򴴽�������
void CreateBiTree(BiTNode **T)
{
	int ch;
	std:: cin >> ch;
	if (ch == -1)
	{
		*T = NULL;
		return;
	}
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		printf("����%d�����ӽڵ�",ch);
		CreateBiTree(&((*T)->Lchild));
		printf("����%d�����ӽڵ�",ch);
		CreateBiTree(&((*T)->Rchild));
	}

	return;
}

//�������������

void PreOrderBiTree(BiTNode *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", T->data);
		PreOrderBiTree(T->Lchild);
		PreOrderBiTree(T->Rchild);
	}
}

//�������������
void MiddleOrderBiTree(BiTNode *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		MiddleOrderBiTree(T->Lchild);
		printf("%d ", T->data);
		MiddleOrderBiTree(T->Rchild);
	}
}

//��������������
void PostOrderBiTree(BiTNode *T)
{
	if (T == NULL)
	{
		return;
	}
	else
	{
		PostOrderBiTree(T->Lchild);
		PostOrderBiTree(T->Rchild);
		printf("%d ", T->data);
	}
}

//�����������
int TreeDeep(BiTNode *T)
{
	int deep = 0;
	if (T != NULL)
	{
		int leftdeep = TreeDeep(T->Lchild);
		int rightdeep = TreeDeep(T->Rchild);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}

	return deep;
}

//Ҷ�ӽڵ����
int LeafCount(BiTNode *T)
{
	static int count;
	if (T != NULL)
	{
		if (T->Lchild == NULL && T->Rchild == NULL)
		{
			count++;
		}

		LeafCount(T->Lchild);
		LeafCount(T->Rchild);
	}

	return count;
}

//������
int main(int argc, const char *argv[])
{
	BiTNode *T;
	int depth, leafCount = 0;
	printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ㣺\n");
	CreateBiTree(&T);

	printf("���������������");
	PreOrderBiTree(T);
	printf("\n");

	printf("���������������");
	MiddleOrderBiTree(T);
	printf("\n");

	printf("����������������");
	PostOrderBiTree(T);
	printf("\n");

	depth = TreeDeep(T);
	printf("�������Ϊ��%d\n", depth);

	leafCount = LeafCount(T);
	printf("Ҷ�ӽڵ����:%d\n", leafCount);

	return 0;
}