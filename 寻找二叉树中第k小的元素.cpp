#include<iostream>
using namespace std;
#define Elemtype char
//��ʼ��
typedef struct Btree
{
	Elemtype data;//�ڵ�����
	struct Btree *Lchild;//������ָ��
	struct Btree *Rchild;//������ָ��
}Btree, *ptrBtree;

//���������
ptrBtree CreateBtree(char *pre, char*mid, int n)
{
	char *p = NULL;
	Btree *q = NULL;
	if (n <= 0)
		return NULL;
	q = (Btree*)malloc(sizeof(Btree));
	q->data = *pre;
	p = mid;
	for (p; p < mid + n; p++)
	{
		if (*p == *pre)
			break;
	}
	int k = p - mid;
	q->Lchild = CreateBtree(pre + 1, mid, k);
	q->Rchild = CreateBtree(pre + 1 + k, p + 1, n - k - 1);
	return q;
}


//�ݹ����
//�������
void PreOrder(ptrBtree T)
{
	if (T)
	{
		cout << T->data << ' ';
		PreOrder(T->Lchild);
		PreOrder(T->Rchild);
	}
}
//�������
void InOrder(ptrBtree T)
{
	if (T)
	{

		InOrder(T->Lchild);
		cout << T->data << ' ';
		InOrder(T->Rchild);

	}
}
//�������
void PostOrder(ptrBtree T)
{
	if (T)
	{
		PostOrder(T->Lchild);
		PostOrder(T->Rchild);
		cout << T->data << ' ';
	}
}
int count(ptrBtree T)
{
	if (T == NULL)
		return 0;
	return 1 + count(T->Lchild) + count(T->Rchild);
}
int kthS(ptrBtree T, int k)
{
	int num = count(T->Lchild);
	if (num == k - 1)
		return T->data;
	if (num > k - 1)
		return kthS(T->Lchild, k);
	return kthS(T->Rchild, k - num - 1);
}
int main()
{
	Btree *b = NULL;
	char pre[] = "ABDECFG";
	char in[] = "DBEAFCG";
	b = CreateBtree(pre, in, 7);
	cout <<(char) kthS(b, 5);
	return 0;
}


