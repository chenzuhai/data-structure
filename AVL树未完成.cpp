#include<iostream>
#include<malloc.h>

struct AVLNode
{
	int data;
	int balance;                  //AVL树的平衡字段，普通二叉树排序用不到
	struct AVLNode* left;
	struct AVLNode* right;
	struct AVLNode* parent;
};

struct AVLTree
{
	AVLNode* root;
}tree;
//查询操作
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
//插入操作
void insetrt(int data, AVLNode* root)
{
	AVLNode* node = select(data, root);   //先从这个树中找到要插入的地方
	if (node == 0)  //如果这个节点还不存在
	{
		tree.root = (AVLNode*)malloc(sizeof(AVLNode));
		tree.root->data = data;
		tree.root->left = tree.root->right = 0;
		tree.root->parent = 0;
		tree.root->balance = 0;
	}
	else if (node->data != data)   //如果这个节点的值不等于要插入的值
	{
		if (node->data > data)     //如果这个节点的值大于要插入的值
		{
			node->left = (AVLNode*)malloc(sizeof(AVLNode));//为这个节点新建一个左节点
			node->left->data = data;//将值赋给他
			node->left->left = node->left->right = 0;//这个新建的节点的左右节点赋值为0
			node->left->parent = node;
			node->left->balance = 0;
		}
		else if (node->data < data)//如果这个节点的值小于要插入的值
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

