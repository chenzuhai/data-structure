#include<iostream>
#include<malloc.h>

struct AVLNode
{
	int data;
	int balance;                  //AVL����ƽ���ֶΣ���ͨ�����������ò���
	struct AVLNode* left;
	struct AVLNode* right;
	struct AVLNode* parent;
};

struct AVLTree
{
	AVLNode* root;
}tree;
//��ѯ����
AVLNode * select(int data, AVLNode* root)
{
	if (root== 0)
		return 0;
	if (root->data == data)
		return root;
	if (root->data > data)
	{
		if (root->left)
			return select(data, root->left);
		else
			return root;
	}
	if (root->data > data)
	{
		if (root->right)
			return select(data, root->right);
		else
			return root;
	}
}
//�������
void insetrt(int data, AVLNode* root)
{
	AVLNode* node = select(data, root);   //�ȴ���������ҵ�Ҫ����ĵط�
	if (node == 0)  //�������ڵ㻹������
	{
		tree.root = (AVLNode*)malloc(sizeof(AVLNode));
		tree.root->data = data;
		tree.root->left = tree.root->right = 0;
		tree.root->parent = 0;
		tree.root->balance = 0;
	}
	else if (node->data != data)   //�������ڵ��ֵ������Ҫ�����ֵ
	{
		if (node->data > data)     //�������ڵ��ֵ����Ҫ�����ֵ
		{
			node->left = (AVLNode*)malloc(sizeof(AVLNode));//Ϊ����ڵ��½�һ����ڵ�
			node->left->data = data;//��ֵ������
			node->left->left = node->left->right = 0;//����½��Ľڵ�����ҽڵ㸳ֵΪ0
			node->left->parent = node;
			node->left->balance = 0;
		}
		else if (node->data < data)//�������ڵ��ֵС��Ҫ�����ֵ
		{
			node->right = (AVLNode*)malloc(sizeof(AVLNode));
			node->right->data = data;
			node->right->left = node->right->right = 0;
			node->right->parent = node;
			node->right->balance = 0;
		}
	}
}

void fun(AVLNode* a)
{
	if (a->parent == 0)
	{
		if (a->left)
		{
			tree.root = a->left;
			a->left->parent = 0;
		}
		else
		{
		tree.root = a->right;
		a->right->parent = 0;
		}
	}
	else
	{
		if (a->parent->left == a)
		{
			if (a->left)
			{

			}
		}
	}
	
}

