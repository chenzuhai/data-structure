#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct
{
	int weight;//�ڵ�Ȩ��
	int parent, left, right;//���ڵ㡢���ӡ��Һ���
}HTNode, *HuffmanTree;

//HTΪ��ַ���ݵĴ洢�������������飬wΪ����ڵ�Ȩ�ص����飬nΪ�ڵ����
void  CreateHuffmanTree(HuffmanTree *HT, int *w, int n)
{
	if (n <= 1)return; //���ֻ��һ��������൱��0
	int m = 2 * n - 1; //�������ܽ������n����Ҷ�ӽڵ�
	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//0��λ�ò���
	HuffmanTree p = *HT;
	//��ʼ�����������е����нڵ�
	for (int i = 1; i <= n; i++)
	{
		(p + i)->weight = *(w + i - 1);
		(p + i)->parent = 0;
		(p + i)->left	= 0;
		(p + i)->right	= 0;
	}
	//��������±�n+1��ʼ��ʼ�����������г�Ҷ�ӽڵ���Ľڵ�
	for (int i = n + 1; i <= n; i++)
	{
		(p + i)->weight = 0;
		(p + i)->parent = 0;
		(p + i)->left	= 0;
		(p + i)->right	= 0;
	}
	//������������
	for (int i = n + 1; i <= m; i++)
	{
		int s1, s2;
		Select()
	}
}