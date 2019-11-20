#include<iostream>
#include<malloc.h>
using namespace std;
typedef char Element;  //ȡ����
/*  Node
* ���ܴ���ջ��ÿ���ڵ�
*  data ��������
*  ָ������һ���ڵ��ָ��
*/
typedef struct Node
{
	Element data;
	struct Node *next;
}LStackNode;
/* LStack
*  ����ָ��ջ����ָ��
*  ջ�ڽڵ����
*/
typedef struct
{
	LStackNode *Top;
	int count;
}LStack;
/*void InitStack(LStack *S)
* ���ܣ���ʼ��һ��ջ
* ���룺��ͷ�ڵ��ָ��
*/
void InitStack(LStack *S)
{
	S->Top = NULL; //��ջ��ָ����Ϊ��
	S->count = 0;  //ջ��Ԫ��Ϊ0
}
/*int StackEmpty(LStack *S)
* ����: �ж���ջ�Ƿ�Ϊ��
* ����: ��ͷ�ڵ��ָ��
* return 1 ��ʾΪ��
* return 0 ��ʾ��Ϊ��
*/
int StackEmpty(LStack *S)
{
	if (S->Top == NULL)return 1;//���ջ��ָ��Ϊ�գ�����ջΪ��

	return 0;
}
/*int Push(LStack *S, Element Data)
* ���ܣ���Ԫ�ؽ�ջ
* ���룺��ͷ�ڵ��ָ�� �� ����
* return 0  ��ʾ����
* return -1 ��ʾ�����ڴ�ʧ��
*/
int Push(LStack *S, Element Data)
{
	LStackNode *p;
	p = (LStackNode*)malloc(sizeof(LStackNode));//�����ڴ�
	if (!p)
	{
		cout << "�����ڴ�ʧ��" << endl;
		return -1;
	}
	p->data = Data;  //��ֵ��������ڵ�
	p->next = S->Top;//����ڵ�ָ��֮ǰ��ջ��ָ��
	S->Top = p;      //������ڵ�p��Ϊ�µ�ջ���ڵ�
	S->count++;      //�ڵ����+1
	return 0;
}
/*int Pop(LStack *S, Element &data)
* ���ܣ���Ԫ�س�ջ������������
* ���룺��ͷ�ڵ��ָ�� �� ����
* return 0  ��ʾ����
* return -1 ��ʾջΪ��
*/
int Pop(LStack *S, Element &data)
{
	LStackNode *temp;         //�½�һ���м��������ջ���ڵ�
	temp = S->Top;
	if (StackEmpty(S) == 1)
	{
		cout << "ջΪ��,�޷���ջ" << endl;
		return -1;
	}
	data = temp->data;  //�����������ɾ���Ľڵ��ֵ����
	S->Top = temp->next;//��ջ��ָ����Ϊ��һ���ڵ�
	S->count--;         //�ڵ����-1
	free(temp);         //�ͷŽڵ�
	return 1;
}
/*int getCount(LStack *S)
* ����: ���ջ��Ԫ�ظ���
* ����ֵ ΪԪ�ظ���
*/
int getCount(LStack *S)
{
	return S->count;
}
/*int getTop(LStack *S, Element &e)
* ����: ��ȡջ��Ԫ��ֵ
* return -1 ��ʾջΪ��
* return 0 ��ʾ����
*/
int getTop(LStack *S, Element &e)
{
	if (StackEmpty(S) == 1)
	{
		cout << "ջΪ��" << endl;
		return -1;
	}
	e = S->Top->data;
	return 0;
}
/*int check(string expressing)
* ����: �����ʽ�������Ƿ�ƥ��
* ���룺string���ͱ��ʽ
* ���ݽṹ���Ĵ���ҵ��һ��
*/
int check(string expr)
{
	LStack S;
	InitStack(&S);
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{'  )
		{
			Push(&S, expr[i]);
		}
		else if (expr[i] == '/')
		{
			Push(&S, expr[i]);
			if (expr[i + 1] != '*')
			{
				cout << "���ʽ����" << endl;
				return -1;
			}
			else
			{
				Push(&S, expr[i+1]);
				i++;
			}
		}
		else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
		{
			char e;
			if (expr[i] == ')')
			{
				int flag;
				flag = Pop(&S, e);
				if (e != '(' || flag == -1)
				{
					cout << "���ʽ����" << endl;
					return -1;
				}
				
			}
			else if (expr[i] == ']')
			{
				int flag;
				flag=Pop(&S, e);
				if (e != '['||flag==-1)
				{
					cout << "���ʽ����" << endl;
					return -1;
				}

			}
			else if (expr[i] == '}')
			{
				int flag;
				flag = Pop(&S, e);
			
				if (e != '{' || flag == -1)
				{
					cout << "���ʽ����" << endl;
					return -1;
				}

			}
		}
		else if (expr[i] == '*')
		{

			if (expr[i+1] != '/')
			{
				cout << "���ʽ����" << endl;
				return -1;
			}
			else
			{
				int flag;
				char e, f;
				Pop(&S, e);
				flag=Pop(&S, f);
				if (e != '*' || f != '/' || flag == -1)
				{
					cout << "���ʽ����" << endl;
					return -1;
				}
				i++;
			}
		}
		else if (expr[i] == '+' || expr[i] == '-' || expr[i] == 'c' || expr[i] == '/'||(expr[i]>'0'&&expr[i]<'9'))
		{

		}
		else
		{
			cout << "��ַ��Ż���" << endl;
			return -1;
		}
	}
	cout << "���ʽ��ȷ" << endl;
	return 0;
}
int main()
{
	string a = "{[(3+40)6+5]}";
	check(a);
	return 0;
}